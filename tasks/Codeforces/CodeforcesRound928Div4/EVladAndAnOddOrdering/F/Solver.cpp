
#include "debug.h"

void solve(int it) {
    int n, k; cin >> n >> k;
    int ret;
    for (int pw = 1;; pw <<= 1) {
        int mul = n / pw;
        int count = mul / 2 + mul % 2;
        if (k > count) {
            k -= count;
        } else {
            ret = pw * (2 * k - 1);
            break;
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
