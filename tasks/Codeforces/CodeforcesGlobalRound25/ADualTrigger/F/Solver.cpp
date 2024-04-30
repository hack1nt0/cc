
#include "debug.h"

void solve(int it) {}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(&cout);
    int n; cin >> n;
    for (int i = 0; i < n; ++i) {
		int n;
		string s;
		cin >> n >> s;
		bool ret;
		vector<int> ones;
		for (int i = 0; i < n; i++) if (s[i] == '1')
			ones.push_back(i);
		ret = ones.size() % 2 == 0 && (ones.size() != 2 || ones[0] + 1 != ones[1]);
		cout << (ret ? "YES" : "NO") << '\n';
	}
    return 0;
}
