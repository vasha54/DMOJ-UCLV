// 3649 - Diamond Collector
// Programación Dinámica : Tabla Acumulativa
// COJ Ad-Hoc Sorting Search
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
#include <list>
#define MID (left+right)/2
#define MOD 1000000007
#define MAX 1010
#define MAX_K 10010
#define MAXTREE (MAX << 2)
#define LIMIT 11111111111
#define INF 987654321
#define ULL unsigned long long
#define LL long long
#define ENDL '\n'
#define SYMBOL '#'
#define REP(i,n) for(int i=0;i<(int)n;++i)
#define REP1_N(i,n) for(int i=1;i<=(int)n;++i)
#define REPN_1(i,n) for(int i=(int)n;i>=1;--i)
#define FOR(i,c) for(__typeof((c).begin())i=(c).begin();i!=(c).end();++i)
#define ALL(c) (c).begin(), (c).end()
#define LINE_BLANK cout<<ENDL;
#define PI 3.1415927

using namespace std;

int sizes[MAX], tablesAcumulative[MAX_K], N, K, maximunDiamond;

int main()
{
	//freopen ("Input.txt","r",stdin );
	//freopen ("Output.txt","w",stdout);  
	cout.setf (ios::fixed ,ios::floatfield );
	cout.precision (2) ;
	ios_base::sync_with_stdio(0);
	std::cin.tie(0);
	
	while(cin>>N>>K)
	{
		memset(tablesAcumulative,0,sizeof(tablesAcumulative));
		
		REP(i,N)
		{
			cin>>sizes[i];
			sizes[i]++;
			tablesAcumulative[sizes[i]]++;
		}
		
		REP1_N(i,MAX_K-1)
			tablesAcumulative[i]+=tablesAcumulative[i-1];
			
		maximunDiamond=0;
		
		REP(i,N)
		{
			if( sizes[i]+K<MAX_K)
				maximunDiamond=max(maximunDiamond, 
				                   tablesAcumulative[sizes[i]+K] -tablesAcumulative[sizes[i]-1]);
		}
		
		cout<<maximunDiamond<<ENDL;
	}
	
	return 0;
}