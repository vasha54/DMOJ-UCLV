/**
 * DMOJ - Suma con pares
 * Tema: Búsqueda Binaria / Two Pointers
 * 
 * Idea: Dado un conjunto de N enteros positivos distintos y un entero X,
 * contar cuántos pares (a, b) con a < b suman exactamente X.
 *
 * La solución ordena el arreglo ascendentemente (O(N log N)).
 * Luego, para cada elemento a = values[i] se calcula su complemento
 * y = X - a. Como a < b, solo se busca en el sufijo values[i+1..N-1]
 * usando binary_search. Si se encuentra, se incrementa el contador.
 * La búsqueda se detiene (break) si y < a, porque todos los complementos
 * serían menores que a en adelante (el arreglo es creciente).
 *
 * Alternativamente, se puede usar two pointers (uno al inicio, otro al
 * final) para resolver en O(N) tras el ordenamiento.
 *
 * Complejidad: O(N log N) por el ordenamiento y las búsquedas binarias.
 * Con N ≤ 100000 (según restricciones del problema) es más que suficiente.
 */
#include <bits/stdc++.h>

#define ENDL '\n'
#define OPTIMIZAR_IO ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define PRESICION(x) cout.setf(ios::fixed,ios::floatfield); cout.precision(x);

#ifdef LOCAL
    #define READ_FILE freopen("Input.txt","r",stdin);
    #define WRITE_FILE freopen("Output.txt","w",stdout);
#else
    #define READ_FILE 
    #define WRITE_FILE 
#endif
#define REP(x) for(int i=1;i<=x;i++)
#define int long long
#define uint unsigned long long
#define PRINT_LINE cout<<ENDL;
#define pii pair<int,int>
#define tiii tuple<int,int,int>
#define MAX_N 1010
#define MAX_TREE MAX_N << 2
#define MOD  1000000007
#define MID (right+left)/2

using namespace std;

signed main() {
    OPTIMIZAR_IO
    //PRESICION(2)
    READ_FILE
    //WRITE_FILE
    int n, x;
    cin >> n;
    vector<int> values(n);
    for (int i = 0; i < n; i++) cin >> values[i];
    cin >> x;

    sort(values.begin(), values.end());

    int pairs = 0;
    for (int i = 0; i < n; i++) {
        int y = x - values[i];
        if (y <= values[i]) break;         
        if (binary_search(values.begin() + i + 1, values.end(), y)) {
            pairs++;
        }
    }

    cout << pairs << ENDL;
    return 0;
}