//DMOJ - Suma de dígitos
//Teoría de grafos:BFS + Programación Dinámica
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
#define MOD 10000000
#define MAX 1000010
#define MAXTREE (MAX << 2)
#define MAX_NODE 66000
#define LIMIT 2500000100
#define ULL unsigned long long
#define LL long long
#define ENDL '\n'
#define SYMBOL '#'
#define REP(i,n) for(int i=0;i<(int)n;++i)
#define REP1_N(i,n) for(int i=1;i<=(int)n;++i)
#define FOR(i,c) for(__typeof((c).begin())i=(c).begin();i!=(c).end();++i)
#define ALL(c) (c).begin(), (c).end()
#define LINE_BLANK cout<<ENDL;
#define OO 1111000
using namespace std;

struct Node{
	ULL bitActive;
	ULL bitActiveAcumulated;
};

Node graph[MAX];

int n;

void precalculate(){

	REP(i,MAX){
		graph[i].bitActive=0;
		graph[i].bitActiveAcumulated=0;
	}
	graph[1].bitActive=1;

	queue<int> visit;

	visit.push(1);

	int cNode,nNode;

	while(!visit.empty()){

		cNode=visit.front();
		visit.pop();

		nNode=cNode<<1;

		if(nNode<MAX){
			graph[nNode].bitActive=graph[cNode].bitActive;
			visit.push(nNode);
		}

		nNode=(cNode<<1)+1;

		if(nNode<MAX){
			graph[nNode].bitActive=graph[cNode].bitActive+1;
			visit.push(nNode);
		}
	}

	REP1_N(i,MAX-1){
		graph[i].bitActiveAcumulated=
				graph[i-1].bitActiveAcumulated+graph[i].bitActive;
	}
}

int main(){
	//freopen ("Input.txt","r",stdin );
	//freopen ("Output.txt","w",stdout );
	cout.setf (ios::fixed ,ios::floatfield );
	cout.precision (2) ;
	ios_base::sync_with_stdio(0);
	std::cin.tie(0);

	precalculate();

	while(cin>>n){
		cout<<graph[n].bitActiveAcumulated<<ENDL;
	}

	return 0;
}
