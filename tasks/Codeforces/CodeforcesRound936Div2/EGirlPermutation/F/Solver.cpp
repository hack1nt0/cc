
#include "debug.h"
#include "math/modint.h"

typedef ModInt<(long long)(1e9) + 7> Int;

void solve(int it) {
	int n, m1, m2; cin >> n >> m1 >> m2;
	vector<int> pm(m1), sm(m2);
	for (int i = 0; i < m1; i++) cin >> pm[i];
	for (int i = 0; i < m2; i++) cin >> sm[i];
	if (pm[0] != 1 || sm[m2 - 1] != n || pm[m1 - 1] != sm[0]) {
		cout << 0 << '\n';
		return;
	}
	int root = sm[0];
	vector<int> size(n + 1, 0);
	vector<vector<int>> adj(n + 1);
	for (int i = 0; i < m1; i++) {
		size[pm[i]] = 1 + (i > 0 ? size[pm[i - 1]] : 0) + (i + 1 < m1 ? pm[i + 1] : m1) - pm[i] - 1;
		if (i + 1 < m1) adj[pm[i + 1]].push_back(pm[i]);
	}
	for (int i = m2 - 1; i >= 0; i--) {
		size[sm[i]] = 1 + (i + 1 < m2 ? size[sm[i + 1]] : 0) + (sm[i] - (i > 0 ? sm[i - 1] : 0) - 1);
		if (i > 0) adj[sm[i - 1]].push_back(sm[i]);
	}
	vector<Int> fact(n, 1);
	for (int i = 1; i < n; i++) fact[i] = fact[i - 1] * i;
	auto dfs = y_combinator([&](auto F, int u) -> Int {
		assert(size[u] > 0);
		Int res = fact[size[u] - 1];
		for (int v : adj[u]) {
			res *= F(v) / fact[size[v]];
		}
		return res;
	});
	auto ret = dfs(root);
	cout << ret << '\n';
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(&cout);
    int n; cin >> n;
    for (int i = 0; i < n; ++i) solve(i);
    return 0;
}
