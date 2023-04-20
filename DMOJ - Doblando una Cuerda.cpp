/**
 * DMOJ - Doblando una Cuerda
 * Temáticas: Ordenamiento + Busqueda
 *
 * Idea: Se ordena los nudos por sus posiciones de forma ascendentemente. Como son
 * pocos nudos se itera por cada uno (exceptuando los nudos del extremo) y
 * se comprueba por cada uno si puede servir como puntos de doblez, los que cumpla
 * se cuentan como parte de la solución. Luego tenemos que ver si entre dos nudos
 * consecutivos de indices en el vector(i, i+1) existe un punto de doblez. De ser
 * asi se cuenta tambien como parte de la solución.
 *
 * El caso de coger el nudo i como punto de doblez solo debemos comprobar que para
 * cada nudo ubicado en el rango [0,i-1] exista un nudo en el rango [i+1,N-1] cuyas
 * diferencias con el nudo i sea igual su valor absoluto.
 *
 * El caso de coger el nudo i y i+1 como punto de doblez solo debemos comprobar que para
 * cada nudo ubicado en el rango  [0,i] exista un nudo en el rango [i+1,N-1] cuyas
 * diferencias con el [0,i]-[i] [i+1]-[i+1,N-1] sea igual su valor absoluto.
 */
#include <bits/stdc++.h>
#include <math.h>
#define ENDL '\n'
#define OPTIMIZAR_IO ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define PRESICION(x) cout.setf(ios::fixed,ios::floatfield); cout.precision(x);
#define MAX 1100
#define MOD 10000
#define EPS 1e-9
#define LL long long
using namespace std;

int nknots, answer, pos, lengtRope;
vector<int> knots;

bool valid(int index) {
	bool is = true;
	int begin = index - 1;
	int end = index + 1;

	while (is && begin >= 0 && end < nknots) {
		if (abs(knots[begin] - knots[index]) != abs(knots[end] - knots[index]))
			is = false;
		begin--;
		end++;
	}

	return is;
}

bool validP(int indexB, int indexE) {
	bool is = true;
	int begin = indexB;
	int end = indexE;

	while (is && begin >= 0 && end < nknots) {
		if (abs(knots[begin] - knots[indexB])
				!= abs(knots[end] - knots[indexE]))
			is = false;
		begin--;
		end++;
	}

	return is;
}

int main() {

	OPTIMIZAR_IO
	PRESICION(0)

	cin >> nknots >> lengtRope;
	answer = 0;

	for (int i = 0; i < nknots; i++) {
		cin >> pos;
		knots.push_back(pos);
	}

	sort(knots.begin(), knots.end());

	for (int i = 1; i < nknots - 1; i++) {
		if (valid(i))answer++;
	}
    for (int i = 0; i < nknots-1; i++) {
		if (validP(i, i+1))answer++;
	}

	cout << answer << ENDL;

	return 0;
}
