#include "debug.h"
#include <algorithm>

using namespace std;

const int MAX = int(1e5) + 10;
int que[MAX];

class Solution {
public:
    vector<int> minReverseOperations(int n, int p, vector<int>& banned, int k) {
        vector<int> dist(n, MAX);
        unordered_set<int> sts[2];
        dist[p] = 0;
        for (auto x : banned) dist[x] = -1;
        for (int i = 0 ; i < n; ++i) if (dist[i] > 0) sts[i & 1].insert(i);
        int pq = 0, qq = 0;
        que[qq++] = p;
        auto valid = y_combinator([&](auto F, int u, int v) -> bool {
            auto [mi, mx] = minmax(u, v);
            int margin = k - (mx - mi + 1);
            return (margin & 1) == 0 && 0 <= mi - (margin >> 1) && mx + (margin >> 1) < n;
        });
        auto update = y_combinator([&](auto F, int u, int v) -> void {
            if (dist[u] + 1 < dist[v]) {
                dist[v] = dist[u] + 1;
                que[qq++] = v;
            }
        });
        while (pq < qq) {
            int u = que[pq++];
            int alb = max(0, u - k + 1);
            int arb = min(n - 1, u + k - 1);
            int vlb = alb + k - 1 + alb - u;
            int vrb = arb - k + 1 + arb - u;
            auto& st = sts[vlb & 1];
            for (int v = vlb;; v += 2) {
                auto pv = st.find(v);
                // auto pv = st.lower_bound(v);
                if (!(pv != st.end() && *pv <= vrb)) break;
                v = *pv;
                dist[v] = dist[u] + 1;
                que[qq++] = v;
                st.erase(pv);
            }
        }
        for (auto& x : dist) if (x == MAX) x = -1;
        return dist;
    }
};

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int n, p, nb, k;
    cin >> n >> p >> nb >> k;
    vector<int> banned(nb);
    for (int i = 0; i < nb; ++i) cin >> banned[i];
    Solution sol;
    for (auto x : sol.minReverseOperations(n, p, banned, k)) cout << x << ' ';
    cout << endl;
    return 0;
}
