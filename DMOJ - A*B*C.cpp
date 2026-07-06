/**
 * DMOJ - A*B*C
 * Temática: Fuerza Bruta / Enumeración ordenada
 *
 * Idea: Dado un entero positivo K (≤ 2·10⁵), contar cuántas ternas (A,B,C)
 * de enteros positivos satisfacen A*B*C ≤ K. El orden importa: por ejemplo,
 * (1,2,3) y (2,1,3) son consideradas ternas diferentes.
 *
 * Para resolverlo de manera eficiente y sin contar permutaciones una a una,
 * enumeramos todas las combinaciones con a ≤ b ≤ c tales que a·b·c ≤ K.
 * Luego multiplicamos por el número de permutaciones del multiconjunto:
 *   - a = b = c → 1 permutación.
 *     Ejemplo de permutación (1,1,1)
 *   - a = b ≠ c  o  a ≠ b = c → 3 permutaciones.
 *     Ejemplo de permutación (1,1,2)
 *   - todos distintos → 6 permutaciones.
 *     Ejemplo de permutación (1,2,3s)
 *
 * Los bucles se implementan:
 *   for a = 1..K
 *     for b = a; a*b ≤ K; b++
 *       for c = b; a*b*c ≤ K; c++
 * La cantidad de iteraciones es el número de triplas ordenadas (a≤b≤c)
 * con producto ≤ K. Para K = 200000 ese número es de aproximadamente
 * 2.2 millones, plenamente aceptable en tiempo y memoria.
 *
 * Complejidad: O(N) donde N = # triplas ordenadas; O(1) memoria extra.
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
#define MAX_N 310
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

bool segure[MAX_N][MAX_N];
int seconds[MAX_N][MAX_N];

signed main()
{
    OPTIMIZAR_IO
    //PRESICION(2)
    READ_FILE
    //WRITE_FILE
    
    int K;
    cin >> K;
    int ans = 0;

    for (int a = 1; a <= K; ++a) {
        for (int b = a; a * b <= K; ++b) {
            for (int c = b; a * b * c <= K; ++c) {
                if (a == b && b == c)
                    ans += 1;
                else if (a == b || b == c)   // a==b!=c  o  a!=b==c
                    ans += 3;
                else
                    ans += 6;
            }
        }
    }

    cout << ans << ENDL;

    return 0; 
}