/**
 * DMOJ - Cerrando Granja
 * Temáticas: Estructura de Datos + Disjoint Set
 *
 * Idea: Se tiene un grupo de granjas interconectadas entre si por caminos
 * bidireccionales las cuales se quieren ir cerrando  en determinado orden y se
 * quiere saber si cada vez que se cierra una granja las granjas que quedan
 * abierta forman un grafo conexo. Cuando una granja cierra no se puede utilizar
 * los caminos de ella hacia otra granja.
 * 
 * Una primera idea es aplicar por cada cierre de granja es ver si el grafo 
 * resultante de eliminar este 'nodo' con sus 'aristas' es conexo bien usando 
 * un bfs o dfs pero la cantidad de nodos y aristas hace que este enfoque se nos 
 * vaya de tiempo.
 * 
 * Ahora si en vez de ir cerrando granja vamos abriendo las granjas en orden 
 * inverso a como son cerradas y vamos conectando aquellas granjas abiertas y
 * que tienen caminos entre si. Con la ayuda de un DSU podriamos saber la 
 * cantidad de componentes conexas (en el caso de la estructura la cantidad
 * de conjuntos disjuntos ) que si es 1 significa que es un grafo conexo sino no
 * lo es. Para lograr esto haremos la tecnica Query Offline es decir leo todas
 * las consultas que para este caso serian las granjas que se cierran. Luego 
 * proceso las consultas en un orden no necesariamente el mismo orden de entrada 
 * sino en un orden que me es más óptimo en nuestro caso las procesamos en orden
 * inverso de la última a la primera 'efecto de abrir granja' y guarda la respuesta
 * para esa consulta para a la hora de imprimir se imprimen en el orden que se dieron
 * en la entrada.
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
#define ALPHABET_SIZE 26 //['a-z']
using namespace std;

struct DisjoinSet {

	vector<int> parent, sizes;
	int ncomponents;
	DisjoinSet(int n) :
			parent(n), sizes(n) {
		for (int i = 0; i < n; i++)
			sizes[parent[i] = i] = 1;
		ncomponents = n;
	}

	int root(int x) {
		return x == parent[x] ? x : root(parent[x]);
	}

	void join(int a, int b) {
		int x = root(a);
		int y = root(b);
		if (x == y)
			return;
		if (sizes[x] < sizes[y]) {
			int z = x;
			x = y;
			y = z;
		}

		parent[y] = x;
		sizes[x] += sizes[y];
		ncomponents--;
	}

};

int main() {
	OPTIMIZAR_IO

	int nnodes, npaths;
	cin >> nnodes >> npaths;

	vector<vector<int> > graph(nnodes + 1);

	for (int i = 0; i < npaths; i++) {
		int a, b;
		cin >> a >> b;
		graph[a].push_back(b);
		graph[b].push_back(a);
	}

	vector<int> remove(nnodes + 1);
	for (int i = 1; i <= nnodes; i++) {
		cin >> remove[i];
	}

	DisjoinSet dsu(nnodes);
	vector<bool> answer(nnodes + 1, false), used(nnodes + 1, false);
	answer[nnodes] = true;
	used[remove[nnodes]] = true;
	for (int i = nnodes - 1; i >= 1; i--) {
		int node = remove[i];
		for (auto x : graph[node])
			if (used[x])
				dsu.join(node, x);
		used[node] = true;
		answer[i] = (dsu.ncomponents == i);
	}

	for (int i = 1; i <= nnodes; i++)
		cout << (answer[i] ? "YES" : "NO") << ENDL;

	return 0;
}

