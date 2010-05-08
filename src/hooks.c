#include "hooks.h"
#include "sim.h"

#include <errno.h>
#include <stdarg.h>

struct hook_entry {
    enum hook_type type;
    enum hook_when when;
    union {
        hc_op_hook op;
        hc_opclass_hook opclass;
    } hook;
    union {
        enum opclass opclass;
        enum op op;
        hc_pred pred;
    } why;
};

struct hook_state {
    size_t hook_count;          ///< counts total hook_entry allocated
    size_t hook_index;          ///< points to next free hook_entry
    struct hook_entry *hooks;
};

static int _init_hook_state(struct sim_state *state)
{
    if (state->hook_state)
        return -EALREADY;

    state->hook_state = calloc(1, sizeof *state->hook_state);

    return 0;
}

static int _grow_hooks(struct hook_state *hs, size_t more)
{
    size_t orig = hs->hook_count;
    while (more + orig > hs->hook_count)
        hs->hooks = realloc(hs->hooks, hs->hook_count *= 2);

    return !hs->hooks;
}

static struct hook_entry * _new_hook(struct hook_state *hs)
{
    _grow_hooks(hs, 1);
    return &hs->hooks[hs->hook_index++];
}

int hc_hook_install(struct sim_state *state, enum hook_when when,
                    enum hook_type type, ...)
{
    _init_hook_state(state);
    struct hook_entry *he = _new_hook(state->hook_state);
    va_list va;
    va_start(va,type);
    he->type = type;
    he->when = when;

    switch (type) {
        case HOOK_TYPE_INSTR: {
            enum op op = va_arg(va, enum op);
            hc_op_hook hook = va_arg(va, hc_op_hook);
            he->why.op = op;
            he->hook.op = hook;
            break;
        }
        case HOOK_TYPE_INSTR_CLASS: {
            enum opclass oc = va_arg(va, enum opclass);
            hc_opclass_hook hook = va_arg(va, hc_opclass_hook);
            he->why.opclass = oc;
            he->hook.opclass = hook;
            break;
        }
        case HOOK_TYPE_PRED: {
            hc_pred pred = va_arg(va, hc_pred);
            hc_op_hook hook = va_arg(va, hc_op_hook);
            he->why.pred = pred;
            he->hook.op = hook;
        }
        default:
            return -1;
    }

    va_end(va);

    return 0;
}

// called by sim loop
int hc_hook_pre_op(struct sim_state *state)
{
    return -1;
}

int hc_hook_post_op(struct sim_state *state)
{
    return -1;
}

/* vi:set ts=4 sw=4 et: */
/* vim:set syntax=c.doxygen: */

