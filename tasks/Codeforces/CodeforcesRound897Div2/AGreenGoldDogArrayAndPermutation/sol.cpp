#include <debug.h>
// #include <functional>

void solve(int it) {
    /*
    dfsdf
    */
    // cout << "E" << endl;
    int n; cin >> n;
    set<int> st;
    vector<int> a(n), b(n);
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
        b[i] = i + 1;
    }
    sort(b.begin(), b.end(), [&a](int i, int j) -> bool {
        return a[i - 1] > a[j - 1];
    });
    cout << b << endl;
}

int main() {
    int nt; cin >> nt;
    for (int it = 1; it <= nt; ++it) solve(it);
    return 0;
}
