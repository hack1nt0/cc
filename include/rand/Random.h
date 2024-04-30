#ifndef INCLUDED_RANDVAL_H
#define INCLUDED_RANDVAL_H

#include "debug.h"
#include <random>

class Random {
    public:
        // Will be used to obtain a seed for the random number engine
        std::random_device dev;
        // Standard mersenne_twister_engine seeded with rd()
        std::mt19937 gen;
        std::uniform_real_distribution<double> dist;

        static Random& getInstance() { 
            // Guaranteed to be destroyed.
            // Instantiated on first use.
            static Random instance;
            return instance;
        }

        double rand() {
            return dist(gen);
        }

        template <typename T> T uniform(T left_close, T right_open) {
            assert(left_close < right_open);
            T x = T(left_close + T((right_open - left_close) * dist(gen)));
            // assert(s <= x && x < t);
            return x;
        }

    private:
        Random(): dev(), gen(dev()), dist(0, 1) {}
};

#endif