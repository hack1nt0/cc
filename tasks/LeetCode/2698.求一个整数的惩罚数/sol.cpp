#include "debug.h"
#include <cstring>
#include <string>

using namespace std;

const int MAX_L = 7;
const int MAX_N = 1000;
int dp[MAX_L + 1][MAX_N + 1];

class Solution {
public:
    int punishmentNumber(int N) {
        int ret = 0;
        for (int n = 1; n <= N; ++n) {
            int mul = n * n;
            string mul_str = to_string(mul);
            int l = mul_str.size();
            for (int i = 0; i <= l; ++i) memset(dp[i], 0, sizeof(int) * (n + 1));
                // for (int j = 0; j <= n; ++j) dp[i][j] = 0;
            dp[l][0] = 1;
            for (int i = l - 1; i >= 0; --i) {
                int acc = 0;
                for (int j = i; j < l; ++j) {
                    acc = acc * 10 + mul_str[j] - '0';
                    for (int k = acc; k <= n; ++k) {
                        dp[i][k] |= dp[j + 1][k - acc];
                    }
                }
            }
            if (dp[0][n]) {
                ret += mul;
            }
        }
        return ret;
    }
};

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int n; cin >> n;
    cout << Solution().punishmentNumber(n) << endl;
    return 0;
}
