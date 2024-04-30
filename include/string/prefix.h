#ifndef INCLUDED_PREFIX_H
#define INCLUDED_PREFIX_H

#include "debug.h"

template<class T>
struct Prefix {
    struct iterator {
        using iterator_category = std::random_access_iterator_tag;
        using difference_type = std::ptrdiff_t;
        using value_type = pair<T, T>;
        using pointer = value_type *;
        using reference = value_type&;

        explicit iterator(T l, T r) : l(l), r(r) {}
        value_type operator*() { return {l, r}; }
        // iterator &operator++() {
        //     r++;
        //     return *this;
        // }
        // iterator &operator+(difference_type n) {
        //     return iterator(l, l + n);
        // }
        bool operator!=(iterator other) const { return !(l == other.l && r == other.r); }

      private:
        T l, r;
    };
    iterator begin() { return iterator(l, l); }
    iterator end() { return iterator(l, r); }
    
    T l, r;
};

template <class iter_t>
Prefix<iter_t> prefixes(iter_t begin, iter_t end) {
    return {begin, end};
}

#endif