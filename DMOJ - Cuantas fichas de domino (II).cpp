//DMOJ - ¿Cuántas fichas de dominó? (II)
//Algebra y Aritmetica : Sumatoria de Gauss
#include <iostream>
#include <vector>
#include <algorithm>
#include <stdio.h>
#include <math.h>
#include <stack>
#include <set>
#include <list>
#include <queue>
#include <string>
#include <string.h>
#include <map>
#include <complex>
#include <cmath>
#include <bitset>
#define MID (left+right)/2
#define MODULO 1000000007
#define MAX 1000010
#define MIN MAX*(-1)
#define MAXTREE (MAX << 2)
#define LIMIT 1000000
#define ULL unsigned long long
#define LL long long
#define ENDL '\n'
#define SYMBOL '#'
#define REP(i,n) for(int i=0;i<(int)n;++i)
#define REP1_N(i,n) for(int i=1;i<=(int)n;++i)
#define FOR(i,c) for(__typeof((c).begin())i=(c).begin();i!=(c).end();++i)
#define ALL(c) (c).begin(), (c).end()
#define LINE_BLANK cout<<ENDL;
using namespace std;


int cases;
ULL pieces;

int main()
{
	
	//freopen ("Input.txt","r",stdin );
    //freopen ("Output.txt","w",stdout );
    while(cin>>cases){
		while(cases--){
			cin>>pieces;
			cout<<((pieces+1)*(pieces+2))/2<<ENDL;
		}
	}
	return 0;
}