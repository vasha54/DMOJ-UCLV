//DMOJ - Transferencia Electronica
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
#define MAX_N 100010
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
#define OO 1000000
#define RADIUS 1.50000
using namespace std;

int nnodes, nedges, nodeBegin, nodeEnd, nEdgesFail, idEdgesFail;

struct Node{
    double dist;
    vector<int> adj;
    vector<double> weight;
};

struct pq_entry{
    int node;
    double dist;
    bool operator <(const pq_entry &a) const{
        if (dist != a.dist) return (dist > a.dist);
        return (node > a.node);
    }
};

struct Edge{
   int nodeA;
   int nodeB;
   int ID;
   double dist;
   bool status;
   
   Edge(int _ID=0, int _nA=0, int _nB=0, double _d=0){
      ID=_ID;
      nodeA=_nA;
      nodeB=_nB;
      dist=_d;
      status=true;
   }
};

Node graf[MAX_N];
bool mark[MAX_N];
map<int,Edge> edges;
Edge tmp;

istream & operator>>(istream & _in, Edge & _edge){
   _in>>_edge.ID>>_edge.nodeA>>_edge.nodeB>>_edge.dist;
   return _in;
}

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
        double dis = curr.dist;
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
	
   while(cin>>nnodes>>nedges>>nEdgesFail>>nodeBegin>>nodeEnd){
      edges.clear();
      REP(i,nedges){
         cin>>tmp;
         edges.insert(make_pair(tmp.ID,tmp));
      }
      
      REP(i,nEdgesFail){
         cin>>idEdgesFail;
         edges[idEdgesFail].status=false;
      }
      
      map<int,Edge>::iterator it=edges.begin();
      while(it!=edges.end()){
         tmp=it->second;
         if(tmp.status){
            graf[tmp.nodeA].adj.push_back(tmp.nodeB);
            graf[tmp.nodeA].weight.push_back(tmp.dist);
            
            graf[tmp.nodeB].adj.push_back(tmp.nodeA);
            graf[tmp.nodeB].weight.push_back(tmp.dist);
         }
         it++;
      }
      
      dijkstra(nodeBegin);
      
      cout<<graf[nodeEnd].dist<<ENDL;
      clearGraph();
   }
   
   return 0;
}

