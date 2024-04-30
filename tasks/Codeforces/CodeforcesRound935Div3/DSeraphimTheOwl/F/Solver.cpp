
#include "debug.h"

typedef long long Int;
const Int maxc = Int(1e15);

void solve(int it) {
	int n, m; cin >> n >> m;
	vector<int> a(n), b(n);
	for (int i = 0; i < n; i++) cin >> a[i];
	for (int i = 0; i < n; i++) cin >> b[i];
	vector<vector<Int>> dp(n + 1, vector<Int>(2));
	for (int i = 0; i <= n; i++) {
		if (i == 0) {
			dp[i][0] = 0;
			dp[i][1] = -1;
			continue;
		}
		for (int j = 0; j < 2; j++) {
			auto &res = dp[i][j];
			res = maxc;
			if (dp[i - 1][0] >= 0) res = min(res, dp[i - 1][0] + a[i - 1]);
			if (dp[i - 1][1] >= 0) res = min(res, dp[i - 1][1] + b[i - 1]);
		}
		if (i < m) dp[i][0] = 0;
	}
	assert(dp[n][0] == dp[n][1]);
	cout << dp[n][0] << '\n';
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(&cout);
    int n; cin >> n;
    for (int i = 0; i < n; ++i) solve(i);
    return 0;
}
