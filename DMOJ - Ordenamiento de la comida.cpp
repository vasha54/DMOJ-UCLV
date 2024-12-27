//DMOJ - Ordenamiento de la comida
//Ordenamiento+ Teoria de grafo: Componente fuertemente conexa+
//Programación dinamica
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
#include <limits.h>
#include <limits>
#define MID (left+right)/2
#define MOD % 100000000
#define MAX 10010
#define MAX_ROW 310
#define MAX_COLUMN MAX_ROW
#define MAX_NODE 31210
#define MAX_EDGE 31210
#define MAXTREE (MAX << 2)
#define ULL unsigned long long
#define LL long long
#define NUMBER LL
#define ENDL '\n'
#define SYMBOL "#"
#define REP(i,n) for(int i=0;i<(int)n;++i)
#define REP1_N(i,n) for(int i=1;i<=(int)n;++i)
#define FOR(i,c) for(__typeof((c).begin())i=(c).begin();i!=(c).end();++i)
#define ALL(c) (c).begin(), (c).end()
#define LINE_BLANK cout<<ENDL;
#define OPERATOR_INC "++"
#define OPERATOR_DEC "--"
#define SYMBOL "#"
#define MAXELEMENT 260
#define MAXCAPACITYKNAPSACK 1010
#define EPS 1e-9
#define OO 1000000000000000
#define RADIUS 1.50000

const int mov_r[]={ 0, 0,-1, 1};
const int mov_c[]={ 1,-1, 0, 0};

using namespace std;

struct Order{
	int indexPreOrder;
	int indexPosOrder;

	Order(int iPreO=0){
		indexPreOrder=iPreO;
		indexPosOrder=-1;
	}
};

struct Node{
	ULL value;
	int following;
	bool visit;

	Node(ULL _v=0,int _f=0){
		visit=false;
		following=_f;
		value=_v;
	}
};

struct Ring{
	ULL N;
	ULL sumAll;
	ULL X;
	ULL Q;

	Ring(){
		N=0;
		sumAll=0;
		X=0;
		Q=0;
	}
};

ostream & operator<<(ostream & out, Ring _r){
	out<<"N:"<<_r.N<<" Q:"<<_r.Q<<" X:"<<
			_r.X<<" sumAll:"<<_r.sumAll;
	return out;
}

int nelements;
ULL elements[MAX],elementsOrder[MAX],Xmin,energy;
map<ULL,Order> orders;
Node graph[MAX];
vector<Ring> rings;
Ring tmp;

Ring findRing(int _nodeStart){

	int currNode,nextNode;
	queue<int> visit;
	ULL X=LLONG_MAX;
	ULL N=0, All=0;

	graph[_nodeStart].visit=true;
	visit.push(_nodeStart);

	while(!visit.empty()){
		currNode=visit.front();
		visit.pop();

		N++;
		All+=graph[currNode].value;
		X=min(graph[currNode].value,X);

		nextNode=graph[currNode].following;

		if(graph[nextNode].visit==false){
			visit.push(nextNode);
			graph[nextNode].visit=true;
		}
	}

	Ring answer;

	answer.N=N;
	answer.Q=All-X;
	answer.sumAll=All;
	answer.X=X;

	return answer;
}

int main(){

	//freopen ("Input.txt","r",stdin );
	//freopen ("Output.txt","w",stdout );
	cout.setf (ios::fixed ,ios::floatfield );
	cout.precision (2) ;
	ios_base::sync_with_stdio(0);
	std::cin.tie(0);

	while(cin>>nelements){

		orders.clear();
		Xmin=LLONG_MAX;

		REP(i,nelements){
			cin>>elements[i];
			Xmin=min(elements[i],Xmin);
			elementsOrder[i]=elements[i];
			orders.insert( make_pair(elements[i],Order(i)) );
		}

		sort(elementsOrder,elementsOrder+nelements);

		REP(i,nelements){
			orders[elementsOrder[i]].indexPosOrder=i;
			Order tmp=orders[elementsOrder[i]];

			graph[tmp.indexPreOrder]=Node(elementsOrder[i],
					tmp.indexPosOrder);
		}

		rings.clear();
		energy=0;

		REP(i,nelements){
			if(graph[i].visit==false){
				tmp=findRing(i);
				rings.push_back(tmp);
				energy+=(tmp.Q+(tmp.N-1)*tmp.X);
			}
		}

		FOR(r,rings){
			ULL current=((*r).Q + ((*r).N-1)*(*r).X);
			ULL variant=((*r).Q + ((*r).N-1)*Xmin)+ 2*(Xmin+(*r).X);
			if(energy-current+variant<energy){
				energy=energy-current+variant;
			}
		}

		cout<<energy<<ENDL;
	}

	return 0;
}
