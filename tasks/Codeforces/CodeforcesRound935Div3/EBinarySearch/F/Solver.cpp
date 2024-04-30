
#include "debug.h"

void solve(int it) {
	int n, x; cin >> n >> x;
	vector<int> p(n + 1);
	int px;
	for (int i = 1; i <= n; i++) {
		cin >> p[i];
		if (p[i] == x) px = i;
	}
	int l = 1, r = n + 1;
	vector<int> vis(n + 1, 0);
	while (l + 1 < r) {
		int mid = (l + r) / 2;
		vis[mid] = 1;
		if (p[mid] <= x) l = mid;
		else r = mid;
	}
	if (p[l] == x) {
		cout << 0 << '\n';
	} else if (!vis[px] || p[l] < x) {
		cout << 1 << '\n';
		cout << l << ' ' << px << '\n';
	} else {
		cout << 2 << '\n';
		cout << l << ' ' << px << '\n';
		for (int i = 1; i <= n; i++) if (!vis[i] && p[i] < x) {
			cout << px << ' ' << i << '\n';
			break;
		}
	}
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(&cout);
    int n; cin >> n;
    for (int i = 0; i < n; ++i) solve(i);
    return 0;
}
