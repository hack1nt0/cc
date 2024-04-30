#ifndef INCLUDED_PRIMES_H
#define INCLUDED_PRIMES_H

#include "debug.h"

template <typename T>
map<int,int> primes(T n) {
    map<int,int> prime_factors;
    for (int p = 2; p <= T(sqrt(n)); p++) {
        if (n % p == 0) {
            prime_factors[p] = 0;
            while (n % p == 0) prime_factors[p]++, n /= p;
        }
    }
    return prime_factors;
}

#endif