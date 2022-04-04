//DMOJ - Cuadrado Maximo
//Programación dinamica: Maxima suma en una matrix 2D.
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
#include <limits.h>
#include <limits>
#define MID (left+right)/2
#define MOD % 100000000
#define MAX 100010
#define MAX_ROW 310
#define MAX_COLUMN MAX_ROW
#define MAX_NODE 2010
#define MAX_EDGE 55000
#define MAXTREE (MAX << 2)
#define ULL unsigned long long
#define LL long long
#define NUMBER LL
#define ENDL '\n'
#define SYMBOL "#"
#define REP(i,n) for(int i=0;i<(int)n;++i)
#define REP1_N(i,n) for(int i=1;i<=(int)n;++i)
#define FOR(i,c) for(__typeof((c).begin())i=(c).begin();i!=(c).end();++i)
#define ALL(c) (c).begin(), (c).end()
#define LINE_BLANK cout<<ENDL;
#define OPERATOR_INC "++"
#define OPERATOR_DEC "--"
#define SYMBOL "#"
#define MAXELEMENT 260
#define MAXCAPACITYKNAPSACK 1010
#define EPS 1e-9
#define OO 1000000000000000
#define RADIUS 1.50000

const int mov_r[]={ 0, 0,-1, 1};
const int mov_c[]={ 1,-1, 0, 0};

using namespace std;

int N;
LL dp[MAX_ROW][MAX_COLUMN];
LL answer,subMatriz;


int main(){

	//freopen ("Input.txt","r",stdin );
	//freopen ("Output.txt","w",stdout );
	cout.setf (ios::fixed ,ios::floatfield );
	cout.precision (2) ;
	ios_base::sync_with_stdio(0);
	std::cin.tie(0);

	while(cin>>N){
		REP(i,N+3){
			dp[i][0]=dp[0][i]=0;
		}
		REP1_N(i,N){
			REP1_N(j,N){
				cin>>dp[i][j];
				dp[i][j]=dp[i-1][j]+dp[i][j-1]-dp[i-1][j-1]+dp[i][j];
			}
		}
		answer=LLONG_MIN;

		REP1_N(k,N){
			REP1_N(i,N){
				REP1_N(j,N){
					if(i-k>=0 && j-k>=0){
						subMatriz=dp[i][j];
						subMatriz-=dp[i][j-k];
						subMatriz-=dp[i-k][j];
						subMatriz+=dp[i-k][j-k];
						answer=max(answer,subMatriz);
					}
				}
			}
		}

		cout<<answer<<ENDL;

	}


	return 0;
}
