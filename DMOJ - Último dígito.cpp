//DMOJ - Último dígito
//Teoria de número: Factorizacion del factorial + Exponenciacion Binaria + Inverso multiplicativo
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
#define MOD 100000007
#define MAX 1000000
#define MAX_N 30
#define MAX_ROW 1010
#define MAX_COLUMN MAX_ROW
#define MAX_NODE 2010
#define MAX_EDGE 55000
#define MAXTREE (MAX << 2)
#define ULL unsigned long long
#define LL long long
#define NUMBER LL
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
#define OO 1000000000
#define RADIUS 1.50000
using namespace std;

typedef pair<ULL,ULL>FAC;

int nwords,cletters[MAX_N],nletters,nprimes;
string word;
vector<ULL> primes;
bool isPrime[MAX];
vector<ULL> denominador,numerador;
ULL tNumerador,tDenominador,invMult;

bool cmp(int a,int b){
	return (a>b);
}

void cribePrime(){
	fill(isPrime,isPrime+MAX,true);
	int root=sqrt(MAX)+1;

	primes.push_back(2);

	for(int i=3;i<=root;i+=2){
		if(isPrime[i]){
			primes.push_back(i);
			for(int j=i*i;j<MAX;j+=i){
				isPrime[j]=false;
			}
		}
	}



	if(root%2==0){
		root++;
	}

	for(int j=root;j<MAX;j+=2){
		if(isPrime[j]){
			primes.push_back(j);
		}
	}
	denominador.resize(primes.size(),0);
	numerador.resize(primes.size(),0);
}


void factorizarFactorial(ULL _n , bool isDenominador=false){

	int l = primes.size();
	vector<FAC>FP;
	for( int i=0; i<l && primes[i]<=_n ; i++){
		ULL exp = 0 ;
		ULL pot = primes[i] ;
		while(pot<=_n){
			exp+=_n/pot ;
			pot*=primes[i];
		}
		if(!isDenominador)
			numerador[i]+=exp;
		else
			denominador[i]+=exp;
	}
}

ULL binpow(ULL a , ULL n){
	ULL res = 1;
	while(n){
		if(n&1)
			res=(res*a)%10;
		a =(a*a)%10 ;
		n>>=1;
	}
	return res;
}

ULL modInverse(ULL a, ULL m) {
	a = a%m;
	for(ULL x=1; x<m; x++)
		if ((a*x) % m == 1)
			return x;
}


int main(){


	//freopen("Input.txt","r",stdin);
	//freopen("Output.txt","w",stdout);
	cout.setf(ios::fixed,ios::floatfield);
	cout.precision(2);
	ios_base::sync_with_stdio(0);
	std::cin.tie(0);

	cribePrime();

	while(cin>>nwords){
		while(nwords--){
			cin>>word;
			fill(cletters,cletters+MAX_N,0);
			nletters=word.size();

			REP(i,nletters)
			cletters[word[i]-'a']++;

			factorizarFactorial(nletters);

			sort(cletters,cletters+MAX_N,cmp);

			for(int i=0;i<MAX_N && cletters[i]>=2 ;i++){
				factorizarFactorial(cletters[i],true);
			}

			nprimes=primes.size();

			ULL t=min(numerador[0],denominador[0]);
			numerador[0]-=t;
			denominador[0]-=t;

			t=min(numerador[2],denominador[2]);
			numerador[2]-=t;
			denominador[2]-=t;


			t=min(numerador[0],numerador[2]);
			numerador[0]-=t;
			numerador[2]-=t;

			t=min(denominador[0],denominador[2]);
			denominador[0]-=t;
			denominador[2]-=t;

			tDenominador=1;
			tNumerador=1;

			for(int i=0;i<nprimes;i++){
				if(denominador[i]>numerador[i]){
					denominador[i]-=numerador[i];
					numerador[i]=0;
				}
				else{
					numerador[i]-=denominador[i];
					denominador[i]=0;
				}

				tDenominador*=binpow(primes[i],denominador[i]);
				tDenominador%=10;

				tNumerador*=binpow(primes[i],numerador[i]);
				tNumerador%=10;

				numerador[i]=0;
				denominador[i]=0;

			}

			invMult=modInverse(tDenominador,10);
			cout<<(tNumerador*invMult)%10<<ENDL;
		}
	}



	return 0;
}

