
#include "debug.h"
#include "graph/maxflow.h"

const int MAX = int(1e6);

void solve(int it) {
    int n;
    cin >> n;
    vector<int> pre(n + 1, 1);
    for (int i = 2; i <= n; ++i)
        cin >> pre[i];
    string types(n + 1, 0);
    for (int i = 1; i <= n; ++i)
        cin >> types[i];
    FlowGraph G(n + 2);
    auto make_edges = [&](int s, int t) {
        if (types[s] == 'S' && types[t] != 'S')
            G.addEdge(s, t, 1);
        if (types[s] == 'C' && types[t] != 'S')
            G.addEdge(s, t, 1);
    };
    for (int i = 2; i <= n; ++i) {
        int s = i, t = pre[i];
        make_edges(s, t);
        make_edges(t, s);
    }
    for (int i = 1; i <= n; ++i)
        if (types[i] == 'S')
            G.addEdge(0, i, MAX);
    for (int i = 1; i <= n; ++i)
        if (types[i] == 'P')
            G.addEdge(i, n + 1, MAX);
    cout << G.maxflow(0, n + 1) << '\n';
    debug(G);
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
