/**
 * DMOJ - Removiendo del Arreglo
 * Temática: DSU (Union-Find) + Procesamiento inverso
 *
 * Idea: Dado un arreglo A de N enteros y el orden en que se van eliminando
 * sus elementos (permutación de índices), antes de cada eliminación se debe
 * calcular la suma máxima de un subarreglo formado exclusivamente por los
 * elementos aún disponibles (no eliminados). La salida son N líneas,
 * correspondientes al estado inicial y después de cada eliminación.
 *
 * Para resolverlo eficientemente (N ≤ 10⁵ típicamente), se procesan las
 * eliminaciones en orden inverso: se comienza con todos los elementos
 * marcados como no disponibles y se van "agregando" en el orden inverso
 * al dado. Al agregar un elemento, se une con sus vecinos disponibles
 * utilizando DSU y se mantiene para cada componente la información
 * necesaria para calcular el máximo subarreglo (suma, prefijo máximo,
 * sufijo máximo, máximo subarreglo). Tras cada adición se registra el
 * máximo global. Finalmente se imprimen los valores en el orden original.
 *
 * Complejidad: O(N α(N)) en tiempo y O(N) en memoria.
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
#define MAX_N 110
#define MAXTREE  (MAX_N << 2)
#define MOD  1000000007
#define pii pair<int,int>
#define tiib tuple<int,int,bool>
#define midle (left+right)/2   // OJO: rigth en lugar de right, se mantiene el original

using namespace std;
using namespace __gnu_pbds;

struct DSU {
    vector<int> parent;
    vector<int> sum, pref, suff, best;
    int global_best;

    DSU(int n, const vector<int>& a) {
        parent.resize(n);
        iota(parent.begin(), parent.end(), 0);
        sum.resize(n);
        pref.resize(n);
        suff.resize(n);
        best.resize(n);
        global_best = LLONG_MIN;
    }

    int find(int x) {
        if (parent[x] != x)
            parent[x] = find(parent[x]);
        return parent[x];
    }

    void activate(int i, int val) {
        parent[i] = i;
        sum[i] = val;
        pref[i] = val;
        suff[i] = val;
        best[i] = val;
        global_best = max(global_best, best[i]);
    }

    void unite(int u, int v) {
        u = find(u);
        v = find(v);
        if (u == v) return;
        int new_sum = sum[u] + sum[v];
        int new_pref = max(pref[u], sum[u] + pref[v]);
        int new_suff = max(suff[v], sum[v] + suff[u]);
        int new_best = max({best[u], best[v], suff[u] + pref[v]});

        parent[v] = u;
        sum[u] = new_sum;
        pref[u] = new_pref;
        suff[u] = new_suff;
        best[u] = new_best;

        global_best = max(global_best, new_best);
    }
};

signed main()
{
    OPTIMIZAR_IO
    //PRESICION(2)
    READ_FILE
    //WRITE_FILE

    int n;
    cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }

    vector<int> perm(n);
    for (int i = 0; i < n; ++i) {
        cin >> perm[i];
        perm[i]--;
    }

    vector<bool> active(n, false);
    DSU dsu(n, a);
    vector<int> answers(n);

    for (int idx = n - 1; idx >= 0; --idx) {
        int i = perm[idx];
        active[i] = true;
        dsu.activate(i, a[i]);

        if (i > 0 && active[i - 1]) {
            dsu.unite(i - 1, i);
        }
        if (i < n - 1 && active[i + 1]) {
            dsu.unite(dsu.find(i), i + 1); 
        }

        answers[idx] = dsu.global_best;
    }

    for (int x : answers) {
        cout << x << ENDL;
    }

    return 0;
}