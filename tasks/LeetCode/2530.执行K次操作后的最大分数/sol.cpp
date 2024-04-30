#include "debug.h"
#include <queue>

using namespace std;

class Solution {
public:
    long long maxKelements(vector<int>& nums, int k) {
        typedef long long LL;
        priority_queue<int> que(nums.begin(), nums.end());
        LL ret = 0;
        for (int i = 0; i < k; ++i) {
            int mx = que.top(); 
            que.pop();
            ret += mx;
            que.push((mx + 2) / 3);
        }
        return ret;
    }
};

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int n, k;
    cin >> n >> k;
    vector<int> nums(n);
    for (int i = 0; i < n; ++i) cin >> nums[i];
    Solution sol;
    cout << sol.maxKelements(nums, k) << endl;
    return 0;
}
