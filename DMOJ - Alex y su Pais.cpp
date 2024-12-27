//DMOJ - Alex y su Pais
//Teoría de Grafos: Distrakj con dos condiciones
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
#define MOD1 % 3
#define MAX 100010
#define MAX_N 30
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
#define OO 1000000000000000
#define RADIUS 1.50000

const int mov_r[]={ 0, 0,-1, 1};
const int mov_c[]={ 1,-1, 0, 0};

using namespace std;

enum TypeConnect {STREET, LINE_TRAIN, UNDEFINED};

struct Edge{
	int to;
	int source;
	int id;
	ULL cost;
	TypeConnect connect;

	Edge(int _id=0,int _to=0,int _source=0, ULL _cost=OO,
			TypeConnect _connect=UNDEFINED){
		to=_to;
		source=_source;
		id=_id;
		cost=_cost;
		connect=_connect;
	}

	bool operator <(const Edge &a) const{
		if(cost==a.cost){
			if(connect!=a.connect) return (connect<a.connect);
			return (id<a.id);
		}
		else{
			return (cost < a.cost);
		}
	}
};

ostream & operator<<(ostream & _out, Edge edge){
	_out<<"id:"<<edge.id<<" to:"<<edge.to<<" source:"<<
			edge.source<<" cost:"<<edge.cost<<" connect:"<<edge.connect<<ENDL;
	return _out;
}

struct Neighbors{
	int node;
	ULL cost;
	TypeConnect connect;

	Neighbors(int _node=0, ULL _cost=OO , TypeConnect _connect=UNDEFINED){
		node=_node;
		cost=_cost;
		connect=_connect;
	}

	bool operator <(const Neighbors &a) const{
		if(connect==a.connect){
			if(cost!=a.cost) return (cost>a.cost);
			return (node>a.node);
		}
		else{
			return (connect > a.connect);
		}
	}
};

struct Node{
	ULL dist;
	vector<Neighbors> adj;
	int parent;
	TypeConnect connectParent;
};


Node graph[MAX];
int nnodes,nstreets,ntrainlines;

vector<Edge> edges;
int ui,vi,idEdges;
ULL xi;

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
			graph[i].dist = 0;
			P.node = i;
			P.dist = 0;
			pq.push(P);
		}
		else
			graph[i].dist = OO;

		graph[i].parent=-1;
		graph[i].connectParent=UNDEFINED;
	}


	while (!pq.empty()){
		pq_entry curr = pq.top();
		pq.pop();
		int nod = curr.node;
		ULL dis = curr.dist;
		for (int i=0;i<graph[nod].adj.size();i++){

			int nextNode = graph[nod].adj[i].node;

			if(dis+graph[nod].adj[i].cost < graph[nextNode].dist){
				graph[nextNode].dist=dis+graph[nod].adj[i].cost;
				graph[nextNode].parent=nod;
				graph[nextNode].connectParent=graph[nod].adj[i].connect;
				P.node = nextNode;
				P.dist = graph[nextNode].dist;
				pq.push(P);
			}
			else if(dis+graph[nod].adj[i].cost == graph[nextNode].dist &&
					graph[nextNode].connectParent==LINE_TRAIN &&
					graph[nod].adj[i].connect!=LINE_TRAIN){
				graph[nextNode].dist=dis+graph[nod].adj[i].cost;
				graph[nextNode].parent=nod;
				graph[nextNode].connectParent=graph[nod].adj[i].connect;
				P.node = nextNode;
				P.dist = graph[nextNode].dist;
				pq.push(P);
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

	while(cin>>nnodes>>nstreets>>ntrainlines){

		edges.clear();
		idEdges=1;

		REP(i,nstreets){
			cin>>ui>>vi>>xi;
			edges.push_back(Edge(idEdges,ui,vi,xi,STREET));
			idEdges++;
		}

		ui=1;

		REP(i,ntrainlines){
			cin>>vi>>xi;
			edges.push_back(Edge(idEdges,ui,vi,xi,LINE_TRAIN));
			idEdges++;
		}

		sort(edges.begin(),edges.end());

		FOR(it,edges){
			Edge edge=(*it);
			graph[edge.to].adj.push_back(
					Neighbors(edge.source,edge.cost,edge.connect));
			graph[edge.source].adj.push_back(
					Neighbors(edge.to,edge.cost,edge.connect));
		}

		dijkstra(1);

		REP1_N(i,nnodes){
			if(graph[i].connectParent==LINE_TRAIN)
				ntrainlines--;
			graph[i].adj.clear();
		}

		cout<<ntrainlines<<ENDL;

	}

	return 0;
}

