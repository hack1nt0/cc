#include "debug.h"

using namespace std;

using ET = vector<vector<int>>;

class Solution {
public:
    long long countPairs(int n, ET& edges) {
        ET adj(n);
        for (const auto& e : edges) {
            auto u = e[0], v = e[1];
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        vector<int> color(n, -1);
        vector<int> nc(n, 0);
        int c = 0;
        auto dfs = y_combinator([&](auto F, int u) -> bool {
            if (color[u] >= 0) 
                return false;
            color[u] = c;
            nc[c]++;
            for (auto v : adj[u]) F(v);
            return true;
        });
        for (int u = 0; u < n; ++u) if(dfs(u)) c++;
        long long ret = 0, sum = 0;
        for (auto n : nc) sum += n;
        for (auto n : nc) ret += n * (sum - n);
        return ret / 2;
    }
};

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int n, m;
    cin >> n >> m;
    ET es;
    for (int i = 0; i < m; ++i) {
        int a, b; cin >> a >> b;
        es.push_back({a, b});
    }
    Solution sol;
    cout << sol.countPairs(n, es) << endl;
    return 0;
}
