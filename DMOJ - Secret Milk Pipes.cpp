//DMOJ - Secret Milk Pipes
//Teoría de grafos: Segundo MTS
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
#define MAX 2010
#define MAX_N 1000010
#define MAX_ROW 1010
#define MAX_COLUMN MAX_ROW
#define MAX_NODE 3010
#define MAX_EDGE 20010
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
struct Edge{
	int source,to;
	LL weight;
	int id;
	Edge(int _i=0,int _s=0,int _t=0, LL _w=0 ){
		source=_s;
		id=_i;
		weight=_w;
		to=_t;
	}
	bool operator <(const Edge &e) const{
		return (weight < e.weight);
	}
};

struct Node{
	int parent;
	int rank;
	vector<  pair<int, int> >  adj;
	int heigth;
	vector<int> up;
	vector< pair<int, int> > dp;
};
Node DSU[MAX_NODE];

int nnodes,nedges,l=21;
Edge tEdge;
vector<Edge> edges;
vector<int> present(MAX_EDGE, 0);
pair<int,int> pairTMP;


inline void MakeSet(int x){
	DSU[x].parent = x;
	DSU[x].rank = 0;
	DSU[x].adj.clear();
	DSU[x].heigth=0;
	DSU[x].up.clear();
	DSU[x].up.resize(l,-1);
	DSU[x].dp.clear();
	DSU[x].dp.resize(l,pairTMP);
}

inline int Find(int x){
	if (DSU[x].parent == x) return x;
	DSU[x].parent = Find(DSU[x].parent);
	return DSU[x].parent;
}

inline void Union(int x, int y){
	int xRoot = Find(x);
	int yRoot = Find(y);
	if (xRoot == yRoot) return;
	if (DSU[xRoot].rank < DSU[yRoot].rank){
		DSU[xRoot].parent = yRoot;}
	else if (DSU[xRoot].rank > DSU[yRoot].rank){
		DSU[yRoot].parent = xRoot;}
	else{
		DSU[yRoot].parent = xRoot;
		DSU[xRoot].rank++;}
}

void dfs(int u, int par, int d) {
	DSU[u].heigth = 1 + DSU[par].heigth;
	DSU[u].up[0] = par;
	DSU[u].dp[0] = {d, -1};
	for (auto v : DSU[u].adj) {
		if (v.first != par) {
			dfs(v.first, u, v.second);
		}
	}
}

pair<int, int> combine(pair<int, int> a, pair<int, int> b) {
	vector<int> v = {a.first, a.second, b.first, b.second};
	int topTwo = -3, topOne = -2;
	for (int c : v) {
		if (c > topOne) {
			topTwo = topOne;
			topOne = c;
		} else if (c > topTwo && c < topOne) {
			topTwo = c;
		}
	}
	return {topOne, topTwo};
}

pair<int, int> lca(int u, int v) {
	pair<int, int> ans = {-2, -3};
	if (DSU[u].heigth < DSU[v].heigth) {
		swap(u, v);
	}
	for (int i = l - 1; i >= 0; i--) {
		if (DSU[u].heigth - DSU[v].heigth >= (1 << i)) {
			ans = combine(ans, DSU[u].dp[i]);
			u = DSU[u].up[i];
		}
	}
	if (u == v) {
		return ans;
	}
	for (int i = l - 1; i >= 0; i--) {
		if (DSU[u].up[i] != -1 && DSU[v].up[i] != -1 && DSU[u].up[i] != DSU[v].up[i]) {
			ans = combine(ans, combine(DSU[u].dp[i], DSU[v].dp[i]));
			u = DSU[u].up[i];
			v = DSU[v].up[i];
		}
	}
	ans = combine(ans, combine(DSU[u].dp[0], DSU[v].dp[0]));
	return ans;
}


void secondWeightMTS(){

	long long res = 0,ans = 2e9;
	for (int i=0;i<=nnodes;i++) MakeSet(i);

	sort(edges.begin(), edges.end());
	for(int i = 0; i<nedges; i++) {
		int a = edges[i].source;
		int b = edges[i].to;
		LL w = edges[i].weight;
		int id = edges[i].id;
		if(Find(a)!=Find(b)){
			Union(a,b);
			DSU[a].adj.emplace_back(b, w);
			DSU[b].adj.emplace_back(a, w);
			present[id] = 1;
			res += w;
		}
	}

	dfs(1,0,0);

	for (int i = 1; i <= l - 1; i++) {
		for (int j = 1; j <= nnodes; ++j) {
			if (DSU[j].up[i - 1] != -1) {
				int v = DSU[j].up[i - 1];
				DSU[j].up[i] = DSU[v].up[i - 1];
				DSU[j].dp[i] = combine(DSU[j].dp[i - 1], DSU[v].dp[i - 1]);
			}
		}
	}
	for (int i = 0; i < nedges ; i++) {
		int id = edges[i].id;
		LL w = edges[i].weight;
		if (!present[id]) {
			auto rem = lca(edges[i].source, edges[i].to);
			if (rem.first != w) {
				if (ans > res + w - rem.first) {
					ans = res + w - rem.first;
				}
			} else if (rem.second != -1) {
				if (ans > res + w - rem.second) {
					ans = res + w - rem.second;
				}
			}
		}
	}

	cout<<ans<<ENDL;
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
			cin>>tEdge.source>>tEdge.to>>tEdge.weight;
			tEdge.id=i;
			edges.push_back(tEdge);
		}
		secondWeightMTS();
	}

	return 0;
}

