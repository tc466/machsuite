
// integer type definitions
#ifndef uint8_t
#define uint8_t  unsigned char
#endif

#ifndef uint16_t
#define uint16_t  unsigned short
#endif

#ifndef uint32_t
#define uint32_t  unsigned long
#endif

#ifndef uint64_t
#define uint64_t  unsigned long long
#endif

void rsa_decrypt(uint64_t *_c, uint64_t *_d, uint64_t *_n, uint64_t *_s);

////////////////////////////////////////////////////////////////////////////////
// Test harness interface code.

struct bench_args_t {
  uint64_t c;
  uint64_t d;
  uint64_t n;
  uint64_t s;
};
int INPUT_SIZE = sizeof(struct bench_args_t);

void run_benchmark(void *vargs) {
	struct bench_args_t *args = (struct bench_args_t *)vargs;
	rsa_decrypt(&(args->c), &(args->d), &(args->n), &(args->s));
}
