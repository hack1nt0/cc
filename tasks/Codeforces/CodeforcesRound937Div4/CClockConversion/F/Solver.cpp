
#include "debug.h"

void solve(int it) {
	string s; cin >> s;
	int h = (s[0] - '0') * 10 + s[1] - '0';
	int m = (s[3] - '0') * 10 + s[4] - '0';
	
	int hh = h;
	if (h == 0 || h == 12) hh = 12;
	else if (h > 12) hh = h % 12;
	bool am = h < 12;
	auto two = [](int d) {
		string s;
		s.push_back(d / 10 + '0');
		s.push_back(d % 10 + '0');
		return s;
	};
	cout << two(hh) << ':' << two(m) << ' ' << (am ? "AM" : "PM") << '\n';
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(&cout);
    int n; cin >> n;
    for (int i = 0; i < n; ++i) solve(i);
    return 0;
}
