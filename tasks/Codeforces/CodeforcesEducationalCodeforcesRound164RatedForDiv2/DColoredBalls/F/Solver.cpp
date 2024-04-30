
#include "debug.h"
#include "math/modint.h"

typedef ModInt<998244353LL> Long;
const int maxn = 5000 + 3;

Long dp[maxn][maxn];
Long dp[maxn][maxn];

void solve() {
	int n;
	cin >> n;
	vector<int> a(n);
	for (int i = 0; i < n; i++) cin >> a[i];
	
	for (int i = 0; i < maxn; i++) dp[0][i] = 1;
	dp[0][0] = 0;
	for (int i = 1; i <= n; i++) {
		for (int j = 0; j < maxn; j++) {
			auto &res = dp[i][j];
			res = dp[i - 1][j];
			if (a[i - 1] <= j)
				res += dp[i - 1][j - a[i - 1]];
		}
	}
	
	
	
	Long ret = 0;
	for (auto ai : a) {
		ret += dp[n][ai] * ai;
		debug(dp[n][ai]);
	}
	
	
	
	cout << ret << '\n';
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(&cout);
	solve();
    return 0;
}
