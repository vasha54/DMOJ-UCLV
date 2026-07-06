/**
 * DMOJ - Apilamiento de Fardos de Heno
 * Temática: Programación Dinamica + Suma de Prefijo
 * 
 * Idea: Dado N pilas vacías (N impar) y K instrucciones "agregar 1 fardo a cada pila en [A,B]",
 * se debe calcular la mediana de las alturas finales. Para aplicar las K actualizaciones de 
 * forma eficiente se usa un arreglo de diferencias: por cada instrucción incrementamos en +1 
 * la posición A y decrementamos en -1 la posición B+1. Luego, con una suma acumulada (prefijo) 
 * obtenemos las alturas finales de las N pilas. Finalmente, ordenamos el arreglo de alturas 
 * y seleccionamos el elemento del medio (índice N/2, asumiendo 0-indexado y N impar) como 
 * la mediana.
 * 
 * Complejidad: O(K + N log N), donde N y K pueden ser hasta 10^6. El ordenamiento domina 
 * el tiempo pero es suficiente para los límites del problema.  
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
#define int long long
#define uint unsigned long long
#define PRINT_LINE cout<<ENDL;
#define MAX_N 2010
#define MAXTREE  (MAX_N << 2)
#define MOD  1000000007
#define pii pair<int,int>
#define tiib tuple<int,int,bool>
#define midle (left+right)/2   // OJO: rigth en lugar de right, se mantiene el original

using namespace std;
using namespace __gnu_pbds;



signed main()
{
    OPTIMIZAR_IO
    //PRESICION(2)
    READ_FILE
    //WRITE_FILE

    int N, K, A, B;
    cin>>N>>K;
    vector<int> piles(N+2,0);
    vector<int> heights;
    for(int i=0;i<K;i++){
        cin>>A>>B;
        piles[A]++;
        piles[B+1]--;
    }
    for(int i=1;i<=N;i++){
        piles[i] += piles[i-1];
        heights.push_back(piles[i]);
    }

    sort(heights.begin(),heights.end());

    cout<<heights[N/2]<<ENDL;
    return 0;
}