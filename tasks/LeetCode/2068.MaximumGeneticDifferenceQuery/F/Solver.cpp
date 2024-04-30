
#include "debug.h";

const int maxb = 20;

struct Node {
	Node *chds[2] = {nullptr, nullptr};
	int size = 0;
};

struct Trie {
	Node *root = new Node();

	void insert(int d) {
		auto u = root;
		for (int b = maxb; b >= 0; b--) {
			auto &v = u->chds[d >> b & 1];
			if (v == nullptr) v = new Node();
			v->size++;
			u = v;
		}
	}
	
	void erase(int d) {
		auto u = root;
		for (int b = maxb; b >= 0; b--) {
			auto v = u->chds[d >> b & 1];
			v->size--;
			u = v;
		}
	}
	
	int get(int d) {
		int ret = 0;
		auto u = root;
		for (int b = maxb; b >= 0; b--) {
			for (int ic: {1 - (d >> b & 1), (d >> b & 1)}) {
				auto v = u->chds[ic];
				if (v && v->size) {
					ret |= ic << b;
					u = v;
					break;
				}
			}
		}
		return ret;
	}

	void dot() {
#ifdef DEBUG
		cerr << "digraph {\n";
		int cnt = 0;
		auto F = y_combinator([&](auto F, Node *u) -> int {
			int uid = cnt++;
			cerr << '\t' << uid << " [label=<" << u->size << ">];\n";
			for (int ic = 0; ic <= 1; ic++) {
				if (u->chds[ic]) {
					int vid = F(u->chds[ic]);
					cerr << '\t' << uid << " -> " << vid << " [label=<" << ic << ">];\n";
				}
			}
			return uid;
		});
		F(root);
		cerr << "}\n";
#else
		;
#endif
	}
};

class Solution {
public:
    vector<int> maxGeneticDifference(vector<int>& fas, vector<vector<int>>& qs) {
		int n = fas.size();
		int m = qs.size();
		vector<int> ret(m);
		vector<vector<int>> adj(n);
		vector<vector<pair<int,int>>> nodeQs(n);
		for (int u = 0; u < n; u++) {
			int v = fas[u];
			if (v != -1) {
				adj[u].push_back(v);
				adj[v].push_back(u);
			}
		}
		for (int q = 0; q < m; q++) {
			nodeQs[qs[q][0]].push_back({q, qs[q][1]});
		}
		int root = -1;
		for (int i = 0; i < n; i++) if (fas[i] == -1) root = i;
		Trie trie;
		auto dfs = y_combinator([&](auto F, int u, int fa) -> void {
			trie.insert(u);
			for (auto q: nodeQs[u]) ret[q.first] = trie.get(q.second) xor q.second;
			for (int v: adj[u]) if (v != fa)
				F(v, u);
			trie.erase(u);
		});
		dfs(root, -1);
		trie.dot();
		return ret;
    }
};

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(&cout);
	int n, q; cin >> n >> q;
	vector<int> fa(n);
	vector<vector<int>> Q(q, vector<int>(2));
	for (int i = 0; i < n; i++) cin >> fa[i];
	for (int i = 0; i < q; i++) cin >> Q[i][0] >> Q[i][1];
	auto ret = Solution().maxGeneticDifference(fa, Q);
	for (auto x : ret) cout << x << '\n';
    return 0;
}

