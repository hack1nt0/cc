#ifndef INCLUDED_GCD_H
#define INCLUDED_GCD_H

#include "debug.h"

template <typename T>
array<T, 3> extend_gcd(T a, T b) {
    if (b == 0) {
        return {1, 0, a};
    } else {
        auto [xx, yy, g] = extend_gcd(b, a % b);
        T x = yy;
        T y = xx - a / b * yy;
        return {x, y, g};
    }
}

#endif