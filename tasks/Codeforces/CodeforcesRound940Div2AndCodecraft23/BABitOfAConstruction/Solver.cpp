
#include "debug.h"

void solve(int it) {
    int n, k; cin >> n >> k;
    auto bits = [](int x) -> int {
        return bitset<31>(x).count();
    };
    if (n == 1) {
        cout << k << '\n';
        return;
    }
    int pow = 0;
    while (1 << pow <= k) pow++;
    pow--;
    int a = (1 << pow) - 1;
    int b = k - a;
    cout << a << ' ' << b << ' ';
    for (int i = 0; i < n - 2; i++) cout << 0 << ' ';
    cout << '\n';
    return;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(&cout);
    int n; cin >> n;
    for (int i = 0; i < n; ++i) solve(i);
    return 0;
}
