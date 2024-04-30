
#include "debug.h"

void solve(int it) {
	int n;
	cin >> n;
	string s;
	cin >> s;
	
	for (int ret = n; ret > 0; ret--) {
		queue<int> que;
		bool ok = true;
		for (int i = 0; i < n; i++) {
			while (que.size() && i - que.front() >= ret) 
				que.pop();
			if (((s[i] - '0') + que.size()) % 2 == 0) {
				if (i + ret <= n) que.push(i);
				else ok = false;
			}
		}
		if (ok) {
			cout << ret << '\n';
			return;
		}
	}
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(&cout);
    int n; cin >> n;
    for (int i = 0; i < n; ++i) solve(i);
    return 0;
}
