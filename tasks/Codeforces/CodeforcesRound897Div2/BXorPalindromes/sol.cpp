#include "debug.h"

void solve(int it) {
    int n;
    string s;
    cin >> n >> s;
    int l = 0, r = n - 1;
    int must = 0;
    while (l < r) {
        must += s[l] != s[r] ? 1 : 0;
        l++, r--;
    }
    int left = n - must * 2;
    for (int i = 0; i <= n; ++i) {
        int ret = 0;
        if (must <= i && (i - must) <= left && ((i - must) % 2 == 0 || (i - must) % 2 == left % 2)) {
            ret = 1;
        }
        cout << ret;
    }
    cout << endl;
}

int main() {
    int nt; cin >> nt;
    for (int it = 1; it <= nt; ++it) solve(it);
}
