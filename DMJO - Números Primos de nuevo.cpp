// DMJO Números Primos de nuevo
// Teoría Numeros: Numeros Primos+ Busqueda 
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


int cases,X;
vector<int> primes;
bool mark[MAX];

void cribePrimes()
{
	memset(mark,true,sizeof(mark));
	
	for(int i=2;i<=sqrt(MAX);i++)
	{
		if(mark[i])
		{
			primes.push_back(i);
			for(int j=i*i;j<MAX;j+=i)
				mark[j]=false;
		}
	}
	
	for(int i=sqrt(MAX)+1;i<MAX;i++)
		if(mark[i])
			primes.push_back(i);
}



int main()
{
    //freopen ("Input.txt","r",stdin );
    //freopen ("Output.txt","w",stdout );
    cout.setf (ios::fixed ,ios::floatfield);
    cout.precision (0) ;
    ios_base::sync_with_stdio(0);
    std::cin.tie(0);
	cribePrimes();
	while(cin>>cases)
    {
		while(cases--)
		{
			cin>>X;
			
			if(binary_search( primes.begin(), primes.end(), X ))
				cout<<X<<" "<<X<<ENDL;
			else
			{
				vector<int>::iterator lower=lower_bound( primes.begin(), primes.end(), X  );
				vector<int>::iterator upper=lower-1;
				cout<<(*upper)<<" "<<(*lower)<<ENDL;
			}
				
		}
    }

    return 0;
}