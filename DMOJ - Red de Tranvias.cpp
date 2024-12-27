//DMOJ - Red de Tranvías
//Teoría de grafos: Disktraj
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
#define MAX 110
#define MAX_ROW 510
#define MAX_COLUMN MAX_ROW
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
#define EPS 1e-15
#define OO 50000
using namespace std;

int nnodes,nodeA,nodeB,nedges,nodeAdj;

struct Node{
    int dist;
    vector<int> adj;
    vector<int> weight;
};
Node graf[MAX];
bool mark[MAX];

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
        else graf[i].dist = OO;
    }
    while (!pq.empty()){
        pq_entry curr = pq.top();
        pq.pop();
        int nod = curr.node;
        int dis = curr.dist;
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

int main(){
  // freopen ("Input.txt","r",stdin );
    //freopen ("Output.txt","w",stdout );
   cout.setf (ios::fixed ,ios::floatfield);
   cout.precision (7) ;
   ios_base::sync_with_stdio(0);
   std::cin.tie(0);

   while(cin>>nnodes>>nodeA>>nodeB){
        memset(mark,false,sizeof(mark));
        REP1_N(i,nnodes){
            graf[i].adj.clear();
            graf[i].weight.clear();
        }
        REP1_N(i,nnodes){
            cin>>nedges;
            REP(j,nedges){
                cin>>nodeAdj;
                graf[i].adj.push_back(nodeAdj);
                (j==0) ? graf[i].weight.push_back(0): 
                            graf[i].weight.push_back(1);
            }
        }
        dijkstra(nodeA);
        if(graf[nodeB].dist==OO)
            cout<<-1<<ENDL;
        else
            cout<<graf[nodeB].dist<<ENDL;
   }
   
   
   return 0;
}
