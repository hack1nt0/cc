
#include "debug.h"

void solve(int it) {
    int n, m;
    cin >> n >> m;
    vector<int> xs(n), ret(n);
    string commands;
    for (int i = 0; i < n; ++i) cin >> xs[i];
    cin >> commands;
    int l = 0, r = n - 1;
    for (char c : commands) {
        if (c == 'L') l++;
        else r--;
    }
    int acc = 1;
    for (int i = n - 1; i >= 0; --i) {
        char c = commands[i];
        if (c == 'L') l--, acc = acc * xs[l] % m;
        else r++, acc = acc * xs[r] % m;
        ret[i] = acc;
    }
    for (int i = 0; i < n; ++i) cout << ret[i] << ' ';
    cout << '\n';
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(&cout);
    int n; cin >> n;
    for (int i = 0; i < n; ++i) solve(i);
    return 0;
}
