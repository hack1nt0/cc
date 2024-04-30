
#include "debug.h"

using Mat = vector<vector<int>>;

class Solution {
public:
    vector<vector<int>> diagonalSort(Mat& mat) {
        vector<pair<int,int>> ss;
        int n = mat.size();
        int m = mat[0].size();
        for (int i = 0; i < n; i++) ss.push_back({i, 0});
        for (int i = 1; i < m; i++) ss.push_back({0, i});
        for (auto s: ss) {
            auto [r, c] = s;
            vector<int> arr;
            while (r < n && c < m) {
                arr.push_back(mat[r][c]);
                r += 1, c += 1;
            }
            sort(begin(arr), end(arr));
            {
                auto [r, c] = s;
                int idx = 0;
                while (r < n && c < m) {
                    mat[r][c] = arr[idx];
                    r += 1, c += 1, idx += 1;
                }
            }
        }
        return mat;
    }
};

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(&cout);
    int n, m; cin >> n >> m;
    Mat mat(n, vector<int>(m));
    for (int i = 0; i < n; i++) for (int j = 0; j < m; j++) cin >> mat[i][j];
    auto ret = Solution().diagonalSort(mat);
    cout << n << ' ' << m << '\n';
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) cout << ret[i][j] << ' ';
        cout << '\n';
    }
    return 0;
}
