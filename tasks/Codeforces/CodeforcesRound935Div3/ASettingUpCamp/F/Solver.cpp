
#include "debug.h"

void solve(int it) {
	int n1, n3, nx; cin >> n1 >> n3 >> nx;
	int ret = n1;
	ret += n3 / 3;
	if (n3 % 3) {
		if (!(3 - n3 % 3 <= nx)) {
			cout << -1 << '\n';
			return;
		}
		ret++;
		nx -= 3 - n3 % 3;
	}
	ret += (nx + 2) / 3;
	cout << ret << '\n';
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(&cout);
    int n; cin >> n;
    for (int i = 0; i < n; ++i) solve(i);
    return 0;
}
