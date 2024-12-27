//DMOJ - Dragones de IslaGrande
//Teoría de grafos : BFS y Dijkstra

/*
 * Se tiene un grupo de islas las cuales se comunican por rutas donde cada 
 * uno tiene una distancia. Cada isla tiene una especie de dragón propia 
 * que puede volar hasta una distancia X antes de hacer un alto, siempre 
 * siguiendo una ruta conocida entre dos islas. Dada las islas y las 
 * rutas con sus distancias existente entre ellas asi como las especie 
 * de dragón para cada isla. Conociendo que cuando se llega una isla se puede
 * una de la siguientes operaciones:
 * 
 * Continuar el viaje con el mismo dragón con que se llego a la isla.
 * 
 * Cambiar su dragón por el de la isla para continuar viaje.
 * 
 * Se quiere determinar dos cuestiones:
 * 
 * 1. Derterminar la distancia máxima de vuelo de los dragones que pertenecen a 
 * las islas que se pueden visitar partiendo desde la isla 1 sin cambiar 
 * de especie de dragón durante el recorrido.
 * 
 * 2. Derterminar la distancia mı́nima que se debe recorrer para ir de la isla 
 * 1 a la isla N.
 * 
 * Es evidente que podemos modelar situación como grafo no dirigido y ponderado. 
 * Para dar solución dividiremos el analisis en dos apartados cada uno 
 * enfocado en resolver una determinada cuestión.
 * 
 * Para la cuestión número uno:
 * Hacer un BFS partiendo de la isla 1 y siempre visitando aquellas islas a las
 * cuales se puede acceder utilizando una ruta cuya distancia debe ser menor o
 * igual a la distancia de vuelo de la especie de dragón de la isla 1. Luego por las
 * islas visitadas busco la distancia mayor de vuelo entre especies de dragones de
 * las islas visitadas.
 * 
 * Para la cuestión número dos:
 * Hacer un Distrakj con varias modificaciones. Primero un nodo puede ser
 * visitado varias veces, nos quedaremos con la menor distancia pero si se llega
 * con un dragón con mayor recorrido que con se llego anteriormente a esa isla
 * se debe analizar nuevamente. Siempre que se puede mejorar de dragón (un
 * dragón con mayor recorrido) se debe mejorar. Tener en cuenta que solo se
 * puede ir de una isla a otra si algunos de los dragones cn que contamos es
 * capaz de cubrir la distancia.
 */


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

/*
 * Estructura para tener el par de vecino y costo para cada isla**/
struct Neighbors{
	int node;
	ULL cost;

	Neighbors(int _node=0, ULL _cost=OO ){
		node=_node;
		cost=_cost;
	}
};

/*
 * Estructura que representa la isla*/
struct Island{
	ULL dist;
	vector<Neighbors> adj;
	ULL dragon;
	ULL dragonVisit;
	bool visit;
};

/*
 * Estructura utilizada en el Distrakj */
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

/*
 * Obvia esto */
ostream & operator<<(ostream & _out, pq_entry entry){
	_out<<" Node:"<<entry.node<<" dist:"<<entry.dist<<" dragon:"<<entry.dragon<<ENDL;
	return _out;
}

/*
 * Variables globales
 * */
Island graph[MAX];
int nislands,npaths,operation,islandA,islandB;
ULL lentgh;

/*
 * Aqui se implementa un BFS siempre visitando las islas que no hayan sido 
 * vistadas y la distancia entre ellas y la isla donde me ubico en un 
 * determinado momento es menor o igual a la distancia que puede volar
 * el dragón de la isla uno*/
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

            /*chequeo no haber visitado la isla y que para llegar sea con una distancia
             * menor o igual al dragon que estoy utilizando*/
			if(graph[nextNode].visit==false && graph[currNode].adj[i].cost<=limit){
				graph[nextNode].visit=true;
				visits.push(nextNode);
			}
		}
	}

	ULL solution=0;

    /*Busco de las islas visitadas cual tiene el dragon con mayor recorrido*/
	REP1_N(i,nislands){
		if(graph[i].visit)
			solution=max(solution,graph[i].dragon);
		graph[i].adj.clear();

	}

	cout<<solution<<ENDL;
}

/*Distrakj con sus modificaciones*/
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
