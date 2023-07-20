/**
 * DMOJ - Árbol de palabras
 * Tematica : Teoria de Grafos: Kruskal
 *
 * Idea: Construir el árbol de expasión mínima e imprimir la arista de mayor peso.
 * Las palabras serán los nodos entre cualquier par de plabras existirá una arista
 * cuya ponderación será igual al coste de una arista entre dos palabras como la
 * suma de los costes entre cada par de letras correspondientes de las dos palabras.
 * letras correspondientes de las dos palabras. Definimos el coste entre dos letras
 * como el valor absoluto de la diferencia entre sus valores ASCII.
 **/
#include <bits/stdc++.h>
#include <math.h>
#define ENDL '\n'
#define OPTIMIZAR_IO ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define PRESICION(x) cout.setf(ios::fixed,ios::floatfield); cout.precision(x);
#define MAX_N 1005
#define MOD 10000
#define EPS 1e-9
#define INF 3*10000000000*(-1)
#define LL long long
#define ULL unsigned long long
#define pii pair<int,int>
#define ALPHABET_SIZE 26 //['a-z']
using namespace std;

int n, m,length;
int numComponents, ret;
struct Edge {
	int a, b;
	int weight;
	bool operator <(const Edge &e) const {
		return (weight < e.weight);
	}
};
Edge E[MAX_N*MAX_N];
struct Node {
	int parent;
	int rank;
};
Node DSU[MAX_N];
inline void MakeSet(int x) {
	DSU[x].parent = x;
	DSU[x].rank = 0;
}
inline int Find(int x) {
	if (DSU[x].parent == x)
		return x;

	DSU[x].parent = Find(DSU[x].parent);
	return DSU[x].parent;
}
inline void Union(int x, int y) {
	int xRoot = Find(x);
	int yRoot = Find(y);
	if (xRoot == yRoot)
		return;
	if (DSU[xRoot].rank < DSU[yRoot].rank) {
		DSU[xRoot].parent = yRoot;
	} else if (DSU[xRoot].rank > DSU[yRoot].rank) {
		DSU[yRoot].parent = xRoot;
	} else {
		DSU[yRoot].parent = xRoot;
		DSU[xRoot].rank++;
	}
}
inline int kruskal() {
	int ret = INT_MIN, numComponents = n;
	for (int i = 0; i < n; i++)
		MakeSet(i);
	sort(E, E + m);
	for (int i = 0; i < m && numComponents > 1; i++) {
		if (Find(E[i].a) != Find(E[i].b)) {
			Union(E[i].a, E[i].b);
			ret =max(ret, E[i].weight);
			numComponents--;
		}
	}
	return ret;
}

char  names[MAX_N][20];

int cost(char * a, char * b, int l){
	int c =0;
	for(int i=0;i<l;i++) c+=abs(a[i]-b[i]);
	return c;
}

int main() {
	OPTIMIZAR_IO
	cin>>n>>length;
	m=0;

	for(int j=0;j<n;j++){
		cin>>names[j];
		for(int i=j-1;i>=0;i--){
			E[m].a=i;E[m].b=j;E[m].weight=cost(names[i],names[j],length);
			m++;
		}
	}
	cout<<kruskal()<<ENDL;



	return 0;
}

