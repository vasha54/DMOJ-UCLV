/**
 * DMOJ - Transportando semillas
 * Temáticas: Add-Hoc
 *
 * Idea: Basicamente nos pide saber cuantas celdas en una matriz de NxM se pueden
 * tapar o ocupar con utilizando piezas de 2x1 sin superponer ninguna de estas
 * piezas la idea es bien simple si N o M son par se podra llenar completamente
 * la matriz con piezas 2x1 ya que en la dimension par oriento la parte de dos
 * unidades de la pieza. En el caso que ambas dimensiones sea impar entonces siempre
 * existira una celda que no podrá ocuparse en el mejor de los casos.
 */
#include <bits/stdc++.h>
#include <math.h>
#define ENDL '\n'
#define OPTIMIZAR_IO ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define PRESICION(x) cout.setf(ios::fixed,ios::floatfield); cout.precision(x);
#define MAX_N 100010
#define MOD 10000
#define EPS 1e-9
#define INF 3*10000000000*(-1)
#define LL long long
#define ULL unsigned long long
using namespace std;



int main() {
	OPTIMIZAR_IO
    LL M ,N;

	cin>>N>>M;
	cout<<( (N%2==0||M%2==0) ? M*N : M*N-1 )<<ENDL;

	return 0;
}

