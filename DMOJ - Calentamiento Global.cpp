/**
 * DMOJ - Calentamiento Global
 * Temática: Programación Dinámica : LIS
 *
 * Idea: Para cada dia i, sea L(i) la longitud de la subsecuencia creciente más
 * larga que termina en el dia i contiene i y R(i) sea la longitud de la
 * subsecuencia creciente más larga que comienza en i después de que [1, i]
 * se reduce. Podemos calcular cada R(i)$ almacenando la longitud de la
 * subsecuencia decreciente más larga para cada prefijo del reverso de la
 * secuencia de dias entradas. Luego la espuesta será aquel tal que L(i)+R(i)-1
 * sea mayor para todos los dias de la colección.
 */
#include <bits/stdc++.h>
#include <math.h>

#define ENDL '\n'
#define OPTIMIZAR_IO ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define PRESICION(x) cout.setf(ios::fixed,ios::floatfield); cout.precision(x);
#define READ_INPUT_FILE freopen("Input.txt","r",stdin);
#define WRITE_OUTPUT_FILE freopen("Output.txt","w",stdout);
#define MAX_N 50
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
	//PRESICION(0)
	//READ_INPUT_FILE
	//WRITE_OUTPUT_FILE

	int n,x;

	cin >> n >> x;
	vector<LL> tempertures(n);
	for (int i = 0; i < n; i++) cin >> tempertures[i];

	vector<LL> LIS(n, INT_MAX);
	vector<int> sizeLIS(n);
	int longest = 0;
	for (int i = 0; i < n; i++) {
		int j = lower_bound(LIS.begin(), LIS.end(), tempertures[i]) - LIS.begin();
		LIS[j] = tempertures[i];
		sizeLIS[i] = j + 1;
		longest = max(longest, sizeLIS[i]);
	}

	vector<LL> LDS  (n, INT_MAX);
	for (int i = n - 1; i >= 0; i--) {
		int pos = lower_bound(LDS.begin(), LDS.end(), -tempertures[i] + x) - LDS.begin();
		longest = max(longest, sizeLIS[i] + pos);

		int insert_pos =
		    lower_bound(LDS.begin(), LDS.end(), -tempertures[i]) - LDS.begin();
		LDS[insert_pos] = -tempertures[i];
	}
	cout << longest << ENDL;
}


