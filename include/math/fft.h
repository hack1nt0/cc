
#ifndef INCLUDED_FFT_H
#define INCLUDED_FFT_H

#include "debug.h"
#include <complex>
#include <iostream>

/*
  https://www.cs.cmu.edu/afs/andrew/scs/cs/15-463/2001/pub/www/notes/fourier/fourier.pdf

  ~ 2s when N = 1e6
*/

typedef complex<double> CT;

template<typename CT>
void fft(vector<CT> & A, vector<CT>& FA, vector<CT> const& R, bool inverse=false) {
    int N = A.size();
    int L = round(log2(N));
    FA = A;
    for (int l = 1; l <= L; l++) {
        FA.swap(A);
        if (l == 1) {
            for (int i = 0; i < N; i++) {
                int ni = 0;
                for (int b = 0; b < L; ++b) if ((i >> b) & 1) ni |= 1 << (L - 1 - b);
                if (i < ni) swap(A[i], A[ni]);
            }
        }
        int group_sz = 1 << l;
        int group_ct = N / group_sz;
        for (int g = 0; g < group_ct; ++g) {
            for (int i = 0; i < group_sz / 2; ++i) {
                int j = g * group_sz + i;
                FA[j] = A[j] + A[j + (group_sz / 2)] * R[j * (1L << (L - l)) % N];
            }
            for (int i = 0; i < group_sz / 2; ++i) {
                int j = g * group_sz + group_sz / 2 + i;
                FA[j] = A[j - (group_sz / 2)] + A[j] * R[j * (1L << (L - l)) % N];
            }
        }
    }
    if (inverse) for (auto& a : FA) a /= N;
}

template<typename T>
vector<T> convolution(vector<T> const& a, vector<T> const& b) {
    int n = a.size();
    int m = b.size();
    if (n == 0 || m == 0)
        return {0};
    int N = 1;
    while (N < n + m - 1) N <<= 1;
    vector<CT> A(N, 0);
    vector<CT> FA(N, 0);
    vector<CT> B(N, 0);
    vector<CT> FB(N, 0);
    vector<CT> C(N, 0);
    vector<CT> R(N, 0);
    vector<CT> RR(N, 0);

    for (int i = 0; i < n; ++i) A[i] = CT(a[i]);
    for (int i = 0; i < m; ++i) B[i] = CT(b[i]);
    for (int i = 0; i < N; ++i) R[i] = exp(CT(0, -2 * acos(-1) * i / N));
    for (int i = 0; i < N; ++i) RR[i] = exp(-CT(0, -2 * acos(-1) * i / N));
    fft(A, FA, R);
    fft(B, FB, R);
    for (int i = 0; i < N; ++i) {
        FA[i] *= FB[i];
    }
    fft(FA, C, RR, true);

    vector<int> res(n + m - 1);
    for (int i = 0; i < res.size(); ++i) {
        res[i] = round(C[i].real());
    }
    return res;
}

#endif

