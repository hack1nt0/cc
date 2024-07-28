#include "debug.h"
#include <algorithm>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int n; cin >> n;
    vector<int> xs(n);
    for (int i = 0; i < n; ++i) cin >> xs[i];
    do {
        for (auto x : xs) cout << x << ' ';
        cout << endl;
    } while (next_permutation(begin(xs), end(xs)));
    return 0;
}
