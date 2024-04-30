
#include "debug.h"

typedef long long Long;

void solve(int it) {
    int n; cin >> n;
    Long ret = 0, period = 10;
    int nn = n;
    while (nn) {
        for (int d = 0; d < 10; ++d)
            ret += d * (period / 10) * ((n + 1) / period);
        Long remain = (n + 1) % period;
        for (int d = 0; remain > 0; d++) {
            ret += d * min(remain, (period / 10));
            remain -= period / 10;
        }
        period *= 10;
        nn /= 10;
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
