
#include "debug.h"

void solve(int it) {
    int n; cin >> n;
    multiset<int> S;
    for (int i = 0; i < n; ++i) {
        int d; cin >> d;
        S.insert(d);
    }
    int sum = (1LL << 31) - 1;
    int ret = 0;
    for (int d : S) {
        ret++;
        auto ptr = S.find(sum - d);
        if (ptr != S.end()) S.erase(ptr);
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
