/**
 * DMOJ - Camino de Bloques
 * Temática: Dijkstra
 *
 * Idea: Dado un grafo no dirigido, conexo, con N ≤ 100 nodos y M ≤ 10000
 * aristas con pesos positivos, y un camino más corto de 1 a N de longitud L,
 * se puede duplicar exactamente una arista para maximizar la nueva distancia
 * mínima. Se debe calcular el máximo incremento posible.
 * 
 * Solo las aristas que pertenecen a todos los caminos más cortos originales
 * (aristas críticas) pueden aumentar la distancia. Se sigue este procedimiento:
 *   1. Calcular distancias mínimas d1 desde 1 y d2 desde N (Dijkstra).
 *      L = d1[N].
 *   2. Reconstruir un camino más corto P (por ejemplo, siguiendo padres desde 1).
 *      Las aristas de P contienen todas las aristas críticas.
 *   3. Para cada arista e = (u,v,w) del camino P:
 *        a) Calcular la distancia más corta sin usar e, llamada bypass(e).
 *           (Se ejecuta Dijkstra prohibiendo temporalmente esa arista)
 *        b) Nueva distancia si se duplica e: nueva = min(bypass(e), L + w)
 *        c) Incremento = nueva - L.
 *   4. La respuesta es el máximo incremento encontrado.
 *
 * Si no hay aristas críticas (existen varios caminos mínimos disjuntos), el
 * máximo incremento será 0.
 * 
 * Complejidad: O(K * (M log N)) donde K ≤ N-1 es la longitud del camino P.
 * Con N=100, M=10000 es muy rápido.
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

int N, M;
vector< vector<pii> > graph;

vector<int> dijkstra(int src, int ban_a = -1, int ban_b = -1) {
    vector<int> dist(N+1, INF);
    priority_queue<pii, vector<pii>, greater<> > pq;
    dist[src] = 0;
    pq.push({0, src});
    while (!pq.empty()) {
        auto [d, u] = pq.top(); pq.pop();
        if (d != dist[u]) continue;
        for (auto [v, w] : graph[u]) {
            if ((u == ban_a && v == ban_b) || (u == ban_b && v == ban_a)) continue;
            if (dist[v] > d + w) {
                dist[v] = d + w;
                pq.push({dist[v], v});
            }
        }
    }
    return dist;
}

vector<tiii> get_path(const vector<int>& dist, const vector<int>& parent) {
    vector<tiii> path;
    int cur = N;
    while (cur != 1) {
        int p = parent[cur];
        int w = 0;
        for (auto [v, peso] : graph[p]) {
            if (v == cur) { w = peso; break; }
        }
        path.emplace_back(p, cur, w);
        cur = p;
    }
    reverse(path.begin(), path.end());
    return path;
}

signed main()
{
    OPTIMIZAR_IO
    //PRESICION(2)
    READ_FILE
    //WRITE_FILE
    
    cin >> N >> M;
    graph.assign(N+1, {});

    for (int i = 0; i < M; i++) {
        int u, v, w;
        cin >> u >> v >> w;
        graph[u].emplace_back(v, w);
        graph[v].emplace_back(u, w);
    }

    vector<int> d1(N+1, INF), d2(N+1, INF);
    vector<int> p1(N+1, -1);

    priority_queue<pii, vector<pii>, greater<>> pq;

    d1[1] = 0;
    pq.push({0, 1});

    while (!pq.empty()) {
        auto [d, u] = pq.top(); pq.pop();
        if (d != d1[u]) continue;
        for (auto [v, w] : graph[u]) {
            if (d1[v] > d + w) {
                d1[v] = d + w;
                p1[v] = u;
                pq.push({d1[v], v});
            }
        }
    }

    int L = d1[N];
    auto path = get_path(d1, p1);

    int max_increase = 0;
    for (auto [u, v, w] : path) {
        vector<int> dist_no = dijkstra(1, u, v);
        int bypass = dist_no[N];
        int new_dist = min(bypass, L + w);
        int increase = new_dist - L;
        if (increase > max_increase) max_increase = increase;
    }

    cout << max_increase << ENDL;

    return 0; 
}