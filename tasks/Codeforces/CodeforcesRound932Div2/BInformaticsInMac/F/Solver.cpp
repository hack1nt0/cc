
#include "debug.h"

const int MAXN = int(1e5 + 3);

void solve(int it) {
	int n; cin >> n;
	vector<int> a(n);
	for (int i = 0; i < n; i++) cin >> a[i];
	set<int> st;
	int pmex = 0;
	vector<int> mex(n);
	for (int i = 0; i < n; i++) {
		st.insert(a[i]);
		if (a[i] == pmex) {
			while (st.contains(pmex)) pmex++;
		}
		mex[i] = pmex;
	}
	pmex = 0;
	st.clear();
	for (int i = n - 1; i > 0; --i) {
		st.insert(a[i]);
		if (a[i] == pmex) {
			while (st.contains(pmex)) pmex++;
		}
		if (pmex == mex[i - 1]) {
			printf("%d\n%d %d\n%d %d\n", 2, 1, i, i + 1, n);
			return;
		}
	}
	cout << -1 << '\n';
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(&cout);
    int n; cin >> n;
    for (int i = 0; i < n; ++i) solve(i);
    return 0;
}
