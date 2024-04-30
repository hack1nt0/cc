#ifndef INCLUDED_RANDSEQ_H
#define INCLUDED_RANDSEQ_H

#include "rand/Random.h"
#include "rand/generator.h"
#include <cassert>
#include <stdexcept>

/*
    Reservoir Sample
    Single pass sampling with/out replacement
*/

template <typename Itr>
auto choice(Itr begin, Itr end, int m, bool replace) {
    vector<typename Itr::value_type> samples;
    auto& R = Random::getInstance();
    int n = 1;
    for (auto itr = begin; itr != end; ++itr, ++n) {
        auto cur = *itr; // TODO copy/move
        if (!replace) {
            if (n <= m) {
                samples.push_back(cur);
            } else if (R.rand() < float(m) / n) {
                samples[R.uniform(0, m)] = cur;
            }
        } else {
            for (int trial = 1; trial <= m; ++trial) {
                if (R.rand() < 1. / n) {
                    if (samples.size() < trial) {
                        samples.push_back(cur);
                    } else {
                        samples[trial - 1] = cur;
                    }
                }
            }
        }
    }
    return samples;
}
/*
    T be 1. float, 2. int, 3. Iterator
*/
template <typename T> vector<T> choice_int(T s, T t, int m, bool replace) {
    assert(is_integral_v<T>);
    auto generator = [=]() -> Generator<T> {
        for (T i = s; i < t; ++i) {
            cout << i << endl;
            co_yield i;
        }
    }();
    auto samples = choice(generator.begin(), generator.end(), m, replace);
    samples.shrink_to_fit();
    return samples;
}

#endif