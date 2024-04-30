
#include "debug.h"

void solve(int it) {
	int n; cin >> n;
	
	int ret = 0;
	int S = n * (n + 1) / 2;
	ret += S * n;
	vector<pair<int,int>> ops;
	int kind = 1;
	for (int r = 1; r <= n; r++) ops.push_back({kind, r});
	
	int remain = n, R = n, C = n;
	kind = 2;
	while (remain && R && C) {
		int remain2 = remain;
		if (kind == 2) {
			int nxtC = 1;
			while (nxtC <= C && remain) {
				int delta = R * (R + 1) / 2 - nxtC * R;
				if (delta < 0) break;
				remain--;
				ret += delta;
				ops.push_back({kind, nxtC});
				nxtC++;
			}
			C = nxtC - 1;
			kind = 1;
		} else {
			int nxtR = 1;
			while (nxtR <= R && remain) {
				int delta = C * (C + 1) / 2 - nxtR * C;
				if (delta < 0) break;
				remain--;
				ret += delta;
				ops.push_back({kind, nxtR});
				nxtR++;
			}
			R = nxtR - 1;
			kind = 2;
		}
		if (remain2 == remain) break;
	}
	
	cout << ret << ' ' << ops.size() << '\n';
	auto one2n = [&](int kind, int idx) {
		cout << kind << ' ' << idx << ' ';
		for (int i = 1; i <= n; i++) cout << i << ' ';
		cout << '\n';
	};
	for (auto &op : ops) one2n(op.first, op.second);
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(&cout);
    int n; cin >> n;
    for (int i = 0; i < n; ++i) solve(i);
    return 0;
}
