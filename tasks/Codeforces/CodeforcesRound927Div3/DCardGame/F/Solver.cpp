
#include "debug.h"
#include <algorithm>

void solve(int it) {
    int n;
    cin >> n;
    char trump;
    cin >> trump;
    map<char, vector<char>> count;
    for (int i = 0; i < n * 2; ++i) {
        string card;
        cin >> card;
        char rank = card[0], suit = card[1];
        count[suit].push_back(rank);
    }
    int lefts = 0;
    int trumps = count[trump].size();
    for (auto &[k, v] : count)
        if (k != trump)
            lefts += v.size() % 2;
    if (trumps < lefts || (trumps - lefts) % 2 != 0) {
        cout << "IMPOSSIBLE\n";
        return;
    }
    for (auto &[k, v] : count)
        sort(begin(v), end(v));
    int trump_ptr = 0;
    for (auto &[k, v] : count) {
        if (k != trump) {
            for (int i = 0; i < v.size(); i += 2) {
                cout << v[i] << k << ' ';
                if (i + 1 < v.size()) {
                    cout << v[i + 1] << k << '\n';
                } else {
                    cout << count[trump][trump_ptr++] << trump << '\n';
                }
            }
        }
    }
    while (trump_ptr < count[trump].size()) {
        cout << count[trump][trump_ptr] << trump << ' '
             << count[trump][trump_ptr + 1] << trump << '\n';
        trump_ptr += 2;
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(&cout);
    int n;
    cin >> n;
    for (int i = 0; i < n; ++i)
        solve(i);
    return 0;
}
