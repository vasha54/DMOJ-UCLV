//DMOJ Secuencia numerada de lapices
//Aritmetica y Algebra : Sucesion Fibonacci + Exponenciacion matricial
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
#define MAX 250010
#define MAX_N 100001
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

typedef vector <NUMBER> Array;
typedef vector <Array > Matrix;

int cases;
ULL N;

Matrix identity (int n) {
	Matrix A (n, Array (n,0));
	for (int i=0; i<n; ++i) A[i][i]=1;
	return A;
}


Matrix mul (const Matrix & A, const Matrix & B) {
	Matrix C (A.size (), Array (B [0]. size ()));
	for (int i = 0; i<C.size(); ++i){
		for (int j=0; j<C[i].size(); ++j){
			C[i][j]=0;
			for (int k=0; k<A[i].size(); ++k){
				C[i][j]+= A[i][k] * B[k][j];
				C[i][j]%=MOD;
			}
		}
	}
	return C;
}

Matrix pow (const Matrix & A, ULL e) {
	return e == 0 ? identity (A.size ()):
			e% 2 == 0? pow (mul (A, A), e / 2): mul (A, pow (A, e-1));
}


ULL fibonacciMatrixExpo(ULL _n){
	if(_n<=1)
		return 1;
	Matrix initial;
	initial.push_back(Array());
	initial[0].push_back(1);
	initial[0].push_back(1);

	Matrix M;
	M.push_back(Array());
	M.push_back(Array());
	M[0].push_back(0);
	M[0].push_back(1);
	M[1].push_back(1);
	M[1].push_back(1);

	Matrix exp=pow(M,_n-1);

	initial=mul(initial,exp);

	return initial[0][1];
}


int main(){


	//freopen("Input.txt","r",stdin);
	//freopen("Output.txt","w",stdout);
	cout.setf(ios::fixed,ios::floatfield);
	cout.precision(2);
	ios_base::sync_with_stdio(0);
	std::cin.tie(0);

	cin>>cases;
	for(int i=0;i<cases;i++){
		cin>>N;
		cout<<fibonacciMatrixExpo(N);
		cout<<" ";
	}



	return 0;
}

