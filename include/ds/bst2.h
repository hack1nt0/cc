#ifndef INCLUDED_BST_H
#define INCLUDED_BST_H
#include "debug.h"
#include <functional>
#include <iostream>
#include <unordered_map>

template <typename T> struct BaseBst {
    vector<T> nodes;
    int dummy, root;
    vector<int> L, R, H, C, S;

    BaseBst()
        : nodes(1, T()), dummy(0), root(0), L(1, 0), R(1, 0), H(1, 0), C(1, 0),
          S(1, 0) {}

    int rotate(int idx, int c = 2) {
        if (H[L[idx]] == H[R[idx]])
            return idx;
        if (c == 0)
            return idx;
        if (abs(H[L[idx]] - H[R[idx]]) < c)
            return idx;
        int ret;
        if (H[L[idx]] > H[R[idx]]) {
            if (H[L[L[idx]]] < H[R[L[idx]]])
                L[idx] = rotate(L[idx], c - 1);
            ret = L[idx];
            int tmp = R[L[idx]];
            R[ret] = idx;
            L[R[ret]] = tmp;
        } else {
            if (H[L[R[idx]]] > H[R[R[idx]]])
                R[idx] = rotate(R[idx], c - 1);
            ret = R[idx];
            int tmp = L[R[idx]];
            L[ret] = idx;
            R[L[ret]] = tmp;
        }
        return ret;
    }

    int insert(const T &v) { return root = insert(v, root); }

    int insert(const T &v, int idx) {
        if (idx == dummy) {
            nodes.push_back(v);
            L.push_back(0);
            R.push_back(0);
            H.push_back(1);
            C.push_back(1);
            S.push_back(1);
            return nodes.size() - 1;
        }
        int cmp = v <=> nodes[idx];
        if (cmp == 0) {
            C[idx]++;
            S[idx]++;
            nodes[idx].up(C[idx], nodes[L[idx]], nodes[R[idx]]);
        } else if (cmp < 0) {
            L[idx] = insert(v, L[idx]);
        } else {
            R[idx] = insert(v, R[idx]);
        }
        idx = rotate(idx);
        for (auto idx : {L[idx], R[idx], idx})
            if (idx) {
                H[idx] = max(H[L[idx]], H[R[idx]]) + 1;
                S[idx] = S[L[idx]] + S[R[idx]] + C[idx];
                nodes[idx].up(C[idx], nodes[L[idx]], nodes[R[idx]]);
            }
        return idx;
    }

#ifdef DEBUG
    void dot() {
        cerr << "\ndigraph {\n";
        _dot(root);
        if (root > 0) {
            cerr << "{rank=source;" << root << "}\n";
            cerr << "{rank=sink;";
            for (int i = 1; i < nodes.size(); ++i)
                if (L[i] == dummy && R[i] == dummy)
                    cerr << i << ";";
            cerr << "}\n";
        }
        cerr << "}\n";
    }

    void _dot(int idx) {
        if (idx <= dummy)
            return;
        cerr << '\t' << idx << " [label=<" << idx << "<BR/>"
             << "height=" << H[idx] << "<BR/>"
             << "count=" << C[idx] << "<BR/>"
             << "size=" << S[idx] << "<BR/>";
        nodes[idx].dot();
        cerr << ">]\n";
        if (L[idx] != dummy) {
            cerr << '\t' << idx << " -> " << L[idx] << "\n";
            _dot(L[idx]);
        }
        if (R[idx] != dummy) {
            cerr << '\t' << idx << " -> " << R[idx] << "\n";
            _dot(R[idx]);
        }
    }
#endif
};

#endif