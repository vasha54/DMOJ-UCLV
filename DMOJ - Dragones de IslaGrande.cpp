//DMOJ - Dragones de IslaGrande
//Teoría de grafos : BFS y Dijkstra
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
#define MOD % 100000000
#define MAX 100010
#define MAX_ROW 1010
#define MAX_COLUMN MAX_ROW
#define MAX_NODE 2010
#define MAX_EDGE 55000
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

struct Neighbors{
	int node;
	ULL cost;

	Neighbors(int _node=0, ULL _cost=OO ){
		node=_node;
		cost=_cost;
	}
};

struct Island{
	ULL dist;
	vector<Neighbors> adj;
	ULL dragon;
	ULL dragonVisit;
	bool visit;
};

struct pq_entry{
	int node;
	ULL dist,dragon;
	bool operator <(const pq_entry &a) const{
		if (dist != a.dist) return (dist > a.dist);
		else{
			if(dragon!=a.dragon) return (dragon < a.dragon);
			else return (node > a.node);
		}


	}
};

ostream & operator<<(ostream & _out, pq_entry entry){
	_out<<" Node:"<<entry.node<<" dist:"<<entry.dist<<" dragon:"<<entry.dragon<<ENDL;
	return _out;
}

Island graph[MAX];
int nislands,npaths,operation,islandA,islandB;
ULL lentgh;

void operation1(int _node){
	ULL limit=graph[_node].dragon;
	graph[_node].visit=true;

	int currNode,nextNode;
	queue<int> visits;
	visits.push(_node);

	while(!visits.empty()){
		currNode=visits.front();
		visits.pop();

		for (int i=0;i<graph[currNode].adj.size();i++){
			nextNode=graph[currNode].adj[i].node;

			if(graph[nextNode].visit==false && graph[currNode].adj[i].cost<=limit){
				graph[nextNode].visit=true;
				visits.push(nextNode);
			}
		}
	}

	ULL solution=0;

	REP1_N(i,nislands){
		if(graph[i].visit)
			solution=max(solution,graph[i].dragon);
		graph[i].adj.clear();

	}

	cout<<solution<<ENDL;
}

void operation2(int _node){
	priority_queue<pq_entry> pq;
	pq_entry P;
	for (int i=1;i<=nislands;i++){
		if (i == _node){
			graph[i].dist = 0;
			P.node = i;
			P.dist = 0;
			P.dragon=graph[i].dragon;
			pq.push(P);
		}
	}

	while (!pq.empty()){
		pq_entry curr = pq.top();
		pq.pop();
		int nod = curr.node;
		ULL dis = curr.dist;
		ULL dragon=curr.dragon;
		for (int i=0;i<graph[nod].adj.size();i++){

			int nextNode = graph[nod].adj[i].node;

			if(dis+graph[nod].adj[i].cost < graph[nextNode].dist &&
					dragon >= graph[nod].adj[i].cost){

				graph[nextNode].dist=dis+graph[nod].adj[i].cost;
				graph[nextNode].dragonVisit=max(dragon,graph[nextNode].dragonVisit);
				P.node = nextNode;
				P.dist = graph[nextNode].dist;
				P.dragon = max(dragon,
						max(graph[nextNode].dragonVisit,graph[nextNode].dragon));
				pq.push(P);
			}
			else if(dis+graph[nod].adj[i].cost == graph[nextNode].dist &&
					dragon >= graph[nod].adj[i].cost &&
					(graph[nextNode].dragon < dragon || graph[nextNode].dragonVisit < dragon)){

				graph[nextNode].dist=dis+graph[nod].adj[i].cost;
				graph[nextNode].dragonVisit=max(dragon,graph[nextNode].dragonVisit);
				P.node = nextNode;
				P.dist = graph[nextNode].dist;
				P.dragon = max(dragon,
						max(graph[nextNode].dragonVisit,graph[nextNode].dragon));
				pq.push(P);
			}
			else if(dis+graph[nod].adj[i].cost > graph[nextNode].dist &&
					dragon >= graph[nod].adj[i].cost &&
					graph[nextNode].dragon < dragon &&
					graph[nextNode].dragonVisit < dragon){

				graph[nextNode].dragonVisit=max(dragon,graph[nextNode].dragonVisit);
				P.node = nextNode;
				P.dist = dis+graph[nod].adj[i].cost;
				P.dragon = max(dragon,
						max(graph[nextNode].dragonVisit,graph[nextNode].dragon));

				pq.push(P);
			}
		}

	}

	cout<<graph[nislands].dist<<ENDL;

	REP1_N(i,nislands){
		graph[i].adj.clear();
	}
}


int main(){

	//freopen ("Input.txt","r",stdin );
	//freopen ("Output.txt","w",stdout );
	cout.setf (ios::fixed ,ios::floatfield );
	cout.precision (2) ;
	ios_base::sync_with_stdio(0);
	std::cin.tie(0);

	while(cin>>operation){
		cin>>nislands>>npaths;
		REP1_N(i,nislands){
			graph[i].visit=false;
			graph[i].dist=OO;
			cin>>graph[i].dragon;
			graph[i].dragonVisit=0;
		}

		REP(i,npaths){
			cin>>islandA>>islandB>>lentgh;
			graph[islandA].adj.push_back(Neighbors(islandB,lentgh));
			graph[islandB].adj.push_back(Neighbors(islandA,lentgh));
		}

		switch (operation) {
		case 1:
			operation1(1);
			break;
		case 2:
			operation2(1);
			break;
		default:
			break;
		}

	}

	return 0;
}
