/**
 * DMOJ - Escondidas
 * Temática: Teoria de grafos : BFS + Camino mínimo
 * 
 * Idea: Una vez leido el problema vemos que podemos modelar la situación como 
 * grafo donde cada nodo es un establo y entre estos existirá aristas si existe 
 * un camino. Por lo descrito es un grafo no dirigido no poderado (la 
 * ponderación es constante porque todas las aristas tienen el mismo valor 1.)
 * El problema nos pide hallar una triada de información:
 *   - El establo mas lejos del establo 1. De existir varios imprimir el de 
 * menor indice
 *   - La distancia del nodo 1 a esos nodos.
 *   - Cuantos nodos están a esa distancia del nodo 1.
 *  
 * Para responder vamos a utilizar un BFS aunque se puede usar algoritmos de 
 * cámino mínimo de un nodo hacia los demás pero en este caso como todos las
 * aristas tienen un peso constante se puede utilizar el BFS. Con el BFS guardo
 * para cada nodo/establo lo que me costo llegar o lo que es lo mismo la cantidad
 * de aristas recorridas para llegar a él. Luego buscaré el mayor valor de esos 
 * caminos mínimos. Con dicho valor podré hallar el establo de menor indice que
 * este a esa distancia de establo/nodo 1 y la cantidad de establo/nodos que están
 * a similar distancia del establo.
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
#define MAX_N 20010
#define MOD  1000000007
#define pii pair<int,int>
#define mp(x,y) make_pair(x,y) 
 
using namespace std;
using namespace __gnu_pbds;

struct Node{
	int dist;
	vector<int> neighbors;
	Node(){
		dist = LONG_MAX;
		}
	};

Node graph[MAX_N];

void bfs(int node){
	queue<pii> order_bfs;
	order_bfs.push(mp(node,0));
	graph[node].dist = 0;
	
	while(!order_bfs.empty()){
		pii current = order_bfs.front();
		order_bfs.pop();
		for(auto neighbor : graph[current.first].neighbors){
			if(graph[neighbor].dist > current.second + 1){
				graph[neighbor].dist = current.second + 1;
				order_bfs.push(mp(neighbor,current.second + 1));
				} 
			}
		}
	}

signed main()
{
    OPTIMIZAR_IO
    PRESICION(2)
    //READ_FILE
    //WRITE_FILE
	int nnodes, nedges, A, B, max_path = LONG_MIN, node = 0, count = 0;
	cin>>nnodes>>nedges;
	REP_INDEX_0(nedges){
		cin>>A>>B;
		graph[A].neighbors.push_back(B);
		graph[B].neighbors.push_back(A);
		}
	bfs(1);
	REP_INDEX_1(nnodes) {
		if (max_path < graph[i].dist){
			node = i ;
			count = 1;
			max_path = graph[i].dist;
			}
		else if(max_path == graph[i].dist) count ++;
		}
	cout<<node<<" "<<max_path<<" "<<count<<ENDL;
    return 0;
}

