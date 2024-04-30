
#include "debug.h"

typedef long long Int;

void solve(int it) {
	Int n, k;
	cin >> n >> k;
	if (k == 0) {
		if (n >= Int(1e18)) {
			cout << "NO\n";
		} else {
			cout << "YES\n" << 1 << '\n' << n + 1 << '\n';
		}
		return;
	}
	if (k > n) {
		cout << "NO\n";
		return;
	}
	
	vector<Int> ret;
	while (k && n) {
		if (k <= (n + 1) / 2) {
			ret.push_back(n - k + 1);
			ret.push_back(1);
			assert(n - k + 1 > 1);
			k = 0;
			break;
		}	
		if (k > n) {
			cout << "NO\n";
			return;
		}
		Int l = 0, r = n;
		while (l + 1 < r) {
			auto mid = l + (r - l) / 2;
			if (n / mid <= k)
				r = mid;
			else
				l = mid;
		}
		auto m = r;
		l = r, r = n + 1;
		while (l + 1 < r) {
			auto mid = l + (r - l) / 2;
			if (n / mid == n / m)
				l  = mid;
			else {
				assert(n / mid < n / m);
				r = mid;
			}
		}
		m = r - 1;
		debug(n / m, k);
		assert(n / m <= k);
		k -= n / m;
		n %= m;
		ret.push_back(m);
	}
	assert(ret.size() > 0);
	if (k == 0 && ret.size() <= 60) {
		cout << "YES\n";
		cout << ret.size() << "\n";
		for (auto x : ret) cout << x << ' ';
		cout << '\n';
	} else {
		cout << "NO\n";
	}
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(&cout);
    int n; cin >> n;
    for (int i = 0; i < n; ++i) solve(i);
    return 0;
}
