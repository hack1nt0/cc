
#include "debug.h"

void solve(int it) {
	int n, k;
	cin >> n >> k;
	cout << (k < n - 1 ? n : 1) << '\n';
}

int main() {
    ios_base::sync_with_stdio(false);
	cin.tie(&cout);
	int n; cin >> n;
	for (int i = 0; i < n; ++i) solve(i);
    return 0;
}
