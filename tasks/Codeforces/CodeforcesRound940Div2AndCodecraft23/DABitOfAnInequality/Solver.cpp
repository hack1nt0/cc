
#include "debug.h"

using Int = long long;
const int B = 31;

void solve(int it) {
    int n;
    cin >> n;
    vector<int> arr(n);
    for (int i = 0; i < n; ++i) cin >> arr[i];

    vector<vector<Int>> lcnt(B, {0, 0});
    vector<vector<Int>> rcnt(B, {0, 0});
    for (int ib = 0; ib < B; ++ib) {
        int v = 0;
        for (auto x : arr) {
            v ^= x;
            rcnt[ib][v >> ib & 1]++;
        }
    }
    Int ret = 0;
    for (int iy = 0; iy < n; ++iy) {
        auto y = arr[iy];
        for (int ib = 0; ib < B; ib++) {
            auto b = y >> ib & 1;
            if (b) {
                swap(lcnt[ib][0], lcnt[ib][1]);
                lcnt[ib][1]++;
            } else {
                lcnt[ib][0]++;
            }
            assert(lcnt[ib][0] + lcnt[ib][1] == iy + 1);
        }
        if (y > 0) {
            int ib = B - 1;
            while ((y >> ib & 1) == 0) ib--;
            ret += lcnt[ib][0] * rcnt[ib][1];
            ret += lcnt[ib][1] * rcnt[ib][0];
        }
        for (int ib = 0; ib < B; ib++) {
            auto b = y >> ib & 1;
            if (b) {
                rcnt[ib][1]--;
                swap(rcnt[ib][0], rcnt[ib][1]);
            } else {
                rcnt[ib][0]--;
            }
            assert(rcnt[ib][0] + rcnt[ib][1] == n - iy - 1);
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
