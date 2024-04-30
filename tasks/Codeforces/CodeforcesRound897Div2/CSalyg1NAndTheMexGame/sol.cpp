#include "debug.h"

template <typename T>
void W(T t) {
	cout << t << '\n';
}

void solve(int it) {
	int n;
	cin >> n;
	cerr << "HI" << endl;
	vector<int> S(n);
	for (int i = 0; i < n; ++i) cin >> S[i];
	cerr << "HI" << endl;
	sort(S.begin(), S.end());
	int Q = n;
	for (int i = 0; i < n; ++i) {
		if (S[i] != i) {
			Q = i;
			break;
		}
	}
	while (1) {
		W(Q);
		// cout << Q << endl;
		int A; cin >> A;
		if (A == -2) {
			exit(0);
		}
		if (A == -1) return;
		Q = A;
	}
}

int main() {
    int nt; cin >> nt;
	cerr << "HI" << endl;
    for (int it = 1; it <= nt; ++it) solve(it);
	return 0;
}
