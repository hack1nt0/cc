
#include "debug.h"

void solve(int it) {
	int n; cin >> n;
	string s; cin >> s;
	vector<int> zeros(n + 1, 0), ones(n + 1, 0);
	for (int i = 1; i <= n; i++) zeros[i] = zeros[i - 1] + (s[i - 1] == '0' ? 1 : 0);
	for (int i = 1; i <= n; i++) ones[i] = ones[i - 1] + (s[n - i] == '1' ? 1 : 0);
	pair<int, int> ret{n + 1, -1};
	for (int i = 0; i <= n; i++) if ((i + 1) / 2 <= zeros[i] && (n - i + 1) / 2 <= ones[n - i]) {
		ret = min(ret, {abs(n - i - i), i});
		debug(i, abs(n / 2 - i));
	}
	cout << ret.second << '\n';
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(&cout);
    int n; cin >> n;
    for (int i = 0; i < n; ++i) solve(i);
    return 0;
}
