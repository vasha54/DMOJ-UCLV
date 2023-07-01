/**
 * DMOJ - Princesa Ciruela
 * Temáticas: Teoria de grafos + Disjtrak
 *
 * Idea: Se tiene N nodos con M caminos en un grafo no dirigido y ponderado y
 * no necesariamente convexo. Cada arista tiene un peso. Se quiere saber la distancia
 * mínima del nodo 1 hacia todos los demas nodos. Se cuenta ademas con un poder
 * especial o magico que nos permite teletransportar del nodo i al nodo N-i+1 con
 * el mismo costo de haber llegado a i. Dicho poder solo se puede usar una sola
 * vez durante el trayecto. En caso que no se alcance un nodo desde el nodo 1
 * la respuesta de la distancia para ese nodo es -1
 *
 * Para resolver el problema vamos utilizar un Disjtrak con una variación por cada
 * nodo vamos a calcular el mínimo camino de forma tradicional y minimo camino
 * utilizando una sola vez el poder magico y luego veremos cual de los dos es menor
 * por cada nodo y esa será la respuesta para ese nodo. La modificación será de la
 * siguiente manera en la cola con prioridad se adicionara en forma de estructura
 * además del nodo y costo de llegar como se llego si de forma normal o magica.
 * La otra modificación será que cada vez que llegue a un nodo por via normal
 * invocare en ese nodo el poder especial por tanto almacenaré en la cola con
 * prioridad el nodo que llego con el mismo costo pero por via magica.
 **/
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

enum TypePath{NORMAL=0,MAGIC=1};

int nnodes,npaths,a,b;
ULL w;

struct Node{
   ULL dist[2];
   vector<int> adj;
   vector<ULL> weight;
};
Node graf[MAX_N];
bool mark[MAX_N];


struct pq_entry{
   int node;
   ULL dist;
   TypePath path;
   bool operator <(const pq_entry &a) const{
      if (dist != a.dist) return (dist > a.dist);
         return (node > a.node);
   }
};

inline void dijkstra(int source){
   priority_queue<pq_entry> pq;
   pq_entry P;
   for (int i=0;i<=nnodes;i++){
      if (i == source){
         fill(graf[i].dist,graf[i].dist+2,0);
         P.node = i;
         P.dist = 0;
         P.path = NORMAL;
         pq.push(P);
      }
      else
    	  fill(graf[i].dist,graf[i].dist+2,ULLONG_MAX);

   }
   while (!pq.empty()){
      pq_entry curr = pq.top();
      pq.pop();
      int nod = curr.node;
      ULL dis = curr.dist;
      TypePath path= curr.path;
      for(int i=0;i<graf[nod].adj.size();i++){
    	  int nextNode = graf[nod].adj[i];
    	  if(dis + graf[nod].weight[i] < graf[nextNode].dist[path]){
    		  graf[nextNode].dist[path] = dis + graf[nod].weight[i];
    		  P.node = nextNode;
    		  P.dist = graf[nextNode].dist[path];
    		  P.path = path;
    		  pq.push(P);
    	  }
      }

      if(path==NORMAL){
    	  int nextNode = nnodes-nod+1;
    	  if(graf[nextNode].dist[MAGIC]> dis){
    		  graf[nextNode].dist[MAGIC]=dis;
    		  P.node = nextNode;
    		  P.dist = graf[nextNode].dist[MAGIC];
    		  P.path = MAGIC;
    		  pq.push(P);
    	  }
      }
   }
}

int main() {
	OPTIMIZAR_IO
	cin>>nnodes>>npaths;
	for(int i=0;i<npaths;i++){
		cin>>a>>b>>w;
		graf[a].adj.push_back(b);
		graf[a].weight.push_back(w);
		graf[b].adj.push_back(a);
		graf[b].weight.push_back(w);
	}

	dijkstra(1);

	for(int i=2;i<=nnodes;i++){
		if(i!=2)cout<<" ";
		w = *min_element(graf[i].dist,graf[i].dist+2);
		if(ULLONG_MAX == w) cout<<-1; else cout<<w;
	}
	cout<<ENDL;

	return 0;
}

