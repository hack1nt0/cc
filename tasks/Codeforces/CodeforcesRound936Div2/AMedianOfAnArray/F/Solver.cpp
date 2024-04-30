
#include "debug.h"

void solve(int it) {
	int n; cin >> n;
	vector<int> xs(n);
	for (int i = 0; i < n; i++) cin >> xs[i];
	sort(begin(xs), end(xs));
	int med = (n + 1) / 2 - 1;
	int lb = distance(begin(xs), lower_bound(begin(xs), end(xs), xs[med]));
	int rb = distance(begin(xs), upper_bound(begin(xs), end(xs), xs[med]));
	int ret = rb - med;
	//if (lb > 0) ret = min(ret, xs[med] + 1 - xs[lb - 1]);
	cout << ret << '\n';
	debug(xs, lb, rb);
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(&cout);
    int n; cin >> n;
    for (int i = 0; i < n; ++i) solve(i);
    return 0;
}
