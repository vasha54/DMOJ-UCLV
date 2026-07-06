/**
 * DMOJ - Cow Dance Show
 * Temática: Búsqueda binaria + Simulación con cola de prioridad
 *
 * Idea: Se tienen N vacas, cada una con un tiempo de baile d_i. El escenario
 * puede albergar K vacas simultáneamente. En cuanto una vaca termina, la
 * siguiente en espera comienza inmediatamente. Se conoce un tiempo máximo
 * permitido T_max. Se debe encontrar el menor K tal que el tiempo total
 * (makespan) para que todas las vacas terminen de bailar sea ≤ T_max.
 *
 * Dado que si un K funciona, cualquier K' > K también funcionará (monotonía),
 * podemos aplicar búsqueda binaria sobre K en el rango [1, N].
 *
 * Para un K fijo, simulamos con una min‑heap (priority_queue) que almacena
 * los tiempos de finalización de las vacas actualmente en el escenario.
 * - Insertamos los primeros K tiempos (o todos si N < K).
 * - Para cada vaca restante:
 *      t = heap.top(); heap.pop();       // la que termina antes
 *      t += d_i;                         // comienza la nueva vaca
 *      heap.push(t);
 * - El tiempo total es el mayor valor del heap al terminar.
 * Si ese tiempo ≤ T_max, entonces K es factible.
 *
 * Complejidad: O(N log N * log N) ≈ 2·10^6 operaciones para N=10^4, suficiente.
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

int ncows, Tmax;
vector<int> cows;

bool can(int K) {
    priority_queue<int, vector<int>, greater<int>> pq;
    int i = 0;
    
    for (; i < K && i < ncows; ++i) pq.push(cows[i]);

    int finish = 0;
    while (!pq.empty()) {
        int t = pq.top(); pq.pop();
        finish = t; 
        if (i < ncows) {
            pq.push(t + cows[i]);
            ++i;
        }
    }
    return finish <= Tmax;
}

signed main()
{
    OPTIMIZAR_IO
    //PRESICION(2)
    READ_FILE
    //WRITE_FILE
    
    cin >> ncows >> Tmax;
    cows.resize(ncows);
    for (int i = 0; i < ncows; ++i) cin >> cows[i];

    int left = 1, rigth = ncows, ans = ncows;
    while (left <= rigth) {
        int mid = (left + rigth) / 2;
        if (can(mid)) {
            ans = mid;
            rigth = mid - 1;
        } else {
            left = mid + 1;
        }
    }
    cout << ans << ENDL;

    return 0; 
}