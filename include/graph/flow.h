#ifndef INCLUDED_MAXFLOW_H
#define INCLUDED_MAXFLOW_H
#include "debug.h"
#include <algorithm>
#include <functional>
#include <iomanip>
#include <iostream>
#include <sstream>

struct FlowGraph {
    struct Edge {
        int s, t, cap, reverse;
    };
    vector<vector<int>> adj;
    vector<Edge> edges;
    vector<int> dist;
    vector<int> cure;
    int n, s, t;
    FlowGraph(int n) : adj(n), dist(n), cure(n), n(n) {}
    void addEdge(int s, int t, int cap) {
        int idx = edges.size();
        edges.push_back({s, t, cap, idx + 1});
        edges.push_back({t, s, 0, idx});
        adj[s].push_back(idx);
        adj[t].push_back(idx + 1);
    }
    int maxflow(int s, int t) {
        this->s = s, this->t = t;
        int ret = 0, flow = 0;
        while (bfs(s, t) > 0) {
            fill(cure.begin(), cure.end(), 0);
            while ((flow = dfs(s, t)) > 0) {
                ret += flow;
            }
        }
        return ret;
    }
    int bfs(int s, int t) {
        // for (int& x : levels) x = 0;
        fill(dist.begin(), dist.end(), -1);
        queue<int> que;
        que.push(s);
        dist[s] = 0;
        while (que.size()) {
            int x = que.front();
            que.pop();
            for (int e : adj[x]) {
                int y = edges[e].t;
                if (edges[e].cap > 0 && dist[y] < 0) {
                    dist[y] = dist[x] + 1;
                    que.push(y);
                }
            }
        }
        return dist[t];
    }
    int dfs(int s, int t, int flow = 0) {
        if (s == t)
            return flow;
        while (cure[s] < adj[s].size()) {
            int e = adj[s][cure[s]];
            if (dist[s] < dist[edges[e].t] && edges[e].cap > 0) {
                int nflow = flow;
                if (flow == 0 || flow > edges[e].cap)
                    nflow = edges[e].cap;
                int ret = dfs(edges[e].t, t, nflow);
                if (ret > 0) {
                    edges[e].cap -= ret;
                    edges[edges[e].reverse].cap += ret;
                    return ret;
                }
            }
            cure[s]++;
        }
        return 0;
    }

    // minimum vertex cover
    void mvc(vector<int> &vertexs, const function<bool(int)> &isLeft) {
        for (int i = 0; i < n - 2; i++)
            if (isLeft(i) && dist[i] < 0 || !isLeft(i) && dist[i] >= 0)
                vertexs.push_back(i);
    }

#ifdef DEBUG
    void dot() {
        cerr << "\ndigraph {\n";
        for (int s = 0; s < dist.size(); s++) {
            auto level = dist[s];
            cerr << "    " << s;
            cerr << "[label=<" << s << "<BR/>"
                 << "level=" << level << ">";
            // cerr << ",cchelper_level=" << level;
            cerr << "];\n";
        }
        for (int ie = 0; ie < edges.size(); ie += 2) {
            auto &e = edges[ie];
            cerr << "    " << e.s << "->" << e.t;
            cerr << "[label=<"
                 << "cap=" << e.cap << ">];\n";
        }
        cerr << "\t{rank=source; " << s << ";}\n";
        cerr << "\t{rank=sink; " << t << ";}\n";
        cerr << "\t{rank=same;}\n";
        cerr << "\trankdir=LR;\n";
        cerr << "}\n";
    }
#endif
};
#endif