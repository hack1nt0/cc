
#include "debug.h"

typedef long long Long;

void solve(int it) {
    int n, q; cin >> n >> q;
    vector<Long> pones(n + 1, 0), psum(n + 1, 0);
    for (int i = 0; i < n; ++i) {
        int d; cin >> d;
        pones[i + 1] = pones[i];
        if (d == 1) pones[i + 1] += 1;
        psum[i + 1] = psum[i] + d - 1;
    }
    for (int iq = 0; iq < q; ++iq) {
        int l, r; cin >> l >> r;
        cout << (l < r && psum[r] - psum[l - 1] >= pones[r] - pones[l - 1] ? "YES" : "NO") << '\n';
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(&cout);
    int n; cin >> n;
    for (int i = 0; i < n; ++i) solve(i);
    return 0;
}
