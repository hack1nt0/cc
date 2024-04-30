
#include "debug.h"
#include "math/modint.h"

typedef long long Long;
typedef ModInt<Long(1e9)+7> Int;

void solve(int it) {
	int n, k; cin >> n >> k;
	vector<int> xs(n);
	for (int i = 0; i < n; i++) cin >> xs[i];
	Long min = 0, max = 0, sum = 0;
	for (int i = 0; i < n; i++) {
		sum += xs[i];
		max = std::max(max, sum - min);
		min = std::min(min, sum);
	}
	Int remain = sum - max;
	Int ret = Int(max) * pow(Int(2), k) + remain;
	cout << ret << '\n';
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(&cout);
    int n; cin >> n;
    for (int i = 0; i < n; ++i) solve(i);
    return 0;
}
