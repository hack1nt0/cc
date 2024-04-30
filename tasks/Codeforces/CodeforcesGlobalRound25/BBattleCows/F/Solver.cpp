
#include "debug.h"

void solve(int it) {
	int n, k; cin >> n >> k;
	vector<int> rates(n + 1);
	for (int i = 1; i <= n; i++) cin >> rates[i];
	
	int ret = 0;
	auto getm = [&](int p) -> int {
		int iw = 1, wins = 0;
		for (int i = 2; i <= n; i++) {
			if (rates[i] > rates[iw])
				iw = i;
			wins += iw == p;
		}
		return wins;
	};
	vector<int> igs;
	for (int i = 1; i < k; i++) if (rates[i] > rates[k])
		igs.push_back(i);
		
	swap(rates[1], rates[k]);
	ret = max(ret, getm(1));
	swap(rates[1], rates[k]);
	
	if (igs.size()) {
		swap(rates[igs[0]], rates[k]);
		debug(rates);
		ret = max(ret, getm(igs[0]));
		swap(rates[igs[0]], rates[k]);
		debug(rates);
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
