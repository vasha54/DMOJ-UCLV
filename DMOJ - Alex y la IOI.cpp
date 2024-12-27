//Alex y la IOI
//Add-Hoc
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
#define MAXTREE (MAX << 2)
#define LIMIT 2500000100
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

int ncity,homeAlex,IOI;
string mapAirport;

int main()
{
    //freopen ("Input.txt","r",stdin );
    //freopen ("Output.txt","w",stdout );
    cout.setf (ios::fixed ,ios::floatfield );
    cout.precision (2) ;
    ios_base::sync_with_stdio(0);
    std::cin.tie(0);

    while(cin>>ncity>>homeAlex>>IOI){
        cin>>mapAirport;
        homeAlex--;
        IOI--;
        if( mapAirport[homeAlex]==mapAirport[IOI])
            cout<<0<<ENDL;
        else
            cout<<1<<ENDL;
    }

    return 0;
}
