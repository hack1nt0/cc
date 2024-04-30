
#include "debug.h"

void solve() {
	int n; cin >> n;
	vector<int> a(n);
	for (int i = 0; i < n; i++) cin >> a[i];
	
	vector<pair<int,int>> ops;
	while (true) {
		auto aa = a;
		for (int len = n; len > 0; len--) {
			map<int, int> cnt;
			int sum = 0;
			for (int i = 0; i + len <= n; i++) {
				if (i == 0) {
					for (int j = 0; j < len; j++) cnt[a[j]]++, sum += a[j];
				} else {
					if (!--cnt[a[i - 1]]) cnt.erase(a[i - 1]);
					cnt[a[i + len - 1]]++;
					sum -= a[i - 1];
					sum += a[i + len - 1];
				}

				bool type1 = true;
				auto p = begin(cnt);
				for (int k = 0; p != end(cnt) && p->first == k; p++, k++);
				type1 &= p == end(cnt);
				if (type1) {
					int mex = cnt.rbegin()->first + 1;
					if (sum < mex * len) {
						for (int j = i; j < i + len; j++) aa[j] = mex;
						ops.push_back({i, i + len - 1});
						goto here;
					}
				}
				
				bool type2 = true;
				p = begin(cnt);
				for (int k = 1; p != end(cnt) && p->first == k; p++, k++);
				type2 &= p == end(cnt);
				if (type2) {
					auto pmaxv = max_element(begin(cnt), end(cnt), [](const auto &a, const auto &b) -> bool { return a.second < b.second; });
					if (pmaxv->second == 1) {
						int mex = cnt.rbegin()->first;
						if (sum < mex * len) {
							int maxp = i;
							for (int j = i; j < i + len; j++) {
								if (aa[j] > aa[maxp]) maxp = j;
								aa[j] = mex;
							}
							ops.push_back({maxp, maxp});
							ops.push_back({i, i + len - 1});
							goto here;
						}
					} else {
						int mex = cnt.rbegin()->first + 1;
						if (sum < mex * len) {
							int maxp = i;
							for (int j = i; j < i + len; j++) {
								if (aa[j] == pmaxv->first) maxp = j;
								aa[j] = mex;
							}
							ops.push_back({maxp, maxp});
							ops.push_back({i, i + len - 1});
							goto here;
						}
					}
				}
			}
		}
		here: 
		if (aa == a) break;
		a = aa;
	}
	
	int ret = 0;
	for (auto x : a) ret += x;
	cout << ret << ' ' << ops.size() << '\n';
	for (auto x : ops) cout << x.first + 1 << ' ' << x.second + 1 << '\n';
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(&cout);
	solve();
    return 0;
}
