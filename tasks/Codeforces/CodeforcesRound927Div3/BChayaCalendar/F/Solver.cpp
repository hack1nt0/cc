
#include "debug.h"

typedef long long Long;

void solve(int it) {
    int n;
    cin >> n;
    Long pre = 0;
    for (int i = 0; i < n; ++i) {
        Long curp; 
        cin >> curp;
        Long mul = pre / curp;
        Long cur = mul * curp;
        if (cur <= pre) cur += curp;
        pre = cur;
    }
    cout << pre << '\n';
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(&cout);
    int n; cin >> n;
    for (int i = 0; i < n; ++i) {
        solve(i);
    }
    return 0;
}
