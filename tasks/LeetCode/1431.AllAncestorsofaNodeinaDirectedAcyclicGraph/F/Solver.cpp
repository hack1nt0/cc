
#include "debug.h"

class Solution {
public:
    vector<vector<int>> getAncestors(int n, vector<vector<int>>& edges) {
		vector<set<int>> ret(n);
		vector<vector<int>> ret2(n);
		vector<int> idx(n), rank(n);
		
		vector<vector<int>> adj(n);
		for (auto &e: edges) {
			adj[e[0]].push_back(e[1]);
		}
		debug(adj);
		int c = 0;
		vector<int> color(n, 0);
		auto gettopo = y_combinator([&](auto F, int u) -> void {
			color[u] = 1;
			for (int v: adj[u]) if (!color[v]) F(v);
			rank[u] = c++;
		});
        for (int i = 0; i < n; i++) if (!color[i])
			gettopo(i);
		
		for (int i = 0; i < n; i++) idx[i] = i;
		sort(begin(idx), end(idx), [&](int a, int b) -> bool { return rank[a] > rank[b]; });
		debug(idx);
		for (int u: idx) {
			for (int fa: ret[u])
				ret2[u].push_back(fa);
			ret[u].insert(u);
			for (int v: adj[u]) {
				ret[v].insert(begin(ret[u]), end(ret[u]));
			}
		}
		return ret2;
    }
};


int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(&cout);
	int n, m;
	cin >> n >> m;
	vector<vector<int>> es(m);
	for (int i = 0; i < m; i++) {
		int u, v; cin >> u >> v;
		es[i] = {u, v};
	}
	auto ret = Solution().getAncestors(n, es);
	for (int i = 0; i < n; i++) {
		for (int fa: ret[i]) cout << fa << ' ';
		cout << '\n';
	}
    return 0;
}

