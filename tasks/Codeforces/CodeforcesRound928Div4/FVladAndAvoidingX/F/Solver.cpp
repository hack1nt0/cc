
#include "debug.h"
#include <cstring>
#include <vector>

const int N = 7;
int dp[N][N][1 << N + 1];
int B[N][N];

typedef bitset<N + 1> bits;

int rec(int x, int y, const bits &S) {
	if (x == N) {
		return rec(0, y + 1, S >> 1);
	}
	if (y == N) {
		return 0;
	}
	int &res = dp[x][y][S.to_ulong()];
	if (res != -1) return res;
	res = N * N;
	bits SS(S);
	if (B[y][x]) {
		bool must = (x >= 2 ? SS[x - 2] : 0) & SS[x];
		if (!must) {
			SS[x] = SS[x] & (x + 2 < N + 1 ? SS[x + 2] : 0);
			res = min(res, rec(x + 1, y, SS));
		}
		debug(x, y, S);
		SS[x] = 0;
		res = min(res, 1 + rec(x + 1, y, SS));
	} else {
		SS[x] = 0;
		res = min(res, rec(x + 1, y, SS));
	}
	return res;
}

void solve(int it) {
	for (int i = 0; i < N; i++)
		for (int j = 0; j < N; j++) {
			char c; cin >> c;
			B[i][j] = c == 'B' ? 1 : 0;
		}
	int ret = N * N;
	for (int i = 0; i < (1 << N); i++)x
		for (int j = 0; j < (1 << N); j++) {
			bits S0(i), S1(j), S;
			for (int x = 0; x < N; x++) {
				if ((B[1][x] ^ S1[x]) 
					&& (x - 2 >= 0 ? B[0][x - 2] ^ S0[x - 2] : 0) 
					&& (x + 2 < N ? B[0][x + 2] ^ S0[x + 2] : 0)
				) 
					S[x] = 1;
			}
			S >>= 1;
			ret = min(ret, int(S0.count() + S1.count() + rec(0, 2, S)));
		}
	cout << ret << '\n';
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(&cout);
    int n; cin >> n;
    for (int i = 0; i < n; ++i) solve(i);
    return 0;
}
