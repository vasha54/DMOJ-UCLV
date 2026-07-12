/**
 * DMOJ - Milk Visits
 * Tematica: DSU
 *
* Idea: Se tiene un árbol con N nodos (granjas), cada una produce un tipo de
 * leche (H o G). Hay M consultas: para un camino entre A_i y B_i, ¿aparece
 * al menos una granja de tipo C_i en el camino?
 *
 * Como solo hay dos tipos de leche, podemos separar el árbol en componentes
 * conexas que contengan únicamente granjas de un mismo tipo (H o G).
 * Para ello, eliminamos del grafo las aristas que conectan granjas de distinto
 * tipo. Las componentes resultantes son monocromáticas.
 * Para una consulta (A, B, C):
 *   - Si la granja A produce leche C, la respuesta es 1.
 *   - Si la granja B produce leche C, la respuesta es 1.
 *   - Si A y B están en componentes distintas (pero conectadas por aristas
 *     originales), significa que hay al menos un cambio de tipo en el camino,
 *     por lo que sí hay al menos una granja de tipo C en el camino.
 *     En este caso la respuesta es 1.
 *   - Si A y B están en la misma componente y ninguna de ellas produce C,
 *     entonces todo el camino es del otro tipo → respuesta 0.
 *
 * Complejidad: O(N + M) con DSU o DFS para unir componentes del mismo tipo.
 */
#include <bits/stdc++.h>

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
#define int long long
#define REP(x) for(int i=0;i<x;i++)
#define uint unsigned long long
#define PRINT_LINE cout<<ENDL;
#define pii pair<int,int>
#define tiii tuple<int,int,int>
#define MAX_N 1010
#define MAX_TREE MAX_N << 2
#define MOD  1000000007
#define MID (right+left)/2

using namespace std;

// Desplazamientos en 4 direcciones
const int dr[] = {1, -1, 0, 0};
const int dc[] = {0, 0, 1, -1};

struct DSU {
    vector<int> parent;
    DSU(int n) {
        parent.resize(n + 1);
        iota(parent.begin(), parent.end(), 0);
    }
    int find(int x) {
        if (parent[x] != x)
            parent[x] = find(parent[x]);
        return parent[x];
    }
    void unite(int x, int y) {
        x = find(x);
        y = find(y);
        if (x != y) parent[x] = y;
    }
    bool same(int x, int y) {
        return find(x) == find(y);
    }
};

signed main() {
    OPTIMIZAR_IO
    //PRESICION(2)
    READ_FILE
    //WRITE_FILE
    int N, M;
    cin >> N >> M;
    string types;
    cin >> types;
    types = " " + types;

    DSU dsu(N);
    for (int i = 0; i < N - 1; i++) {
        int u, v;
        cin >> u >> v;
        if (types[u] == types[v]) {
            dsu.unite(u, v);
        }
    }

    string answer;
    for (int i = 0; i < M; i++) {
        int a, b;
        char c;
        cin >> a >> b >> c;
        if (types[a] == c || types[b] == c || !dsu.same(a, b)) answer += '1';
        else answer += '0';

    }

    cout << answer << ENDL;
    return 0;
}