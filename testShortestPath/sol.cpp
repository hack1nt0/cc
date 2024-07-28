#include "graph/shortestpath.h"

int main() {
    int n, m, s;
    cin >> n >> m >> s;
    G<int> g(n);
    vector<int> dist(n), pre(n);
    for (int i = 0;i < m; ++i) {
        int u, v, w;
        cin >> u >> v >> w;
        g.adde({u, v, w});
    }

    if (bellmanford(g, s, dist, pre)) {
        for (int u = 0; u < n; u++) cout << s << " -> " << u << ": " << dist[u] << endl;
    } else {
        cout << "Negative cycle exists" << endl;
    }

    return 0;
}
