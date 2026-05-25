/**
 * DMOJ - OCI 2025 Day 2 A - AND-Magedón
 * Temática: Greedy (voraz sobre bits)
 * 
 * Idea: Tenemos un arreglo A de N números y un entero K (0 <= K <= N).
 * Debemos encontrar el máximo AND bit a bit de una subsecuencia de exactamente K elementos.
 *
 * Propiedad clave: el AND es posicional y el bit más significativo pesa más que todos
 * los menos significativos juntos. Por tanto, podemos decidir bit a bit de mayor a menor
 * si es posible tenerlo encendido en el AND de algún subconjunto de tamaño K.
 *
 * Algoritmo:
 * 1. Inicializar ans = 0.
 * 2. Para cada bit b desde 60 hasta 0 (10^18 < 2^60):
 *      candidato = ans | (1LL << b)
 *      Contar cuántos elementos de A contienen TODOS los bits del candidato
 *      (condición: (x & candidato) == candidato).
 *      Si hay al menos K elementos, entonces podemos elegir K de ellos y su AND
 *      tendrá al menos esos bits encendidos. Fijamos ans = candidato.
 * 3. Al final ans es el máximo AND posible. Si K == 0, por convención retornamos 0.
 *
 * Complejidad: O(T * N * 61), donde T es el número de casos.
 * Con N <= 10^6 por caso y T <= 100, el peor caso teórico es 6.1e9 operaciones,
 * lo que no pasaría en C++. Se asume que la suma total de N sobre todos los casos es <= 10^6
 * (restricción usual en problemas multi-caso). Si no es así, se requiere optimización adicional.
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
#define MAX_N 1000010
#define MOD  1000000007
#define pii pair<int,int>
#define tiib tuple<int,int,bool>
 
using namespace std;
using namespace __gnu_pbds;

signed main()
{
    OPTIMIZAR_IO
    //PRESICION(2)
    READ_FILE
    //WRITE_FILE

    int cases, N, K, ans;
    cin >> cases;
    while(cases--) {
        cin >> N >> K;
        vector<int> A(N);
        for(int i = 0; i < N; i++) cin >> A[i];
        
        if(K == 0) {
            // Por convención en problemas de subsecuencia de tamaño 0, el AND es 0.
            // Si el neutro lógico fuera requerido, sería (1LL << 61) - 1.
            cout << 0 << ENDL;
            continue;
        }
        
        ans = 0;
        for(int bit = 60; bit >= 0; bit--) {
            int cand = ans | (1LL << bit);
            int cnt = 0;
            for(int x : A) {
                if((x & cand) == cand) {
                    cnt++;
                    if(cnt >= K) break; // ya tenemos suficientes
                }
            }
            if(cnt >= K) {
                ans = cand;
            }
        }
        cout << ans << ENDL;
    }
    return 0;
}
