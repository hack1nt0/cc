
#include "debug.h"
#include "graph/maxflow.h"

void solve(int it) {
    int n;
    cin >> n;
    vector<vector<int>> adj(n);
    for (int i = 0; i < n - 1; i++) {
        int u, v;
        cin >> u >> v, u--, v--;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    if (n == 1) {
        cout << 1 << ' ' << 0 << '\n';
        return;
    }
    vector<int> radius(n, 0);
    vector<vector<int>> maxdist(n, vector<int>(n, -1));
    auto rec = y_combinator([&](auto rec, int root, int fa) -> int {
        int &ret = maxdist[root][fa];
        if (ret >= 0)
            return ret;
        ret = 0;
        for (auto chd : adj[root])
            if (chd != fa)
                ret = max(ret, rec(chd, root) + 1);
        return ret;
    });
    for (int i = 0; i < n; i++)
        for (int j : adj[i]) {
            radius[i] = max(radius[i], rec(j, i) + 1);
        }
    vector<int> order(n);
    for (int i = 0; i < n; i++)
        order[i] = i;
    sort(order.begin(), order.end(),
         [&](int a, int b) -> bool { return radius[a] < radius[b]; });
    if (radius[order[0]] != radius[order[1]]) {
        int center = order[0];
        int ret = radius[center] + 1;
        printf("%d\n", ret);
        for (int i = 0; i < ret; i++)
            printf("%d %d\n", center + 1, i);
    } else {
        int N = (radius[order[0]] + 1) * 2;
        FlowGraph G(N + 2);
        vector<vector<int>> edges(n);
        auto dfs = y_combinator(
            [&](auto dfs, int root, int fa, int dist, int prefix) -> void {
                int u = prefix + dist;
                for (auto chd : adj[root])
                    if (chd != fa) {
                        edges[chd].push_back(u);
                        dfs(chd, root, dist + 1, prefix);
                    }
            });
        dfs(order[0], order[0], 0, 0);
        dfs(order[1], order[1], 0, N / 2);
        for (int i = 0; i < n; i++)
            G.addEdge(edges[i][0], edges[i][1], 1);
        printf("%d\n", G.maxflow(N, N + 1));
        vector<int> vertexs;
        G.mvc(vertexs, [=](int i) { return i < N / 2; });
        for (auto v : vertexs) {
            printf("%d %d\n", v < N / 2 ? order[0] : order[1], v % (N / 2));
        }
    }
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
