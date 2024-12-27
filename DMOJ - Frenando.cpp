/**
 * DMOJ - Frenando
 * Temáticas: Teoria de Grafo : DFS + Estructura de Datos : Feneckiws Tree (BIT)
 *
 * Idea: Se tiene un grupo de N (N<=10^5) pastizales que esta organizado de forma
 * de arbol siendo la raiz el pastizal 1. Se tiene tambien N vacas  las cuales
 * tienen su pastizal preferido. Las vacas salen del establo de forma creciente
 * es decir primero la vaca 1 , luego la 2 asi sucesivamente. La vaca i no saldra
 * en busca se su pastizal de preferencia hasta que la vaca i-1 no haya llegado
 * al suyo. Se quiere saber para cada vaca i cuantas vacas encuentra en su camino
 * hacia el pastizal de su preferencia. Para una vaca i que esta en el nodo j la
 * cantidad de vacas será igual a la cantidad de vacas menores de i que su
 * pastizal de preferencia en el camino del nodo 1 al nodo j. Cuando hacemos un DFS
 * sobre un arbol y llegamos al nodo j los nodos marcados hasta ahí son los nodos
 * que forman parte del camino de 1 a j por tanto cada vez que yo llego a un nodo
 * puede saber los nodos visitados y de esos nodos cuales vacas estarían en ellos
 * y mas importante cuales de esas vacas son menores que i esto ultimo con ayuda
 * de una suma acumulada que permita saber hasta un valor i cuantas vacas han sido
 * utilizadas pero sucede que cuando salgamos del nodo que terminamos de visitar
 * hay que descamar la vaca i como utilizada en la suma acumulada por tanto debemos
 * utilizar un Feneckiws Tree (BIT) el cual inicialmente en todas las posiciones
 * es cero. Cuando llego a un nodo adiciono en uno las posiciones de las vacas que
 * gustan de ese nodo/pastizal y antes salir vuelvo a decrementar en uno las misma
 * posiciones y luego con ayuda del BIT saber la suma acumulada hasta i-1 y eso
 * me dará la cantidad de vacas que se encontrará la vaca i en el nodo j.
 * Importante como no lo especifican un pastizal puede ser preferido por varias
 * vacas por tanto a la hora de adicionar el 1 en BIt lo hacemos de forma creciente
 * por los ids de la vacas y luego a la hora de adicionar el -1 lo hacemos de forma
 * decreciente aunque me di cuenta escribiendo esto  que era incecesario.
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

vector<int> tree[MAX_N];
vector<int> fields[MAX_N];
vector<bool> visited;
vector<int> solutions;
int nnodes, A, B;

struct FenwickTreeOneBasedIndexing {
	vector<int> bit;
	int n;
	FenwickTreeOneBasedIndexing(int n) {
		this->n = n + 1;
		bit.assign(n + 1, 0);
	}

	int sum(int idx) {
		int ret = 0;
		for (++idx; idx > 0; idx -= idx & -idx)
			ret += bit[idx];
		return ret;
	}
	void add(int idx, int delta) {
		for (++idx; idx < n; idx += idx & -idx)
			bit[idx] += delta;
	}
};

FenwickTreeOneBasedIndexing * treeBIT;

void dfs(int node){
	visited[node]=true;
	int size=fields[node].size();
	//sort(fields[node].begin(),fields[node].end());

	for(auto y: fields[node])
		treeBIT->add(y,1);

	for(auto x : tree[node])
		if(visited[x]==false)
			dfs(x);

	for(int i=size-1;i>=0;i--){
		treeBIT->add(fields[node][i],-1);
		solutions[fields[node][i]]=treeBIT->sum(fields[node][i]-1);
	}
	visited[node]=false;
}

int main() {
	OPTIMIZAR_IO
	cin >> nnodes;
	for (int i = 1; i < nnodes; i++) {
		cin >> A >> B;
		tree[A].push_back(B);
		tree[B].push_back(A);
	}
	for (int i = 1; i <= nnodes; i++) {
		cin >> A;
		fields[A].push_back(i);
	}

	treeBIT = new FenwickTreeOneBasedIndexing(nnodes);
	visited.assign(nnodes + 1, false);
	solutions.assign(nnodes + 1, 0);
	dfs(1);
	for(int i=1;i<=nnodes;i++){
		cout<<solutions[i]<<ENDL;
	}
	return 0;
}

