//DMOJ - En Hombros
//Teoria de Grafos: BFS
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
#define MOD  1000000007
#define MAX 100010
#define MAX_N 30010
#define MAX_ROW 1010
#define MAX_COLUMN MAX_ROW
#define MAX_NODE 40010
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
#define OO 1000010
#define RADIUS 1.50000
using namespace std;

const int mov_c[]={0, 0, 1,-1, 1, 1,-1,-1};
const int mov_r[]={1,-1, 0, 0, 1,-1, 1,-1};

struct Node{
	LL distN1;
	LL distN2;
	LL distNN;

	vector<int> neighborns;

	Node(){
		distN1=INT64_MAX;
		distN2=INT64_MAX;
		distNN=INT64_MAX;
		neighborns.clear();
	}

	void clear(){
		distN1=INT64_MAX;
		distN2=INT64_MAX;
		distNN=INT64_MAX;
		neighborns.clear();
	}
};

LL B,E,P,answer;
int nnodes, nedges, nodeA,nodeB;
Node graphs[MAX_NODE];
bool mark[MAX_NODE];

void bfs(int _nodeStart){
	fill(mark,mark+MAX_NODE,false);
	queue<int> visit;

	int currNode,nextNode;

	if(_nodeStart==1) graphs[_nodeStart].distN1=0;
	else if(_nodeStart==2) graphs[_nodeStart].distN2=0;
	else graphs[_nodeStart].distNN=0;

	mark[_nodeStart]=true;
	visit.push(_nodeStart);

	while(!visit.empty()){
		currNode=visit.front();
		visit.pop();
		FOR(it,graphs[currNode].neighborns){
			nextNode=(*it);
			if(!mark[nextNode]){
				mark[nextNode]=true;
				visit.push(nextNode);

				if(_nodeStart==1) graphs[nextNode].distN1=graphs[currNode].distN1+1;
				else if (_nodeStart==2) graphs[nextNode].distN2=graphs[currNode].distN2+1;
				else graphs[nextNode].distNN=graphs[currNode].distNN+1;

			}
		}
	}
}

int main(){
	//freopen("Input.txt","r",stdin);
	//freopen("Output.txt","w",stdout);
	cout.setf(ios::fixed,ios::floatfield);
	cout.precision(2);
	ios_base::sync_with_stdio(0);
	std::cin.tie(0);

	while(cin>>B>>E>>P>>nnodes>>nedges){
		REP1_N(i,nnodes){
			graphs[i].clear();
		}
		REP(i,nedges){
			cin>>nodeA>>nodeB;
			graphs[nodeA].neighborns.push_back(nodeB);
			graphs[nodeB].neighborns.push_back(nodeA);
		}

		bfs(1);
		bfs(2);
		bfs(nnodes);

		answer=graphs[1].distN1*B+
				graphs[1].distN2*E+
				graphs[1].distNN*P;

		for(int i=2;i<=nnodes;i++){
			answer=min(answer,graphs[i].distN1*B+
					graphs[i].distN2*E+
					graphs[i].distNN*P);
		}

		cout<<answer<<ENDL;
	}

	return 0;
}

