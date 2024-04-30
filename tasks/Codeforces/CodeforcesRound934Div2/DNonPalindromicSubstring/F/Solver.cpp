
#include "debug.h"

typedef long long Long;

void manacher(const string &s, vector<int> &maximal) {
	maximal[0] = 0;
	int idx = 0;
	for (int r = 1; r < s.size(); r++) {
		maximal[r] = 0;
		if (r < idx + maximal[idx]) {
			int l = idx * 2 - r;
			maximal[r] = min({maximal[l], idx + maximal[idx] - l, l - idx + maximal[idx]});
		}
		while (true) {
			int p = r - maximal[r], q = r + maximal[r];
			if (0 <= p && q < s.size() && s[p] == s[q]) {
				maximal[r]++;
			} else {
				maximal[r]--;
				break;
			}
		}
		if (r + maximal[r] > idx + maximal[idx]) idx = r;
	}
}

void solve(int it) {
	int n, q; cin >> n >> q;
	string s; cin >> s;
	vector<vector<int>> srm(2, vector<int>(n));
	srm[0][n - 1] = n - 1;	
	for (int i = n - 2; i >= 0; i--) srm[0][i] = s[i] == s[i + 1] ? srm[0][i + 1] : i;
	srm[1][n - 1] = n - 1, srm[1][n - 2] = n - 2;
	for (int i = n - 3; i >= 0; i--) srm[1][i] = s[i] == s[i + 2] ? srm[1][i + 2] : i;
	string ss(n * 2, '$');
	vector<int> maxspan(n * 2, 0);
	for (int i = 0; i < n; i++) ss[i * 2] = s[i];
	manacher(ss, maxspan);
	auto palindromic = [&](int l, int r) {
		int ll = l * 2, rr = r * 2, mid = (ll + rr) / 2;
		return maxspan[mid] >= (rr - ll) / 2;
	};
	auto sum = [](Long s, Long t) {
		return s <= t ? (s + t) * ((t - s) / 2 + 1) / 2 : 0;
	};
	for (int iq = 0; iq < q; iq++) {
		Long ret = 0;
		int l, r; cin >> l >> r;
		l--, r--;
		int len = r - l + 1;
		if (!palindromic(l, r)) ret += len;
		len--;
		if (!(srm[0][l] >= r)) ret += sum(2, len % 2 ? len - 1 : len);
		if (!(min(srm[1][l], srm[1][l + 1]) + 1 >= r)) ret += sum(3, len % 2 ? len : len - 1);
		cout << ret << '\n';
	}
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(&cout);
    int n; cin >> n;
    for (int i = 0; i < n; ++i) solve(i);
    return 0;
}
