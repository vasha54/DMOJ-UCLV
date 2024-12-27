//3699 - An interesting game
// Teoria de juegos
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
#define LIMIT 100010000
#define ULL unsigned long long
#define LL long long
#define ENDL '\n'
#define SYMBOL '#'
#define REP(i,n) for(int i=0;i<(int)n;++i)
#define REP1_N(i,n) for(int i=1;i<=(int)n;++i)
#define FOR(i,c) for(__typeof((c).begin())i=(c).begin();i!=(c).end();++i)
#define ALL(c) (c).begin(), (c).end()
#define LINE_BLANK cout<<ENDL;
#define PI 3.1415927
#define TWO 2.0000000
using namespace std;


int n,ai;
   

int main()
{
   // freopen ("Input.txt","r",stdin );
    
    cout.setf (ios::fixed ,ios::floatfield );
    cout.precision (7) ;
    ios_base::sync_with_stdio(0);
    std::cin.tie(0);
    
    while(cin>>n)
    {
		for(int i=0;i<n;i++)
			cin>>ai;
		
		if(n==1)
			cout<<"Tie"<<ENDL;
		else if(n%2==1)
			cout<<"Second"<<ENDL;
		else if (n%2==0)
			cout<<"First"<<ENDL;	
	}
    
    return 0;
}