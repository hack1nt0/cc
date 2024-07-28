#ifndef INCLUDED_SCC_H
#define INCLUDED_SCC_H

#include "ycomb.h"

struct SccGraph {
    int n;
    vector<vector<int>> adj;
    vector<int> scc;
    vector<int> lowest;
    vector<int> preorder;

    SccGraph(int n): n(n), adj(n), scc(n, -1), lowest(n, -1), preorder(n, -1) {} 
    
    void addEdge(int u, int v) {
        adj[u].push_back(v);
    }

    void decompose() {
        int nodeN = 0;
        int sccN = 0;
        stack<int> stk;
        auto dfs = y_combinator([&](auto dfs, int u) -> void {
            preorder[u] = lowest[u] = nodeN++;
            stk.push(u);
            for (auto v: adj[u])
                if (preorder[v] == -1) {
                    dfs(v);
                    lowest[u] = min(lowest[u], lowest[v]);
                } else if (scc[v] == -1) {
                    lowest[u] = min(lowest[u], preorder[v]);
                }
            if (preorder[u] == lowest[u]) {
                while (stk.size()) {
                    auto v = stk.top();
                    stk.pop();
                    scc[v] = sccN;
                    if (v == u) break;
                }
                sccN++;
            }
        });
        for (int i = 0; i < n; ++i) if (preorder[i] == -1) {
            dfs(i);
        }
        for (int i = 0; i < n; ++i) assert(scc[i] >= 0 && scc[i] < n);
    }

};

/*
 * n: count of variables, despite +/-
 */
struct TwoSatGraph: private SccGraph {
    
    TwoSatGraph(int n): SccGraph(n * 2), n(n), _truth(n) {}

    int encode(int u) const {
        return u < 0 ? (-u - 1) * 2 + 1 : (u - 1) * 2;
    }

    void addClause(int x, int y) {
        assert(-n <= x && x <= n && x);
        assert(-n <= y && y <= n && y);
        addEdge(encode(-x), encode(y));
        addEdge(encode(-y), encode(x));
    }

    bool sat() {
        decompose();
        for (int x = 1; x <= n; ++x) {
            int cmp = scc[encode(x)] - scc[encode(-x)]; 
            if (cmp == 0) return false;
            else _truth[x - 1] = cmp < 0;
        }
        return true;
    }

    bool truth(int x) {
        assert(-n <= x && x <= n && x);
        return x > 0 ? _truth[x - 1] : -_truth[-x - 1];
    }

private:
    int n;
    vector<int> _truth;
};

#endif
