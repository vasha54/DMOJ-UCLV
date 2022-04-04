//DMOJ - David's expedition
//Aritmetica-Algebra: Ecuación diofantina lineal
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
#define MAX_N 100010
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

int A,B,C,RX,LX;

int gcd(int a, int b, int &x, int &y){
   if(a==0){
     x=0; y=1;
     return b;
   }
   int x1, y1;
   int d = gcd(b%a,a,x1,y1);
   x = y1-(b/a)*x1;
   y = x1;
   return d;
}

bool findAnySolution(int a, int b, int c, int &x0, int &y0, int &g){
   g=gcd(abs(a), abs(b), x0, y0);
   if(c%g){
      return false;
   }
   x0*=c/g;
   y0*=c/g;
   if(a<0) x0=-x0;
   if(b<0) y0=-y0;
   return true;
}

void shiftSolution(int &x, int &y, int a, int b, int cnt) {
   x+=cnt*b;
   y-=cnt*a;
}

int findAllSolutions(int a, int b, int c, int minx, int maxx, int miny, int maxy, int &_rx , int &_lx) {
   int x, y, g;
   if(!findAnySolution(a,b,c,x,y,g))
      return 0;
   a/=g;
   b/=g;

   int sign_a=a>0?+1:-1;
   int sign_b=b>0?+1:-1;

   shiftSolution(x,y,a,b,(minx-x)/b);
   if(x<minx)
      shiftSolution(x,y,a,b,sign_b);
   if(x>maxx)
      return 0;
   int lx1=x;

   shiftSolution(x,y,a,b,(maxx-x)/b);
   if(x>maxx)
      shiftSolution(x,y,a,b,-sign_b);
   int rx1=x;

   shiftSolution(x,y,a,b,-(miny-y)/a);
   if(y<miny)
      shiftSolution(x,y,a,b,-sign_a);
   if(y>maxy)
      return 0;
   int lx2 = x;

   shiftSolution(x,y,a,b,-(maxy-y)/a);
   if(y>maxy)
      shiftSolution(x,y,a,b,sign_a);
   int rx2 = x;

   if(lx2>rx2)
      swap(lx2,rx2);
   int lx=max(lx1,lx2);
   int rx=min(rx1,rx2);

   if(lx>rx)
      return 0;
   _rx=rx;
   _lx=lx;
   return (rx-lx)/abs(b)+1;
}

int main(){
	//freopen("Input.txt","r",stdin);
   //freopen("Output.txt","w",stdout);
	cout.setf(ios::fixed,ios::floatfield);
	cout.precision(0);
	ios_base::sync_with_stdio(0);
	std::cin.tie(0);
	
   while(cin>>C){
      A=364;
      B=1092;
      findAllSolutions(A,B,C,1,100,1,145600,RX,LX);
      cout<<RX<<ENDL;
      cout<<(C-(A*RX))/B<<ENDL;
   }
   
   return 0;
}

