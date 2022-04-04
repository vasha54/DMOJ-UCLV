//DMOJ - Castillo medieval
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
	bool visit;
	bool hasWallNorth;
	bool hasWallSouth;
	bool hasWallEast;
	bool hasWallWest;

	Cell(int value=0 ,int _r=0, int _c=0){
		r=_r;
		c=_c;
		visit=false;
		hasWallWest=(value & (1<<0));
		hasWallSouth=(value & (1<<1));
		hasWallEast=(value & (1<<2));
		hasWallNorth=(value & (1<<3));
	}
};

struct Room{
	vector<Cell> cells;
	int area;
	int id;

	Room(int _id=0){
		cells.clear();
		area=0;
		id=_id;
	}
};

bool operator<(Cell _a, Cell _b){
	if(_a.r!=_b.r)
		return (_a.r<_b.r);
	else
		return (_a.c<_b.c);
}

bool operator<(Room _a, Room _b){
	if(_a.area!=_b.area)
		return (_a.area>_b.area);
	else
		return (_a.cells.front()<_b.cells.front());
}

ostream & operator<<(ostream & _out, Cell _cell){
	_out<<_cell.r<<" "<<_cell.c;
	return _out;
}


int operation,N,walls;
Cell maps[MAX][MAX];
vector<Room> rooms;

bool isValidCell(int _r, int _c){
	return (1<=_r && _r<=N && 1<=_c && _c<=N);
}

Room scanningRoom(Cell _start){
	Room room;

	queue<Cell> visit;

	maps[_start.r][_start.c].visit=true;
	room.cells.push_back(_start);

	visit.push(_start);

	Cell next,current;

	while(!visit.empty()){
		current=visit.front();
		visit.pop();

		//South to North
		next.r=current.r+1;
		next.c=current.c;

		if(isValidCell(next.r,next.c)){
			if(maps[current.r][current.c].hasWallSouth==false &&
					maps[next.r][next.c].hasWallNorth==false	&&
					maps[next.r][next.c].visit==false){

				maps[next.r][next.c].visit=true;
				visit.push(maps[next.r][next.c]);
				room.cells.push_back(maps[next.r][next.c]);
			}
		}


		//North to South
		next.r=current.r-1;
		next.c=current.c;

		if(isValidCell(next.r,next.c)){
			if(maps[current.r][current.c].hasWallNorth==false &&
					maps[next.r][next.c].hasWallSouth==false	&&
					maps[next.r][next.c].visit==false){

				maps[next.r][next.c].visit=true;
				visit.push(maps[next.r][next.c]);
				room.cells.push_back(maps[next.r][next.c]);
			}
		}


		//East to West
		next.r=current.r;
		next.c=current.c+1;

		if(isValidCell(next.r,next.c)){
			if(maps[current.r][current.c].hasWallEast==false &&
					maps[next.r][next.c].hasWallWest==false	&&
					maps[next.r][next.c].visit==false){

				maps[next.r][next.c].visit=true;
				visit.push(maps[next.r][next.c]);
				room.cells.push_back(maps[next.r][next.c]);
			}
		}


		//West to East
		next.r=current.r;
		next.c=current.c-1;

		if(isValidCell(next.r,next.c)){
			if(maps[current.r][current.c].hasWallWest==false &&
					maps[next.r][next.c].hasWallEast==false	&&
					maps[next.r][next.c].visit==false){

				maps[next.r][next.c].visit=true;
				visit.push(maps[next.r][next.c]);
				room.cells.push_back(maps[next.r][next.c]);
			}
		}

	}

	sort(room.cells.begin(),room.cells.begin());
	room.area=room.cells.size();

	return room;
}

void findCellOutRoom(){
	REP1_N(i,N){
		if(maps[1][i].visit==false &&
				maps[1][i].hasWallNorth==false){
			scanningRoom(maps[1][i]);
		}

		if(maps[N][i].visit==false &&
				maps[N][i].hasWallSouth==false){
			scanningRoom(maps[N][i]);
		}

		if(maps[i][1].visit==false &&
				maps[i][1].hasWallWest==false){
			scanningRoom(maps[i][1]);
		}

		if(maps[i][N].visit==false &&
				maps[i][N].hasWallEast==false){
			scanningRoom(maps[i][N]);
		}
	}
}



void findRooms(){
	REP1_N(i,N){
		REP1_N(j,N){
			if(maps[i][j].visit==false){
				Room x=scanningRoom(maps[i][j]);
				rooms.push_back(x);
			}
		}
	}

	sort(rooms.begin(),rooms.end());
}

int main(){


	//freopen("Input.txt","r",stdin);
	//freopen("Output.txt","w",stdout);
	cout.setf(ios::fixed,ios::floatfield);
	cout.precision(2);
	ios_base::sync_with_stdio(0);
	std::cin.tie(0);

	while(cin>>operation){
		cin>>N;
		REP1_N(i,N){
			REP1_N(j,N){
				cin>>walls;
				maps[i][j]=Cell(walls,i,j);
			}
		}

		findCellOutRoom();
		findRooms();

		switch (operation) {
		case 1:
			cout<<rooms.size()<<ENDL;
			break;
		case 2:
			cout<<rooms.front().area<<ENDL;
			break;
		case 3:
			cout<<rooms.front().cells.front()<<" "
			<<rooms.front().cells.back()<<ENDL;
			break;
		default:
			break;
		}

	}

	return 0;
}

