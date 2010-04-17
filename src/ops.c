#include "ops.h"
/// @todo take out stdio reference
#include <stdio.h>

////////////////////////////////////////////////////////////////////////////////
// Data declarations
////////////////////////////////////////////////////////////////////////////////

const char *opnames[] = {
#define NAMED(X) [OP_##X] = #X
    NAMED(ADC),
    NAMED(ADD),
    NAMED(AIS),
    NAMED(AIX),
    NAMED(AND),
    NAMED(ASR),
    NAMED(ASRA),
    NAMED(ASRX),
    NAMED(BCC),
    NAMED(BCLR0),
    NAMED(BCLR1),
    NAMED(BCLR2),
    NAMED(BCLR3),
    NAMED(BCLR4),
    NAMED(BCLR5),
    NAMED(BCLR6),
    NAMED(BCLR7),
    NAMED(BCS),
    NAMED(BEQ),
    NAMED(BGE),
    NAMED(BGND),
    NAMED(BGT),
    NAMED(BHCC),
    NAMED(BHCS),
    NAMED(BHI),
    NAMED(BIH),
    NAMED(BIL),
    NAMED(BIT),
    NAMED(BLE),
    NAMED(BLS),
    NAMED(BLT),
    NAMED(BMC),
    NAMED(BMI),
    NAMED(BMS),
    NAMED(BNE),
    NAMED(BPL),
    NAMED(BRA),
    NAMED(BRCLR0),
    NAMED(BRCLR1),
    NAMED(BRCLR2),
    NAMED(BRCLR3),
    NAMED(BRCLR4),
    NAMED(BRCLR5),
    NAMED(BRCLR6),
    NAMED(BRCLR7),
    NAMED(BRN),
    NAMED(BRSET0),
    NAMED(BRSET1),
    NAMED(BRSET2),
    NAMED(BRSET3),
    NAMED(BRSET4),
    NAMED(BRSET5),
    NAMED(BRSET6),
    NAMED(BRSET7),
    NAMED(BSET0),
    NAMED(BSET1),
    NAMED(BSET2),
    NAMED(BSET3),
    NAMED(BSET4),
    NAMED(BSET5),
    NAMED(BSET6),
    NAMED(BSET7),
    NAMED(BSR),
    NAMED(CBEQ),
    NAMED(CBEQA),
    NAMED(CBEQX),
    NAMED(CLC),
    NAMED(CLI),
    NAMED(CLR),
    NAMED(CLRA),
    NAMED(CLRH),
    NAMED(CLRX),
    NAMED(CMP),
    NAMED(COM),
    NAMED(COMA),
    NAMED(COMX),
    NAMED(CPHX),
    NAMED(CPX),
    NAMED(DAA),
    NAMED(DBNZ),
    NAMED(DBNZA),
    NAMED(DBNZX),
    NAMED(DEC),
    NAMED(DECA),
    NAMED(DECX),
    NAMED(DIV),
    NAMED(EOR),
    NAMED(INC),
    NAMED(INCA),
    NAMED(INCX),
    NAMED(JMP),
    NAMED(JSR),
    NAMED(LDA),
    NAMED(LDHX),
    NAMED(LDX),
    NAMED(LSL),
    NAMED(LSLA),
    NAMED(LSLX),
    NAMED(LSR),
    NAMED(LSRA),
    NAMED(LSRX),
    NAMED(MOV),
    NAMED(MUL),
    NAMED(NEG),
    NAMED(NEGA),
    NAMED(NEGX),
    NAMED(NOP),
    NAMED(NSA),
    NAMED(ORA),
    NAMED(PSHA),
    NAMED(PSHH),
    NAMED(PSHX),
    NAMED(PULA),
    NAMED(PULH),
    NAMED(PULX),
    NAMED(ROL),
    NAMED(ROLA),
    NAMED(ROLX),
    NAMED(ROR),
    NAMED(RORA),
    NAMED(RORX),
    NAMED(RSP),
    NAMED(RTI),
    NAMED(RTS),
    NAMED(SBC),
    NAMED(SEC),
    NAMED(SEI),
    NAMED(STA),
    NAMED(STHX),
    NAMED(STOP),
    NAMED(STX),
    NAMED(SUB),
    NAMED(SWI),
    NAMED(TAP),
    NAMED(TAX),
    NAMED(TPA),
    NAMED(TST),
    NAMED(TSTA),
    NAMED(TSTX),
    NAMED(TSX),
    NAMED(TXA),
    NAMED(TXS),
    NAMED(WAIT)
#undef NAMED
};

int opnames_size = countof(opnames);

const char *modenames[] = {
    [MODE_DD  ] = "DD",
    [MODE_DIR ] = "DIR",
    [MODE_DIXP] = "DIX+",
    [MODE_EXT ] = "EXT",
    [MODE_IMD ] = "IMD",
    [MODE_IMM ] = "IMM",
    [MODE_INH ] = "INH",
    [MODE_IX  ] = "IX",
    [MODE_IXP ] = "IX+",
    [MODE_IXPD] = "IX+D",
    [MODE_IX1 ] = "IX1",
    [MODE_IX1P] = "IX1+",
    [MODE_IX2 ] = "IX2",
    [MODE_REL ] = "REL",
    [MODE_SP1 ] = "SP1",
    [MODE_SP2 ] = "SP2"
};

int modenames_size = countof(modenames);

static int handle_op_INVALID(__attribute__((unused)) hc_state_t *state,
                             __attribute__((unused)) const struct opinfo *info)
{
    printf("INVALID op encountered\n");
    return info->cycles;
}

static int handle_op_UNHANDLED(__attribute__((unused)) hc_state_t *state,
                               __attribute__((unused)) const struct opinfo *info)
{
    printf("Unhandled op %s\n", opnames[info->type]);
    return info->cycles;
}

#pragma weak handle_op_ADC     = handle_op_UNHANDLED
int handle_op_ADC    (hc_state_t *state, const struct opinfo *info);
#pragma weak handle_op_ADD     = handle_op_UNHANDLED
int handle_op_ADD    (hc_state_t *state, const struct opinfo *info);
#pragma weak handle_op_AIS     = handle_op_UNHANDLED
int handle_op_AIS    (hc_state_t *state, const struct opinfo *info);
#pragma weak handle_op_AIX     = handle_op_UNHANDLED
int handle_op_AIX    (hc_state_t *state, const struct opinfo *info);
#pragma weak handle_op_AND     = handle_op_UNHANDLED
int handle_op_AND    (hc_state_t *state, const struct opinfo *info);
#pragma weak handle_op_ASR     = handle_op_UNHANDLED
int handle_op_ASR    (hc_state_t *state, const struct opinfo *info);
#pragma weak handle_op_ASRA    = handle_op_UNHANDLED
int handle_op_ASRA   (hc_state_t *state, const struct opinfo *info);
#pragma weak handle_op_ASRX    = handle_op_UNHANDLED
int handle_op_ASRX   (hc_state_t *state, const struct opinfo *info);
#pragma weak handle_op_BCC     = handle_op_UNHANDLED
int handle_op_BCC    (hc_state_t *state, const struct opinfo *info);
#pragma weak handle_op_BCLR0   = handle_op_UNHANDLED
int handle_op_BCLR0  (hc_state_t *state, const struct opinfo *info);
#pragma weak handle_op_BCLR1   = handle_op_UNHANDLED
int handle_op_BCLR1  (hc_state_t *state, const struct opinfo *info);
#pragma weak handle_op_BCLR2   = handle_op_UNHANDLED
int handle_op_BCLR2  (hc_state_t *state, const struct opinfo *info);
#pragma weak handle_op_BCLR3   = handle_op_UNHANDLED
int handle_op_BCLR3  (hc_state_t *state, const struct opinfo *info);
#pragma weak handle_op_BCLR4   = handle_op_UNHANDLED
int handle_op_BCLR4  (hc_state_t *state, const struct opinfo *info);
#pragma weak handle_op_BCLR5   = handle_op_UNHANDLED
int handle_op_BCLR5  (hc_state_t *state, const struct opinfo *info);
#pragma weak handle_op_BCLR6   = handle_op_UNHANDLED
int handle_op_BCLR6  (hc_state_t *state, const struct opinfo *info);
#pragma weak handle_op_BCLR7   = handle_op_UNHANDLED
int handle_op_BCLR7  (hc_state_t *state, const struct opinfo *info);
#pragma weak handle_op_BCS     = handle_op_UNHANDLED
int handle_op_BCS    (hc_state_t *state, const struct opinfo *info);
#pragma weak handle_op_BEQ     = handle_op_UNHANDLED
int handle_op_BEQ    (hc_state_t *state, const struct opinfo *info);
#pragma weak handle_op_BGE     = handle_op_UNHANDLED
int handle_op_BGE    (hc_state_t *state, const struct opinfo *info);
#pragma weak handle_op_BGND    = handle_op_UNHANDLED
int handle_op_BGND   (hc_state_t *state, const struct opinfo *info);
#pragma weak handle_op_BGT     = handle_op_UNHANDLED
int handle_op_BGT    (hc_state_t *state, const struct opinfo *info);
#pragma weak handle_op_BHCC    = handle_op_UNHANDLED
int handle_op_BHCC   (hc_state_t *state, const struct opinfo *info);
#pragma weak handle_op_BHCS    = handle_op_UNHANDLED
int handle_op_BHCS   (hc_state_t *state, const struct opinfo *info);
#pragma weak handle_op_BHI     = handle_op_UNHANDLED
int handle_op_BHI    (hc_state_t *state, const struct opinfo *info);
#pragma weak handle_op_BIH     = handle_op_UNHANDLED
int handle_op_BIH    (hc_state_t *state, const struct opinfo *info);
#pragma weak handle_op_BIL     = handle_op_UNHANDLED
int handle_op_BIL    (hc_state_t *state, const struct opinfo *info);
#pragma weak handle_op_BIT     = handle_op_UNHANDLED
int handle_op_BIT    (hc_state_t *state, const struct opinfo *info);
#pragma weak handle_op_BLE     = handle_op_UNHANDLED
int handle_op_BLE    (hc_state_t *state, const struct opinfo *info);
#pragma weak handle_op_BLS     = handle_op_UNHANDLED
int handle_op_BLS    (hc_state_t *state, const struct opinfo *info);
#pragma weak handle_op_BLT     = handle_op_UNHANDLED
int handle_op_BLT    (hc_state_t *state, const struct opinfo *info);
#pragma weak handle_op_BMC     = handle_op_UNHANDLED
int handle_op_BMC    (hc_state_t *state, const struct opinfo *info);
#pragma weak handle_op_BMI     = handle_op_UNHANDLED
int handle_op_BMI    (hc_state_t *state, const struct opinfo *info);
#pragma weak handle_op_BMS     = handle_op_UNHANDLED
int handle_op_BMS    (hc_state_t *state, const struct opinfo *info);
#pragma weak handle_op_BNE     = handle_op_UNHANDLED
int handle_op_BNE    (hc_state_t *state, const struct opinfo *info);
#pragma weak handle_op_BPL     = handle_op_UNHANDLED
int handle_op_BPL    (hc_state_t *state, const struct opinfo *info);
#pragma weak handle_op_BRA     = handle_op_UNHANDLED
int handle_op_BRA    (hc_state_t *state, const struct opinfo *info);
#pragma weak handle_op_BRCLR0  = handle_op_UNHANDLED
int handle_op_BRCLR0 (hc_state_t *state, const struct opinfo *info);
#pragma weak handle_op_BRCLR1  = handle_op_UNHANDLED
int handle_op_BRCLR1 (hc_state_t *state, const struct opinfo *info);
#pragma weak handle_op_BRCLR2  = handle_op_UNHANDLED
int handle_op_BRCLR2 (hc_state_t *state, const struct opinfo *info);
#pragma weak handle_op_BRCLR3  = handle_op_UNHANDLED
int handle_op_BRCLR3 (hc_state_t *state, const struct opinfo *info);
#pragma weak handle_op_BRCLR4  = handle_op_UNHANDLED
int handle_op_BRCLR4 (hc_state_t *state, const struct opinfo *info);
#pragma weak handle_op_BRCLR5  = handle_op_UNHANDLED
int handle_op_BRCLR5 (hc_state_t *state, const struct opinfo *info);
#pragma weak handle_op_BRCLR6  = handle_op_UNHANDLED
int handle_op_BRCLR6 (hc_state_t *state, const struct opinfo *info);
#pragma weak handle_op_BRCLR7  = handle_op_UNHANDLED
int handle_op_BRCLR7 (hc_state_t *state, const struct opinfo *info);
#pragma weak handle_op_BRN     = handle_op_UNHANDLED
int handle_op_BRN    (hc_state_t *state, const struct opinfo *info);
#pragma weak handle_op_BRSET0  = handle_op_UNHANDLED
int handle_op_BRSET0 (hc_state_t *state, const struct opinfo *info);
#pragma weak handle_op_BRSET1  = handle_op_UNHANDLED
int handle_op_BRSET1 (hc_state_t *state, const struct opinfo *info);
#pragma weak handle_op_BRSET2  = handle_op_UNHANDLED
int handle_op_BRSET2 (hc_state_t *state, const struct opinfo *info);
#pragma weak handle_op_BRSET3  = handle_op_UNHANDLED
int handle_op_BRSET3 (hc_state_t *state, const struct opinfo *info);
#pragma weak handle_op_BRSET4  = handle_op_UNHANDLED
int handle_op_BRSET4 (hc_state_t *state, const struct opinfo *info);
#pragma weak handle_op_BRSET5  = handle_op_UNHANDLED
int handle_op_BRSET5 (hc_state_t *state, const struct opinfo *info);
#pragma weak handle_op_BRSET6  = handle_op_UNHANDLED
int handle_op_BRSET6 (hc_state_t *state, const struct opinfo *info);
#pragma weak handle_op_BRSET7  = handle_op_UNHANDLED
int handle_op_BRSET7 (hc_state_t *state, const struct opinfo *info);
#pragma weak handle_op_BSET0   = handle_op_UNHANDLED
int handle_op_BSET0  (hc_state_t *state, const struct opinfo *info);
#pragma weak handle_op_BSET1   = handle_op_UNHANDLED
int handle_op_BSET1  (hc_state_t *state, const struct opinfo *info);
#pragma weak handle_op_BSET2   = handle_op_UNHANDLED
int handle_op_BSET2  (hc_state_t *state, const struct opinfo *info);
#pragma weak handle_op_BSET3   = handle_op_UNHANDLED
int handle_op_BSET3  (hc_state_t *state, const struct opinfo *info);
#pragma weak handle_op_BSET4   = handle_op_UNHANDLED
int handle_op_BSET4  (hc_state_t *state, const struct opinfo *info);
#pragma weak handle_op_BSET5   = handle_op_UNHANDLED
int handle_op_BSET5  (hc_state_t *state, const struct opinfo *info);
#pragma weak handle_op_BSET6   = handle_op_UNHANDLED
int handle_op_BSET6  (hc_state_t *state, const struct opinfo *info);
#pragma weak handle_op_BSET7   = handle_op_UNHANDLED
int handle_op_BSET7  (hc_state_t *state, const struct opinfo *info);
#pragma weak handle_op_BSR     = handle_op_UNHANDLED
int handle_op_BSR    (hc_state_t *state, const struct opinfo *info);
#pragma weak handle_op_CBEQ    = handle_op_UNHANDLED
int handle_op_CBEQ   (hc_state_t *state, const struct opinfo *info);
#pragma weak handle_op_CBEQA   = handle_op_UNHANDLED
int handle_op_CBEQA  (hc_state_t *state, const struct opinfo *info);
#pragma weak handle_op_CBEQX   = handle_op_UNHANDLED
int handle_op_CBEQX  (hc_state_t *state, const struct opinfo *info);
#pragma weak handle_op_CLC     = handle_op_UNHANDLED
int handle_op_CLC    (hc_state_t *state, const struct opinfo *info);
#pragma weak handle_op_CLI     = handle_op_UNHANDLED
int handle_op_CLI    (hc_state_t *state, const struct opinfo *info);
#pragma weak handle_op_CLR     = handle_op_UNHANDLED
int handle_op_CLR    (hc_state_t *state, const struct opinfo *info);
#pragma weak handle_op_CLRA    = handle_op_UNHANDLED
int handle_op_CLRA   (hc_state_t *state, const struct opinfo *info);
#pragma weak handle_op_CLRH    = handle_op_UNHANDLED
int handle_op_CLRH   (hc_state_t *state, const struct opinfo *info);
#pragma weak handle_op_CLRX    = handle_op_UNHANDLED
int handle_op_CLRX   (hc_state_t *state, const struct opinfo *info);
#pragma weak handle_op_CMP     = handle_op_UNHANDLED
int handle_op_CMP    (hc_state_t *state, const struct opinfo *info);
#pragma weak handle_op_COM     = handle_op_UNHANDLED
int handle_op_COM    (hc_state_t *state, const struct opinfo *info);
#pragma weak handle_op_COMA    = handle_op_UNHANDLED
int handle_op_COMA   (hc_state_t *state, const struct opinfo *info);
#pragma weak handle_op_COMX    = handle_op_UNHANDLED
int handle_op_COMX   (hc_state_t *state, const struct opinfo *info);
#pragma weak handle_op_CPHX    = handle_op_UNHANDLED
int handle_op_CPHX   (hc_state_t *state, const struct opinfo *info);
#pragma weak handle_op_CPX     = handle_op_UNHANDLED
int handle_op_CPX    (hc_state_t *state, const struct opinfo *info);
#pragma weak handle_op_DAA     = handle_op_UNHANDLED
int handle_op_DAA    (hc_state_t *state, const struct opinfo *info);
#pragma weak handle_op_DBNZ    = handle_op_UNHANDLED
int handle_op_DBNZ   (hc_state_t *state, const struct opinfo *info);
#pragma weak handle_op_DBNZA   = handle_op_UNHANDLED
int handle_op_DBNZA  (hc_state_t *state, const struct opinfo *info);
#pragma weak handle_op_DBNZX   = handle_op_UNHANDLED
int handle_op_DBNZX  (hc_state_t *state, const struct opinfo *info);
#pragma weak handle_op_DEC     = handle_op_UNHANDLED
int handle_op_DEC    (hc_state_t *state, const struct opinfo *info);
#pragma weak handle_op_DECA    = handle_op_UNHANDLED
int handle_op_DECA   (hc_state_t *state, const struct opinfo *info);
#pragma weak handle_op_DECX    = handle_op_UNHANDLED
int handle_op_DECX   (hc_state_t *state, const struct opinfo *info);
#pragma weak handle_op_DIV     = handle_op_UNHANDLED
int handle_op_DIV    (hc_state_t *state, const struct opinfo *info);
#pragma weak handle_op_EOR     = handle_op_UNHANDLED
int handle_op_EOR    (hc_state_t *state, const struct opinfo *info);
#pragma weak handle_op_INC     = handle_op_UNHANDLED
int handle_op_INC    (hc_state_t *state, const struct opinfo *info);
#pragma weak handle_op_INCA    = handle_op_UNHANDLED
int handle_op_INCA   (hc_state_t *state, const struct opinfo *info);
#pragma weak handle_op_INCX    = handle_op_UNHANDLED
int handle_op_INCX   (hc_state_t *state, const struct opinfo *info);
#pragma weak handle_op_JMP     = handle_op_UNHANDLED
int handle_op_JMP    (hc_state_t *state, const struct opinfo *info);
#pragma weak handle_op_JSR     = handle_op_UNHANDLED
int handle_op_JSR    (hc_state_t *state, const struct opinfo *info);
#pragma weak handle_op_LDA     = handle_op_UNHANDLED
int handle_op_LDA    (hc_state_t *state, const struct opinfo *info);
#pragma weak handle_op_LDHX    = handle_op_UNHANDLED
int handle_op_LDHX   (hc_state_t *state, const struct opinfo *info);
#pragma weak handle_op_LDX     = handle_op_UNHANDLED
int handle_op_LDX    (hc_state_t *state, const struct opinfo *info);
#pragma weak handle_op_LSL     = handle_op_UNHANDLED
int handle_op_LSL    (hc_state_t *state, const struct opinfo *info);
#pragma weak handle_op_LSLA    = handle_op_UNHANDLED
int handle_op_LSLA   (hc_state_t *state, const struct opinfo *info);
#pragma weak handle_op_LSLX    = handle_op_UNHANDLED
int handle_op_LSLX   (hc_state_t *state, const struct opinfo *info);
#pragma weak handle_op_LSR     = handle_op_UNHANDLED
int handle_op_LSR    (hc_state_t *state, const struct opinfo *info);
#pragma weak handle_op_LSRA    = handle_op_UNHANDLED
int handle_op_LSRA   (hc_state_t *state, const struct opinfo *info);
#pragma weak handle_op_LSRX    = handle_op_UNHANDLED
int handle_op_LSRX   (hc_state_t *state, const struct opinfo *info);
#pragma weak handle_op_MOV     = handle_op_UNHANDLED
int handle_op_MOV    (hc_state_t *state, const struct opinfo *info);
#pragma weak handle_op_MUL     = handle_op_UNHANDLED
int handle_op_MUL    (hc_state_t *state, const struct opinfo *info);
#pragma weak handle_op_NEG     = handle_op_UNHANDLED
int handle_op_NEG    (hc_state_t *state, const struct opinfo *info);
#pragma weak handle_op_NEGA    = handle_op_UNHANDLED
int handle_op_NEGA   (hc_state_t *state, const struct opinfo *info);
#pragma weak handle_op_NEGX    = handle_op_UNHANDLED
int handle_op_NEGX   (hc_state_t *state, const struct opinfo *info);
#pragma weak handle_op_NOP     = handle_op_UNHANDLED
int handle_op_NOP    (hc_state_t *state, const struct opinfo *info);
#pragma weak handle_op_NSA     = handle_op_UNHANDLED
int handle_op_NSA    (hc_state_t *state, const struct opinfo *info);
#pragma weak handle_op_ORA     = handle_op_UNHANDLED
int handle_op_ORA    (hc_state_t *state, const struct opinfo *info);
#pragma weak handle_op_PSHA    = handle_op_UNHANDLED
int handle_op_PSHA   (hc_state_t *state, const struct opinfo *info);
#pragma weak handle_op_PSHH    = handle_op_UNHANDLED
int handle_op_PSHH   (hc_state_t *state, const struct opinfo *info);
#pragma weak handle_op_PSHX    = handle_op_UNHANDLED
int handle_op_PSHX   (hc_state_t *state, const struct opinfo *info);
#pragma weak handle_op_PULA    = handle_op_UNHANDLED
int handle_op_PULA   (hc_state_t *state, const struct opinfo *info);
#pragma weak handle_op_PULH    = handle_op_UNHANDLED
int handle_op_PULH   (hc_state_t *state, const struct opinfo *info);
#pragma weak handle_op_PULX    = handle_op_UNHANDLED
int handle_op_PULX   (hc_state_t *state, const struct opinfo *info);
#pragma weak handle_op_ROL     = handle_op_UNHANDLED
int handle_op_ROL    (hc_state_t *state, const struct opinfo *info);
#pragma weak handle_op_ROLA    = handle_op_UNHANDLED
int handle_op_ROLA   (hc_state_t *state, const struct opinfo *info);
#pragma weak handle_op_ROLX    = handle_op_UNHANDLED
int handle_op_ROLX   (hc_state_t *state, const struct opinfo *info);
#pragma weak handle_op_ROR     = handle_op_UNHANDLED
int handle_op_ROR    (hc_state_t *state, const struct opinfo *info);
#pragma weak handle_op_RORA    = handle_op_UNHANDLED
int handle_op_RORA   (hc_state_t *state, const struct opinfo *info);
#pragma weak handle_op_RORX    = handle_op_UNHANDLED
int handle_op_RORX   (hc_state_t *state, const struct opinfo *info);
#pragma weak handle_op_RSP     = handle_op_UNHANDLED
int handle_op_RSP    (hc_state_t *state, const struct opinfo *info);
#pragma weak handle_op_RTI     = handle_op_UNHANDLED
int handle_op_RTI    (hc_state_t *state, const struct opinfo *info);
#pragma weak handle_op_RTS     = handle_op_UNHANDLED
int handle_op_RTS    (hc_state_t *state, const struct opinfo *info);
#pragma weak handle_op_SBC     = handle_op_UNHANDLED
int handle_op_SBC    (hc_state_t *state, const struct opinfo *info);
#pragma weak handle_op_SEC     = handle_op_UNHANDLED
int handle_op_SEC    (hc_state_t *state, const struct opinfo *info);
#pragma weak handle_op_SEI     = handle_op_UNHANDLED
int handle_op_SEI    (hc_state_t *state, const struct opinfo *info);
#pragma weak handle_op_STA     = handle_op_UNHANDLED
int handle_op_STA    (hc_state_t *state, const struct opinfo *info);
#pragma weak handle_op_STHX    = handle_op_UNHANDLED
int handle_op_STHX   (hc_state_t *state, const struct opinfo *info);
#pragma weak handle_op_STOP    = handle_op_UNHANDLED
int handle_op_STOP   (hc_state_t *state, const struct opinfo *info);
#pragma weak handle_op_STX     = handle_op_UNHANDLED
int handle_op_STX    (hc_state_t *state, const struct opinfo *info);
#pragma weak handle_op_SUB     = handle_op_UNHANDLED
int handle_op_SUB    (hc_state_t *state, const struct opinfo *info);
#pragma weak handle_op_SWI     = handle_op_UNHANDLED
int handle_op_SWI    (hc_state_t *state, const struct opinfo *info);
#pragma weak handle_op_TAP     = handle_op_UNHANDLED
int handle_op_TAP    (hc_state_t *state, const struct opinfo *info);
#pragma weak handle_op_TAX     = handle_op_UNHANDLED
int handle_op_TAX    (hc_state_t *state, const struct opinfo *info);
#pragma weak handle_op_TPA     = handle_op_UNHANDLED
int handle_op_TPA    (hc_state_t *state, const struct opinfo *info);
#pragma weak handle_op_TST     = handle_op_UNHANDLED
int handle_op_TST    (hc_state_t *state, const struct opinfo *info);
#pragma weak handle_op_TSTA    = handle_op_UNHANDLED
int handle_op_TSTA   (hc_state_t *state, const struct opinfo *info);
#pragma weak handle_op_TSTX    = handle_op_UNHANDLED
int handle_op_TSTX   (hc_state_t *state, const struct opinfo *info);
#pragma weak handle_op_TSX     = handle_op_UNHANDLED
int handle_op_TSX    (hc_state_t *state, const struct opinfo *info);
#pragma weak handle_op_TXA     = handle_op_UNHANDLED
int handle_op_TXA    (hc_state_t *state, const struct opinfo *info);
#pragma weak handle_op_TXS     = handle_op_UNHANDLED
int handle_op_TXS    (hc_state_t *state, const struct opinfo *info);
#pragma weak handle_op_WAIT    = handle_op_UNHANDLED
int handle_op_WAIT   (hc_state_t *state, const struct opinfo *info);

const actor_t actors[] = {
    [OP_ADC    ] = handle_op_ADC,
    [OP_ADD    ] = handle_op_ADD,
    [OP_AIS    ] = handle_op_AIS,
    [OP_AIX    ] = handle_op_AIX,
    [OP_AND    ] = handle_op_AND,
    [OP_ASR    ] = handle_op_ASR,
    [OP_ASRA   ] = handle_op_ASRA,
    [OP_ASRX   ] = handle_op_ASRX,
    [OP_BCC    ] = handle_op_BCC,
    [OP_BCLR0  ] = handle_op_BCLR0,
    [OP_BCLR1  ] = handle_op_BCLR1,
    [OP_BCLR2  ] = handle_op_BCLR2,
    [OP_BCLR3  ] = handle_op_BCLR3,
    [OP_BCLR4  ] = handle_op_BCLR4,
    [OP_BCLR5  ] = handle_op_BCLR5,
    [OP_BCLR6  ] = handle_op_BCLR6,
    [OP_BCLR7  ] = handle_op_BCLR7,
    [OP_BCS    ] = handle_op_BCS,
    [OP_BEQ    ] = handle_op_BEQ,
    [OP_BGE    ] = handle_op_BGE,
    [OP_BGND   ] = handle_op_BGND,
    [OP_BGT    ] = handle_op_BGT,
    [OP_BHCC   ] = handle_op_BHCC,
    [OP_BHCS   ] = handle_op_BHCS,
    [OP_BHI    ] = handle_op_BHI,
    [OP_BIH    ] = handle_op_BIH,
    [OP_BIL    ] = handle_op_BIL,
    [OP_BIT    ] = handle_op_BIT,
    [OP_BLE    ] = handle_op_BLE,
    [OP_BLS    ] = handle_op_BLS,
    [OP_BLT    ] = handle_op_BLT,
    [OP_BMC    ] = handle_op_BMC,
    [OP_BMI    ] = handle_op_BMI,
    [OP_BMS    ] = handle_op_BMS,
    [OP_BNE    ] = handle_op_BNE,
    [OP_BPL    ] = handle_op_BPL,
    [OP_BRA    ] = handle_op_BRA,
    [OP_BRCLR0 ] = handle_op_BRCLR0,
    [OP_BRCLR1 ] = handle_op_BRCLR1,
    [OP_BRCLR2 ] = handle_op_BRCLR2,
    [OP_BRCLR3 ] = handle_op_BRCLR3,
    [OP_BRCLR4 ] = handle_op_BRCLR4,
    [OP_BRCLR5 ] = handle_op_BRCLR5,
    [OP_BRCLR6 ] = handle_op_BRCLR6,
    [OP_BRCLR7 ] = handle_op_BRCLR7,
    [OP_BRN    ] = handle_op_BRN,
    [OP_BRSET0 ] = handle_op_BRSET0,
    [OP_BRSET1 ] = handle_op_BRSET1,
    [OP_BRSET2 ] = handle_op_BRSET2,
    [OP_BRSET3 ] = handle_op_BRSET3,
    [OP_BRSET4 ] = handle_op_BRSET4,
    [OP_BRSET5 ] = handle_op_BRSET5,
    [OP_BRSET6 ] = handle_op_BRSET6,
    [OP_BRSET7 ] = handle_op_BRSET7,
    [OP_BSET0  ] = handle_op_BSET0,
    [OP_BSET1  ] = handle_op_BSET1,
    [OP_BSET2  ] = handle_op_BSET2,
    [OP_BSET3  ] = handle_op_BSET3,
    [OP_BSET4  ] = handle_op_BSET4,
    [OP_BSET5  ] = handle_op_BSET5,
    [OP_BSET6  ] = handle_op_BSET6,
    [OP_BSET7  ] = handle_op_BSET7,
    [OP_BSR    ] = handle_op_BSR,
    [OP_CBEQ   ] = handle_op_CBEQ,
    [OP_CBEQA  ] = handle_op_CBEQA,
    [OP_CBEQX  ] = handle_op_CBEQX,
    [OP_CLC    ] = handle_op_CLC,
    [OP_CLI    ] = handle_op_CLI,
    [OP_CLR    ] = handle_op_CLR,
    [OP_CLRA   ] = handle_op_CLRA,
    [OP_CLRH   ] = handle_op_CLRH,
    [OP_CLRX   ] = handle_op_CLRX,
    [OP_CMP    ] = handle_op_CMP,
    [OP_COM    ] = handle_op_COM,
    [OP_COMA   ] = handle_op_COMA,
    [OP_COMX   ] = handle_op_COMX,
    [OP_CPHX   ] = handle_op_CPHX,
    [OP_CPX    ] = handle_op_CPX,
    [OP_DAA    ] = handle_op_DAA,
    [OP_DBNZ   ] = handle_op_DBNZ,
    [OP_DBNZA  ] = handle_op_DBNZA,
    [OP_DBNZX  ] = handle_op_DBNZX,
    [OP_DEC    ] = handle_op_DEC,
    [OP_DECA   ] = handle_op_DECA,
    [OP_DECX   ] = handle_op_DECX,
    [OP_DIV    ] = handle_op_DIV,
    [OP_EOR    ] = handle_op_EOR,
    [OP_INC    ] = handle_op_INC,
    [OP_INCA   ] = handle_op_INCA,
    [OP_INCX   ] = handle_op_INCX,
    [OP_JMP    ] = handle_op_JMP,
    [OP_JSR    ] = handle_op_JSR,
    [OP_LDA    ] = handle_op_LDA,
    [OP_LDHX   ] = handle_op_LDHX,
    [OP_LDX    ] = handle_op_LDX,
    [OP_LSL    ] = handle_op_LSL,
    [OP_LSLA   ] = handle_op_LSLA,
    [OP_LSLX   ] = handle_op_LSLX,
    [OP_LSR    ] = handle_op_LSR,
    [OP_LSRA   ] = handle_op_LSRA,
    [OP_LSRX   ] = handle_op_LSRX,
    [OP_MOV    ] = handle_op_MOV,
    [OP_MUL    ] = handle_op_MUL,
    [OP_NEG    ] = handle_op_NEG,
    [OP_NEGA   ] = handle_op_NEGA,
    [OP_NEGX   ] = handle_op_NEGX,
    [OP_NOP    ] = handle_op_NOP,
    [OP_NSA    ] = handle_op_NSA,
    [OP_ORA    ] = handle_op_ORA,
    [OP_PSHA   ] = handle_op_PSHA,
    [OP_PSHH   ] = handle_op_PSHH,
    [OP_PSHX   ] = handle_op_PSHX,
    [OP_PULA   ] = handle_op_PULA,
    [OP_PULH   ] = handle_op_PULH,
    [OP_PULX   ] = handle_op_PULX,
    [OP_ROL    ] = handle_op_ROL,
    [OP_ROLA   ] = handle_op_ROLA,
    [OP_ROLX   ] = handle_op_ROLX,
    [OP_ROR    ] = handle_op_ROR,
    [OP_RORA   ] = handle_op_RORA,
    [OP_RORX   ] = handle_op_RORX,
    [OP_RSP    ] = handle_op_RSP,
    [OP_RTI    ] = handle_op_RTI,
    [OP_RTS    ] = handle_op_RTS,
    [OP_SBC    ] = handle_op_SBC,
    [OP_SEC    ] = handle_op_SEC,
    [OP_SEI    ] = handle_op_SEI,
    [OP_STA    ] = handle_op_STA,
    [OP_STHX   ] = handle_op_STHX,
    [OP_STOP   ] = handle_op_STOP,
    [OP_STX    ] = handle_op_STX,
    [OP_SUB    ] = handle_op_SUB,
    [OP_SWI    ] = handle_op_SWI,
    [OP_TAP    ] = handle_op_TAP,
    [OP_TAX    ] = handle_op_TAX,
    [OP_TPA    ] = handle_op_TPA,
    [OP_TST    ] = handle_op_TST,
    [OP_TSTA   ] = handle_op_TSTA,
    [OP_TSTX   ] = handle_op_TSTX,
    [OP_TSX    ] = handle_op_TSX,
    [OP_TXA    ] = handle_op_TXA,
    [OP_TXS    ] = handle_op_TXS,
    [OP_WAIT   ] = handle_op_WAIT,
    [OP_INVALID] = handle_op_INVALID
};

int actors_size = countof(actors);

const struct page pages[] = {
    [0] = { 0, 0, { 0x00 } },
    [1] = { 1, 1, { 0x9E } }
};

int pages_size = countof(pages);

const struct opinfo opinfos[2][256] = {
    [0] = {
        [0x00] = { OP_BRSET0 , MODE_DIR , 0x00,  5, 3 },
        [0x10] = { OP_BSET0  , MODE_DIR , 0x10,  5, 2 },
        [0x20] = { OP_BRA    , MODE_REL , 0x20,  3, 2 },
        [0x30] = { OP_NEG    , MODE_DIR , 0x30,  5, 2 },
        [0x40] = { OP_NEGA   , MODE_INH , 0x40,  1, 1 },
        [0x50] = { OP_NEGX   , MODE_INH , 0x50,  1, 1 },
        [0x60] = { OP_NEG    , MODE_IX1 , 0x60,  5, 2 },
        [0x70] = { OP_NEG    , MODE_IX  , 0x70,  4, 1 },
        [0x80] = { OP_RTI    , MODE_INH , 0x80,  9, 1 },
        [0x90] = { OP_BGE    , MODE_REL , 0x90,  3, 2 },
        [0xA0] = { OP_SUB    , MODE_IMM , 0xA0,  2, 2 },
        [0xB0] = { OP_SUB    , MODE_DIR , 0xB0,  3, 2 },
        [0xC0] = { OP_SUB    , MODE_EXT , 0xC0,  4, 3 },
        [0xD0] = { OP_SUB    , MODE_IX2 , 0xD0,  4, 3 },
        [0xE0] = { OP_SUB    , MODE_IX1 , 0xE0,  3, 2 },
        [0xF0] = { OP_SUB    , MODE_IX  , 0xF0,  3, 1 },
        [0x01] = { OP_BRCLR0 , MODE_DIR , 0x01,  5, 3 },
        [0x11] = { OP_BCLR0  , MODE_DIR , 0x11,  5, 2 },
        [0x21] = { OP_BRN    , MODE_REL , 0x21,  3, 2 },
        [0x31] = { OP_CBEQ   , MODE_DIR , 0x31,  5, 3 },
        [0x41] = { OP_CBEQA  , MODE_IMM , 0x41,  4, 3 },
        [0x51] = { OP_CBEQX  , MODE_IMM , 0x51,  4, 3 },
        [0x61] = { OP_CBEQ   , MODE_IX1P, 0x61,  5, 3 },
        [0x71] = { OP_CBEQ   , MODE_IXP , 0x71,  5, 2 },
        [0x81] = { OP_RTS    , MODE_INH , 0x81,  6, 1 },
        [0x91] = { OP_BLT    , MODE_REL , 0x91,  3, 2 },
        [0xA1] = { OP_CMP    , MODE_IMM , 0xA1,  2, 2 },
        [0xB1] = { OP_CMP    , MODE_DIR , 0xB1,  3, 2 },
        [0xC1] = { OP_CMP    , MODE_EXT , 0xC1,  4, 3 },
        [0xD1] = { OP_CMP    , MODE_IX2 , 0xD1,  4, 3 },
        [0xE1] = { OP_CMP    , MODE_IX1 , 0xE1,  3, 2 },
        [0xF1] = { OP_CMP    , MODE_IX  , 0xF1,  3, 1 },
        [0x02] = { OP_BRSET1 , MODE_DIR , 0x02,  5, 3 },
        [0x12] = { OP_BSET1  , MODE_DIR , 0x12,  5, 2 },
        [0x22] = { OP_BHI    , MODE_REL , 0x22,  3, 2 },
        [0x32] = { OP_LDHX   , MODE_EXT , 0x32,  5, 3 },
        [0x42] = { OP_MUL    , MODE_INH , 0x42,  5, 1 },
        [0x52] = { OP_DIV    , MODE_INH , 0x52,  6, 1 },
        [0x62] = { OP_NSA    , MODE_INH , 0x62,  1, 1 },
        [0x72] = { OP_DAA    , MODE_INH , 0x72,  1, 1 },
        [0x82] = { OP_BGND   , MODE_INH , 0x82,  5, 1 },
        [0x92] = { OP_BGT    , MODE_REL , 0x92,  3, 2 },
        [0xA2] = { OP_SBC    , MODE_IMM , 0xA2,  2, 2 },
        [0xB2] = { OP_SBC    , MODE_DIR , 0xB2,  3, 2 },
        [0xC2] = { OP_SBC    , MODE_EXT , 0xC2,  4, 3 },
        [0xD2] = { OP_SBC    , MODE_IX2 , 0xD2,  4, 3 },
        [0xE2] = { OP_SBC    , MODE_IX1 , 0xE2,  3, 2 },
        [0xF2] = { OP_SBC    , MODE_IX  , 0xF2,  3, 1 },
        [0x03] = { OP_BRCLR1 , MODE_DIR , 0x03,  5, 3 },
        [0x13] = { OP_BCLR1  , MODE_DIR , 0x13,  5, 2 },
        [0x23] = { OP_BLS    , MODE_REL , 0x23,  3, 2 },
        [0x33] = { OP_COM    , MODE_DIR , 0x33,  5, 2 },
        [0x43] = { OP_COMA   , MODE_INH , 0x43,  1, 1 },
        [0x53] = { OP_COMX   , MODE_INH , 0x53,  1, 1 },
        [0x63] = { OP_COM    , MODE_IX1 , 0x63,  5, 2 },
        [0x73] = { OP_COM    , MODE_IX  , 0x73,  4, 1 },
        [0x83] = { OP_SWI    , MODE_INH , 0x83, 11, 1 },
        [0x93] = { OP_BLE    , MODE_REL , 0x93,  3, 2 },
        [0xA3] = { OP_CPX    , MODE_IMM , 0xA3,  2, 2 },
        [0xB3] = { OP_CPX    , MODE_DIR , 0xB3,  3, 2 },
        [0xC3] = { OP_CPX    , MODE_EXT , 0xC3,  4, 3 },
        [0xD3] = { OP_CPX    , MODE_IX2 , 0xD3,  4, 3 },
        [0xE3] = { OP_CPX    , MODE_IX1 , 0xE3,  3, 2 },
        [0xF3] = { OP_CPX    , MODE_IX  , 0xF3,  3, 1 },
        [0x04] = { OP_BRSET2 , MODE_DIR , 0x04,  5, 3 },
        [0x14] = { OP_BSET2  , MODE_DIR , 0x14,  5, 2 },
        [0x24] = { OP_BCC    , MODE_REL , 0x24,  3, 2 },
        [0x34] = { OP_LSR    , MODE_DIR , 0x34,  5, 2 },
        [0x44] = { OP_LSRA   , MODE_INH , 0x44,  1, 1 },
        [0x54] = { OP_LSRX   , MODE_INH , 0x54,  1, 1 },
        [0x64] = { OP_LSR    , MODE_IX1 , 0x64,  5, 2 },
        [0x74] = { OP_LSR    , MODE_IX  , 0x74,  4, 1 },
        [0x84] = { OP_TAP    , MODE_INH , 0x84,  1, 1 },
        [0x94] = { OP_TXS    , MODE_INH , 0x94,  2, 1 },
        [0xA4] = { OP_AND    , MODE_IMM , 0xA4,  2, 2 },
        [0xB4] = { OP_AND    , MODE_DIR , 0xB4,  3, 2 },
        [0xC4] = { OP_AND    , MODE_EXT , 0xC4,  4, 3 },
        [0xD4] = { OP_AND    , MODE_IX2 , 0xD4,  4, 3 },
        [0xE4] = { OP_AND    , MODE_IX1 , 0xE4,  3, 2 },
        [0xF4] = { OP_AND    , MODE_IX  , 0xF4,  3, 1 },
        [0x05] = { OP_BRCLR2 , MODE_DIR , 0x05,  5, 3 },
        [0x15] = { OP_BCLR2  , MODE_DIR , 0x15,  5, 2 },
        [0x25] = { OP_BCS    , MODE_REL , 0x25,  3, 2 },
        [0x35] = { OP_STHX   , MODE_DIR , 0x35,  4, 2 },
        [0x45] = { OP_LDHX   , MODE_IMM , 0x45,  3, 3 },
        [0x55] = { OP_LDHX   , MODE_DIR , 0x55,  4, 2 },
        [0x65] = { OP_CPHX   , MODE_IMM , 0x65,  3, 3 },
        [0x75] = { OP_CPHX   , MODE_DIR , 0x75,  5, 2 },
        [0x85] = { OP_TPA    , MODE_INH , 0x85,  1, 1 },
        [0x95] = { OP_TSX    , MODE_INH , 0x95,  2, 1 },
        [0xA5] = { OP_BIT    , MODE_IMM , 0xA5,  2, 2 },
        [0xB5] = { OP_BIT    , MODE_DIR , 0xB5,  3, 2 },
        [0xC5] = { OP_BIT    , MODE_EXT , 0xC5,  4, 3 },
        [0xD5] = { OP_BIT    , MODE_IX2 , 0xD5,  4, 3 },
        [0xE5] = { OP_BIT    , MODE_IX1 , 0xE5,  3, 2 },
        [0xF5] = { OP_BIT    , MODE_IX  , 0xF5,  3, 1 },
        [0x06] = { OP_BRSET3 , MODE_DIR , 0x06,  5, 3 },
        [0x16] = { OP_BSET3  , MODE_DIR , 0x16,  5, 2 },
        [0x26] = { OP_BNE    , MODE_REL , 0x26,  3, 2 },
        [0x36] = { OP_ROR    , MODE_DIR , 0x36,  5, 2 },
        [0x46] = { OP_RORA   , MODE_INH , 0x46,  1, 1 },
        [0x56] = { OP_RORX   , MODE_INH , 0x56,  1, 1 },
        [0x66] = { OP_ROR    , MODE_IX1 , 0x66,  5, 2 },
        [0x76] = { OP_ROR    , MODE_IX  , 0x76,  4, 1 },
        [0x86] = { OP_PULA   , MODE_INH , 0x86,  3, 1 },
        [0x96] = { OP_STHX   , MODE_EXT , 0x96,  5, 3 },
        [0xA6] = { OP_LDA    , MODE_IMM , 0xA6,  2, 2 },
        [0xB6] = { OP_LDA    , MODE_DIR , 0xB6,  3, 2 },
        [0xC6] = { OP_LDA    , MODE_EXT , 0xC6,  4, 3 },
        [0xD6] = { OP_LDA    , MODE_IX2 , 0xD6,  4, 3 },
        [0xE6] = { OP_LDA    , MODE_IX1 , 0xE6,  3, 2 },
        [0xF6] = { OP_LDA    , MODE_IX  , 0xF6,  3, 1 },
        [0x07] = { OP_BRCLR3 , MODE_DIR , 0x07,  5, 3 },
        [0x17] = { OP_BCLR3  , MODE_DIR , 0x17,  5, 2 },
        [0x27] = { OP_BEQ    , MODE_REL , 0x27,  3, 2 },
        [0x37] = { OP_ASR    , MODE_DIR , 0x37,  5, 2 },
        [0x47] = { OP_ASRA   , MODE_INH , 0x47,  1, 1 },
        [0x57] = { OP_ASRX   , MODE_INH , 0x57,  1, 1 },
        [0x67] = { OP_ASR    , MODE_IX1 , 0x67,  5, 2 },
        [0x77] = { OP_ASR    , MODE_IX  , 0x77,  4, 1 },
        [0x87] = { OP_PSHA   , MODE_INH , 0x87,  2, 1 },
        [0x97] = { OP_TAX    , MODE_INH , 0x97,  1, 1 },
        [0xA7] = { OP_AIS    , MODE_IMM , 0xA7,  2, 2 },
        [0xB7] = { OP_STA    , MODE_DIR , 0xB7,  3, 2 },
        [0xC7] = { OP_STA    , MODE_EXT , 0xC7,  4, 3 },
        [0xD7] = { OP_STA    , MODE_IX2 , 0xD7,  4, 3 },
        [0xE7] = { OP_STA    , MODE_IX1 , 0xE7,  3, 2 },
        [0xF7] = { OP_STA    , MODE_IX  , 0xF7,  2, 1 },
        [0x08] = { OP_BRSET4 , MODE_DIR , 0x08,  5, 3 },
        [0x18] = { OP_BSET4  , MODE_DIR , 0x18,  5, 2 },
        [0x28] = { OP_BHCC   , MODE_REL , 0x28,  3, 2 },
        [0x38] = { OP_LSL    , MODE_DIR , 0x38,  5, 2 },
        [0x48] = { OP_LSLA   , MODE_INH , 0x48,  1, 1 },
        [0x58] = { OP_LSLX   , MODE_INH , 0x58,  1, 1 },
        [0x68] = { OP_LSL    , MODE_IX1 , 0x68,  5, 2 },
        [0x78] = { OP_LSL    , MODE_IX  , 0x78,  4, 1 },
        [0x88] = { OP_PULX   , MODE_INH , 0x88,  3, 1 },
        [0x98] = { OP_CLC    , MODE_INH , 0x98,  1, 1 },
        [0xA8] = { OP_EOR    , MODE_IMM , 0xA8,  2, 2 },
        [0xB8] = { OP_EOR    , MODE_DIR , 0xB8,  3, 2 },
        [0xC8] = { OP_EOR    , MODE_EXT , 0xC8,  4, 3 },
        [0xD8] = { OP_EOR    , MODE_IX2 , 0xD8,  4, 3 },
        [0xE8] = { OP_EOR    , MODE_IX1 , 0xE8,  3, 2 },
        [0xF8] = { OP_EOR    , MODE_IX  , 0xF8,  3, 1 },
        [0x09] = { OP_BRCLR4 , MODE_DIR , 0x09,  5, 3 },
        [0x19] = { OP_BCLR4  , MODE_DIR , 0x19,  5, 2 },
        [0x29] = { OP_BHCS   , MODE_REL , 0x29,  3, 2 },
        [0x39] = { OP_ROL    , MODE_DIR , 0x39,  5, 2 },
        [0x49] = { OP_ROLA   , MODE_INH , 0x49,  1, 1 },
        [0x59] = { OP_ROLX   , MODE_INH , 0x59,  1, 1 },
        [0x69] = { OP_ROL    , MODE_IX1 , 0x69,  5, 2 },
        [0x79] = { OP_ROL    , MODE_IX  , 0x79,  4, 1 },
        [0x89] = { OP_PSHX   , MODE_INH , 0x89,  2, 1 },
        [0x99] = { OP_SEC    , MODE_INH , 0x99,  1, 1 },
        [0xA9] = { OP_ADC    , MODE_IMM , 0xA9,  2, 2 },
        [0xB9] = { OP_ADC    , MODE_DIR , 0xB9,  3, 2 },
        [0xC9] = { OP_ADC    , MODE_EXT , 0xC9,  4, 3 },
        [0xD9] = { OP_ADC    , MODE_IX2 , 0xD9,  4, 3 },
        [0xE9] = { OP_ADC    , MODE_IX1 , 0xE9,  3, 2 },
        [0xF9] = { OP_ADC    , MODE_IX  , 0xF9,  3, 1 },
        [0x0A] = { OP_BRSET5 , MODE_DIR , 0x0A,  5, 3 },
        [0x1A] = { OP_BSET5  , MODE_DIR , 0x1A,  5, 2 },
        [0x2A] = { OP_BPL    , MODE_REL , 0x2A,  3, 2 },
        [0x3A] = { OP_DEC    , MODE_DIR , 0x3A,  5, 2 },
        [0x4A] = { OP_DECA   , MODE_INH , 0x4A,  1, 1 },
        [0x5A] = { OP_DECX   , MODE_INH , 0x5A,  1, 1 },
        [0x6A] = { OP_DEC    , MODE_IX1 , 0x6A,  5, 2 },
        [0x7A] = { OP_DEC    , MODE_IX  , 0x7A,  4, 1 },
        [0x8A] = { OP_PULH   , MODE_INH , 0x8A,  3, 1 },
        [0x9A] = { OP_CLI    , MODE_INH , 0x9A,  1, 1 },
        [0xAA] = { OP_ORA    , MODE_IMM , 0xAA,  2, 2 },
        [0xBA] = { OP_ORA    , MODE_DIR , 0xBA,  3, 2 },
        [0xCA] = { OP_ORA    , MODE_EXT , 0xCA,  4, 3 },
        [0xDA] = { OP_ORA    , MODE_IX2 , 0xDA,  4, 3 },
        [0xEA] = { OP_ORA    , MODE_IX1 , 0xEA,  3, 2 },
        [0xFA] = { OP_ORA    , MODE_IX  , 0xFA,  3, 1 },
        [0x0B] = { OP_BRCLR5 , MODE_DIR , 0x0B,  5, 3 },
        [0x1B] = { OP_BCLR5  , MODE_DIR , 0x1B,  5, 2 },
        [0x2B] = { OP_BMI    , MODE_REL , 0x2B,  3, 2 },
        [0x3B] = { OP_DBNZ   , MODE_DIR , 0x3B,  7, 3 },
        [0x4B] = { OP_DBNZA  , MODE_INH , 0x4B,  4, 2 },
        [0x5B] = { OP_DBNZX  , MODE_INH , 0x5B,  4, 2 },
        [0x6B] = { OP_DBNZ   , MODE_IX1 , 0x6B,  7, 3 },
        [0x7B] = { OP_DBNZ   , MODE_IX  , 0x7B,  6, 2 },
        [0x8B] = { OP_PSHH   , MODE_INH , 0x8B,  2, 1 },
        [0x9B] = { OP_SEI    , MODE_INH , 0x9B,  1, 1 },
        [0xAB] = { OP_ADD    , MODE_IMM , 0xAB,  2, 2 },
        [0xBB] = { OP_ADD    , MODE_DIR , 0xBB,  3, 2 },
        [0xCB] = { OP_ADD    , MODE_EXT , 0xCB,  4, 3 },
        [0xDB] = { OP_ADD    , MODE_IX2 , 0xDB,  4, 3 },
        [0xEB] = { OP_ADD    , MODE_IX1 , 0xEB,  3, 2 },
        [0xFB] = { OP_ADD    , MODE_IX  , 0xFB,  3, 1 },
        [0x0C] = { OP_BRSET6 , MODE_DIR , 0x0C,  5, 3 },
        [0x1C] = { OP_BSET6  , MODE_DIR , 0x1C,  5, 2 },
        [0x2C] = { OP_BMC    , MODE_REL , 0x2C,  3, 2 },
        [0x3C] = { OP_INC    , MODE_DIR , 0x3C,  5, 2 },
        [0x4C] = { OP_INCA   , MODE_INH , 0x4C,  1, 1 },
        [0x5C] = { OP_INCX   , MODE_INH , 0x5C,  1, 1 },
        [0x6C] = { OP_INC    , MODE_IX1 , 0x6C,  5, 2 },
        [0x7C] = { OP_INC    , MODE_IX  , 0x7C,  4, 1 },
        [0x8C] = { OP_CLRH   , MODE_INH , 0x8C,  1, 1 },
        [0x9C] = { OP_RSP    , MODE_INH , 0x9C,  1, 1 },
        [0xBC] = { OP_JMP    , MODE_DIR , 0xBC,  3, 2 },
        [0xCC] = { OP_JMP    , MODE_EXT , 0xCC,  4, 3 },
        [0xDC] = { OP_JMP    , MODE_IX2 , 0xDC,  4, 3 },
        [0xEC] = { OP_JMP    , MODE_IX1 , 0xEC,  3, 2 },
        [0xFC] = { OP_JMP    , MODE_IX  , 0xFC,  3, 1 },
        [0x0D] = { OP_BRCLR6 , MODE_DIR , 0x0D,  5, 3 },
        [0x1D] = { OP_BCLR6  , MODE_DIR , 0x1D,  5, 2 },
        [0x2D] = { OP_BMS    , MODE_REL , 0x2D,  3, 2 },
        [0x3D] = { OP_TST    , MODE_DIR , 0x3D,  4, 2 },
        [0x4D] = { OP_TSTA   , MODE_INH , 0x4D,  1, 1 },
        [0x5D] = { OP_TSTX   , MODE_INH , 0x5D,  1, 1 },
        [0x6D] = { OP_TST    , MODE_IX1 , 0x6D,  4, 2 },
        [0x7D] = { OP_TST    , MODE_IX  , 0x7D,  3, 1 },
        [0x9D] = { OP_NOP    , MODE_INH , 0x9D,  1, 1 },
        [0xAD] = { OP_BSR    , MODE_REL , 0xAD,  5, 2 },
        [0xBD] = { OP_JSR    , MODE_DIR , 0xBD,  5, 2 },
        [0xCD] = { OP_JSR    , MODE_EXT , 0xCD,  6, 3 },
        [0xDD] = { OP_JSR    , MODE_IX2 , 0xDD,  6, 3 },
        [0xED] = { OP_JSR    , MODE_IX1 , 0xED,  5, 2 },
        [0xFD] = { OP_JSR    , MODE_IX  , 0xFD,  5, 1 },
        [0x0E] = { OP_BRSET7 , MODE_DIR , 0x0E,  5, 3 },
        [0x1E] = { OP_BSET7  , MODE_DIR , 0x1E,  5, 2 },
        [0x2E] = { OP_BIL    , MODE_REL , 0x2E,  3, 2 },
        [0x3E] = { OP_CPHX   , MODE_EXT , 0x3E,  6, 3 },
        [0x4E] = { OP_MOV    , MODE_DD  , 0x4E,  5, 3 },
        [0x5E] = { OP_MOV    , MODE_DIXP, 0x5E,  5, 2 },
        [0x6E] = { OP_MOV    , MODE_IMD , 0x6E,  4, 3 },
        [0x7E] = { OP_MOV    , MODE_IXPD, 0x7E,  5, 2 },
        [0x8E] = { OP_STOP   , MODE_INH , 0x8E,  2, 1 },
        [0xAE] = { OP_LDX    , MODE_IMM , 0xAE,  2, 2 },
        [0xBE] = { OP_LDX    , MODE_DIR , 0xBE,  3, 2 },
        [0xCE] = { OP_LDX    , MODE_EXT , 0xCE,  4, 3 },
        [0xDE] = { OP_LDX    , MODE_IX2 , 0xDE,  4, 3 },
        [0xEE] = { OP_LDX    , MODE_IX1 , 0xEE,  3, 2 },
        [0xFE] = { OP_LDX    , MODE_IX  , 0xFE,  3, 1 },
        [0x0F] = { OP_BRCLR7 , MODE_DIR , 0x0F,  5, 3 },
        [0x1F] = { OP_BCLR7  , MODE_DIR , 0x1F,  5, 2 },
        [0x2F] = { OP_BIH    , MODE_REL , 0x2F,  3, 2 },
        [0x3F] = { OP_CLR    , MODE_DIR , 0x3F,  5, 2 },
        [0x4F] = { OP_CLRA   , MODE_INH , 0x4F,  1, 1 },
        [0x5F] = { OP_CLRX   , MODE_INH , 0x5F,  1, 1 },
        [0x6F] = { OP_CLR    , MODE_IX1 , 0x6F,  5, 2 },
        [0x7F] = { OP_CLR    , MODE_IX  , 0x7F,  4, 1 },
        [0x8F] = { OP_WAIT   , MODE_INH , 0x8F,  2, 1 },
        [0x9F] = { OP_TXA    , MODE_INH , 0x9F,  1, 1 },
        [0xAF] = { OP_AIX    , MODE_IMM , 0xAF,  2, 2 },
        [0xBF] = { OP_STX    , MODE_DIR , 0xBF,  3, 2 },
        [0xCF] = { OP_STX    , MODE_EXT , 0xCF,  4, 3 },
        [0xDF] = { OP_STX    , MODE_IX2 , 0xDF,  4, 3 },
        [0xEF] = { OP_STX    , MODE_IX1 , 0xEF,  3, 2 },
        [0xFF] = { OP_STX    , MODE_IX  , 0xFF,  2, 1 }
    },
    [1] = {
        [0x60] = { OP_NEG    , MODE_SP1 , 0x60,  6, 3 },
        [0xD0] = { OP_SUB    , MODE_SP2 , 0xD0,  5, 4 },
        [0xE0] = { OP_SUB    , MODE_SP1 , 0xE0,  4, 3 },
        [0x61] = { OP_CBEQ   , MODE_SP1 , 0x61,  6, 4 },
        [0xD1] = { OP_CMP    , MODE_SP2 , 0xD1,  5, 4 },
        [0xE1] = { OP_CMP    , MODE_SP1 , 0xE1,  4, 3 },
        [0xD2] = { OP_SBC    , MODE_SP2 , 0xD2,  5, 4 },
        [0xE2] = { OP_SBC    , MODE_SP1 , 0xE2,  4, 3 },
        [0x63] = { OP_COM    , MODE_SP1 , 0x63,  6, 3 },
        [0xD3] = { OP_CPX    , MODE_SP2 , 0xD3,  5, 4 },
        [0xE3] = { OP_CPX    , MODE_SP1 , 0xE3,  4, 3 },
        [0xF3] = { OP_CPHX   , MODE_SP1 , 0xF3,  6, 3 },
        [0x64] = { OP_LSR    , MODE_SP1 , 0x64,  6, 3 },
        [0xD4] = { OP_AND    , MODE_SP2 , 0xD4,  5, 4 },
        [0xE4] = { OP_AND    , MODE_SP1 , 0xE4,  4, 3 },
        [0xD5] = { OP_BIT    , MODE_SP2 , 0xD5,  5, 4 },
        [0xE5] = { OP_BIT    , MODE_SP1 , 0xE5,  4, 3 },
        [0x66] = { OP_ROR    , MODE_SP1 , 0x66,  6, 3 },
        [0xD6] = { OP_LDA    , MODE_SP2 , 0xD6,  5, 4 },
        [0xE6] = { OP_LDA    , MODE_SP1 , 0xE6,  4, 3 },
        [0x67] = { OP_ASR    , MODE_SP1 , 0x67,  6, 3 },
        [0xD7] = { OP_STA    , MODE_SP2 , 0xD7,  5, 4 },
        [0xE7] = { OP_STA    , MODE_SP1 , 0xE7,  4, 3 },
        [0x68] = { OP_LSL    , MODE_SP1 , 0x68,  6, 3 },
        [0xD8] = { OP_EOR    , MODE_SP2 , 0xD8,  5, 4 },
        [0xE8] = { OP_EOR    , MODE_SP1 , 0xE8,  4, 3 },
        [0x69] = { OP_ROL    , MODE_SP1 , 0x69,  6, 3 },
        [0xD9] = { OP_ADC    , MODE_SP2 , 0xD9,  5, 4 },
        [0xE9] = { OP_ADC    , MODE_SP1 , 0xE9,  4, 3 },
        [0x6A] = { OP_DEC    , MODE_SP1 , 0x6A,  6, 3 },
        [0xDA] = { OP_ORA    , MODE_SP2 , 0xDA,  5, 4 },
        [0xEA] = { OP_ORA    , MODE_SP1 , 0xEA,  4, 3 },
        [0x6B] = { OP_DBNZ   , MODE_SP1 , 0x6B,  8, 4 },
        [0xDB] = { OP_ADD    , MODE_SP2 , 0xDB,  5, 4 },
        [0xEB] = { OP_ADD    , MODE_SP1 , 0xEB,  4, 3 },
        [0x6C] = { OP_INC    , MODE_SP1 , 0x6C,  6, 3 },
        [0x6D] = { OP_TST    , MODE_SP1 , 0x6D,  5, 3 },
        [0xAE] = { OP_LDHX   , MODE_IX  , 0xAE,  5, 2 },
        [0xBE] = { OP_LDHX   , MODE_IX2 , 0xBE,  6, 4 },
        [0xCE] = { OP_LDHX   , MODE_IX1 , 0xCE,  5, 3 },
        [0xDE] = { OP_LDX    , MODE_SP2 , 0xDE,  5, 4 },
        [0xEE] = { OP_LDX    , MODE_SP1 , 0xEE,  4, 3 },
        [0xFE] = { OP_LDHX   , MODE_SP1 , 0xFE,  5, 3 },
        [0x6F] = { OP_CLR    , MODE_SP1 , 0x6F,  6, 3 },
        [0xDF] = { OP_STX    , MODE_SP2 , 0xDF,  5, 4 },
        [0xEF] = { OP_STX    , MODE_SP1 , 0xEF,  4, 3 },
        [0xFF] = { OP_STHX   , MODE_SP1 , 0xFF,  5, 3 }
    }
};

int opinfos_size[] = { 253, 47 };

/* vi:set ts=4 sw=4 et: */
/* vim:set syntax=c.doxygen: */
