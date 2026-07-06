/**
 * DMOJ - Reiner y Bertholdt
 * Temática: Pila monótona / Algoritmo voraz
 *
 * Idea: Dado un número con N dígitos (sin ceros iniciales) y un entero K,
 * debemos eliminar exactamente K dígitos para obtener el mayor número
 * posible. La longitud del resultado será N - K.
 *
 * Para maximizar el número, interesa que los dígitos más significativos
 * (los de la izquierda) sean lo más grandes posible. Se puede lograr con
 * una pila monótona decreciente:
 *   - Recorremos cada dígito d del número original.
 *   - Mientras la pila no esté vacía, aún queden eliminaciones (K > 0) y
 *     el tope de la pila sea menor que d, extraemos el tope (eliminamos ese
 *     dígito) y decrementamos K.
 *   - Apilamos d.
 *   - Si al final del recorrido aún K > 0, eliminamos los últimos K dígitos
 *     (los menos significativos que quedaron al final).
 *
 * La pila contendrá los dígitos del número máximo, en orden. Se imprime
 * la secuencia resultante.
 *
 * Complejidad: O(N), ya que cada dígito se inserta y se extrae a lo sumo
 * una vez. N y K hasta 5·10^5.
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
#define MAX_N 1000
#define SHIT 500
#define MAXTREE  (MAX_N << 2)
#define MOD  1234567891LL
#define INF 1e18
#define pii pair<int,int>
#define tiib tuple<int,int,bool>
#define tiii tuple<int,int,int>
#define midle (left+right)/2   

using namespace std;
using namespace __gnu_pbds;

int mov_r[] = { 0, 0, 1,-1};
int mov_c[] = { 1,-1, 0, 0};



signed main()
{
    OPTIMIZAR_IO
    //PRESICION(2)
    READ_FILE
    //WRITE_FILE
    
    int N, K;
    string s;
    cin >> N >> K >> s;

    vector<char> st; 
    int to_remove = K;

    for (char c : s) {
        while (!st.empty() && to_remove > 0 && st.back() < c) {
            st.pop_back();
            to_remove--;
        }
        st.push_back(c);
    }

    while (to_remove > 0 && !st.empty()) {
        st.pop_back();
        to_remove--;
    }

    for (char c : st) cout << c;
    cout << ENDL;  

    return 0;
}