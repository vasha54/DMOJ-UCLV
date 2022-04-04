//DMOJ - Telefonos moviles
//Estructura de Datos: FenwickTree 2D
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
#define MAX_NODE 2020
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

struct FenwickTree2D{

	long long ** matriz;
	int columns;
	int rows;

	FenwickTree2D(int _r=10,int _c=10){
		rows=_r;
		columns=_c;
		matriz=new long long*[columns];
		REP(i,columns)
		matriz[i]=new long long [rows];
		REP(i,rows){
			REP(j,columns){
				matriz[i][j]=0;
			}
		}
	}

	void add( int _r, int _c, long long _value) {
		for(int i=_r; i<rows; i+=(i+1)&-(i+1)){
			for(int j=_c;j<columns;j+=(j+1)&-(j+1)){
				matriz[i][j]+=_value;
			}
		}
	}

	//sum[(0,0),(r,c)]
	long long sum(int _r,int _c){
		long long res = 0;
		for(int i=_r;i>=0;i-=(i+1)&-(i+1)){
			for(int j=_c;j>=0;j-=(j+1)&-(j+1)){
				res+=matriz[i][j];
			}
		}
		return res;
	}

	//sum[(r1,c1),(r2,c2)]
	long long sum(int _r1,int _c1,int _r2,int _c2){
		return sum(_r2,_c2)-sum(_r1-1,_c2)-sum(_r2,_c1-1)+sum(_r1-1,_c1-1);
	}

    long long get(int _r,int _c){
		return sum(_r,_c,_r,_c);
	}

	void set(int _r,int _c,int _value) {
		add(_r,_c,-get(_r,_c)+_value);
	}
};


FenwickTree2D * tree2D;
int operation,N,r1,c1,r2,c2;
long value;
bool exitProgram;



int main(){
	//freopen("Input.txt","r",stdin);
	//freopen("Output.txt","w",stdout);
	cout.setf(ios::fixed,ios::floatfield);
	cout.precision(2);
	ios_base::sync_with_stdio(0);
	std::cin.tie(0);

	exitProgram=false;
	tree2D=NULL;
	while(!exitProgram){
		cin>>operation;
		switch (operation) {
			case 0:
				cin>>N;
				if(tree2D!=NULL)
					delete tree2D;
				tree2D=new FenwickTree2D(N,N);
				break;
			case 1:
				cin>>r1>>c1>>value;
				if(tree2D!=NULL)
					tree2D->add(r1,c1,value);
				break;
			case 2:
				cin>>r1>>c1>>r2>>c2;
				if(tree2D!=NULL)
					cout<<tree2D->sum(r1,c1,r2,c2)<<ENDL;
				break;
			case 3:
				exitProgram=true;
				break;
			default:
				break;
		}
	}

	return 0;
}

