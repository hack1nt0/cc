
#include "debug.h"

void solve(int it) {
	int n, x; cin >> n >> x;
	vector<int> a(n);
	for (int i = 0; i < n; i++) cin >> a[i];
	
	int ret = -1;
	set<int> segs;
	for (int i = 0; i < n; i++) segs.insert(i);
	for (int b = 29;; b--) {
		if (b < 0) {
			ret = max(ret, (int) segs.size());
			break;
		}
		
		int ones = 0;
		for (int aa: a) ones += aa >> b & 1;
		if (ones % 2) {
			if ((x >> b & 1) == 0) {
				break;
			}
			continue;
		}
		
		set<int> segs2;
		for (int p = 0; p < n; ) {
			int s = 0;
			for (int q = p; q < n; q++) {
				s ^= a[q] >> b & 1;
				if (!s && segs.count(q)) {
					segs2.insert(q);
					p = q + 1;
					break;
				}
			}
		}
		if ((x >> b & 1) == 0) {
			segs = segs2;
		} else {
			ret = max(ret, (int) segs2.size());
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
