//DMOJ - Envíos de Paquetes
//Teoría de Grafos: Dijkstra
#include <iostream>
#include <vector>
#include <algorithm>
#include <stdio.h>
#include <math.h>
#include <stack>
#include <set>
#include <queue>
#include <string>
#include <string.h>
#include <map>
#include <complex>
#include <cmath>
#define MID (left+right)/2
#define MOD 1000000007
#define MAX 100010
#define MAX_N 50010
#define MAX_ROW 1010
#define MAX_COLUMN MAX_ROW
#define MAX_NODE 2010
#define MAX_EDGE 55000
#define MAXTREE (MAX << 2)
#define ULL unsigned long long
#define LL long long
#define ENDL '\n'
#define SYMBOL '#'
#define REP(i,n) for(int i=0;i<(int)n;++i)
#define REP1_N(i,n) for(int i=1;i<=(int)n;++i)
#define FOR(i,c) for(__typeof((c).begin())i=(c).begin();i!=(c).end();++i)
#define ALL(c) (c).begin(), (c).end()
#define LINE_BLANK cout<<ENDL;
#define OPERATOR_INC "++"
#define OPERATOR_DEC "--"
#define MAXELEMENT 260
#define MAXCAPACITYKNAPSACK 1010
#define EPS 1e-9
#define OO 100000000
#define RADIUS 1.50000
using namespace std;

int nnodes, nedges, nodeA, nodeB, cost;

struct Node{
    LL dist;
    vector<int> adj;
    vector<LL> weight;
};
Node graf[MAX_N];
bool mark[MAX_N];

struct pq_entry{
    int node;
    LL  dist;
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
        else graf[i].dist = OO;
    }
    while (!pq.empty()){
        pq_entry curr = pq.top();
        pq.pop();
        int nod = curr.node;
        LL dis = curr.dist;
        for (int i=0;i<graf[nod].adj.size();i++){
            if (!mark[graf[nod].adj[i]]){
                int nextNode = graf[nod].adj[i];
                if (dis + graf[nod].weight[i] < graf[nextNode].dist){
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

void clearGraph(){
   REP1_N(i,nnodes){
      graf[i].adj.clear();
      graf[i].weight.clear();
   }
}

int main(){
	//freopen("Input.txt","r",stdin);
   //freopen("Output.txt","w",stdout);
	cout.setf(ios::fixed,ios::floatfield);
	cout.precision(2);
	ios_base::sync_with_stdio(0);
	std::cin.tie(0);
	
   while(cin>>nnodes>>nedges){
      REP(i,nedges){
         cin>>nodeA>>nodeB>>cost;
         graf[nodeA].adj.push_back(nodeB);
         graf[nodeA].weight.push_back(cost);
         graf[nodeB].adj.push_back(nodeA);
         graf[nodeB].weight.push_back(cost);
      }
      dijkstra(1);
      cout<<graf[nnodes].dist<<ENDL;
      clearGraph();
   }
   
   return 0;
}

