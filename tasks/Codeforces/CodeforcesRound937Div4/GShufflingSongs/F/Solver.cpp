
#include "debug.h"

struct Song {
	string g, w;
	
	bool operator==(const Song &o) {
		return g == o.g || w == o.w;
	}
};

const int maxn = 16;
int dist[1 << maxn][maxn];
int adj[maxn][maxn];

void solve(int it) {
	int n; cin >> n;
	vector<Song> songs(n);
	for (int i = 0; i < n; i++) cin >> songs[i].g >> songs[i].w;
	for (int i = 0; i < n; i++)
		for (int j = 0; j < n; j++) adj[i][j] = i == j ? 0 : (songs[i] == songs[j] ? 1 : 0);
	memset(dist, -1, sizeof(dist));
	memset(dist[0], 0, sizeof(dist[0]));
	int maxpath = 0;
	for (int s = 1; s < (1 << n); s++)
		for (int i = 0; i < n; i++) if ((s >> i & 1) == 0) {
			int &cur = dist[s][i];
			for (int b = 0; b < n; b++) if ((s >> b & 1) && adj[i][b]) {
				int nxt = dist[s ^ (1 << b)][b];
				if (nxt != -1) cur = max(cur, nxt + 1);
			}
			maxpath = max(maxpath, cur);
		}
	assert(0 <= maxpath && maxpath < n);
	int ret = n - (maxpath + 1);
	cout << ret << '\n';
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(&cout);
    int n; cin >> n;
    for (int i = 0; i < n; ++i) solve(i);
    return 0;
}
