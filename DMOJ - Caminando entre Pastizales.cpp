/**
* DMOJ - Caminando entre Pastizales
* Temática: Teoria de Grafos: DFS
* Idea: Tenemos un árbol sobre cual se realiza una serie de preguntas del
* tipo (p1,p2) donde se debe calcular la distancia entre los nodos p1 y p2.
* Dada las cantidad de nodos del árbol podemos precalcular todas las posibles
* preguntas ya que la respuesta para (p1,p2) es la misma que (p2,p1) vamos a ir
* almacenando las soluciones en una matriz.
*/
#include <iostream>
#include <math.h>
#include <bits/stdc++.h>
#define ENDL '\n'
#define OPTIMIZAR_IO ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define PRESICION(x) cout.setf(ios::fixed,ios::floatfield); cout.precision(x);
#define READ_FILE freopen("Input.txt","r",stdin);
#define WRITE_FILE freopen("Output.txt","w",stdout);
#define MAX_N 1010
#define MOD 1000000007
#define EPS 1e-9
#define INF 1000000000
#define int long long
#define uint unsigned long long
#define pii pair<int,int>
#define ALPHABET_SIZE 26 //['a-z']
#define K 25
using namespace std;

struct Node{
    vector<pair<int,int> > neighborns;
};

Node graphs[MAX_N];
int cost[MAX_N][MAX_N], times[MAX_N], nnodes, nqueries, maxQueries, a, b, c;

void dfs(int source,int t){
    times[source]=t;
    for(auto neigborn : graphs[source].neighborns){
        if(times[neigborn.first] == -1){
            dfs(neigborn.first,t+neigborn.second);
        }
    }
}

signed main(){
    OPTIMIZAR_IO
    PRESICION(0)
    //READ_FILE
    cin>>nnodes>>nqueries;

    for(int i=1;i<=nnodes;i++){
        fill(cost[i],cost[i]+MAX_N,-1);
        graphs[i].neighborns.clear();
    }

    for(int i=0;i<nnodes-1;i++){
        cin>>a>>b>>c;
        graphs[a].neighborns.push_back({b,c});
        graphs[b].neighborns.push_back({a,c});
    }

    maxQueries=nnodes*nnodes;

    while(maxQueries > 0){
        for(int i=1;i<=nnodes  && maxQueries;i++){
            cost[i][i]=0;
            maxQueries--;
            for(int j=i;j<=nnodes && maxQueries;j++){
                if(cost[i][j]!=-1) continue;
                fill(times,times+MAX_N,-1);
                dfs(i,0);
                for(int k=1;k<=nnodes;k++){
                    if(i!=k && cost[i][k]==-1){
                        maxQueries-=2;
                        cost[i][k]=cost[k][i]=times[k];
                    }
                }
            }
        }
    }

    for(int i=0;i<nqueries;i++){
        cin>>a>>b;
        cout<<cost[a][b]<<ENDL;
    }

    return 0;
}
