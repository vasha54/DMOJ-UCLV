// DMJO Robot desobediente.
// Add HOC
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
#define MAX 1000110
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


int N;



int main()
{
    //freopen ("Input.txt","r",stdin );
    //freopen ("Output.txt","w",stdout );
    cout.setf (ios::fixed ,ios::floatfield);
    cout.precision (0) ;
    ios_base::sync_with_stdio(0);
    std::cin.tie(0);
	while(cin>>N)
    {
		string input;
		cin>>input;
		int U=0,D=0,L=0,R=0;
		
		for(int i=0;i<N;i++)
		{
			if(input[i]=='U')
				U++;
			else if(input[i]=='D')
				D++;
			else if(input[i]=='L')
				L++;
			else if(input[i]=='R')
				R++;
		}
		
		cout<<min(R,L)*2+min(U,D)*2<<ENDL;
    }

    return 0;
}