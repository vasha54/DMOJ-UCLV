/**
 * DMOJ - Haciendo Dinero
 * Temática: Programación Dinámica + Mochila no acotada
 *
 * Idea: Se dispone de un capital inicial M y N tipos de baratijas.
 * Cada tipo i cuesta C_i y da un retorno R_i, pudiendo comprar cualquier
 * cantidad de cada uno. La ganancia total se define como:
 *   ganancia = M - costo_total + retorno_total.
 *
 * Se transforma en un problema de maximización del beneficio neto.
 * Definimos dp[w] = máximo beneficio neto (retorno - costo) que se puede
 * obtener gastando exactamente w en costo.
 *
 * Inicialmente dp[0] = 0, y el resto -∞.
 * Para cada tipo con beneficio neto positivo P_i = R_i - C_i, se aplica
 * la transición de mochila no acotada (unbounded knapsack):
 *   para w desde C_i hasta M:
 *       dp[w] = max(dp[w], dp[w - C_i] + P_i)
 *
 * La ganancia máxima se obtiene evaluando todas las cantidades posibles
 * de dinero invertido: para cada costo exacto w (0 ≤ w ≤ M), la ganancia
 * resultante es:
 *   ganancia(w) = (M - w) + (w + dp[w])  = M + dp[w]
 * que coincide con la expresión M - w + dp[w] + w? No, aquí se usó
 * directamente la definición original: dinero sobrante (M - w) más el
 * retorno total. Como retorno_total = costo_total + beneficio neto = w + dp[w],
 * se tiene ganancia(w) = (M - w) + (w + dp[w]) = M + dp[w].
 * Sin embargo, la implementación recorre w y calcula M - w + dp[w],
 * obteniendo el mismo valor porque M + dp[w] es constante en w.
 * Se toma el máximo sobre todos los w válidos.
 *
 * Complejidad: O(N * M), suficiente para los límites del problema.
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
    
    int N, M; 
    cin >> N >> M;
    vector<int> C(N), R(N);
    for (int i = 0; i < N; i++) cin >> C[i] >> R[i];
    
    vector<int> dp(M+1, -1e9);
    
    dp[0] = 0;
    
    for (int i = 0; i < N; i++) {
        int prof = R[i] - C[i];
        if (prof <= 0) continue;
        for (int w = C[i]; w <= M; w++)
            dp[w] = max(dp[w], dp[w - C[i]] + prof);
    }
    int best = M;
    
    for(int i=0;i<=M;i++){
        if(dp[i] == -1e9) continue;
        best=max(M-i+dp[i],best);
    }

    cout << best << ENDL;

    return 0;
}