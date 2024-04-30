
#include "debug.h"

void solve(int it) {
	int n; cin >> n;
	string s; cin >> s;
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
	for (int len = 1; len <= n; len++) if (n % len == 0 && ok(len)) {
		cout << len << '\n';
		return;
	}
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(&cout);
    int n; cin >> n;
    for (int i = 0; i < n; ++i) solve(i);
    return 0;
}
