#ifndef INCLUDED_RANGETREE_H
#define INCLUDED_RANGETREE_H

#include "debug.h"

template <typename Node> struct RangeTree {
    using W = typename Node::value_type;
    vector<Node> nodes;

    // BaseRangeTree(const Dat& dat, int l, int r): dat(dat), nodes(1 <<
    // int(ceil(log2(r - l)))) {
    //     init(l, r, 0);
    // }

    inline int lc(int i) const { return (i << 1) + 1; }
    inline int rc(int i) const { return (i << 1) + 2; }

    void init(int l, int r, const function<void(int, int)> &init_leaf,
              const function<void(int)> &init_inner, int i = 0) {
        if (i == 0) {
            nodes.resize(1 << int(ceil(log2(r - l))) << 1);
        }
        nodes[i].l = l;
        nodes[i].r = r;
        if (r - l == 1) {
            init_leaf(i, l);
            return;
        }
        int m = l + (r - l) / 2;
        init(l, m, init_leaf, init_inner, lc(i));
        init(m, r, init_leaf, init_inner, rc(i));
        init_inner(i);
    }

    // template<typename QRY_ZERO=function<W()>, typename
    // QRY_FULL=function<W(int)>, typename QRY_BEFORE=function<void(int)>,
    // typename QRY_AFTER=function<W(int,W,W)>> template<typename QRY_ZERO,
    // typename QRY_FULL, typename QRY_BEFORE, typename QRY_AFTER> W qry(int l,
    // int r, const QRY_ZERO& qry_zero, const QRY_FULL& qry_full, const
    // QRY_BEFORE& qry_before, const QRY_AFTER& qry_after, int i=0) {
    W qry(int l, int r, const function<W()> &qry_zero,
          const function<W(int)> &qry_full,
          const function<void(int)> &qry_before,
          const function<W(int, W, W)> &qry_after, int i = 0) {
        if (r <= nodes[i].l || nodes[i].r <= l) {
            return qry_zero();
        }
        if (l <= nodes[i].l && nodes[i].r <= r) {
            return qry_full(i);
        }
        // int m = l + (r - l) / 2;
        qry_before(i);
        W lR = qry(l, r, qry_zero, qry_full, qry_before, qry_after, lc(i));
        W rR = qry(l, r, qry_zero, qry_full, qry_before, qry_after, rc(i));
        return qry_after(i, lR, rR);
    }

    // template<typename UPD_FULL=function<void(int)>, typename
    // UPD_BEFORE=function<void(int)>, typename UPD_AFTER=function<void(int)>>
    // template<typename UPD_FULL, typename UPD_BEFORE, typename UPD_AFTER>
    // void upd(int l, int r, const UPD_FULL& upd_full, const UPD_BEFORE&
    // upd_before, const UPD_AFTER& upd_after, int i=0) {
    void upd(int l, int r, const function<void(int)> &upd_full,
             const function<void(int)> &upd_before,
             const function<void(int)> &upd_after, int i = 0) {
        if (r <= nodes[i].l || nodes[i].r <= l) {
            return;
        }
        if (l <= nodes[i].l && nodes[i].r <= r) {
            upd_full(i);
            return;
        }
        upd_before(i);
        upd(l, r, upd_full, upd_before, upd_after, lc(i));
        upd(l, r, upd_full, upd_before, upd_after, rc(i));
        upd_after(i);
    }
};

#endif