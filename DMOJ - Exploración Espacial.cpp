/**
 * DMOJ - Exploración Espacial
 * Temática: Flood Fill + Cantidad de Componentes Conexas
 *
 * Idea:  Dado un mapa de N x N con '*' (asteroide) y '.' (vacío), contar
 * el número de grupos conexos de asteroides (conexidad 4‑direccional).
 *
 * Para evitar el posible desbordamiento de pila de una recursión profunda
 * (hasta 10^6 celdas en un solo componente), se utiliza BFS con una cola
 * explícita. Al encontrar un '*', se inicia una inundación que lo marca
 * como '.' y encola sus vecinos '*' hasta vaciar el componente. Cada
 * componente se cuenta una vez.
 *
 * Complejidad: O(N²) tiempo, O(N²) espacio.
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
#define REP(x) for(int i=1;i<=x;i++)
#define int long long
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

char maps[MAX_N][MAX_N];
string line;
int dimensions, asteriods;

void flood_fill_bfs(int x, int y) {
    queue<pii> q;
    q.push({x, y});
    maps[x][y] = '.'; 

    while (!q.empty()) {
        auto [r, c] = q.front();
        q.pop();

        for (int d = 0; d < 4; ++d) {
            int nr = r + dr[d];
            int nc = c + dc[d];
            if (nr >= 0 && nr < dimensions &&
                nc >= 0 && nc < dimensions &&
                maps[nr][nc] == '*') {
                maps[nr][nc] = '.';  
                q.push({nr, nc});
            }
        }
    }
}

signed main() {
    OPTIMIZAR_IO
    //PRESICION(2)
    READ_FILE
    //WRITE_FILE
    cin>>dimensions;
    for(int i=0;i<dimensions;i++){
        cin>>line;
        for(int j=0;j<dimensions;j++){
            maps[i][j] = line[j];
        }
    }
    asteriods = 0;
    for(int i=0;i<dimensions;i++){
        for(int j=0;j<dimensions;j++){
            if(maps[i][j] == '*'){
                flood_fill_bfs(i,j);
                asteriods++;
            }
        }
    }
    cout<<asteriods<<ENDL;
    return 0;
}