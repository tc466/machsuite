# Extract Vivado HLS include path
VHLS_PATH := $(dir $(shell which vivado_hls))/..
VHLS_INC ?= ${VHLS_PATH}/include

md: md.cpp md.h ../../common/harness.cpp
	g++ -I${VHLS_INC} $(CFLAGS) $(CFLAGS) -o md md.cpp ../../common/harness.cpp

run: md input.data check.data
	./md input.data check.data

generate_fixed: generate_fixed.cpp md.h
	g++ -I${VHLS_INC} $(CFLAGS) $(CFLAGS) -o $@ $<

hls: md.cpp md.h
	vivado_hls hls.tcl

clean:
	rm -f md
