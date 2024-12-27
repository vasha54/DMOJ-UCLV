//DMOJ - Interseccion
//Add Hod + String
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
#define MAX 255
#define MAX_N 100001
#define MAX_ROW 1010
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
#define EPS 1e-9
#define OO 1000000
#define RADIUS 1.50000
using namespace std;

int contLettersA[MAX],contLettersB[MAX],lengthA,lengthB,common;
string A,B;

int main()
{
	//freopen("Input.txt","r",stdin);
	//cout.setf(ios::fixed,ios::floatfield);
	//cout.precision(2);
	ios_base::sync_with_stdio(0);
	std::cin.tie(0);
	while(cin>>A){
      cin>>B;
      fill(contLettersA,contLettersA+MAX,0);
      fill(contLettersB,contLettersB+MAX,0);
      common=0;
      lengthA=A.size();
      lengthB=B.size();
      REP(i,lengthA)
         contLettersA[A[i]-'A']++;
      REP(i,lengthB)
         contLettersB[B[i]-'A']++;   
      REP(i,MAX)
            common+=min(contLettersA[i],contLettersB[i]);
      cout<<common<<ENDL;
   }
    return 0;
}
