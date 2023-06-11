/**
 * DMOJ - Estructura Celulares
 * Temáticas: Estructura de Datos + Heavy Light Descomposition
 *
 * Idea: Dado un arbol con los pesos de las aristas y un grupo de consulta del
 * tipo (u,v) decir en el camino del nodo u al nodo v cual es la arista de mayor
 * peso y la arista de menor peso. Implementar un Descomposición Pesada/Ligera
 * que responda la dos prreguntas al mismo tiempo.
 */
#include <bits/stdc++.h>
#include <math.h>
#define ENDL '\n'
#define OPTIMIZAR_IO ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define PRESICION(x) cout.setf(ios::fixed,ios::floatfield); cout.precision(x);
#define MAX_N 100010
#define MOD 10000
#define EPS 1e-9
#define INF 3*10000000000*(-1)
#define LL long long
#define ULL unsigned long long
using namespace std;

struct segtree {

	struct node {
		// Valor inicial de los nodos hojas
		long long mx = LLONG_MIN;
		long long mn = LLONG_MAX;
		long long sum = 0;
		long long add = 0;

		void apply(int l, int r, long long v) {
			mx = v;
			mn = v;
			sum += (r - l + 1) * v;
			add += v;
		}
	};

	int nnodes;
	vector<node> tree;

	static node unite(const node &a, const node &b) {
		node res;
		res.mx = max(a.mx, b.mx);
		res.mn = min(a.mn, b.mn);
		res.sum = a.sum + b.sum;
		return res;
	}

	segtree(int _n) :
			nnodes(_n) {
		tree.resize(2 * nnodes - 1);
		build(0, 0, nnodes - 1);
	}

	void pull(int x, int y) {
		tree[x] = unite(tree[x + 1], tree[y]);
	}

	void push(int x, int l, int r) {
		int m = (l + r) >> 1;
		int y = x + ((m - l + 1) << 1);
		if (tree[x].add != 0) {
			tree[x + 1].apply(l, m, tree[x].add);
			tree[y].apply(m + 1, r, tree[x].add);
			tree[x].add = 0;
		}
	}

	void build(int x, int l, int r) {
		if (l == r) {
			return;
		}
		int m = (l + r) >> 1;
		int y = x + ((m - l + 1) << 1);
		build(x + 1, l, m);
		build(y, m + 1, r);
		pull(x, y);
	}

	node get(int x, int l, int r, int ll, int rr) {
		if (ll <= l && r <= rr) {
			return tree[x];
		}
		int m = (l + r) >> 1;
		int y = x + ((m - l + 1) << 1);
		push(x, l, r);
		node res;
		if (rr <= m) {
			res = get(x + 1, l, m, ll, rr);
		} else {
			if (ll > m) {
				res = get(y, m + 1, r, ll, rr);
			} else {
				res = unite(get(x + 1, l, m, ll, rr), get(y, m + 1, r, ll, rr));
			}
		}
		pull(x, y);
		return res;
	}

	node get(int ll, int rr) {
		return get(0, 0, nnodes - 1, ll, rr);
	}


	void modify(int x, int l, int r, int ll, int rr, long &v) {
		if (ll <= l && r <= rr) {
			tree[x].apply(l, r, v);
			return;
		}
		int m = (l + r) >> 1;
		int y = x + ((m - l + 1) << 1);
		push(x, l, r);
		if (ll <= m) {
			modify(x + 1, l, m, ll, rr, v);
		}
		if (rr > m) {
			modify(y, m + 1, r, ll, rr, v);
		}
		pull(x, y);
	}


	void modify(int ll, int rr, long v) {
		modify(0, 0, nnodes - 1, ll, rr, v);
	}
};

struct Edge{
	int a,b;
	long long weigth;
	Edge(int _a,int _b,long long _w):a(_a),b(_b),weigth(_w){}
};

class HeavyLight {
public:
	vector<vector<int>> tree;
	bool valuesOnVertices; // true - values on vertices, false - values on edges
	segtree segment_tree;
	vector<int> parent;
	vector<int> depth;
	vector<int> pathRoot;
	vector<int> in;

	HeavyLight(const vector<vector<int>> &t,int root, bool valuesOnVertices) :
			tree(t), valuesOnVertices(valuesOnVertices), segment_tree(t.size()), parent(
					t.size()), depth(t.size()), pathRoot(t.size()), in(t.size()) {
		int time = 0;
		parent[root] = -1;

		function<int(int)> dfs1 = [&](int u) {
			int size = 1;
			int maxSubtree = 0;
			for (int &v : tree[u]) {
				if (v == parent[u])
					continue;
				parent[v] = u;
				depth[v] = depth[u] + 1;
				int subtree = dfs1(v);
				if (maxSubtree < subtree) {
					maxSubtree = subtree;
					int t = v;
					v = tree[u][0];
					tree[u][0] = t;
				}
				size += subtree;
			}
			return size;
		};

		function<void(int)> dfs2 = [&](int u) {
			in[u] = time++;
			for (int v : t[u]) {
				if (v == parent[u])
					continue;
				pathRoot[v] = v == t[u][0] ? pathRoot[u] : v;
				dfs2(v);
			}
		};

		dfs1(root);
		dfs2(root);
	}

	segtree::node get(int u, int v) {
		segtree::node res;
		process_path(u, v, [this, &res](int a, int b) {
			res = segtree::unite(res, segment_tree.get(a, b));
		});
		return res;
	}

	void modify(int u, int v, long long delta) {
		process_path(u, v, [this, delta](int a, int b) {
			segment_tree.modify(a, b, delta);
		});
	}

	void process_path(int u, int v, const function<void(int x, int y)> &op) {
		for (; pathRoot[u] != pathRoot[v]; v = parent[pathRoot[v]]) {
			if (depth[pathRoot[u]] > depth[pathRoot[v]]) {
				int t = u;
				u = v;
				v = t;
			}
			op(in[pathRoot[v]], in[v]);
		}
		if (u != v || valuesOnVertices)
			op(min(in[u], in[v]) + (valuesOnVertices ? 0 : 1),
					max(in[u], in[v]));
	}
};

int main() {
	OPTIMIZAR_IO

	int nnodes,nquerys,A,B;
	long long w;
	vector< vector<int> > tree;
	vector<int> p;
	vector<Edge> edges;

	cin>>nnodes;
	tree.assign(nnodes+1,p);
	for(int i=0;i<nnodes-1;i++){
		cin>>A>>B>>w;
		tree[A].push_back(B);
		tree[B].push_back(A);
		edges.push_back(Edge(A,B,w));
	}

	HeavyLight hle(tree,1, false);

	for(Edge e:edges){
		hle.modify(e.a,e.b,e.weigth);
	}

	cin>>nquerys;
	for(int i=0;i<nquerys;i++){
		cin>>A>>B;
		segtree::node p = hle.get(A,B);
		cout<<p.mn<<" "<<p.mx<<ENDL;
	}

	return 0;
}

