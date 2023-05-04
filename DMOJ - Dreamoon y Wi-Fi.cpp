/**
 * DMOJ - Dreamoon y Wi-Fi
 * Temáticas: Combinatoria
 *
 * Idea: Se tiene una secuencia S1 de signos - y + que van a producir un 
 * valor N que va depender de la cantidad de - (por cada ocurrencia 
 * decremento en uno el valor) y la cantidad de + (por cada ocurrencia 
 * incremento en uno el valor). Se tiene otra otra cadena S2 con los mismos
 * simbolos y el simbolo ?.
 * 
 * El valor producido por la cadena S1 vamos a llamarlos N mientras el valor
 * producido por S2 (ignorando los simbolos vamos llamarlo P). Hallar la 
 * probabilidad de sustituir los simbolos ? en S2 y que el valor obtenido sea
 * igual N. La probabilidad la vamos a definir como Q/R donde R es la cantidad 
 * de posibles escenarios mientras Q la cantidad de escenerios favorables
 * 
 * 1er Caso: S2 no tiene presencia de ? y el valor de P es igual a al valor
 * de N la probabilidad es 1.
 * 
 * 2do Caso: S2 no tiene presencia de ? y el valor de P no esigual a al valor
 * de N la probabilidad es 0.
 * 
 * 3er Caso: S2 genero un valor P y tiene ? cuya cantidad vamos a denominar
 * como T. A partir de T simbolos ? cuantos nuevos valores puede tomar P.
 * La cantidad posible de nuevos nuevos posibles posible P es 2^T (R).
 * 
 * Para buscar los Q valores nuevos que sumados a P de N: Z=N-P
 * 	-Si Z > 0 implica que debe tener Z simbolos + en los posibles T símbolos
 * a sustituir que la cantidad de simbolos -. Para ese caso T se puede expresar
 * como T=2Y+Z siendo Y la cantidad de simbolos - que deberá tener aquellas 
 * posibles sustiticiones que van arrojar un valor Z que sumados a P daran
 * N y será un escenario factible por tanto bastara con calcular C(T,Y) combinaciones
 * de Y en T, de cuantas formas puedo seleccionar Y objetos de T posibles 
 * candidatos. Dicho valor sería Q.
 * 
 * -Si Z < 0 implica que debe tener Z simbolos - en los posibles T símbolos
 * a sustituir que la cantidad de simbolos +. Para ese caso T se puede expresar
 * como T=2Y+Z siendo Y la cantidad de simbolos + que deberá tener aquellas 
 * posibles sustiticiones que van arrojar un valor Z que sumados a P daran
 * N y será un escenario factible por tanto bastara con calcular C(T,Y) combinaciones
 * de Y en T, de cuantas formas puedo seleccionar Y objetos de T posibles 
 * candidatos. Dicho valor sería Q. 
 * 
 * -Si Z == 0 implica que N==P por tanto la cantidad de simbolos + y - ha
 * utilizar en los posibles T símbolos a sustituir tienen que ser iguales
 * para generar un escenario factible. Para ese caso T se puede expresar
 * como T=2Y siendo Y la cantidad de simbolos + y la cantidad de 
 * simbolos - que deberá tener aquellas posibles sustiticiones que van 
 * arrojar un valor Z que sumados a P daran N y será un escenario factible
 * por tanto bastará con calcular C(T,T/2) combinaciones de T/2 en T, de 
 * cuantas formas puedo seleccionar T/2 objetos de T posibles 
 * candidatos. Dicho valor sería Q.
 * 
 * Para probar que T se puede expresar como 2Y+Z en los casos anteriores
 * es evidente que (T-Z) mod 2 ==0 y  T >= Z de no cumplirse lo anterior
 * no habrá alguna ninguna sustitución posible que de Z y por tanto no
 * habrá escenario factibles lo que provoca que sea Q 0 al igual que la 
 * probabilidad. 
 */
#include <bits/stdc++.h>
#include <math.h>
#define ENDL '\n'
#define OPTIMIZAR_IO ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define PRESICION(x) cout.setf(ios::fixed,ios::floatfield); cout.precision(x);
#define MAX_N 100010
#define MOD 10000
#define EPS 1e-9
#define INF 100000000000010
#define LL long long
#define ULL unsigned long long
using namespace std;

int Combinations(int n, int k) {
	k = min(k, n - k);
	int res = 1;
	for (int i = 0; i < k; i++) {
		res = res * (n - i) / (i + 1);
	}
	return res;
}

int main() {

	OPTIMIZAR_IO
	PRESICION(9)

	string S1, S2;
	int N = 0, P = 0, T = 0, Z, Y;
	double probality = 0.0, R, Q = 0;

	cin >> S1;
	cin >> S2;
	for (int i = 0; i < S1.length(); i++) {
		if (S1[i] == '+')
			N++;
		else
			N--;
	}

	for (int i = 0; i < S2.length(); i++) {
		if (S2[i] == '+')
			P++;
		else if (S2[i] == '-')
			P--;
		else
			T++;
	}

	if (N == P && T == 0) {
		probality = 1;
	} else if (N != P && T == 0) {
		probality = 0;
	} else {
		R = 1 << T;
		Z = N - P;
		if ((T - Z) % 2 == 0 && T >= Z) {
			Y = (T - Z) / 2;
			Q = Combinations(T, Y);
		}
		probality = Q / R;
	}

	cout << probality << ENDL;

	return 0;
}
