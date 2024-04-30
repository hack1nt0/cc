
#include "debug.h"

void solve(int it) {
	int k, q;
	cin >> k >> q;
	vector<int> a(k);
	for (int i = 0; i < k; i++) cin >> a[i];
	for (int i = 0; i < q; i++) {
		int n; cin >> n;
		cout << min(n, a[0] - 1) << ' ';
	}
	cout << '\n';
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(&cout);
    int n; cin >> n;
    for (int i = 0; i < n; ++i) solve(i);
    return 0;
}
