/**
 * DMOJ - C-3BA y Las Rutas Incendiadas
 * Temáticas: Teoria de grafos + Distrakj + Puentes
 *
 * Idea: Dados dos nodos A y B se quiere saber cuantas aristas existen tal que
 * si se eliminarán ellas unicamente del grafo el camino mínimo de A a B difiere
 * con respecto al original. Basicamente los que nos piden es determinar de todas
 * las aristas que pueden ser parte de un posible camino mínimo de A a B y son
 * puentes en grafo donde solo estén las aristas que son parte de los caminos mínimo.
 * Como el grafo el bidireccional la distancia mínima de A a B va hacer la misma de
 * B a A esto nos ayudará a buscar dichas aristas.
 *
 * Lo primero será realizar dos dijkstra uno partiendo de A y otro partiendo de B
 * en ambos casos guardo la distancia mínima de A hacia todos los nodos y la
 * distancia mínima de B hacia todos los nodos.
 *
 * Segundo construimos un grafo donde solo estén las aristas que forman parte de
 * un posible camino mínimo. Una arista (x,v,w) que une en nodo x con el nodo v
 * con un peso w será parte de un camino mínimo si se cumple al menos una de estas
 * dos condiciones:
 *
 * distA[x]+distB[v]+w == Z
 * distA[v]+distB[x]+w == Z
 *
 * Donde:
 * 	distA -> es el vector donde almacene la mínima distancia del nodo A hacia todos
 * 	los nodos del grafo en la posición i esta la distancia mínima de A al nodo i
 * 	distB -> es el vector donde almacene la mínima distancia del nodo B hacia todos
 * 	los nodos del grafo en la posición i esta la distancia mínima de B al nodo i
 * 	Z -> distancia minima de A a B.
 *
 * 	Tercero una vez construido el grafo buscamos sobre este las aristas que son
 * 	puentes y la cantidad de puentes será la respuesta
 */
#include <bits/stdc++.h>
#include <math.h>
#define ENDL '\n'
#define OPTIMIZAR_IO ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define PRESICION(x) cout.setf(ios::fixed,ios::floatfield); cout.precision(x);
#define MAX_N 100010
#define MOD 10000
#define EPS 1e-9
#define INF 100000000000010
#define LL long long
#define ULL unsigned long long
using namespace std;

struct Node{
	ULL dist;
	vector<int> adj;
	vector<ULL> weight;
};

struct Edge{
	int a,b;
	ULL w;
	Edge(int _a=0,int _b=0,ULL _w=0):a(_a),b(_b),w(_w){}
};

struct pq_entry{
	int node;
	ULL dist;
	bool operator <(const pq_entry &a) const{
		if (dist != a.dist) return (dist >= a.dist);
		return (node > a.node);
	}
};

Node graf[MAX_N];
bool mark[MAX_N];

ULL distA [MAX_N];
ULL distB [MAX_N];

Edge edges[2*MAX_N];

int tin[MAX_N], low[MAX_N];
int timer, nnodes,nedges,nodeA,nodeB,nbridges;

inline void dijkstra(int source,ULL * dist){
	priority_queue<pq_entry> pq;
	pq_entry P;
	for (int i=1;i<=nnodes;i++){
		if (i == source){
			graf[i].dist = 0;
			P.node = i;
			P.dist = 0;
			pq.push(P);
			dist[i]=0;
		}
		else{
			graf[i].dist = INF;
			dist[i] = INF;
		}
	}
	while (!pq.empty()){
		pq_entry curr = pq.top();
		pq.pop();
		int nod = curr.node;
		ULL dis = curr.dist;

		for(int i=0;i<(int)graf[nod].adj.size();i++){
			if(!mark[graf[nod].adj[i]]){
				int nextNode = graf[nod].adj[i];
				if(dis + graf[nod].weight[i] < graf[nextNode].dist){
					graf[nextNode].dist = dis + graf[nod].weight[i];
					P.node = nextNode;
					P.dist = graf[nextNode].dist;
					dist[nextNode]= graf[nextNode].dist;
					pq.push(P);
				}
			}
		}

		mark[nod] = true;
	}
}

void dfs(int v, int p = -1) {
	mark[v] = true;
	tin[v] = low[v] = timer++;
	for (int k= 0;k<(int)graf[v].adj.size();k++) {
		int to =graf[v].adj[k];
		if (to == p) continue;
		if (mark[to]) {
			low[v] = min(low[v], tin[to]);
		} else {
			dfs(to, v);
			low[v] = min(low[v], low[to]);
			if (low[to] > tin[v])
				nbridges++;
		}
	}
}

void find_bridges() {
	timer = 0;
	nbridges = 0;
	fill(mark,mark+MAX_N,false);
	fill(tin,tin+MAX_N,-1);
	fill(low,low+MAX_N,-1);
	for (int i = 1; i <= nnodes; ++i) {
		if (!mark[i])
			dfs(i);
	}
	cout<<nbridges<<ENDL;
}



int main() {

	OPTIMIZAR_IO
	PRESICION(0)

	cin>>nnodes>>nedges;
	cin>>nodeA>>nodeB;

	for(int i=0;i<nedges;i++){
		cin>>edges[i].a>>edges[i].b>>edges[i].w;

		graf[edges[i].a].adj.push_back(edges[i].b);
		graf[edges[i].a].weight.push_back(edges[i].w);

		graf[edges[i].b].adj.push_back(edges[i].a);
		graf[edges[i].b].weight.push_back(edges[i].w);
	}

	fill(mark,mark+MAX_N,false);
	dijkstra(nodeA,distA);
	fill(mark,mark+MAX_N,false);
	dijkstra(nodeB,distB);

	for(int i=0;i<=nnodes;i++){
		graf[i].adj.clear();
		graf[i].weight.clear();
	}

	for(int i=0;i<nedges;i++){
		Edge e =edges[i];
		if(distA[e.a]+distB[e.b]+e.w==distA[nodeB] || distA[e.b]+distB[e.a]+e.w==distA[nodeB]){
			graf[e.a].adj.push_back(e.b);
			graf[e.b].adj.push_back(e.a);
		}
	}

	find_bridges();

	return 0;
}
