/**
 * DMOJ - Coleccion de semillas
 * Temáticas: Ordenamiento + Busqueda Binaria
 *
 * Idea: Dada una colección de valores buscar la subcolección tal que contenga la
 * mayor cantidad de elementos de la colección inicial con la restricción que
 * cualquier par de elementos de la nueva colección la diferencia entre ellos no
 * sea superior a K. Para lograr esto ordenamos los elementos . Por cada posición
 * i vamos a buscar el máximo j en el rango de i a N-1 con busqueda binaria tal
 * que la diferencia de [j]-[i]<=K y la repuesta será el máxima diferencia entre
 * todos los pares (i,j) encontrados incrementados en 1.
 */
#include <iostream>
#include <bits/stdc++.h>
#include <algorithm>
#define ENDL '\n'
#define MAX 1000010
#define MOD 10000
#define LL long long
using namespace std;

LL values[MAX], K;
int n;

int main() {

	ios_base::sync_with_stdio(0);
	cin.tie(0);

	cout.setf(ios::fixed, ios::floatfield);
	cout.precision(0);

	cin >> n >> K;
	for (int i = 0; i < n; i++)
		cin >> values[i];
	sort(values, values + n);

	int answer = 0, begin, end, pivot, solTemp;

	for (int i = 0; i < n; i++) {
		solTemp = begin = i;
		end = n - 1;

		while (begin <= end) {
			pivot = (begin + end) / 2;
			if (values[pivot] - values[i] <= K) {
				begin = pivot + 1;
				solTemp = max(solTemp, pivot);
			} else {
				end = pivot - 1;
			}
		}

		answer = max(answer, solTemp - i + 1);
	}

	cout<<answer<<ENDL;

	return 0;
}
