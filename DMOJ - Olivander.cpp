//DMOJ - Olivander
//Ordenamiento + Greedy
#include <iostream>
#include <algorithm>
#include <stdio.h>
#include <vector>
#include <math.h>
#include <set>
#include <string>
#include <string.h>
#include <stdio.h>
#include <queue>

#define MID (left+right)/2
#define MOD 1000000007
#define MAX 110
#define MARK 2000010
#define MAXTREE (MAX << 2)
#define LIMIT 100000
#define ULL unsigned long long
#define LL long long
#define ENDL '\n'
#define SYMBOL '#'
#define REP(i,n) for(int i=0;i<(int)n;++i)
#define REP1_N(i,n) for(int i=1;i<=(int)n;++i)
#define FOR(i,c) for(__typeof((c).begin())i=(c).begin();i!=(c).end();++i)
#define ALL(c) (c).begin(), (c).end()
#define LINE_BLANK cout<<ENDL;
#define INF 100000000
#define ROW 110
#define COLUMN 110

using namespace std;

int N;
ULL cajas[MAX];
ULL varitas[MAX];

bool esPosible;

int main()
{
    //freopen("Input.txt","r",stdin);
    //freopen("Output.txt","w",stdout);

    cout.setf(ios::fixed,ios::floatfield);
    cout.precision(0);
	 ios_base::sync_with_stdio(0);
    std::cin.tie(0);
    std::cout.tie(0);

    cin>>N;
			REP(i,N) cin>>varitas[i];
			REP(i,N) cin>>cajas[i];
			
			sort(varitas,varitas+N);
			sort(cajas,cajas+N);
			
			esPosible=true;
			
			for(int i=0;i<N && esPosible==true;i++){
				 if(cajas[i]<varitas[i])
					esPosible=false;
			}
			
			(esPosible==true) ? cout<<"DA"<<ENDL : cout<<"NE"<<ENDL;
	 
    
    return 0;
}