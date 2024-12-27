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
#define MAX 100010
#define MARK 1000
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


int numero;



int main()
{
    //freopen ("Input.txt","r",stdin );
    //freopen ("Output.txt","w",stdout );
    cout.setf (ios::fixed ,ios::floatfield);
    cout.precision (0) ;
    ios_base::sync_with_stdio(0);
    std::cin.tie(0);

	while(cin>>numero)
    {
        if(numero>=0)
			cout<<(numero*(numero+1))/2<<ENDL;
		else
		{
			numero=numero*(numero-1);
			numero=numero/2;
			numero=numero*(-1) +1;
			cout<<numero<<ENDL;
		}
    }

    return 0;
}