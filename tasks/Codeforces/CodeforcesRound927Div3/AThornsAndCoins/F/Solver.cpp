
#include "debug.h"

void solve(int it) {
    int len;
    string line;
    cin >> len >> line;
    char pre = ' ';
    int ret = 0;
    for (char c : line) {
        if (c == '@') {
            ret++;
        }
        if (c == '*') {
            if (pre == c) break;
        }
        pre = c;
    }
    cout << ret << '\n';
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(&cout);
    int n; cin >> n;
    for (int i = 0; i < n; ++i) {
        solve(i);
    }
    return 0;
}
