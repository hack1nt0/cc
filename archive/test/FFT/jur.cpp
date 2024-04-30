#include "debug.h"

int main() {
    typedef vector<int> Poly;
    int n, m;
    cin >> n >> m;
    Poly pa(n), pb(m);
    for (int i = 0; i < n; ++i) cin >> pa[i];
    for (int i = 0; i < m; ++i) cin >> pb[i];

    Poly pc(n + m - 1, 0);
    for (int k = 0; k < n + m - 1; k++) {
        for (int i = 0; i <= min(k, n - 1); i++) {
            int j = k - i;
            if (0 <= j && j < m) {
                pc[k] += pa[i] * pb[k - i];
            }
        }
    }

    for (int i = 0; i < pc.size(); ++i) cout << pc[i] << ' ';
    cout << endl;

    return 0;
}