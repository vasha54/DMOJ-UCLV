//DMOJ - Bolos Bovinos
//Progrmación dinamica: Tabla acumulativa.
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

int N;
LL matrix[MAX][MAX],dp[MAX][MAX];

int main(){
    //freopen ("Input.txt","r",stdin );
    //freopen ("Output.txt","w",stdout );
   cout.setf (ios::fixed ,ios::floatfield);
   cout.precision (2) ;
   ios_base::sync_with_stdio(0);
   std::cin.tie(0);

   while(cin>>N){
	   for(int i=1;i<=N;i++){
		   for(int j=1;j<=i;j++){
			   cin>>matrix[i][j];
			   dp[i][j]=0;
		   }
	   }

	   dp[1][1]=matrix[1][1];

	   for(int i=2;i<=N;i++){
		   for(int j=1;j<=i;j++){
			   if(j==1){
				   dp[i][j]=matrix[i][j]+dp[i-1][j];
			   }
			   else if(j==i){
				   dp[i][j]=matrix[i][j]+dp[i-1][j-1];
			   }
			   else{
				   dp[i][j]=matrix[i][j]+max(dp[i-1][j],dp[i-1][j-1]);
			   }
		   }
	   }

	   cout<<*max_element(dp[N]+1,dp[N]+N+1)<<ENDL;
   }

   return 0;
}
