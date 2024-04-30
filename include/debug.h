#ifndef INCLUDED_DEBUG_H
#define INCLUDED_DEBUG_H

#include <algorithm>
#include <cassert>
#include <complex>
#include <cstring>
#include <forward_list>
#include <functional>
#include <iomanip>
#include <iostream>
#include <limits>
#include <list>
#include <map>
#include <queue>
#include <random>
#include <set>
#include <stack>
#include <string>
#include <unordered_map>
#include <unordered_set>
#include <vector>
#include <bitset>

using namespace std;

#ifdef DEBUG
void __print(int x) { cerr << x; }
void __print(long x) { cerr << x; }
void __print(long long x) { cerr << x; }
void __print(unsigned x) { cerr << x; }
void __print(unsigned long x) { cerr << x; }
void __print(unsigned long long x) { cerr << x; }
void __print(float x) { cerr << x; }
void __print(double x) { cerr << x; }
void __print(long double x) { cerr << x; }
void __print(char x) { cerr << '\'' << x << '\''; }
void __print(const char *x) { cerr << '\"' << x << '\"'; }
void __print(const string &x) { cerr << '\"' << x << '\"'; }
void __print(bool x) { cerr << (x ? "true" : "false"); }

template <typename T, typename V> void __print(const pair<T, V> &x) {
    cerr << '{';
    __print(x.first);
    cerr << ',';
    __print(x.second);
    cerr << '}';
}
template <typename T> void __print(const complex<T> &x) {
    __print(x.real());
    cerr << '+';
    __print(x.imag());
    cerr << 'i';
}
template <typename T> void __print(const vector<T> &xs) {
    int f = 0;
    cerr << '[';
    for (const auto &x : xs)
        cerr << (f++ ? "," : ""), __print(x);
    cerr << ']';
}
template <typename T> void __print(const set<T> &xs) {
    int f = 0;
    cerr << '{';
    for (const auto &x : xs)
        cerr << (f++ ? "," : ""), __print(x);
    cerr << '}';
}
template <typename K, typename V> void __print(const map<K, V> &xs) {
    cerr << "{";
    for (const auto &x : xs) {
        __print(x.first);
        cerr << ": ";
        __print(x.second);
        cerr << ", ";
    }
    cerr << "}";
}
template< std::size_t N >
void __print(const bitset<N> &xs) {
    cerr << xs;
}
// template <typename T> void __print(T &o) { o.dot(); }
void _print() { cerr << "]\n"; }
template <typename T, typename... V> void _print(T t, V... v) {
    __print(t);
    if (sizeof...(v))
        cerr << ", ";
    _print(v...);
}
#define debug(x...)                                                            \
    cerr << "[" << #x << "] = [";                                              \
    _print(x)
#else
#define debug(x...)
#endif

// uint64_t now() {
//   using namespace std::chrono;
//   return
//   duration_cast<milliseconds>(system_clock::now().time_since_epoch()).count();
// }

// template <class T> T &minip(T &a, const T &b) {
//     if (b < a)
//         a = b;
//     return a;
// }

// template <class T> T &maxip(T &a, const T &b) {
//     if (b > a)
//         a = b;
//     return a;
// }

// https://www.open-std.org/jtc1/sc22/wg21/docs/papers/2016/p0200r0.html
template <class Fun> class y_combinator_result {
    Fun fun_;

  public:
    template <class T>
    explicit y_combinator_result(T &&fun) : fun_(std::forward<T>(fun)) {}

    template <class... Args> decltype(auto) operator()(Args &&...args) {
        return fun_(std::ref(*this), std::forward<Args>(args)...);
    }
};

template <class Fun> decltype(auto) y_combinator(Fun &&fun) {
    return y_combinator_result<std::decay_t<Fun>>(std::forward<Fun>(fun));
}

#endif
