
#include "debug.h"
#include <queue>

void solve(int it) {
    int n;
    cin >> n;
    int N = n * 4;
    vector<vector<int>> adj(N);
    auto encode = [=](int x, int y, int k) -> int {
        return ((y * n + x) << 1) + k;
    };
    for (int y = 0; y < 2; y++)
        for (int x = 0; x < n; x++) {
            char c;
            cin >> c;
            {
                int s = encode(x, y, 0);
                for (int dx = -1; dx <= 1; dx++)
                    for (int dy = -1; dy <= 1; dy++)
                        if (abs(dx) + abs(dy) == 1) {
                            int xx = x + dx, yy = y + dy;
                            if (0 <= xx && xx < n && 0 <= yy && yy < 2) {
                                int t = encode(xx, yy, 1);
                                adj[s].push_back(t);
                            }
                        }
            }
            {
                int s = encode(x, y, 1);
                int xx = (c == '<' ? x - 1 : x + 1);
                int yy = y;
                int t = encode(xx, yy, 0);
                adj[s].push_back(t);
            }
        }
    int s = 0, t = encode(n - 1, 1, 0);
    vector<int> color(N, 0);
	// queue<int> que;
	// que.push(s);
    auto visit = y_combinator([&](auto visit, int cur) -> void {
        if (color[cur])
            return;
        color[cur] = -1;
		for (auto nxt : adj[cur])
        	visit(nxt);
        color[cur] = +1;
    });
    visit(s);
    cout << (color[t] ? "YES" : "NO") << '\n';
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
