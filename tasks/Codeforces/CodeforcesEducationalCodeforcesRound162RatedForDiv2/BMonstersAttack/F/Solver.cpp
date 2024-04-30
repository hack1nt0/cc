
#include "debug.h"

typedef long long Long;

void solve(int it) {
    int n, k; cin >> n >> k;
    vector<int> H(n), P(n);
    vector<Long> need(n + 1, 0);
    for (int i = 0; i < n; ++i) cin >> H[i];
    for (int i = 0; i < n; ++i) {
        cin >> P[i];
        need[abs(P[i])] += H[i];
    }
    Long B = 0;
    bool ret = true;
    for (int i = 0; i < n; ++i) {
        B += k;
        need[i + 1] += need[i];
        if (B < need[i + 1]) {
            ret = false;
            break;
        }
    }
    cout << (ret ? "YES" : "NO") << '\n';
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(&cout);
    int n; cin >> n;
    for (int i = 0; i < n; ++i) solve(i);
    return 0;
}
