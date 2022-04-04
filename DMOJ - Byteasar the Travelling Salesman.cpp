//DMOJ - Byteasar the Travelling Salesman
//Teoría de Grafos: LCA
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

struct LCA {
   vector<int> height, euler, first, segtree;
   vector<bool> visited;
   int n;

   LCA(vector<vector<int> > &adj, int root = 0) {
      n = adj.size();
      height.resize(n);
      first.resize(n);
      euler.reserve(n * 2);
      visited.assign(n, false);
      dfs(adj, root);
      int m = euler.size();
      segtree.resize(m * 4);
      build(1, 0, m - 1);
   }

   void dfs(vector<vector<int> > &adj, int node, int h = 0) {
      visited[node] = true;
      height[node] = h;
      first[node] = euler.size();
      euler.push_back(node);
      FOR(k,adj[node]) {
          int to=(*k);
        if(!visited[to]) {
          dfs(adj, to, h + 1);
          euler.push_back(node);
        }
      }
   }

   void build(int node, int b, int e) {
      if(b==e){
        segtree[node] = euler[b];
      } else {
        int mid = (b + e) / 2;
        build(node << 1, b, mid);
        build(node << 1 | 1, mid + 1, e);
        int l = segtree[node << 1], r = segtree[node << 1 | 1];
        segtree[node] = (height[l] < height[r]) ? l : r;
      }
   }

   int query(int node, int b, int e, int L, int R) {
      if (b > R || e < L)
         return -1;
      if (b >= L && e <= R)
         return segtree[node];
      int mid = (b + e) >> 1;

      int left = query(node << 1, b, mid, L, R);
      int right = query(node << 1 | 1, mid + 1, e, L, R);
      if (left == -1) return right;
      if (right == -1) return left;
      return height[left] < height[right] ? left : right;
   }

   int lca(int u, int v) {
       int left = first[u], right = first[v];
       if (left > right)
       swap(left, right);
       return query(1, 0, euler.size() - 1, left, right);
   }
};

int nnodes,nquerys,timeTravel,nodeA,nodeB,nodeLCA;
vector<vector <int> >matrixAdy;

LCA * m_lca;

int main(){
	//freopen("Input.txt","r",stdin);
   //freopen("Output.txt","w",stdout);
	cout.setf(ios::fixed,ios::floatfield);
	cout.precision(2);
	ios_base::sync_with_stdio(0);
	std::cin.tie(0);

    while(cin>>nnodes){
        matrixAdy.clear();
        matrixAdy.resize(nnodes);
        REP(i,nnodes-1){
           cin>>nodeA>>nodeB;
           nodeA--;
           nodeB--;
           matrixAdy[nodeA].push_back(nodeB);
           matrixAdy[nodeB].push_back(nodeA);
        }

        m_lca=new LCA(matrixAdy,0);

        timeTravel=0;
        cin>>nquerys;
        nodeA=0;
        REP(i,nquerys){
            cin>>nodeB;
            nodeB--;
            nodeLCA=m_lca->lca(nodeA,nodeB);
            timeTravel+=((m_lca->height[nodeA]-m_lca->height[nodeLCA])
                         +(m_lca->height[nodeB]-m_lca->height[nodeLCA]));
            nodeA=nodeB;

        }
        cout<<timeTravel<<ENDL;

        delete m_lca;
    }


   return 0;
}

