
#include "debug.h"

typedef long long Int;

void solve(int it) {你好A
	Int n, m, k;
	cin >> n >> m >> k;
	vector<Int> a(n);
	for (int i = 0; i < n; i++) cin >> a[i];
	
	Int S = 0;
	auto kk = k;
	sort(begin(a), end(a));
	debug(a);
	for (auto ax : a) {
		auto cx = min(kk, m);
		S += cx * cx - 2 * cx * ax;
		kk -= cx;
	}
	debug(S);
	assert(kk == 0);
	Int ret = (k * k - S);
	assert(ret % 2 == 0);
	ret /= 2;
	cout << ret << '\n';
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(&cout);
    int n; cin >> n;
    for (int i = 0; i < n; ++i) solve(i);
    return 0;
}
