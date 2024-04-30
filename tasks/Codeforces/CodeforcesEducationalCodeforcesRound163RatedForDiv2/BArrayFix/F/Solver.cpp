
#include "debug.h"

void solve(int it) {
	int n; cin >> n;
	vector<int> a(n);
	for (int i = 0; i < n; i++) cin >> a[i];
	bool ret = true;
	while (true) {
		bool found = false;
		for (int i = 1; i < a.size(); ++i) {
			if (a[i - 1] > a[i]) {
				if (a[i - 1] < 10) {
					ret = false;
				} else {
					vector<int> aa;
					for (int j = 0; j < i - 2; j++) aa.push_back(a[j]);
					aa.push_back(a[i - 1] / 10);
					aa.push_back(a[i - 1] % 10);
					for (int j = i; j < a.size(); j++) aa.push_back(a[j]);
					a = aa;
					found = true;
				}
			}
		}
		if (!found) break;
	}
				
	cout << (ret ? "YES" : "NO") << '\n';
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(&cout);
    int n; cin >> n;
    for (int i = 0; i < n; ++i) solve(i);
    return 0;
}
