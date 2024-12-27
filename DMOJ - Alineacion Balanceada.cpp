//DMOJ - Alineación Balanceada
//Estrtuctura de datos : RQM
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
#define MAX_N 100001
#define MAX_ROW 1010
#define MAX_COLUMN MAX_ROW
#define MAX_NODE 2010
#define MAX_EDGE 55000
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
#define EPS 1e-9
#define OO 1000000
#define RADIUS 1.50000
using namespace std;

int N,Q,A,B;
int alturasVacas[MAX];

int *buildRMQMin(int *a, int n) {
   int logn = 1;
   for(int k=1;k<n;k*=2) ++logn;
   int *r = new int[n*logn];
   int *b = r; copy(a,a+n,b);
   for(int k=1;k<n;k*=2){
      copy(b,b+n,b+n); b+= n;
      REP(i,n-k) b[i]=min(b[i],b[i+k]);
   }
   return r;
}

int *buildRMQMax(int *a, int n) {
   int logn = 1;
   for(int k=1;k<n;k*=2) ++logn;
   int *r = new int[n*logn];
   int *b = r; copy(a,a+n,b);
   for(int k=1;k<n;k*=2){
      copy(b,b+n,b+n); b+= n;
      REP(i,n-k) b[i]=max(b[i],b[i+k]);
   }
   return r;
}

int minimum(int x, int y, int *rmq, int n){
   int z=y-x, k=0, e=1, s; //y-x>=e=2^k
   s=((z & 0xffff0000) != 0 )<<4; z>>=s; e<<=s; k|=s;
   s=((z & 0x0000ff00) != 0 )<<3; z>>=s; e<<=s; k|=s;
   s=((z & 0x000000f0) != 0 )<<2; z>>=s; e<<=s; k|=s;
   s=((z & 0x0000000c) != 0 )<<1; z>>=s; e<<=s; k|=s;
   s=((z & 0x00000002) != 0 )<<0; z>>=s; e<<=s; k|=s;
   return min( rmq[x+n*k], rmq[y+n*k-e+1] );
}

int maximun(int x, int y, int *rmq, int n){
   int z=y-x, k=0, e=1, s; //y-x>=e=2^k
   s=((z & 0xffff0000) != 0 )<<4; z>>=s; e<<=s; k|=s;
   s=((z & 0x0000ff00) != 0 )<<3; z>>=s; e<<=s; k|=s;
   s=((z & 0x000000f0) != 0 )<<2; z>>=s; e<<=s; k|=s;
   s=((z & 0x0000000c) != 0 )<<1; z>>=s; e<<=s; k|=s;
   s=((z & 0x00000002) != 0 )<<0; z>>=s; e<<=s; k|=s;
   return max( rmq[x+n*k], rmq[y+n*k-e+1] );
}

int main()
{
	//freopen("Input.txt","r",stdin);
   //freopen("Output.txt","w",stdout);
	cout.setf(ios::fixed,ios::floatfield);
	cout.precision(2);
	ios_base::sync_with_stdio(0);
	std::cin.tie(0);
	
   while(cin>>N>>Q){
      REP(i,N)
         cin>>alturasVacas[i];
      int * rmqMin=buildRMQMin(alturasVacas,N);
      int * rmqMax=buildRMQMax(alturasVacas,N);
      REP(i,Q){
         cin>>A>>B;
         A--;
         B--;
         cout<<maximun(A,B,rmqMax,N)-minimum(A,B,rmqMin,N)<<ENDL;
      }
   }
   
   return 0;
}

