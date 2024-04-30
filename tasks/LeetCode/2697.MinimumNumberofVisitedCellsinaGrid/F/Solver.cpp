
#include "debug.h"


class Solution {
	struct Node {
		int idx, dist;
		bool operator<(const Node &o) const {
			return idx > o.idx;
			//return dist != o.dist ? dist > o.dist : idx > o.idx;
		}
	};
public:
    int minimumVisitedCells(vector<vector<int>>& grid) {
		int n = grid.size(), m = grid[0].size();
		int maxd = n * m + 3;
		vector<int> dist(n * m, maxd);
		vector<int> colmax(m, 0), rowmax(n, 0);
		priority_queue<int, vector<int>, greater<int>> Q;
		Q.push(0);
		dist[00] = 1;
		while (Q.size()) {
			auto idx = Q.top();
			int row = idx / m, col = idx % m;
			if (row == n - 1 && col == m - 1) {
				return dist[idx];
			}
			Q.pop();
			int val = grid[row][col];
			{
				int lb = max(col, rowmax[row]) + 1;
				int rb = min(m - 1, col + val);
				for (int i = lb; i <= rb; i++) {
					int nxt = row * m + i;
					if (dist[nxt] == maxd) Q.push(nxt);
					dist[nxt] = min(dist[nxt], dist[idx] + 1);
				}
				rowmax[row] = max(rowmax[row], rb);
			}
			{
				int lb = max(row, colmax[col]) + 1;
				int rb = min(n - 1, row + val);
				for (int i = lb; i <= rb; i++) {
					int nxt = i * m + col;
					if (dist[nxt] == maxd) Q.push(nxt);
					dist[nxt] = min(dist[nxt], dist[idx] + 1);
				}
				colmax[col] = max(colmax[col], rb);
			}
			
			debug(row, col, dist, rowmax[row], colmax[col]);
		}
		return dist[n * m - 1] != maxd ? dist[n * m - 1] : -1;
    }
};

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(&cout);
    int n, m; cin >> n >> m;
	vector<vector<int>> G(n, vector<int>(m));
	for (int i = 0; i < n; i++)
		for (int j = 0; j < m; j++) cin >> G[i][j];
	cout << Solution().minimumVisitedCells(G) << '\n';
    return 0;
}