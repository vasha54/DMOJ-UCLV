//DMOJ - Reparando acrosticos
//Geometría + Add-Hoc:
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
#define MAX 1000000
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

struct Point{
	int X,Y;
	Point(int _X=0, int _Y=0){
		X=_X;
		Y=_Y;
	}
};

struct Segment{
	Point p1;
	Point p2;
	int maxX;
	int maxY;
	int minX;
	int minY;

	Segment(Point _p1=Point(), Point _p2=Point()){
		p1=_p1;
		p2=_p2;
	}
};

istream & operator>>(istream & _in, Segment & _a){
	int length,row,column,orientation;
	_in>>length>>row>>column>>orientation;
	_a.p1.X=column;
	_a.p1.Y=row;

	if(orientation==1){
		_a.p2.Y=_a.p1.Y+length-1;
		_a.p2.X=_a.p1.X;
	}
	else{
		_a.p2.Y=_a.p1.Y;
		_a.p2.X=_a.p1.X+length-1;
	}

	_a.maxX=max(_a.p1.X,_a.p2.X);
	_a.maxY=max(_a.p1.Y,_a.p2.Y);
	_a.minX=min(_a.p1.X,_a.p2.X);
	_a.minY=min(_a.p1.Y,_a.p2.Y);

	return _in;
}


int nsegments,width,heigth,lX,hX,lY,hY;
Segment t;


int main(){


	//freopen("Input.txt","r",stdin);
	//freopen("Output.txt","w",stdout);
	cout.setf(ios::fixed,ios::floatfield);
	cout.precision(2);
	ios_base::sync_with_stdio(0);
	std::cin.tie(0);

	while(cin>>nsegments){
		REP(i,nsegments){
			cin>>t;
			if(i==0){
				hX=t.maxX;
				lX=t.minX;
				hY=t.maxY;
				lY=t.minY;
			}
			else{
				hX=max(hX,t.maxX);
				lX=min(lX,t.minX);
				hY=max(hY,t.maxY);
				lY=min(lY,t.minY);
			}
		}
		width=hX-lX+1;
		heigth=hY-lY+1;
		cout<<heigth<<" "<<width<<ENDL;
	}

	return 0;
}

