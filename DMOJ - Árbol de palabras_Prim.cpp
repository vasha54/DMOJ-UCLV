/**
 * DMOJ - Árbol de palabras
 * Tematica : Teoria de Grafos: Prim
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
#define INF 1000000000
#define LL long long
#define ULL unsigned long long
#define pii pair<int,int>
#define ALPHABET_SIZE 26 //['a-z']
using namespace std;

int n,length;
char  names[MAX_N][20];
vector<vector<int> > adj; //matrix de adyacencia
struct Edge { int w = INF, to = -1; };

int  prim() {
   int total_weight = INT_MIN;
   vector<bool> selected(n, false);
   vector<Edge> min_e(n);
   min_e[0].w = 0;

   for(int i=0;i<n;++i){
      int v = -1;
      for(int j = 0; j < n; ++j) {
         if(!selected[j] && (v==-1 || min_e[j].w<min_e[v].w))
            v = j;
      }
      if(min_e[v].w == INF) {
         i=n+1;
         continue;
      }

      selected[v] = true;
      total_weight =max(total_weight, min_e[v].w);
//      if(min_e[v].to!=-1)
//         cout <<v<<" "<<min_e[v].to<<endl;
      for(int to=0;to<n;++to){
         if(adj[v][to] < min_e[to].w)
            min_e[to] = {adj[v][to], v};
      }
   }
   return total_weight ;
}

int cost(char * a, char * b, int l){
	int c =0;
	for(int i=0;i<l;i++) c+=abs(a[i]-b[i]);
	return c;
}

int main() {
	OPTIMIZAR_IO
	cin>>n>>length;
	vector<int> row(n,0);
	for(int i=0;i<n;i++){
		cin>>names[i];
		adj.push_back(row);
	}
	for(int i=0;i<n;i++){
		for(int j=i+1;j<n;j++){
			adj[i][j] = adj[j][i] = cost(names[i],names[j],length);
		}
	}

	cout<<prim()<<ENDL;

	return 0;
}

