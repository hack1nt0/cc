
#include "debug.h"

void solve(int it) {
	int n, k;
	cin >> n >> k;
	vector<vector<int>> arrs(2, vector<int>(n));
	for (int i = 0; i < n * 2; i++) cin >> arrs[i / n][i % n];
	for (const auto &arr : arrs) {
		map<int, int> mp;
		vector<pair<int,int>> cs;
		for (auto x : arr) mp[x]++;
		for (auto p : mp) cs.push_back({p.first, p.second});
		sort(cs.begin(), cs.end(), [](const auto &a, const auto &b) -> bool  {
			return a.second != b.second ? a.second > b.second : a.first < b.first;
		});
		for (int remain = k * 2, i=0; remain > 0; i++) {
			for (int c = 0; c < cs[i].second; c++)
				cout << cs[i].first << ' ';
			remain -= cs[i].second;
		}
		cout << '\n';
	}
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(&cout);
    int n; cin >> n;
    for (int i = 0; i < n; ++i) solve(i);
    return 0;
}
