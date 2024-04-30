
#include "debug.h"

void solve(int it) {
	int n, m, k;
	cin >> n >> m >> k;
	vector<int> a(n), b(m);
	for (int i = 0; i < n; i++) cin >> a[i];
	for (int i = 0; i < m; i++) cin >> b[i];
	
	map<int, int> aMap, bMap;
	int ret = 0, matches = 0;
	for (int i = 0; i <= n - m; i++) {
		if (i == 0) {
			for (int j = 0; j < m; j++)
				aMap[a[j]]++, bMap[b[j]]++;
			for (auto [key, v] : aMap) {
				matches += min(v, bMap[key]);
			}
			ret += matches >= k;
			continue;
		}
		{
			auto key = a[i - 1];
			aMap[key]--;
			if (aMap[key] < bMap[key]) matches--;
		}
		{
			auto key = a[i + m - 1];
			aMap[key]++;
			if (aMap[key] <= bMap[key]) matches++;
		}
		ret += matches >= k;
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
