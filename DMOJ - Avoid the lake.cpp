//DMOJ - Avoid the lake
//Teoría de grafos: BFS sobre tabero + Componentes conexa
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
#define MOD 100000007
#define MAX 110
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
#define OO 1000000000
#define RADIUS 1.50000
using namespace std;

const int mov_r[]={ 0, 0,-1, 1};
const int mov_c[]={ 1,-1, 0, 0};

struct Cell{
	int r,c;
	Cell(int _r=0,int _c=0){
		r=_r;
		c=_c;
	}
};

istream & operator>>(istream & _in, Cell & _a){
	_in>>_a.r>>_a.c;
	return _in;
}



int nrows,ncolumns,K,answer;
bool maps[MAX][MAX];
Cell tmp;
vector<Cell> lakes;

void resetMAP(){
	REP(i,MAX){
		REP(j,MAX){
			maps[i][j]=true;
		}
	}
}

bool validCell(int _r, int _c){
	return (1<=_r && _r<=nrows && 1<=_c && _c<=ncolumns);
}


int findLakes(Cell _start){
	int tArea=1;
    queue<Cell> visit;
    Cell current,next;
    maps[_start.r][_start.c]=true;
    visit.push(_start);

    while(!visit.empty()){
    	current=visit.front();
    	visit.pop();
    	REP(i,4){
    		next.c=current.c+mov_c[i];
    		next.r=current.r+mov_r[i];

    		if(validCell(next.r,next.c)){
    			if(maps[next.r][next.c]==false){
    				tArea++;
    				maps[next.r][next.c]=true;
    				visit.push(next);
    			}
    		}
    	}
    }

	return tArea;
}

int main(){


	freopen("Input.txt","r",stdin);
	//freopen("Output.txt","w",stdout);
	cout.setf(ios::fixed,ios::floatfield);
	cout.precision(2);
	ios_base::sync_with_stdio(0);
	std::cin.tie(0);

	while(cin>>nrows>>ncolumns>>K){
		resetMAP();
		lakes.clear();
		REP(i,K){
			cin>>tmp;
			maps[tmp.r][tmp.c]=false;
			lakes.push_back(tmp);
		}
		answer=0;
		FOR(it,lakes){
			tmp=(*it);
			if(maps[tmp.r][tmp.c]==false){
				answer=max(answer,findLakes(tmp));
			}
		}

		cout<<answer<<ENDL;
	}

	return 0;
}

