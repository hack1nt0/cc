#include "debug.h"
#include "math/modint.h"

using Int = ModInt<(long long)1e9 + 7>;

void solve(int it) {
    int n; cin >> n;
    Int comb = n + 1, fact = 1, ret = 0;
    for (int i = 1; i <= n; i++) {
        fact *= i;
        //comb(m, k+1) = comb(m,k) * (m-k) / (k+1)
        int k = i, m = n + 1;
        comb = comb * (m - k) / (k + 1);
        if (n == 3) {
            debug(n, i, comb);
        }
        ret += comb * fact / i % i;
        if (n == 3) {
            debug(n, i, ret);
        }
    }
    cout << ret << '\n';
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(&cout);
    int n; cin >> n;
    for (int i = 0; i < n; ++i) solve(i);
    return 0;
}
