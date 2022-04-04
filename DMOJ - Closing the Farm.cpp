//DMOJ - Closing the Farm
//Teoría de grafos : Componentes conexa

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
#include <map>
#include <utility>
#define MID (left+right)/2
#define MOD 100000007
#define MAX 3010
#define MAX_N 100001
#define MAX_ROW 1010
#define MAX_COLUMN MAX_ROW
#define MAX_NODE 2010
#define MAX_EDGE 55000
#define MAXTREE (MAX << 2)
#define ULL unsigned long long
#define LL long long
#define NUMBER LL
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
#define OO 1000000000
#define RADIUS 1.50000
using namespace std;


struct Node{
	vector<int> neigborns;
};

Node graphs[MAX];
int nnodes,npath,nfarmClose,nvisit,nodeA,nodeB;
bool visit[MAX],farmClose[MAX];
set<int> nodeActive;

bool connectFull(int _nodeStart){

	fill(visit,visit+MAX,false);
	visit[_nodeStart]=true;
	nvisit=1;
	int nCurrent,nNext;
	stack<int> dfs;
	dfs.push(_nodeStart);

	while(!dfs.empty()){
		nCurrent=dfs.top();
		dfs.pop();
		FOR(it,graphs[nCurrent].neigborns){
			nNext=(*it);
			if(!visit[nNext] && !farmClose[nNext]){
				nvisit++;
				visit[nNext]=true;
				dfs.push(nNext);
			}
		}
	}

	return (nfarmClose+nvisit==nnodes);
}

int main(){


	//freopen("Input.txt","r",stdin);
	//freopen("Output.txt","w",stdout);
	cout.setf(ios::fixed,ios::floatfield);
	cout.precision(2);
	ios_base::sync_with_stdio(0);
	std::cin.tie(0);

	while(cin>>nnodes>>npath){
		REP1_N(i,nnodes){
			graphs[i].neigborns.clear();
			nodeActive.insert(i);
		}
		REP(i,npath){
			cin>>nodeA>>nodeB;
			graphs[nodeA].neigborns.push_back(nodeB);
			graphs[nodeB].neigborns.push_back(nodeA);
		}
		fill(farmClose,farmClose+MAX,false);
		nfarmClose=0;
		REP1_N(i,nnodes){
			connectFull((*nodeActive.begin()))==true ?cout<<"YES"<<ENDL : cout<<"NO"<<ENDL;
			cin>>nodeA;
			farmClose[nodeA]=true;
			nodeActive.erase(nodeA);
			nfarmClose++;
		}
	}

	return 0;
}

