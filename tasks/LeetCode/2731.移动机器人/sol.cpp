#include "math/modint.h"

typedef long long LL;
const LL MOD = LL(1e9) + 7LL;
typedef ModInt<MOD> MI;

class Solution {
public:
    int sumDistance(vector<int>& nums, string s, int d) {
        int n = nums.size();
        vector<LL> xs(n);
        vector<MI> psum(n);
        for (int i = 0; i < n; ++i) {
            xs[i] = LL(nums[i]) + d * (s[i] == 'L' ? -1 : +1);
        }
        sort(xs.begin(), xs.end());
        
        auto ret = binsol(xs, 0, n, psum);
        ret /= 2;
        return int(ret.val);
    }

    MI binsol(const vector<LL>& xs, int l, int r, vector<MI>& psum) {
        if (r - l <= 1) return 0;
        int m = l + (r - l) / 2;
        MI lr = binsol(xs, l, m, psum);
        MI rr = binsol(xs, m, r, psum);
        MI lacc = 0;
        MI racc = 0;
        MI ret = lr + rr;

        psum[m] = 0;
        for (int i = m - 1; i >= l; --i) {
            psum[i] = psum[i + 1] + xs[i + 1] - xs[i];
            lacc += psum[i];
        }
        for (int i = m + 1; i < r; ++i) {
            psum[i] = psum[i - 1] + xs[i] - xs[i - 1];
            racc += psum[i];
        }
        for (int i = l; i < m; ++i) {
            ret += psum[i] * (r - m) + racc;
        }
        // for (int i = m; i < r; ++i) {
        //     ret += psum[i] * (m - l) + lacc;
        // }
        return ret;
    }
};

int main() {
    // cout << (-MOD-1) % MOD << endl;

    int n; cin >> n;
    vector<int> nums(n);
    for (int i = 0; i < n; ++i) cin >> nums[i];
    string s; cin >> s;
    int d; cin >> d;

    Solution sol;
    cout << sol.sumDistance(nums, s, d) << endl;

    return 0;
}