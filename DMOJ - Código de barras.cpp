/**
 * DMOJ - Código de barras
 * Temática: Conteo con prefijos / Transformación
 *
 * Idea: Dada una cadena binaria de longitud N, se desea contar cuántas subcadenas
 * contienen igual cantidad de '0's y '1's. Transformamos cada carácter en un valor:
 * '1' → +1, '0' → -1. Una subcadena [l, r] tiene balance cero si la suma de esos
 * valores es 0, lo que equivale a que la diferencia entre los prefijos hasta r y
 * hasta l-1 sea cero: pref[r] == pref[l-1]. 
 * Calculamos el arreglo de prefijos (comenzando con pref[0]=0). Luego, para cada 
 * valor de prefijo, debemos contar la cantidad de veces que aparece. Cada par de
 * posiciones con el mismo valor de prefijo da una subcadena balanceada. Si un valor
 * de prefijo aparece k veces, el número de subcadenas que aporta es k*(k-1)/2.
 * Usamos un mapa (o un arreglo con desplazamiento) para registrar las frecuencias.
 * Complejidad: O(N) en tiempo y O(N) en espacio, suficiente para N ≤ 10^5.
 */
#include <bits/stdc++.h>
#include <bitset>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>

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
// #define int long long
// #define uint unsigned long long
#define PRINT_LINE cout<<ENDL;
#define MAX_N 110
#define MAXTREE  (MAX_N << 2)
#define MOD  1000000007
#define pii pair<int,int>
#define tiib tuple<int,int,bool>
#define midle (left+right)/2   

using namespace std;
using namespace __gnu_pbds;



signed main()
{
    OPTIMIZAR_IO
    //PRESICION(2)
    READ_FILE
    //WRITE_FILE

    int n;
    string s;
    cin >> n >> s;

    map<int, int> freq;
    freq[0] = 1;          
    int pref = 0, answer = 0;
    for (char c : s) {
        pref += (c == '1' ? 1 : -1);
        answer += freq[pref]; 
        freq[pref]++;
    }

    cout << answer << ENDL;

    return 0;
}