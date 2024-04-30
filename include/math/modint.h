#ifndef INCLUDED_MODINT_H
#define INCLUDED_MODINT_H

#include "math/gcd.h"

template <auto MOD> struct ModInt {
    using value_t = decltype(MOD);
    using self_t = ModInt<MOD>;
    using ref_t = ModInt<MOD> &;
    using cref_t = const ModInt<MOD> &;
    value_t val;

    inline void set_val(value_t val) {
        if (val >= MOD) {
            val = val % MOD;
        } else if (val <= 0) {
            val = (val % MOD + MOD) % MOD;
        }
        this->val = val;
    }

    ModInt() : val(0) {}

    ModInt(value_t val) { set_val(val); }
    ModInt(cref_t other) { set_val(other.val); }

    cref_t operator=(value_t val) {
        set_val(val);
        return *this;
    }

    cref_t operator=(cref_t other) {
        set_val(other.val);
        return *this;
    }

    self_t operator+(cref_t other) const { return val + other.val; }
    ref_t operator+=(cref_t other) {
        set_val(this->val + other.val);
        return *this;
    }

    self_t operator-(cref_t other) const { return val - other.val; }
    ref_t operator-=(cref_t other) {
        set_val(this->val - other.val);
        return *this;
    }

    self_t operator*(cref_t other) const { return val * other.val; }
    ref_t operator*=(cref_t other) {
        set_val(this->val * other.val);
        return *this;
    }

    self_t operator/(cref_t other) const { return val * other.inverse().val; }
    ref_t operator/=(cref_t other) {
        set_val(this->val * other.inverse().val);
        return *this;
    }

	self_t operator%(cref_t other) const { return val % other.val; }
    ref_t operator%=(cref_t other) {
        set_val(this->val % other.val);
        return *this;
    }

    self_t inverse() const {
        auto [x, y, d] = extend_gcd(val, MOD);
        assert(d == 1);
        return x;
    }

    friend self_t pow(cref_t a, value_t n) {
        auto pw = abs(n);
        self_t result{1}, acc = a;
        while (pw > 0) {
            if ((pw & 1) == 1) {
                result *= acc;
            }
            acc *= acc;
            pw >>= 1;
        }
        if (n < 0)
            result = result.inverse();
        return result;
    }

    friend ostream &operator<<(ostream &os, cref_t c) { return os << c.val; }

    friend istream &operator>>(istream &is, ref_t c) {
        self_t::value_t val;
        is >> val, c.set_val(val);
        return is;
    }

    bool operator==(cref_t other) const { return val == other.val; }
    bool operator<(cref_t othr) const { return this->val < othr.val; }

    const value_t &operator*() const { return val; }
    value_t &operator*() { return val; }
};

#ifdef DEBUG
template <auto MOD> void __print(const ModInt<MOD> &x) { cerr << x.val; }
#endif

#endif