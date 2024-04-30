
#include "debug.h"

void solve(int it) {
	string s; cin >> s;
	int ret = 0;
	for (int half = s.size() / 2; half > 0; half--) {
		int l = 0, r = half, matches = 0;
		while (matches < half && r < s.size()) {
			if (s[l] == s[r] || s[l] == '?' || s[r] == '?') {
				l++, r++, matches++;
			} else {
				l++, r++, matches = 0;
			}
		}
		if (matches == half) {
			ret = half * 2;
			break;
		}
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
