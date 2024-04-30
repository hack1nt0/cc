
#include "debug.h"

void solve(int it) {
	int n; cin >> n;
	if (n % 2) {
		cout << "NO" << '\n';
	} else {
		cout << "YES" << '\n';
		for (int i = 0; i < n / 2; i++) {
			cout << (i % 2 == 0 ? "AA" : "BB");
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
