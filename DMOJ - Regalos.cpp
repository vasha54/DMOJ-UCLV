/**
 * DMOJ - Regalos
 * Temática: Búsqueda binaria + Ordenamiento + Prefijos
 *
 * Idea: Dados N regalos con precio P_i y envío S_i, y un presupuesto B,
 * se puede aplicar un cupón que reduce a la mitad el precio de un solo regalo
 * (división entera). Determinar el máximo número de regalos comprables.
 *
 * La solución óptima para un tamaño fijo k es elegir un regalo i para aplicar
 * el cupón, y luego completar con los k-1 regalos restantes de menor costo
 * total (P_j + S_j) sin descuento. Esto se debe a que, una vez fijado i,
 * el resto debe ser lo más barato posible sin importar sus precios individuales.
 *
 * Estrategia:
 * 1. Ordenar todos los regalos por costo total (P_i+S_i) ascendente.
 * 2. Calcular sumas prefijo de estos costos totales.
 * 3. Búsqueda binaria sobre k (0..N). Para un k dado, verificar si existe
 *    algún i tal que:
 *      costo = (⌊P_i/2⌋ + S_i) + (suma de los k-1 totales más pequeños
 *              excluyendo i) ≤ B.
 *    La suma de los k-1 totales excluyendo i se obtiene:
 *      - Si i está entre los primeros k en orden: suma = prefijo[k] - total[i].
 *      - Si i está después: suma = prefijo[k-1].
 *    Si algún i cumple, k es factible.
 *
 * Complejidad: O(N log N) por el ordenamiento y la verificación O(N) por
 * cada paso de la búsqueda binaria (total O(N log N)).
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

struct Gift {
    int price, ship, total;
    bool operator<(const Gift &other) const {
        return total < other.total;
    }
};

bool can(int k, const vector<Gift> &gifts, int B, const vector<int> &pref) {
    if (k == 0) return true;       
    if (k > (int)gifts.size()) return false;

    for (int i = 0; i < (int)gifts.size(); i++) {
        int sum_others;
        if (i < k) 
            sum_others = pref[k] - gifts[i].total;
        else
            sum_others = pref[k - 1];

        int cost = (gifts[i].price / 2) + gifts[i].ship + sum_others;
        if (cost <= B) return true;
    }
    return false;
}



signed main()
{
    OPTIMIZAR_IO
    //PRESICION(2)
    READ_FILE
    //WRITE_FILE
    
    int N, B;
    cin >> N >> B;
    vector<Gift> gifts(N);
    
    for (int i = 0; i < N; i++) {
        cin >> gifts[i].price >> gifts[i].ship;
        gifts[i].total = gifts[i].price + gifts[i].ship;
    }

    sort(gifts.begin(), gifts.end());

    vector<int> pref(N + 1, 0);
    for (int i = 1; i <= N; i++)
        pref[i] = pref[i - 1] + gifts[i - 1].total;

    int lo = 0, hi = N, ans = 0;
    while (lo <= hi) {
        int mid = lo + (hi - lo) / 2;
        if (can(mid, gifts, B, pref)) {
            ans = mid;
            lo = mid + 1;
        } else {
            hi = mid - 1;
        }
    }

    cout << ans << ENDL;

    return 0; 
}