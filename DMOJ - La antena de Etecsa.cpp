/**
 * DMOJ - La antena de Etecsa
 * Temática: Geometria + Pitágoras
 *
 * Idea: Dado un triangulo rectángulo del cual es conocidos sus catetos N y R se
 * requiere hallar el valor de la hipotemusa y multiplicarla dicho valor K.
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
	double N,K,R;
	cin>>N>>K>>R;
	cout<<ceil(sqrt(N*N+R*R)*K)<<ENDL;
	return 0;
}

