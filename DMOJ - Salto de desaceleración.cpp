/**
 * DMOJ - Salto de desaceleración
 * Temáticas: Programación Dinámica
 *
 * Idea: A priori en el peor de los casos se toma solamente los valores de la
 * primera celda o última que dicha suma sería en el peor de los casos 2*10^9.
 * Vamos a construir una matriz donde el la posición [i,j] vamos almacenar lo
 * mejor hasta la celda i (incluyendo el valor de dicha celda )
 * llegando a ella con un salto previo mayor o igual a j de forma que la solución
 * del problema nos queda en [n,1].
 *
 * Si en la posición [i,j] hay un valor x significa que hasta la celda i lo mejor
 * hasta ella es x con un salto previo igual o mayor que j. Por tanto a partir
 * de ella se puede tomar ese valor x y realizar j saltos diferentes en el rango
 * [1,j] para caer en otras celdas en una posicion del rango [i+1 , i+j] y
 * sumar el valor x. Para optimizar este proceso basta con propagar el valor x
 * en la fila i para las columnas menores que j siempre y cuando el valor de [i,j]
 * sea mayor que [i,j-1]
 *
 * Inicialmente en todas las posiciones de la matriz valor almacenar el -OO
 * que para este caso sería -3*10^9. Para llenar la matriz lo haremos de la
 * siguiente manera:
 *
 * Por cada x pertence [1,n]:
 *    dp[1][x] = v[1]
 *
 * Por cada i pertence [1,n]:
 *   Por cada j pertence[n-1,1]:
 *      dp[i][j] = max(dp[i][j],dp[i][j+1])//
 *      Si dp[i][j] != -OO:
 *         Si i+j<=n y dp[i+j][j]< dp[i][j]+v[i+j]:
 *           dp[i+j][j] = dp[i][j]+v[i+j]
 *
 */
#include <bits/stdc++.h>
#include <math.h>
#define ENDL '\n'
#define OPTIMIZAR_IO ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define PRESICION(x) cout.setf(ios::fixed,ios::floatfield); cout.precision(x);
#define MAX_N 3010
#define MOD 10000
#define EPS 1e-9
#define INF 3*10000000000*(-1)
#define LL long long
#define ULL unsigned long long
using namespace std;

LL dp[MAX_N][MAX_N], values[MAX_N], best;
int nelements;
int main() {

	OPTIMIZAR_IO
	PRESICION(0)
	cin >> nelements;
	fill(dp[0], dp[0] + MAX_N, INF);
	for (int i = 1; i <= nelements; i++) {
		cin >> values[i];
		fill(dp[i], dp[i] + MAX_N, INF);
	}
	fill(dp[1], dp[1] + MAX_N, values[1]);


	for (int i = 1; i <= nelements; i++) {
		for (int j = nelements - 1; j >= 1; j--) {
			dp[i][j]=max(dp[i][j],dp[i][j+1]);
			if (dp[i][j] != INF) {
				if(i+j<=nelements && dp[i+j][j]<dp[i][j]+values[i+j])
					dp[i+j][j]=dp[i][j]+values[i+j];
			}
		}
	}


	cout << dp[nelements][1]<<ENDL;
	return 0;
}
