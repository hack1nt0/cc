
#include "debug.h"
#include "ds/rangetree.h"
#include "math/modint.h"
#include <ostream>

typedef ModInt<998244353LL> Long;

struct Node {
    Node *chds[2];
    int bounds[2];
    int g, s;
    Node() : chds{nullptr, nullptr} {}
    void pushdown() {}
    void maintain() {
        g = chds[0]->g + chds[1]->g;
        s = chds[0]->s + chds[1]->s;
    }
    friend ostream &operator<<(ostream &out, const Node &obj) {
        return out << '[' << obj.g << ',' << obj.s << ']';
    }
};

typedef RangeTree<Node> rangetree;

void solve(int it) {
    int n, q;
    cin >> n >> q;
    vector<int> cg(n), cs(n);
    int totg = 0, tots = 0;
    for (int i = 0; i < n; i++)
        cin >> cg[i], totg += cg[i];
    for (int i = 0; i < n; i++)
        cin >> cs[i], tots += cs[i];
    vector<Long> comb(tots + 1, 1), psum(tots + 2, 0);
    for (int i = 1; i < tots + 1; i++) {
        comb[i] = comb[i - 1] * (tots - i + 1) / i;
    }
    for (int i = 1; i < tots + 2; i++) {
        psum[i] = comb[i - 1] + psum[i - 1];
    }
    rangetree tree(0, n, [&](Node *root, int idx) -> void {
        root->g = cg[idx];
        root->s = cs[idx];
    });
    // tree.dot();
    int a, b;
    auto Q = [&](Node *root) -> void {
        a += root->g;
        b += root->s;
    };
    for (int i = 0; i < q; i++) {
        int l, r;
        cin >> l >> r, l--, r;
        a = b = 0;
        tree.query(l, r, Q);
        int rk = clamp(a + b - (totg - a), 0, tots + 1);
        cout << psum[rk] / pow(Long(2), tots) << '\n';
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(&cout);
    solve(0);
    return 0;
}
