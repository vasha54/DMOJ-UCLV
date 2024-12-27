//DMOJ - Equipo de Futbol
//Programación dinámica: Variación de subconjunto con suma divisible por m
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
#define MOD % 100000000
#define MOD1 % 3
#define MAX 100010
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

int N,F;
ULL habilidad;
vector<ULL> habilidades;

ULL subSetModularSum(vector<ULL> _array, int n, int m){
	vector<bool> DP(m,false);
	vector<ULL> DP2(m,0);

	REP(i,n){
		vector<bool> tmp(m,false);
		vector<ULL> tmp2(m,0);

		REP(j,m){
			if(DP[j]==true){
				tmp[(j+_array[i])%m]=true;
				tmp2[(j+_array[i])%m]+=DP2[j];
				tmp2[(j+_array[i])%m]=tmp2[(j+_array[i])%m]MOD;
			}
		}

		REP(j,m){
			if(tmp[j])DP[j]=true;
			DP2[j]+=tmp2[j];
			DP2[j]=DP2[j]MOD;
		}

		DP[_array[i]%m]=true;
		DP2[_array[i]%m]++;
		DP2[_array[i]%m]=DP2[_array[i]%m] MOD;
	}

	return DP2[0];
}

int main(){

	//freopen("Input.txt","r",stdin);
	//freopen("Output.txt","w",stdout);
	cout.setf(ios::fixed,ios::floatfield);
	cout.precision(2);
	ios_base::sync_with_stdio(0);
	std::cin.tie(0);

	while(cin>>N>>F){
		habilidades.clear();
		REP1_N(i,N){
			cin>>habilidad;
			habilidades.push_back(habilidad);
		}
		cout<<subSetModularSum(habilidades,N,F)<<ENDL;
	}

	return 0;
}

