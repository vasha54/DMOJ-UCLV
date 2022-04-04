//DMOJ - Contando prefijos palíndromos
//String : Manacher
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

int cases;

string input;
bool wolves[MAX];

bool isWolvels(char _letter){
   return (_letter=='A' || _letter=='E' || _letter=='I' || _letter=='O'
   || _letter=='U' || _letter=='a' || _letter=='e' || _letter=='i' ||
   _letter=='o' || _letter=='u');
}

int manacher(string _text){
  int n=_text.size();
  int rad[2*n];
  int i,j,k;
  for(i=0,j=0;i<2*n;i+=k, j=max(j-k,0)){
    while(i-j>=0 && i+j+1<2*n && _text[(i-j)/2]==_text[(i+j+1)/2])
      ++j;
      rad[i]=j;
    for(k=1; i-k>=0 && rad[i]-k>=0 && rad[i-k]!=rad[i]-k ;++k)
      rad[i+k]=min(rad[i-k],rad[i]-k);
  }
  
  int answer=0;
  
  for(int i=0;i<2*n;i++){
     if(rad[i]!=0){
       int r=rad[i]/2;
       int pivot=i/2;
       int beginP,endP=(pivot+r);     
       
       if(i%2==0) beginP=(pivot-r);
		 else beginP=(pivot-r+1);
		
		  if(beginP==0 && wolves[endP])
         answer++;			
     }
   }
    
   return answer;
}

int main()
{
	//freopen("Input.txt","r",stdin);
   //freopen("Output.txt","w",stdout);
	cout.setf(ios::fixed,ios::floatfield);
	cout.precision(2);
	ios_base::sync_with_stdio(0);
	std::cin.tie(0);
	
   while(cin>>cases){
      while(cases--){
         cin>>input;
         fill(wolves,wolves+MAX,false);
         REP(i,input.size()){
            if(isWolvels(input[i]))
               wolves[i]=true;
            else if(i!=0)
               wolves[i]|=wolves[i-1];
         }
         cout<<manacher(input)<<endl;
      }
   }
   
   return 0;
}

