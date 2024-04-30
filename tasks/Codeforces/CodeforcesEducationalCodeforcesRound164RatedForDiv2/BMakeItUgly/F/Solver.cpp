
#include "debug.h"

void solve(int it) {
	int n;
	cin >> n;
	vector<int> a(n);
	for (int i = 0; i < n; i++) cin >> a[i];
	auto [mi, ma] = minmax_element(begin(a), end(a));
	int ret = n;
	if (*mi == *ma) {
		ret = -1;
	} else {
		int acc = 0;
		for (int i = 0; i < n; i++)
			if (a[i] == a[0]) 
				acc++;
			else {
				ret = min(ret, acc);
				acc = 0;
			}
		assert(acc > 0);
		ret = min(ret, acc);
	}
	cout << ret << '\n';
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(&cout);
    int n; cin >> n;
    for (int i = 0; i < n; ++i) solve(i);
    return 0;
}
