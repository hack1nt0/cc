#include "graph/mst.h"

int main() {
    int n, m, s;
    cin >> n >> m >> s;
    vector<int> father(n * 2);
    vector<int> color(n * 2);
    G<int> g(n);
    for (int i = 0; i < m; ++i) {
        int u, v, w;
        cin >> u >> v >> w;
        g.adde({u, v, w});
    }

    for (auto e: directed_mst(g, s, father, color)) if (e) {
        cout << e->s << " -> " << e->t << ": " << e->w << endl;
    }

    return 0;
}