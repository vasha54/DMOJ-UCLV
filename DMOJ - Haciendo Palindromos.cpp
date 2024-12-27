//DMOJ - Haciendo Palíndromos//String : Manacher#include <iostream>#include <vector>#include <algorithm>#include <stdio.h>#include <math.h>#include <stack>#include <set>#include <queue>#include <string>#include <string.h>#include <map>#include <complex>#include <cmath>#define MID (left+right)/2#define MOD 1000000007#define MAX 1010#define MAXTREE (MAX << 2)#define LIMIT 100010000#define ULL unsigned long long#define LL long long#define ENDL '\n'#define SYMBOL '#'#define REP(i,n) for(int i=0;i<(int)n;++i)#define REP1_N(i,n) for(int i=1;i<=(int)n;++i)#define FOR(i,c) for(__typeof((c).begin())i=(c).begin();i!=(c).end();++i)#define ALL(c) (c).begin(), (c).end()#define LINE_BLANK cout<<ENDL;using namespace std;string input;int manacher(string _text){  int n=_text.size();  int rad[2*n];  int i,j,k;  for(i=0,j=0;i<2*n;i+=k, j=max(j-k,0)){    while(i-j>=0 && i+j+1<2*n && _text[(i-j)/2]==_text[(i+j+1)/2])      ++j;      rad[i]=j;    for(k=1; i-k>=0 && rad[i]-k>=0 && rad[i-k]!=rad[i]-k ;++k)      rad[i+k]=min(rad[i-k],rad[i]-k);  }    int answer=0;    for(int i=0;i<2*n;i++){     if(rad[i]!=0){       int r=rad[i]/2;       int pivot=i/2;       int beginP,endP=(pivot+r);                   if(i%2==0) beginP=(pivot-r);		 else beginP=(pivot-r+1);				  if(endP==n-1)		  answer=max(answer,endP-beginP+1);			     }   }       return answer;}int main(){   //freopen ("Input.txt","r",stdin );   //freopen ("Output.txt","w",stdout );   cout.setf (ios::fixed ,ios::floatfield);   cout.precision (2) ;   ios_base::sync_with_stdio(0);   std::cin.tie(0);	while(cin>>input)		cout<<input.size()-manacher(input)<<ENDL;		return 0;}