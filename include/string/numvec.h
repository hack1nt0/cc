#ifndef INCLUDED_NUMVEC_H
#define INCLUDED_NUMVEC_H

#include "debug.h"

template <typename T, int base, bool rev, int fix_len>
struct NumberVector : vector<T> {
    using super = vector<T>;

    NumberVector(T n) : super::vector() {    
        while (n > 0) {
            super::push_back(n % base);
            n /= base;
        }
        while (super::size() < fix_len) super::push_back(0);
        if (rev) {
            std::reverse(super::begin(), super::end());
        }
        super::shrink_to_fit();
    }

    NumberVector(const vector<T>& xs): super::vector(xs) {        
    }

    T number() {
        return !rev ? _number(super::begin(), super::end()) : _number(super::rbegin(), super::rend());
    }

    template <class Iter>
    T _number(Iter begin, Iter end) {
        T pw = 1, result = 0;
        while (begin != end) {
            result += *begin * pw;
            pw *= base;
            begin++;
        }
        return result;
    }

};

// template<int nbits>
// struct BitsetIterator {
//     using self_type = BitsetIterator;
//     using value_type = bool;
    
//     const bitset<nbits>& bs;
//     int pb;
//     BitsetIterator(const bitset<nbits>& bs, int pb) : bs(bs), pb(pb) {}
//     value_type operator*() {
//         return bs[pb];
//     }
//     self_type operator++() {
//         pb++;
//         return *this;
//     }
//     bool operator!=(BitsetIterator other) {
//         return !(pb == other.pb);
//     }
// };

// template<unsigned long nbits>
// auto begin(const bitset<nbits>& bs) {
//     return BitsetIterator<nbits>(bs, 0);
// }

// template<unsigned long nbits>
// auto end(const bitset<nbits>& bs) {
//     return BitsetIterator<nbits>(bs, bs.size());
// }
#endif