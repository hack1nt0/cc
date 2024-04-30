
#include "debug.h"

void solve(int it) {
	int n; cin >> n;
	string s; cin >> s;
	string r = s;
	reverse(r.begin(), r.end());
	if (s <= r)
		cout << s << '\n';
	else {
		cout << r << s << '\n';
	}
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(&cout);
    int n; cin >> n;
    for (int i = 0; i < n; ++i) solve(i);
    return 0;
}
