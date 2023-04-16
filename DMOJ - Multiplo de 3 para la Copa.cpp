/**
 * DMOJ - Multiplo de 3 para la Copa
 * Temáticas: Teoria de Numero + Reglas de Divisibilidad
 *
 * Idea:Dado un número N se quiere eliminar la menor cantidad de digitos tal que
 * el numero resultado sea multiplo de 3. Lo primero es ver la suma de todos los
 * digitos del numero así como la cantidad de digitos del numero sean mod 1 y
 * mod 2 con respecto a 3. Si la suma de los digitos es multiplo de 3 no hay
 * problema y no debemos quitar ningún digito.
 *
 * Si la suma de los digitos mod 3 diera como resultado 1 debemos chequear los
 * siguiente:
 * 		1. Si hay una cantidad de digitos que mod 3 es 1 en el número mayor e
 * 		igual a 1 y la cantidad de digitos del numero inicial es mayor que 1
 * 		entonces la solución es quitar un digito al número.
 *      2. Si hay una cantidad de digitos que mod 3 es 2 en el número mayor e
 * 		igual a 2 y la cantidad de digitos del numero inicial es mayor que 2
 * 		entonces la solución es quitar dos digitos al número.
 * 		3. De no cumplirse ni 1 ni 2 no hay forma por tanto la respuesta es
 * 		-1
 *
 *
 * Si la suma de los digitos mod 3 diera como resultado 2 debemos chequear los
 * siguiente:
 * 		1. Si hay una cantidad de digitos que mod 3 es 2 en el número mayor e
 * 		igual a 1 y la cantidad de digitos del numero inicial es mayor que 1
 * 		entonces la solución es quitar un digito al número.
 *      2. Si hay una cantidad de digitos que mod 3 es 1 en el número mayor e
 * 		igual a 2 y la cantidad de digitos del numero inicial es mayor que 2
 * 		entonces la solución es quitar dos digitos al número.
 * 		3. De no cumplirse ni 1 ni 2 no hay forma por tanto la respuesta es
 * 		-1
 */
#include <bits/stdc++.h>
#define ENDL '\n'
#define OPTIMIZAR_IO ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define PRESICION(x) cout.setf(ios::fixed,ios::floatfield); cout.precision(x);
#define MAX 1100
#define MOD 10000
#define LL long long
using namespace std;

int main() {

	OPTIMIZAR_IO
	//PRESICION(2)

	string numberstr;
	cin >> numberstr;
	int cCountDigits = numberstr.size();

	int cMod2 = 0;
	int cMod1 = 0;
	int sumDigits = 0;

	for (int i = 0; i < cCountDigits; i++) {
		int digit = numberstr[i] - '0';
		sumDigits += digit;
		if (digit % 3 == 1)
			cMod1++;
		if (digit % 3 == 2)
			cMod2++;
	}

	int answer = -1;

	if (sumDigits % 3 == 0) {
		answer = 0;
	} else if (sumDigits % 3 == 2) {
		if (cMod2 >= 1 && cCountDigits - 1 > 0)
			answer = 1;
		if (cMod1 >= 2 && cCountDigits - 2 > 0)
			answer = 2;
	} else if (sumDigits % 3 == 1) {
		if (cMod1 >= 1 && cCountDigits - 1 > 0)
			answer = 1;
		if (cMod2 >= 2 && cCountDigits - 2 > 0)
			answer = 2;
	}

	cout << answer << ENDL;

	return 0;
}
