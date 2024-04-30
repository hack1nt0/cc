
#include "debug.h"
#include "graph/maxflow.h"

const int maxn = int(2e3) + 3;
int R[maxn][maxn];


void solve(int it) {
	int n;
	cin >> n;
	vector<vector<int>> adj(n + 1);
	for (int i = 0; i < n - 1; i++) {
	    int u, v;
	    cin >> u >> v;
	    adj[u].push_back(v);
	    adj[v].push_back(u);
	}
	memset(R, -1, sizeof(R));
	auto getR = y_combinator([&](auto F, int u, int fa=0) -> int {
		int &ret = R[u][fa];
		if (ret >= 0) return ret;
		ret = 0;
		for (int v: adj[u]) if (v != fa)
			ret = max(ret, F(v, u) + 1);
		return ret;
	});
	int R = n;
	vector<int> C;
	for (int i = 1; i <= n; i++) {
		int curR = getR(i);
		debug(i, curR);
		if (curR < R) {
			R = curR;
			C.clear();
			C.push_back(i);
		} else if (curR == R) {
			C.push_back(i);
		}
	}
	debug(C.size());
	assert(C.size() <= 2);
	if (C.size() == 1) {
		printf("%d\n", R + 1);
		for (int d = 0; d <= R; d++) printf("%d %d\n", C[0], d);
		return;
	}
	
	int half = R + 1;
	int N = half * 2 + 2, S = N - 2, T = N - 1;
	vector<vector<int>> edges(n + 1);
	auto getedges = y_combinator([&](auto F, int u, int fa, int dist, int prefix) -> void {
		edges[u].push_back(prefix + dist);
		for (auto v: adj[u]) if (v != fa)
			F(v, u, dist + 1, prefix);
	});
	getedges(C[0], 0, 0, 0);
	getedges(C[1], 0, 0, half);
	FlowGraph G(N);
	for (int i = 1; i <= n; i++) {
		auto &e = edges[i];
		assert(e.size() == 2);
		G.addEdge(e[0], e[1], 1);
	}
	for (int i = 0; i < half; i++) {
		G.addEdge(S, i, 1);
		G.addEdge(i + half, T, 1);
	}
	printf("%d\n", G.maxflow(S, T));
	vector<int> vs;
	G.mvc(vs, [=](int v) -> bool { return v < half; });
	for (auto v: vs) printf("%d %d\n", (v < half ? C[0] : C[1]), v % half);
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(&cout);
    int n;
    cin >> n;
    for (int i = 0; i < n; ++i)
        solve(i);
    return 0;
}
