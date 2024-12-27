//DMOJ - Cuban Roulette
//Teoría de números: Números comprimos + función Euler Pi.
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
#define MAX 360
#define MAX_ROW 510
#define MAX_COLUMN MAX_ROW
#define MAXTREE (MAX << 2)
#define ULL unsigned long long
#define LL long long
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
#define EPS 1e-15
#define OO 50000
using namespace std;

int cases;
LL N;

LL phi(LL n) {
    LL result = n;
    for (LL i = 2; i * i <= n; i++) {
        if(n % i == 0) {
            while(n % i == 0)
                n /= i;
            result -= result / i;
        }
    }
    if(n > 1)
        result -= result / n;
    return result;
}

int main(){
    freopen ("Input.txt","r",stdin );
    //freopen ("Output.txt","w",stdout );
   cout.setf (ios::fixed ,ios::floatfield);
   cout.precision (2) ;
   ios_base::sync_with_stdio(0);
   std::cin.tie(0);

   while(cin>>cases){
	   while(cases--){
		   cin>>N;
		   cout<<phi(N)<<ENDL;
	   }
   }

   return 0;
}
