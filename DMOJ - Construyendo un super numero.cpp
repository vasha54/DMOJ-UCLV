//DMOJ - Construyendo un super numero
//Aritmetica Algebra: Recurrencia
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
#define MOD % 34047161064
#define MOD1 % 3
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

const int mov_r[]={ 0, 0,-1, 1};
const int mov_c[]={ 1,-1, 0, 0};

int operation,K;
string number;
ULL N,Q,Xo,Yo,Ro;

int main(){


	//freopen("Input.txt","r",stdin);
	//freopen("Output.txt","w",stdout);
	cout.setf(ios::fixed,ios::floatfield);
	cout.precision(2);
	ios_base::sync_with_stdio(0);
	std::cin.tie(0);

	while(cin>>operation>>K>>number){
		N=number.size();
		Q=0;

		for(int i=0;i<number.size();i++)
			Q+=(number[i]-'0');

		Xo=(N-1) MOD;

		Yo=(N-1) MOD1;
		Ro=Q MOD1;


		for(int i=1;i<K;i++){
			Ro=(Ro+(Q*Yo))MOD1;
			Xo=(Xo+(N*Xo))MOD;
			Yo=(Yo+(N*Yo))MOD1;
		}

		Xo=(Xo+1)MOD;

		if(operation==1 || operation==2)
			cout<<Xo<<ENDL;

		if(operation==2){
			(Ro==0) ? cout<< "Si" : cout<< "No";
			LINE_BLANK
		}

	}

	return 0;
}

