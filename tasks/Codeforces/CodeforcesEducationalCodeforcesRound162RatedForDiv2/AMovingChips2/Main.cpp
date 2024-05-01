#include <bits/stdc++.h>

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
    int n; cin >> n;
    vector<int> xs(n);
    for (int i = 0; i < n; ++i) cin >> xs[i];
    int l = 0, r = n - 1;
    while (l < n && xs[l] == 0) l++;
    while (r >= 0 && xs[r] == 0) r--;
    int ret = 0;
    for (int i = l; i <= r; ++i) if (xs[i] == 0) ret++;
    cout << ret << '\n';
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(&cout);
    int n; cin >> n;
    for (int i = 0; i < n; ++i) solve(i);
    return 0;
}
