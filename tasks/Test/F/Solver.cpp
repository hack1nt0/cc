
#include "debug.h"
#include "math/modint.h"

typedef ModInt<998244353LL> Long;


int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(&cout);
	int n; cin >> n;
	Long x{1};
	for (int i = 1; i <= n; i++) solve(i);
    return 0;
}
