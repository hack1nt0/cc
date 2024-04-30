
#include "debug.h"

void solve(int it) {
	string s; cin >> s;
	string ss;
	for (char c : s) ss.push_back(c), ss.push_back(' ');
	
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(&cout);
    int n; cin >> n;
    for (int i = 0; i < n; ++i) solve(i);
    return 0;
}
