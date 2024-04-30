
#include "debug.h"

const int MAXN = int(1e5) + 4;
int dp[MAXN];

void solve(int it) {
	int n; cin >> n;
	cout << (dp[n] ? "YES" : "NO") << '\n';
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(&cout);
	vector<int> divs;
	auto getdivs = y_combinator([&](auto F, int ib=5, int acc=0) {
		if (ib < 0) {
			divs.push_back(acc);
			return;
		}
		for (int b = 0; b < 2; b++) F(ib - 1, acc * 10 + b);
	});
	getdivs();
	sort(begin(divs), end(divs));
	debug(divs.size());
	memset(dp, 0, sizeof(dp));
	dp[1] = 1;
	for (int n = 2; n < MAXN; n++) {
		int &ret = dp[n];
		int nn = n;
		for (int d : divs) {
			if (d > nn) break;
			if (d > 1 && nn % d == 0)
				ret |= dp[nn / d];
		}
	}
    int n; cin >> n;
    for (int i = 0; i < n; ++i) solve(i);
    return 0;
}
