/*
Copyright (c) 2014, the President and Fellows of Harvard College.
All rights reserved.

Redistribution and use in source and binary forms, with or without
modification, are permitted provided that the following conditions are met:

* Redistributions of source code must retain the above copyright notice, this
  list of conditions and the following disclaimer.

* Redistributions in binary form must reproduce the above copyright notice,
  this list of conditions and the following disclaimer in the documentation
  and/or other materials provided with the distribution.

* Neither the name of Harvard University nor the names of its contributors may 
  be used to endorse or promote products derived from this software without
  specific prior written permission.

THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS" 
AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE 
IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE 
DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT HOLDER OR CONTRIBUTORS BE LIABLE
FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL
DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR
SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER
CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY,
OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE 
OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.


Based on algorithm described here:
http://www.cs.berkeley.edu/~mhoemmen/matrix-seminar/slides/UCB_sparse_tutorial_1.pdf
*/

#include <stdlib.h>
#include <stdio.h>

//#define NNZ 2474
//#define N 662
#define NNZ_MAX 65536
#define N_MAX 1024
//#define NNZ 1666
//#define N 494

#define FIXED_POINT

#ifdef FIXED_POINT
  #define TYPE int
#else
  #define TYPE double
#endif

void spmv(int config[2], TYPE val[NNZ_MAX], int cols[NNZ_MAX], int rowDelimiters[N_MAX + 1],
          TYPE vec[N_MAX], TYPE out[N_MAX]);
////////////////////////////////////////////////////////////////////////////////
// Test harness interface code.

struct bench_args_t {
  int config[2];
  TYPE val[NNZ_MAX];
  int cols[NNZ_MAX];
  int rowDelimiters[N_MAX+1];
  TYPE vec[N_MAX];
  TYPE out[N_MAX];
};
int INPUT_SIZE = sizeof(struct bench_args_t);


void run_benchmark( void *vargs ) {
  struct bench_args_t *args = (struct bench_args_t *)vargs;
  spmv( args->config, args->val, args->cols, args->rowDelimiters, args->vec, args->out );
}

////////////////////////////////////////////////////////////////////////////////
