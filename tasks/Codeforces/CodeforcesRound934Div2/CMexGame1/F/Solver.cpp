
#include "debug.h"

void solve(int it) {
	int n; cin >> n;
	map<int,int> cs;
	for (int i = 0; i < n; i++) {
		int x; cin >> x;
		cs[x]++;
	}
	int ret;
	if (cs[0] == 0)
		ret = 0;
	else {
	for (int x = 1; x <=n; x++) if (cs[x] < 2) {
		ret = x;
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
