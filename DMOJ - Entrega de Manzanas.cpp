/**
 * DMOJ - Entrega de Manzanas
 * (https://dmoj.uclv.edu.cu/problem/apple)
 * Temática: Teoria de grafos + Dijkstra
 * 
 * Idea: Una vez leido el problema es facil de entender que se debe buscar la menor
 * ruta que empiece en PB y pasar por PA1 y PA2 lo cual conduce a dos posibles rutas
 *  - PB -> PA1 -> PA2
 *  - PB -> PA2 -> PA1
 * Dado las caracteristicas del grafo del problema el cual es ponderado y no dirigido
 * es evidente que la menor ruta de PA1 -> PA2 va ser la misma que PA2 -> PA1 por
 * lo que la solucion se reduce a:
 *   - min(PB -> PA1, PB -> PA2) + PA1 -> PA2
 * La solución al problema radica en ejecutar dos veces el algoritmo de Dijkstra
 * que permite hallar la distancia mínima de un nodo hacia los demas nodos del 
 * grafo siempre y cuando las aristas tenga peso positivo como es el caso.
 * 
 * Una primera ejecucción del algoritmo será a partir del nodo PB para asi hallar
 * las distancias minimas de PB a PA1 y PA2. La segunda ejecucción será comenzando
 * bien el PA1 para hallar la distancia mínima hacia PA2 o vicersa como sea de su 
 * gusto, ya con esos valores calculado solo queda evaluar el resultado de 
 * min(PB -> PA1, PB -> PA2) + PA1 -> PA2 y tendremos la solución.
 */ 
#include <bits/stdc++.h>
#include <bitset>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>

#define ENDL '\n'
#define OPTIMIZAR_IO ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define PRESICION(x) cout.setf(ios::fixed,ios::floatfield); cout.precision(x);
#define READ_FILE freopen("Input.txt","r",stdin);
#define WRITE_FILE freopen("Output.txt","w",stdout);
#define REP_INDEX_1(x) for(int i=1;i<=x;i++)
#define REP_INDEX_0(x) for(int i=0;i<x;i++)
#define int long long
#define uint unsigned long long
#define PRINT_LINE cout<<ENDL;
#define MAX_N 100010
#define MOD  1000000007
#define pii pair<int,int>
#define mp(x,y) make_pair(x,y) 
 
using namespace std;
using namespace __gnu_pbds;

struct Node{
   int dist;
   vector<int> adj;
   vector<int> weight;
};
Node graf[MAX_N];
bool mark[MAX_N];
int nnodes,nedges,PB,PA1,PA2,a,b,c;


struct pq_entry{
   int node, dist;
   bool operator <(const pq_entry &a) const{
      if (dist != a.dist) return (dist > a.dist);
         return (node > a.node);
   }
};

inline void dijkstra(int source){
   priority_queue<pq_entry> pq;
   pq_entry P;
   for (int i=1;i<=nnodes;i++){
      if (i == source){
         graf[i].dist = 0;
         P.node = i;
         P.dist = 0;
         pq.push(P);
      }
      else graf[i].dist = LONG_MAX;
	  mark[i]=false;
   }
   while (!pq.empty()){
      pq_entry curr = pq.top();
      pq.pop();
      int nod = curr.node;
      int dis = curr.dist;
      for(int i=0;i<graf[nod].adj.size();i++){
         if(!mark[graf[nod].adj[i]]){
            int nextNode = graf[nod].adj[i];
            if(dis + graf[nod].weight[i] < graf[nextNode].dist){
               graf[nextNode].dist = dis + graf[nod].weight[i];
               P.node = nextNode;
               P.dist = graf[nextNode].dist;
               pq.push(P);
            }
         }
      }
      mark[nod] = true;
   }
}

signed main()
{
    OPTIMIZAR_IO
    PRESICION(2)
    //READ_FILE
    //WRITE_FILE
	cin>>nedges>>nnodes>>PB>>PA1>>PA2;
	REP_INDEX_1(nedges){
		cin>>a>>b>>c;
		graf[a].adj.push_back(b);
		graf[a].weight.push_back(c);
		
		graf[b].adj.push_back(a);
		graf[b].weight.push_back(c);
		}
	dijkstra(PB);
	int PB_to_PA1 = graf[PA1].dist;
	int PB_to_PA2 = graf[PA2].dist;
	dijkstra(PA1);
	int PA1_to_PA2 = graf[PA2].dist;
	cout<<PA1_to_PA2 + min(PB_to_PA1, PB_to_PA2)<<ENDL;
    return 0;
}

