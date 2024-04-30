
#include "debug.h"
#include "math/modint.h"

using Int = ModInt<(long long)1e9+7>;

void solve(int it) {
    int n, k;
    cin >> n >> k;
    set<int> remains;
    for (int i = 1; i <= n; ++i) remains.insert(i);
    for (int i = 0; i < k; ++i) {
        int r, c;
        cin >> r >> c;
        remains.erase(r);
        remains.erase(c);
    }
    int N = remains.size();
    vector<Int> dp(N + 1, 1);
    for (int i = 2; i <= N; ++i) {
        auto& res = dp[i];
        res = 0;
        res += dp[i - 1];
        res += dp[i - 2] * (i - 1) * 2;
    }
    cout << dp[N] << '\n';
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(&cout);
    int n; cin >> n;
    for (int i = 0; i < n; ++i) solve(i);
    return 0;
}
