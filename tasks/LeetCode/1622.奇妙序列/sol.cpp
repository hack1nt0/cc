#include "debug.h"
#include "ds/rangetree.h"
#include "math/modint.h"

using LL = long long;
const LL MOD = 1e9 + 7;
const LL MAXL = 1e5 + 3;
using MI = ModInt<MOD>;

struct Node {
    typedef MI value_type;
    int l, r;
    MI mul = 1;
    MI sum = 0;
};

class Fancy : public BaseRangeTree<Node> {
  public:
    vector<LL> app_add;
    vector<LL> app;
    vector<int> index;

    Fancy() : app_add(), app(), index() {
        init(
            0, MAXL, [](int i, int ii) {}, [](int i) {});
    }

    void append(int val) {
        app.push_back(val);
        app_add.push_back(0);
        index.push_back(app_add.size() - 1);
    }

    void addAll(int inc) {
        app_add.push_back(inc);
        change_point(app_add.size() - 1, inc);
    }

    void change_point(int p, int v) {
        upd(
            p, p + 1,
            [&](int i) { 
                nodes[i].sum = v;
            },
            [&](int i) {
                // nodes[lc(i)].mul *= nodes[i].mul; 
                // nodes[rc(i)].mul *= nodes[i].mul; 
                // nodes[i].mul = 1; 
            },
            [&](int i) {
                nodes[i].sum = nodes[lc(i)].sum * nodes[lc(i)].mul + nodes[rc(i)].sum * nodes[rc(i)].mul;
            });
    }

    void multAll(int m) {
        upd(
            0, app_add.size(), 
            [&](int i) { 
                nodes[i].mul *= m;
            },
            [&](int i) {
                // nodes[lc(i)].mul *= nodes[i].mul; 
                // nodes[rc(i)].mul *= nodes[i].mul; 
                // nodes[i].mul = 1; 
            },
            [&](int i) {
                nodes[i].sum = nodes[lc(i)].sum * nodes[lc(i)].mul + nodes[rc(i)].sum * nodes[rc(i)].mul;
            });
    }

    int getIndex(int idx) {
        if (!(0 <= idx && idx < app.size())) 
            return -1;
        change_point(index[idx], app[idx]);
        MI ret = qry(
            index[idx], app_add.size(), []() { return 0; },
            [&](int i) { 
                return nodes[i].sum * nodes[i].mul;
            },
            [&](int i) {
                nodes[lc(i)].mul *= nodes[i].mul;
                nodes[rc(i)].mul *= nodes[i].mul; 
                nodes[i].mul = 1; 
            },
            [&](int i, MI lr, MI rr) { 
                return (lr + rr);
            });
        change_point(index[idx], 0);
        return *ret;
    }
};

int main() {
    int n;
    cin >> n;
    string s;
    int v;
    Fancy *obj = nullptr;
    for (int i = 0; i < n; ++i) {
        cin >> s >> v;
        if (s == "Fancy") {
            obj = new Fancy();
        } else if (s == "append") {
            obj->append(v);
        } else if (s == "addAll") {
            obj->addAll(v);
        } else if (s == "multAll") {
            obj->multAll(v);
        } else {
            cout << obj->getIndex(v) << endl;
        }
    }
    return 0;
}