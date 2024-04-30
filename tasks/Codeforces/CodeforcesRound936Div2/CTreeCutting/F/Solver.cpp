
#include "debug.h"

void solve(int it) {
	int n, k; cin >> n >> k;
	vector<vector<int>> adj(n + 1);
	for (int i = 0; i < n - 1; i++) {
		int u, v; cin >> u >> v;
		adj[u].push_back(v);
		adj[v].push_back(u);
	}
	vector<int> remain(n + 1);
	auto cc = y_combinator([&](auto F, int u, int fa, int minx) -> int {
		int res = 0;
		remain[u] = 1;
		for (int v: adj[u]) if (v != fa) {
			res += F(v, u, minx);
			remain[u] += remain[v];
		}
		if (remain[u] >= minx) {
			remain[u] = 0;
			res++;
		}
		return res;
	});
		
	int xl = 1, xr = n;
	while (xl + 1 < xr) {
		int x = xl + (xr - xl) / 2;
		if (cc(1, 0, x) - 1 >= k) {
			xl = x;
		} else {
			xr = x;
		}
	}
	cout << xl << '\n';
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(&cout);
    int n; cin >> n;
    for (int i = 0; i < n; ++i) solve(i);
    return 0;
}
