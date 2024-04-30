#include "debug.h"

using namespace std;

class Solution {
public:
    int maxSatisfaction(vector<int>& satisfaction) {
        vector<int> sat = satisfaction;
        sort(begin(sat), end(sat));
        int ret = 0;
        int n = sat.size();
        for (int i = 0; i < n; ++i) {
            int cur = 0;
            for (int j = i; j < n; ++j) cur += sat[j] * (j - i + 1);
            ret = max(ret, cur);
        }
        return ret;
    }
};

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int n; cin >> n;
    vector<int> xs(n);
    for (int i = 0; i < n; ++i) cin >> xs[i];
    cout << Solution().maxSatisfaction(xs) << endl;
    return 0;
}
