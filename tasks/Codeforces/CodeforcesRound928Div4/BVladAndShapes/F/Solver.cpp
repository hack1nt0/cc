
#include "debug.h"

void solve(int it) {
    int n; cin >> n;
    int minx, maxx, miny, maxy;
    minx = miny = n, maxx = maxy = 0;
    vector<string> G(n);
    for (int y = 0; y < n; ++y) {
        cin >> G[y];
        for (int x = 0; x < n; ++x) {
            if (G[y][x] == '1') {
                minx = min(minx, x);
                maxx = max(maxx, x);
                miny = min(miny, y);
                maxy = max(maxy, y);
            }
        }
    }
    bool S = true;
    for (int x = minx; x <= maxx; ++x)
        for (int y = miny; y <= maxy; ++y) if (G[y][x] != '1') {
            S = false;
            break;
        }
    cout << (S ? "SQUARE" : "TRIANGLE") << '\n';
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(&cout);
    int n; cin >> n;
    for (int i = 0; i < n; ++i) solve(i);
    return 0;
}
