#include "debug.h"
#include <unordered_map>

using namespace std;

class Solution {
public:
    int tupleSameProduct(vector<int>& nums) {
        unordered_map<int, int> mp;
        int n = nums.size();
        for (int i = 0; i < n; ++i)
            for (int j = i + 1; j < n; ++j) mp[nums[i] * nums[j]]++;
        long long ret = 0;
        for (auto [k, v] : mp) {
            ret += v * (v - 1) / 2;
        }
        ret *= 8;
        return ret;
    }
};

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    Solution sol;
    int n; cin >> n;
    vector<int> nums(n);
    for (int i = 0; i < n; ++i) cin >> nums[i];
    cout << sol.tupleSameProduct(nums) << endl;
    return 0;
}
