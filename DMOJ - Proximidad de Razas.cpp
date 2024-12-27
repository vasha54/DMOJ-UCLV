//DMOJ-Proximidad de Razas
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
#define MAX 1000010
#define MAX_ROW 510
#define MAX_COLUMN MAX_ROW
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
#define OPERATOR_INC "++"
#define OPERATOR_DEC "--"
#define MAXELEMENT 260
#define MAXCAPACITYKNAPSACK 1010
#define EPS 1e-15
using namespace std;

int ncows,posID[MAX],maxID,K,id;

int main(){
  // freopen ("Input.txt","r",stdin );
    //freopen ("Output.txt","w",stdout );
   cout.setf (ios::fixed ,ios::floatfield);
   cout.precision (2) ;
   ios_base::sync_with_stdio(0);
   std::cin.tie(0);
	
   while(cin>>ncows>>K){
      fill(posID,posID+MAX,-1);
      maxID=-1;
      REP(i,ncows){
         cin>>id;
         if(posID[id]!=-1 && i-posID[id]<=K)
            maxID=max(maxID,id);
         posID[id]=i;
      }
      cout<<maxID<<ENDL;
   }
   
	return 0;
}
