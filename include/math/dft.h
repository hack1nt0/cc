
#ifndef INCLUDED_DFT_H
#define INCLUDED_DFT_H

#include "debug.h"

/*
  https://www.cs.cmu.edu/afs/andrew/scs/cs/15-463/2001/pub/www/notes/fourier/fourier.pdf
*/

template<typename T>
vector<complex<T>> fft(vector<complex<T>> const & p) {
    int n = p.size();
    if (n <= 1)
        return {p[0]};
    vector<complex<double>> temp(n / 2);
    for (int i = 0; i < n / 2; ++i) temp[i] = p[i * 2];
    auto fftl = fft(temp);
    for (int i = 0; i < n / 2; ++i) temp[i] = p[i * 2 + 1];
    auto fftr = fft(temp);
    
    vector<complex<double>> res(n);
    for (int i = 0; i < n; ++i) {
        auto theta = -2 * acos(-1) * i / n;
        // complex<double> root(cos(theta), sin(theta));
        complex<double> root = exp(complex<double>(0, theta));
        res[i] = fftl[i % (n / 2)] + root * fftr[i % (n / 2)];
    }
    return res;
}

template<typename T>
vector<complex<T>> ifft(vector<complex<T>> & p) {
    // reverse(p.begin(), p.end());
    for (auto& x: p) x = conj(x);
    auto res = fft(p);
    for (auto & x: res) x = conj(x) / double(p.size());
    return res;
}

#endif

