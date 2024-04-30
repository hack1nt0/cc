#include "debug.h"
#include <iostream>

template <typename T>
void W(T t) {
	cout << t << '\n';
}

void solve(int it) {
	int n;
	cin >> n;
    cerr << "J" << endl;
	vector<int> S(n);
	for (int i = 0; i < n; ++i) {
        cin >> S[i];
        cerr << i << endl;
    }

    cout << n << ' ';
    // cout << n << endl;
	for (int i = 0; i < n; ++i) cout << S[i] << ' ';
    cout << endl << flush;

    set<int> ST;
	for (int i = 0; i < n; ++i) ST.insert(S[i]);
    int nq = 0;
    while (1) {
        int Q; cin >> Q;
        if (ST.contains(Q)) {
            W(-2);
            // cout << -2 << endl;
            exit(1);
        }
        if (nq >= n) {
            W(-1);
            // cout << -1 << endl;
            return;
        }
        ST.insert(Q);
        int A = -1;
        for (auto s: ST) {
            if (s < Q) {
                A = s;
                break;
            }
        }
        W(A);
        // cout << A << endl;
        if (A == -1) return;
        nq++;
    };
}

int main() {
    int nt; cin >> nt;

    W(nt);
    cerr << "J" << endl;

    for (int it = 1; it <= nt; ++it) solve(it);
    return 0;
}