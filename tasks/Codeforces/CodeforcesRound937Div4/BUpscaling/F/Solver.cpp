
#include "debug.h"

void solve(int it) {
	int n; cin >> n;
	for (int i = 0; i < 2 * n; i++) {
		for (int j = 0; j < 2 * n; j++) {
			int row = i / 2, col = j / 2;
			char chr = (row + col) % 2 ? '.' : '#';
			cout << chr;
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
