
#include "debug.h"
#include "ds/bst.h"
#include <algorithm>
#include <climits>
#include <cstddef>
#include <iostream>
#include <ostream>
#include <ratio>

typedef long long Long;

struct Node {
    Long val, sum;
    Node *chd[2], *fa;
    int height, count, size;
    Node(Long val = 0) : val(val), sum(val), height(0), count(0), size(0) {}

    int operator<=>(const Node &o) const {
        return val == o.val ? 0 : (val > o.val ? 1 : -1);
    }

    void maintain() {
        sum = chd[0]->sum + chd[1]->sum + val * count;
        size = chd[0]->size + chd[1]->size + count;
    }

    friend ostream &operator<<(ostream &o, const Node &node) {
        return o << "val=" << node.val << "<BR/>"
                 << "sum=" << node.sum << "<BR/>"
                 << "count=" << node.count << "<BR/>"
                 << "size=" << node.size << "<BR/>";
    }
};

typedef BaseBst<Node> Bst;

int maxlen(const Bst &bst, Long remain) {
    int ret = 0;
    bst.traverse(
        [&](const Node &root) -> bool {
            if (root.sum <= remain) {
                ret += root.size;
                remain -= root.sum;
                return false;
            }
            return remain > 0;
        },
        [&](const Node &root) -> bool {
            if (remain > 0) {
                ret += min((Long)root.count, remain / root.val);
                remain -= root.val * root.count;
            }
            return remain > 0;
        },
        [&](const Node &root) -> void { ; });
    return ret;
}

void solve(int it) {
    Long N, L;
    cin >> N >> L;
    vector<pair<Long, Long>> msgs(N);
    for (int i = 0; i < N; ++i)
        cin >> msgs[i].first >> msgs[i].second;

    sort(begin(msgs), end(msgs), [](const auto &x, const auto &y) -> bool {
        return x.second != y.second ? x.second < y.second : x.first < y.first;
    });
    int ret = 0;
    for (int l = 0; l < N; ++l) {
        if (L - msgs[l].first >= 0)
            ret = max(ret, 1);
        Bst bst;
        for (int r = l + 1; r < N; ++r) {
            Long remain = L - (msgs[r].second - msgs[l].second + msgs[l].first +
                               msgs[r].first);
            if (remain >= 0) {
                ret = max(ret, 2 + maxlen(bst, remain));
            }
            if (ret == 4) {
                for (int i = l; i <= r; i++) {
                    cerr << msgs[i].first << ' ' << msgs[i].second << endl;
                }
                debug(bst, remain, 2 + maxlen(bst, remain));
            }
            bst.insert(msgs[r].first);
        }
    }
    cout << ret << '\n';
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
