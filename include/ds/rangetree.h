#ifndef INCLUDED_RANGETREE_H
#define INCLUDED_RANGETREE_H

#include "debug.h"
#include <functional>
#include <iostream>

/*
Pointer based range tree, slow but agile. Node Template:

struct Node {
    Node *chds[2];
    int bounds[2];
    void pushdown() {}
    void maintain() {}
    friend ostream &operator<<(ostream &out, const Node &obj) {
        return out;
    }
};
*/
template <typename T> struct RangeTree {
    T *root;

    RangeTree(int l, int r, const function<void(T *root, int idx)> &visit)
        : root(nullptr) {
        initialize(l, r, visit);
    }

    bool overlay(int aL, int aR, int bL, int bR) {
        return !(aR <= bL || bR <= aL);
    }

    bool contains(int aL, int aR, int bL, int bR) {
        return aL <= bL && bR <= aR;
    }

    T *initialize(int l, int r, const function<void(T *root, int idx)> &visit,
                  T *root = nullptr) {
        if (l >= r)
            return nullptr;
        if (root == nullptr) {
            root = new T();
            if (this->root == nullptr) {
                this->root = root;
            }
        }
        if (l + 1 == r) {
            visit(root, l);
            root->chds[0] = nullptr;
            root->chds[1] = nullptr;
        } else {
            int mid = l + ((r - l) >> 1);
            root->chds[0] = initialize(l, mid, visit, root->chds[0]);
            root->chds[1] = initialize(mid, r, visit, root->chds[1]);
            root->maintain();
        }
        root->bounds[0] = l;
        root->bounds[1] = r;
        return root;
    }

    void query(int l, int r, const function<void(T *root)> &visit,
               T *root = nullptr) {
        if (root == nullptr)
            root = this->root;
        if (!overlay(l, r, root->bounds[0], root->bounds[1]))
            return;
        if (contains(l, r, root->bounds[0], root->bounds[1])) {
            visit(root);
        } else {
            root->pushdown();
            query(l, r, visit, root->chds[0]);
            query(l, r, visit, root->chds[1]);
        }
    }

    void update(int l, int r, const function<void(T *root)> &visit,
                T *root = nullptr) {
        if (root == nullptr)
            root = this->root;
        if (!overlay(l, r, root->bounds[0], root->bounds[1]))
            return;
        if (contains(l, r, root->bounds[0], root->bounds[1])) {
            visit(root);
        } else {
            update(l, r, visit, root->chds[0]);
            update(l, r, visit, root->chds[1]);
            root->maintain();
        }
    }

#ifdef DEBUG
    void dot() {
        cerr << "\ndigraph {\n";
        if (root != nullptr) {
            vector<int> leafs;
            _dot(root, leafs);
            cerr << "\t{rank=source;" << 0 << "}\n";
            cerr << "\t{rank=sink;";
            for (auto x : leafs)
                if (x != 0)
                    cerr << x << ";";
            cerr << "}\n";
        }
        cerr << "}\n";
    }

    void _dot(T *root, vector<int> &leafs, int idx = 0) {
        cerr << "\t" << idx << " [label=<[" << root->bounds[0] << ","
             << root->bounds[1] - 1 << "]";
        cerr << "<BR/>" << *root;
        cerr << "<BR/>>]\n";
        if (root->chds[0] == nullptr && root->chds[1] == nullptr) {
            leafs.push_back(idx);
        } else {
            _dot(root->chds[0], leafs, idx * 2 + 1);
            _dot(root->chds[1], leafs, idx * 2 + 2);
            cerr << "\t" << idx << " -> " << idx * 2 + 1 << "\n";
            cerr << "\t" << idx << " -> " << idx * 2 + 2 << "\n";
        }
    }
#else
    void dot() {}
#endif
};

#endif
