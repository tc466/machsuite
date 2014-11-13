
#include "rsa.h"

void rsa_decrypt(uint64_t *_c, uint64_t *_d, uint64_t *_n, uint64_t *_s)
{
    uint64_t c, d, n, s;
    int i;
    c = *_c, d = *_d, n = *_n;
    s = 1;
    c = c % n;
    for (i = 0; i < 64; i++) {
        if (((d>>i) & 1) == 1)
            s = (s * c) % n;
        c = (c * c) % n;
    }
    *_s = s;
}
