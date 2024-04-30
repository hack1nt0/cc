
#include "debug.h"
#include <cstring>
#include <vector>

const int N = 7, MAX = N * N;
int board[N][N];
int dp[N][N][1 << N][1 << N][1 << 2];

inline int bitat(int d, int b) {
    return d >> b & 1;
}

int bitcount(int S) {
    int ret = 0;
    for (int b = 0; b < N; ++b) ret += bitat(S, b);
    return ret;
}

int rec(int y, int x, int upper, int lower, int two) {
    if (y == N) {
        return 0;
    }
    if (x == N) {
        return rec(y + 1, 0, lower, upper, 0);
    }
    int& ret = dp[y][x][upper][lower][two];
    if (ret >= 0) return ret;
    ret = MAX;
    two = (two << 1) + bitat(upper, x) & 3;
    if (x < 2) {
        if (board[y][x])
            ret = min(ret, 1 + rec(y, x + 1, upper | (1 << x), lower, two));
        ret = min(ret, rec(y, x + 1, upper & ~(1 << x), lower, two));
        return ret;
    }
    bool must = true;
    must &= (board[y - 1][x - 1] ^ bitat(lower, x - 1));
    must &= (board[y - 2][x - 2] ^ bitat(two, 1));
    must &= (board[y - 2][x - 0] ^ bitat(upper, x));
    must &= (board[y - 0][x - 2] ^ bitat(upper, x - 2));
    if (!must || board[y][x] == 0)
        ret = min(ret, rec(y, x + 1, upper & ~(1 << x), lower, two));
    if (board[y][x])
        ret = min(ret, 1 + rec(y, x + 1, upper | (1 << x), lower, two));
    return ret;
}

void solve(int it) {
    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < N; ++j) {
            char c; cin >> c;
            board[i][j] = c == 'B' ? 1 : 0;
        }
    }
    memset(dp, -1, sizeof(dp));
    int ret = MAX;
    for (int i = 0; i < (1 << N); ++i)
        for (int j = 0; j < (1 << N); ++j)
            ret = min(ret, bitcount(i) + bitcount(j) + rec(2, 0, i, j, 0));
    cout << ret << '\n';
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(&cout);
    int n; cin >> n;
    for (int i = 0; i < n; ++i) solve(i);
    return 0;
}
