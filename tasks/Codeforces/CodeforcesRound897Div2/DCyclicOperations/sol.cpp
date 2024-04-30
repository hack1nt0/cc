#include "debug.h"

using namespace std;

int dfs(int i, vector<int>& B, vector<int>& color, int c) {
    if (color[i] >= 0) {
        return color[i];
    }
    if (color[i] == -2) {
        return color[i] = c;
    }
    color[i] = -2;
    return color[i] = dfs(B[i], B, color, c);
}

void solve(int it) {
    int n, k;
    cin >> n >> k;
    vector<int> B(n);
    for (int i = 0; i < n; ++i) cin >> B[i], B[i]--;
    vector<int> color(n, -1);
    int nc = 0;
    for (int i = 0; i < n; ++i) if (color[i] == -1) {
        if (dfs(i, B, color, nc) == nc) {
            nc++;
        }
    }
    vector<int> cnt(nc, 0);
    for (int c : color) cnt[c]++;
    auto [mn, mx] = minmax_element(begin(cnt), end(cnt));
    if ((k == 1 && *mn == 1 && *mx == 1) || (k > 1 && *mn > 1)) {
        cout << "YES" << endl;
    } else {
        cout << "NO" << endl;
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int nt; cin >> nt;
    for (int it = 1; it <= nt; ++it) solve(it);
    return 0;
}
