
#include "debug.h"

void solve(int it) {
	int n, m, k;
	cin >> n >> m >> k;
	int bob = k >= n - n / m - (n % m ? 1 : 0);
	cout << (!bob ? "YES" : "NO") << '\n';
	
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(&cout);
    int n; cin >> n;
    for (int i = 0; i < n; ++i) solve(i);
    return 0;
}
