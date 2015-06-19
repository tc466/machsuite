# Extract Vivado HLS include path
VHLS_PATH := $(dir $(shell which vivado_hls))/..
VHLS_INC ?= ${VHLS_PATH}/include

crs: crs.c crs.h ../../common/harness.c
	$(CC) -I${VHLS_INC} $(CFLAGS) -o crs crs.c ../../common/harness.c

generate: generate.c crs.h
	$(CC) $(CFLAGS) -o $@ $<

run: crs input.data check.data
	./crs input.data check.data

hls: crs.c crs.h	
	vivado_hls hls.tcl

clean:
	rm -f crs
