//DMOJ - Tiling
//Progrmación dinamica: Tiling o Perfil Roto
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
#define MOD 1000000007
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

int n, m;
vector<vector<long long> > d;


void tiling(int x=0, int y=0, int mask=0, int next_mask=0){
	if(x==n)
		return;
	if(y>=m)
		d[x+1][next_mask]=(d[x+1][next_mask]+d[x][mask])%MOD;
	else{
	  int my_mask=1<<y;

	  if(mask & my_mask)
		  tiling(x,y+1,mask,next_mask);
	  else{
		  tiling(x,y+1,mask,next_mask|my_mask);
			if(y+1<m && !(mask&my_mask) && !(mask&(my_mask<<1)))
				tiling(x,y+2,mask,next_mask);
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

	n=100000;
	m=4;

	d.resize (n+1, vector<long long> (1<<m));
	d[0][0]= 1;
	for (int x=0; x<=n; ++x)
		for (int mask=0; mask<(1<<m); ++mask)
			tiling(x, 0, mask, 0);

	while(cin>>n){
		cout<<d[n][0];
	}



	return 0;
}

