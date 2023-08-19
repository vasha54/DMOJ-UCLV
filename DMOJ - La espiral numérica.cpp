/**
 * DMOJ - La espiral numérica
 * Temática: Aritmetica - Álgebra
 *
 * Idea: Cuando se hace varias espirales vamos a notar ciertas cosas en la diagonal
 * del 1 para arriba esta los cuadrados de los numeros impares de [1,N] mientras
 * de 1 hacia abajo estan los cuadrados incrementados en uno de los numeros pares
 * en el rango de [1,N]. Por tanto la fórmula de la solución sera:
 *
 * N(N+1)(2N+1)/6
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

	ULL N;
	cin>>N;
	cout<<(N*(N+1)*(2*N+1))/6+(N/2)<<ENDL;

	return 0;
}

