#include "debug.h"

void solve(int it) {
    int n; cin >> n;
    vector<int> xs(n);
    for (int i = 0; i < n; ++i) cin >> xs[i];
    int l = 0, r = n - 1;
    while (l < n && xs[l] == 0) l++;
    while (r >= 0 && xs[r] == 0) r--;
    int ret = 0;
    for (int i = l; i <= r; ++i) if (xs[i] == 0) ret++;
    cout << ret << '\n';
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(&cout);
    int n; cin >> n;
    for (int i = 0; i < n; ++i) solve(i);
    return 0;
}
