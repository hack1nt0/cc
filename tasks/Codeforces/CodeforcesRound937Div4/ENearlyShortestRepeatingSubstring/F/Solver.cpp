
#include "debug.h"

void solve(int it) {
	int n; cin >> n;
	string s; cin >> s;
	if (n <= 2) {
		cout << 1 << '\n';
		return;
	}
	auto ok = [&](int len) -> bool {
		map<string, int> mp;
		for (int i = 0; i < n; i += len) mp[s.substr(i, len)]++;
		if (mp.size() == 1) return true;
		if (mp.size() >= 3) return false;
		auto a = *mp.begin();
		auto b = *--mp.end();
		int diff = 0;
		for (int i = 0; i < len; i++) diff += a.first[i] != b.first[i];
		return (min(a.second, b.second) == 1 && diff <= 1);
	};
	vector<int> divs;
	for (int div = 1; div * div <= n; div++) if (n % div == 0) {
		divs.push_back(div);
		divs.push_back(n / div);
	}
	sort(begin(divs), end(divs));
	int r = distance(begin(divs), unique(begin(divs), end(divs)));
	for (int i = 0; i < r; i++) {
		int len = divs[i];
		if (ok(len)) {
			cout << len << '\n';
			return;
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
