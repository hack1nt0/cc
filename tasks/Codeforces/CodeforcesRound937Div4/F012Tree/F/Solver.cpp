#include <complex>
#include <unordered_set>
#include <map>
#include <stack>
#include <limits>
#include <cassert>
#include <functional>
#include <set>
#include <string>
#include <iomanip>
#include <cstring>
#include <iostream>
#include <unordered_map>
#include <list>
#include <vector>
#include <algorithm>
#include <forward_list>
#include <random>
#include <queue>
 
using namespace std;
template <class Fun> class y_combinator_result {
    Fun fun_;
 
  public:
    template <class T>
    explicit y_combinator_result(T &&fun) : fun_(std::forward<T>(fun)) {}
 
    template <class... Args> decltype(auto) operator()(Args &&...args) {
        return fun_(std::ref(*this), std::forward<Args>(args)...);
    }
};
 
template <class Fun> decltype(auto) y_combinator(Fun &&fun) {
    return y_combinator_result<std::decay_t<Fun>>(std::forward<Fun>(fun));
}
 
void solve(int it) {
    int cnt[3];
    cin >> cnt[2] >> cnt[1] >> cnt[0];
    if (cnt[2] + 1 != cnt[0]) {
        printf("-1\n");
        return;
    }
    auto div = [](int a, int b) {
        return (a + b - 1) / b;
    };
    int ret;
    for (int h = 0;; h++) {
        int levels = 1 << h;
        if (cnt[2] == 0) {
            ret = h + div(cnt[1], levels);
            break;
        } else if (cnt[2] < levels) {
            int leafs = cnt[0] - cnt[2] * 2;
            if (cnt[1] <= leafs) {
                ret = h + 1;
            } else {
                ret = h + 1 + div(cnt[1] - leafs, cnt[2] * 2 + leafs);
            }
            break;
        } else {
            cnt[2] -= levels;
            continue;
        }
    }
    printf("%d\n", ret);
}
 
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(&cout);
    int n; cin >> n;
    for (int i = 0; i < n; ++i) solve(i);
    return 0;
}