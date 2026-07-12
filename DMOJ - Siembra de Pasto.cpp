/**
 * DMOJ - Siembra de pasto
 * Tematica: Grafos, Teoría de grafos, Coloración
 *
* Idea: Se tiene un árbol (grafo conexo y acíclico) con N nodos. Se deben
 * asignar tipos de pasto (colores) a los campos (nodos) de manera que dos
 * campos que sean adyacentes o que compartan un vecino común no tengan el
 * mismo tipo de pasto. En otras palabras, dos nodos a distancia 1 o 2 no
 * pueden compartir color. Esto equivale a colorear el cuadrado del grafo G².
 *
 * Observación clave: en un árbol, los vecinos de un nodo v junto con v
 * forman una clique en G². Por tanto, el número cromático de G² es al menos
 * el tamaño de la mayor de esas cliques, es decir, 1 + max_grado(v).
 *
 * Se puede demostrar que este valor también es suficiente: podemos colorear
 * el árbol con BFS desde una raíz, usando colores {1..K} donde K = 1 + Δ.
 * En cada paso, un nodo debe evitar los colores de su padre, abuelo y
 * hermanos; como a lo sumo hay Δ vecinos en el padre, siempre hay un color
 * libre entre los K disponibles.
 *
 * Por tanto, la respuesta es simplemente: max_grado(v) + 1.
 *
 * Complejidad: O(N) para leer el árbol y calcular el grado máximo.
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



signed main() {
    OPTIMIZAR_IO
    //PRESICION(2)
    READ_FILE
    //WRITE_FILE
    int N; cin >> N;
    vector<int> deg(N+1, 0);
    for (int i=0; i<N-1; ++i) {
        int u, v; cin >> u >> v;
        deg[u]++; deg[v]++;
    }
    int ans = 0;
    for (int i=1; i<=N; ++i) ans = max(ans, deg[i] + 1);
    cout << ans << ENDL;
    return 0;
}