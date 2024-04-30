
#include "debug.h"

void solve(int it) {
	int n;
	cin >> n;
	map<int,int> cnt;
	int ret = 0;
	for (int i = 0; i < n; i++) {
		int a; cin >> a;
		if (++cnt[a] > 1) ret++;
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
