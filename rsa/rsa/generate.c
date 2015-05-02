#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <assert.h>
#include <time.h>

#include "rsa.h"
// Fake benchmark function to satisfy the extern
void rsa_decrypt(uint64_t *_c, uint64_t *_d, uint64_t *_n, uint64_t *_s){}

void generate_binary()
{
  struct bench_args_t data;
  data.c = 0xdeadbeefL;
  data.d = 0x61200011L;
  data.n = 0x1e5a000673600033LL; // 0x50000003L x 0x61200011L
  data.s = 0x0;
  char *ptr;
  int status, fd, written=0;

  // Open and write
  fd = open("input.data", O_WRONLY|O_CREAT|O_TRUNC, S_IRUSR|S_IWUSR|S_IRGRP|S_IWGRP|S_IROTH|S_IWOTH);
  assert( fd>0 && "Couldn't open input data file" );
  
  ptr = (char *) &data;
  while( written<sizeof(data) ) {
    status = write( fd, ptr, sizeof(data)-written );
    assert( status>=0 && "Couldn't write input data file" );
    written += status;
  }
}

int main(int argc, char **argv)
{
  generate_binary();
  return 0;
}
