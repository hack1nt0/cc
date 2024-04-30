
#include "debug.h"

void solve(int it) {
	string x, y;
	cin >> x >> y;
	int len = x.size();
	
	for (int i = 0, first = -1; i < len; i++) {
		if (x[i] != y[i]) {
			if (first < 0) {
				first = i;
				continue;
			}
			if (x[first] * x[i] + y[first] * y[i] > x[first] * y[i] + y[first] * x[i])
				swap(x[i], y[i]);
		}
	}
	
	cout << x << '\n' << y << '\n';
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(&cout);
    int n; cin >> n;
    for (int i = 0; i < n; ++i) solve(i);
    return 0;
}
