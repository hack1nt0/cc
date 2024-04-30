#ifndef INCLUDED_RANDGRAPH_H
#define INCLUDED_RANDGRAPH_H

#include "rand/tree.h"

// template<typename G>
// void rand_graph(G& g, int nv, bool directional, bool self_loop,
//                 int64_t max_ne = int(1e7 + 1), bool forest=true) {
//     using edge_type = pair<int, int>;

//     int64_t ne = directional ? (nv * (self_loop ? nv : nv - 1))
//                              : (nv * (nv - 1) / 2 + (self_loop ? nv : 0));
//     ne = min(ne, max_ne);
//     ne = rand<int>(nv, ne + 1);
//     vector<edge_type> es = rand_tree<G>(g, nv, false);

//     set<pair<int, int>> tree_set{es.begin(), es.end()};
//     auto edge_generator = [&]() -> Generator<edge_type> {
//         for (int u = 0; u < nv; ++u)
//             for (int v = (directional ? 0 : u); v < nv; ++v) {
//                 auto e = make_pair(u, v);
//                 if ((!self_loop && u == v) || tree_set.contains(e))
//                     continue;
//                 co_yield e;
//             }
//     }();
//     for (auto e : choice(edge_generator.begin(), edge_generator.end(),
//                          ne - nv + 1, false)) {
//         es.push_back(e);
//     }
//     if (!directional) {
//         for (int ie = 0; ie < ne; ++ie) {
//             es.push_back({es[ie].second, es[ie].first});
//         }
//     }
//     return es;
// }

#endif