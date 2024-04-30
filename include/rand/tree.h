#ifndef INCLUDED_RANDTREE_H
#define INCLUDED_RANDTREE_H

#include "rand/Random.h"

// template<typename G>
// void rand_tree(G& g, int cc = 1) {
//     vector<int> pos = choice<int>(0, g.nv() - 1, cc - 1, false);
//     pos.push_back(g.nv());
//     for (int i = 0, j = 0; i < g.nv(); ++i) {
//         if 
//     }
//     int ne = nv - 1;
//     vector<int> vs(nv);
//     for (int i = 0; i < nv; ++i)
//         vs[i] = i;
//     shuffle(vs.begin(), vs.end(), randg);
//     for (int iv = 1; iv < nv; ++iv) {
//         int fa = vs[rand<int>(0, iv)];
//         int u = vs[iv], v = fa;
//         if (u > v)
//             swap(u, v);
//         g.adde({u, v});
//     }
//     if (!g.directional()) {
//         for (int ie = 0; ie < ne; ++ie) {
//             g.adde({es[ie].second, es[ie].first});
//         }
//     }
// }

#endif