rsa: rsa.c rsa.h ../../common/harness.c
	$(CC) $(CFLAGS) -o rsa rsa.c ../../common/harness.c

run: rsa input.data check.data
	./rsa input.data check.data

hls: rsa.c rsa.h
	vivado_hls hls.tcl

clean:
	rm -f rsa
