#include "ds/rangetree.h"

struct Node {
    typedef int value_type;
    int l, r;
    int min;
    int acc;
};

struct RangeTree : BaseRangeTree<Node> {

    RangeTree(const vector<int> &xs) {
        init(
            0, xs.size(),
            [&](int i, int ii) {
                nodes[i].min = xs[ii];
                nodes[i].acc = 0;
            },
            [&](int i) {
                nodes[i].min = min(nodes[lc(i)].min, nodes[rc(i)].min);
                nodes[i].acc = 0;
            });
    }

    int qry_min(int l, int r) {
        return qry(
            l, r, []() { return numeric_limits<int>::max(); },
            [&](int i) { return nodes[i].min; },
            [&](int i) {
                nodes[lc(i)].acc += nodes[i].acc;
                nodes[lc(i)].min += nodes[i].acc;
                nodes[rc(i)].acc += nodes[i].acc;
                nodes[rc(i)].min += nodes[i].acc;
                nodes[i].acc = 0;
            },
            [&](int i, int lR, int rR) { return min(lR, rR); });
    }
    // void qry_preq(int s, int t) { ; }

    void upd_add(int l, int r, int w) {
        upd(
            l, r,
            [&](int i) {
                nodes[i].acc += w;
                nodes[i].min += w;
            },
            [&](int i) {
                nodes[lc(i)].acc += nodes[i].acc;
                nodes[lc(i)].min += nodes[i].acc;
                nodes[rc(i)].acc += nodes[i].acc;
                nodes[rc(i)].min += nodes[i].acc;
                nodes[i].acc = 0;
            },
            [&](int i) {
                nodes[i].min = min(nodes[lc(i)].min, nodes[rc(i)].min);
            });
    }
};

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int n, m;
    cin >> n >> m;
    vector<int> xs(n);
    for (int i = 0; i < n; ++i)
        cin >> xs[i];

    RangeTree tree(xs);

    for (int i = 0; i < m; ++i) {
        string kind, op;
        int l, r, w;
        cin >> kind >> op >> l >> r;
        if (kind == "Q") {
            if (op == "MIN") {
                // tree.qry_min(l, r);
                cout << tree.qry_min(l, r) << '\n';
            }
        } else {
            cin >> w;
            if (op == "ADD") {
                tree.upd_add(l, r, w);
            }
        }
        // cerr << "S D " << i << '\n';
    }
    return 0;
}