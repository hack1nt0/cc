
#include "debug.h"

void solve(int it) {
	int n, k; cin >> n >> k;
	for (int l = 1; l <= n; l += k) {
		int r = min(n + 1, l + k);
		int mid = l + (r - l) / 2;
		for (int i = mid; i >= l; i--) cout << i << ' ';
		for (int i = r - 1; i >= mid + 1; i--) cout << i << ' ';
	}
	cout << '\n' << (n + k - 1) / k << '\n';
	for (int i = 0, c = 1; i < n; i += k, c++)
		for (int j = i; j < min(n, i + k); j++)
			cout << c << ' ';
	cout << '\n';
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(&cout);
    int n; cin >> n;
    for (int i = 0; i < n; ++i) solve(i);
/*
	auto maxmin = [](int n) -> int {
		vector<int> p(n), pp;
		for (int i = 0; i < n; i++) p[i] = i + 1;
		int min = n * 2;
		do {
			int max = 0;
			for (int i = 0; i < n; i++)
				for (int j = i + 1; j < n; ++j) 
					max = std::max(max, j - i + abs(p[i] - p[j]));
			if (max < min) {
				pp = p;
				min = max;
			}
			//min = std::min(min, max);
		} while (next_permutation(p.begin(), p.end()));
		
		for (auto x : pp) cerr << x << ' ';
		cerr << '\n';
		return min;
	};
	for (int i = 11; i <= 11; i++) {
		cout << i << ": " << maxmin(i) << '\n';
	}
*/
    return 0;
}
