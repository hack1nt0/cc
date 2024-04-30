
#include "debug.h"

void solve(int it) {}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(&cout);
    int n; cin >> n;
    string s;
    for (int i = 0; i < n; ++i) {
        cin >> s;
        int count = 0;
        for (char c : s) if (c == 'A') count++;
        cout << (count >= 3 ? 'A' : 'B') << '\n';
    }
    return 0;
}
