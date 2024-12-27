/**
 * DMOJ - Agua Fría Clara
 * Temáticas: Árboles + Recorridos
 *
 * Idea: Calcular para cada nodo del arbol su nivel.
 */
#include <bits/stdc++.h>
#include <math.h>
#define ENDL '\n'
#define OPTIMIZAR_IO ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define PRESICION(x) cout.setf(ios::fixed,ios::floatfield); cout.precision(x);
#define MAX_N 1005
#define MOD 1000000007
#define EPS 1e-9
#define INF 1000000000
#define LL long long
#define ULL unsigned long long
#define pii pair<int,int>
#define ALPHABET_SIZE 26 //['a-z']
using namespace std;

struct Node {
	int nivel = 0, sL = -2, sR = -2;
};

int main() {
	OPTIMIZAR_IO
	//PRESICION(20)
	int n, e, p, l, r;
	cin >> n >> e;

	vector<Node> tree(n + 1);

	for (int i = 0; i < e; i++) {
		cin >> p >> l >> r;
		tree[p].sL = l;
		tree[p].sR = r;
	}

	tree[1].nivel = 1;

	queue<int> visit;
	visit.push(1);

	while (!visit.empty()) {
		p = visit.front();
		visit.pop();
		l = tree[p].sL;
		r = tree[p].sR;

		if (l > 0) {
			tree[l].nivel = tree[p].nivel + 1;
			visit.push(l);
		}

		if (r > 0) {
			tree[r].nivel = tree[p].nivel + 1;
			visit.push(r);
		}
	}

	for (int i = 1; i <= n; i++)
		cout << tree[i].nivel << ENDL;

	return 0;
}

