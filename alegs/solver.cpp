
#include "debug.h"

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(&cout);
    
    int nt; cin >> nt;
    for (int it = 0; it < nt; ++it) {
        int n; cin >> n;
        cout << n / 4 + (n % 4 > 0) << '\n';
    }

    return 0;
}
