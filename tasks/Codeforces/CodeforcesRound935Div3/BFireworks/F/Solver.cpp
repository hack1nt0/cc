
#include "debug.h"

typedef long long Int;

void solve(int it) {
	Int a, b, m;
	cin >> a >> b >> m;
	auto ret = m / a + 1;
	ret += m / b + 1;
	cout << ret << '\n';
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(&cout);
    int n; cin >> n;
    for (int i = 0; i < n; ++i) solve(i);
    return 0;
}
