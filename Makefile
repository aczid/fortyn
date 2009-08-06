HC_MODEL ?= MC9S08GB60A
CFILES = $(wildcard *.c)

override CFLAGS += -g
all: sim

CLEANFILES += sim

# TODO
CLOBBERFILES += ops.h
ops.h: $(HC_MODEL).ops
	touch $@

CLOBBERFILES += $(HC_MODEL).ops
$(HC_MODEL).ops: $(HC_MODEL).txt
	perl -ne 'print if /Opcode Map/.../Opcode Map/' $< | ./munge_ops_table.pl > $@

.SECONDARY: $(HC_MODEL).txt
CLOBBERFILES += $(HC_MODEL).txt
$(HC_MODEL).txt: $(HC_MODEL).pdf
	pdftotext -raw $< $@

CLOBBERFILES += $(HC_MODEL).pdf
$(HC_MODEL).pdf:
	wget http://www.freescale.com/files/microcontrollers/doc/data_sheet/$(notdir $@)

CLEANFILES += *.[od]
.PHONY: clean clobber
clean:
	-rm -rf $(CLEANFILES)

clobber: clean
	-rm -rf $(CLOBBERFILES)

ifneq ($(MAKECMDGOALS),clean)
include $(CFILES:.c=.d)
endif

%.d: %.c
	$(CC) -MM -MG -MF $@ $^
