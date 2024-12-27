/**
 * DMOJ - Cubo
 * Temática: Fuerza Bruta
 *
 * Idea: Dado un N generar todas las triadas(A,B,C) diferentes tal que A*B*C sea
 * igual a N
 */
#include <bits/stdc++.h>
#include <math.h>
#define ENDL '\n'
#define OPTIMIZAR_IO ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define PRESICION(x) cout.setf(ios::fixed,ios::floatfield); cout.precision(x);
#define MAX_N 85
#define MOD 1000000007
#define EPS 1e-9
#define INF 1000000000
#define LL long long
#define ULL unsigned long long
#define pii pair<int,int>
#define ALPHABET_SIZE 26 //['a-z']
using namespace std;



int main() {
	OPTIMIZAR_IO
	PRESICION(0)

	LL N,cubes=0;
	cin>>N;
	for(LL a=1;a<=N;a++){
		for(LL b=a;b<=N;b++){
			if(N%(a*b)==0 && N/(a*b)>=b)
				cubes++;
		}
	}
	cout<<cubes<<ENDL;
	return 0;
}

