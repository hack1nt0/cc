#include "math/fft.h"

int main() {
    typedef vector<int> Poly;
    int n, m;
    cin >> n >> m;
    Poly pa(n), pb(m);
    for (int i = 0; i < n; ++i) cin >> pa[i];
    for (int i = 0; i < m; ++i) cin >> pb[i];

    auto pc = convolution(pa, pb);
    for (int i = 0; i < pc.size(); ++i) cout << pc[i] << ' ';
    cout << endl;

    return 0;
}