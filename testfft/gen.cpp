#include "rand/generator.h"
#include "rand/seq.h"

Generator<int> f() {
    for (int i = 0; i < 10; i++)
        co_yield i;
}
int main() {
    int N = int(1e5);
    int V = 1e4;
    auto & R = Random::getInstance();
    int n = R.uniform(1, N);

    auto g= []() -> Generator<int> {
        for (int i = 0; i < 10; ++i) {
            co_yield i;
        }
    }();
    auto pa = choice(g.begin(), g.end(), n, true);
    // auto pa = choice_int(0, 10, n, true);
    int m = R.uniform(1, N);
    auto g2= []() -> Generator<int> {
        for (int i = 0; i < 10; ++i) {
            co_yield i;
        }
    }();
    auto pb = choice(g2.begin(), g2.end(), m, true);
    cout << n << ' ' << m << endl;
    for (auto a : pa) cout << a << ' '; cout << endl;
    for (auto b : pb) cout << b << ' '; cout << endl;
    return 0;
}