
#include "debug.h"

typedef long long Long;

void solve(int it) {
    int n; cin >> n;
    vector<Long> a(n), psum(n), rsum(n), lb(n), rb(n);
    for (int i = 0; i < n; ++i) cin >> a[i];
    for (int i = 0, b = 0; i < n; ++i) {
        psum[i] = a[i] + (i - 1 >= 0 ? psum[i - 1] : 0);
        if (a[i] != a[b]) b = i;
        lb[i] = b;
    }
    for (int i = n - 1, b = n - 1; i >= 0; --i) {
        rsum[i] = a[i] + (i + 1 < n ? rsum[i + 1] : 0);
        if (a[i] != a[b]) b = i;
        rb[i] = b;
    }
    for (int i = 0; i < n; ++i) {
        int ret = n;
        {
        int l = -1, r = i - 1 >= 0 ? lb[i - 1] : -1;
        while (l + 1 < r) {
            int mid = l + (r - l) / 2;
            if (rsum[mid] - rsum[i] > a[i]) l = mid;
            else r = mid;
        }
        if (l != -1) ret = min(ret, i - l);
        }
        {
        int l = i + 1 < n ? rb[i + 1] : n, r = n;
        while (l + 1 < r) {
            int mid = l + (r - l) / 2;
            if (psum[mid] - psum[i] > a[i]) r = mid;
            else l = mid;
        }
        if (r != n) ret = min(ret, r - i);
        }
        if (i - 1 >= 0 && a[i - 1] > a[i] || i + 1 < n && a[i] < a[i + 1]) ret = 1;
        cout << (ret == n ? -1 : ret) << ' ';
    }
    cout << '\n';
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(&cout);
    int n; cin >> n;
    for (int i = 0; i < n; ++i) solve(i);
    return 0;
}
