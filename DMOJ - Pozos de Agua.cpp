//DMOJ - Pozos de Agua
//Teoría de Grafos: Kruskal modificado.
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
#define MAX 310
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

int npasture,costWaterWell[MAX];
ULL minCost,matrixCost[MAX][MAX];

struct Edge{
    int a, b;
    ULL weight;
    Edge(int _a=0,int _b=0, ULL _c=0){
        a=_a;
        b=_b;
        weight=_c;
    }
    
    bool operator <(const Edge &e) const{
        return (weight < e.weight);
    }
};
vector<Edge> edges;

struct Node{
    int parent;
    int rank;
    int parentWaterWell;
};
Node DSU[MAX];

inline void MakeSet(int x){
    DSU[x].parent = x;
    DSU[x].rank = 0;
    DSU[x].parentWaterWell=x;
}

inline int Find(int x){
    if (DSU[x].parent == x) return x;
    DSU[x].parent = Find(DSU[x].parent);
    return DSU[x].parent;
}

inline ULL FindWaterWellParent(int x){
    if (DSU[x].parent == x) return costWaterWell[x];
    DSU[x].parent = Find(DSU[x].parent);
    return costWaterWell[DSU[x].parent];
}

inline void Union(int x, int y){
    int xRoot = Find(x);
    int yRoot = Find(y);
    if (xRoot == yRoot) return;
    if (costWaterWell[xRoot] > costWaterWell[yRoot]){
        DSU[xRoot].parent = yRoot;}
    else if (costWaterWell[xRoot] < costWaterWell[yRoot]){
        DSU[yRoot].parent = xRoot;}
    else{
        DSU[yRoot].parent = xRoot;
        DSU[xRoot].rank++;}
}

inline void buidlRedWater(){
    int  numComponents = npasture;
    int nedges=edges.size();
    for (int i=0;i<npasture;i++) MakeSet(i);
    sort(edges.begin(), edges.end());
    for (int i=0;i < nedges && numComponents > 1;i++){
        int nodeA=edges[i].a;
        int nodeB=edges[i].b;
        ULL cost=edges[i].weight;
        
        if (Find(nodeA) != Find(nodeB)){
            ULL wellA=FindWaterWellParent(nodeA);
            ULL wellB=FindWaterWellParent(nodeB);
            
            if(minCost>minCost-max(wellA,wellB)+cost){
                minCost=minCost-max(wellA,wellB)+cost;
                Union(nodeA, nodeB);
                numComponents--;
            }
        }
    }
    
}

int main(){
  // freopen ("Input.txt","r",stdin );
   //freopen ("Output.txt","w",stdout );
   cout.setf (ios::fixed ,ios::floatfield);
   cout.precision (7) ;
   ios_base::sync_with_stdio(0);
   std::cin.tie(0);

   while(cin>>npasture){
       minCost=0;
       REP(i,npasture){
        cin>>costWaterWell[i];
        minCost+=costWaterWell[i];
        }
       REP(i,npasture)
        REP(j,npasture){
            cin>>matrixCost[i][j];
            if(i<j)
                edges.push_back(Edge(i,j,matrixCost[i][j]));
        }
       buidlRedWater();
       cout<<minCost<<ENDL;
    }
   
   return 0;
}
