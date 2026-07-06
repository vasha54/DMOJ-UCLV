/**
 * DMOJ / USACO - Lluvia de Meteoros (Meteor Shower)
 * Temática: BFS sobre grilla con restricciones temporales
 *
 * Idea: Bessie parte de (0,0) en t=0. Cada uno de los M meteoros cae en
 * (Xi, Yi) en el instante Ti y destruye esa celda junto con sus 4 vecinas
 * ortogonales. Bessie se mueve en 4 direcciones a 1 unidad/segundo. Solo
 * puede estar en una celda durante un tiempo estrictamente menor que su
 * momento de destrucción. Se busca el tiempo mínimo para alcanzar una
 * celda segura (que nunca será destruida).
 *
 * Solución:
 * 1. Se define una grilla de 310×310 (suficiente para coordenadas ≤ 300
 *    más margen).
 *    - segure[r][c] : true si la celda nunca será destruida.
 *    - seconds[r][c]: instante de destrucción (INF si nunca se destruye).
 * 2. Por cada meteoro (X,Y,T):
 *    - Para la celda (Y,X) y sus 4 vecinas, si están dentro de la matriz,
 *      se actualiza segure = false y seconds = min(seconds, T).
 *      Así conservamos el menor tiempo de destrucción en caso de solapes.
 * 3. BFS desde (0,0,0):
 *    - Se usa una cola de tuplas (r,c,t).
 *    - En cada paso se extrae un estado; si segure[r][c] es true, se ha
 *      llegado a un lugar seguro → answer = t.
 *    - Si no, para cada vecino dentro de la matriz, si t+1 < seconds[nr][nc],
 *      se actualiza seconds[nr][nc] = t+1 (marcar visitado) y se encola.
 * 4. Se imprime answer (-1 si no se encontró, aunque el problema garantiza
 *    que siempre hay solución si el origen no es destruido en t=0).
 *
 * Nota: Se asume que el origen no es destruido en t=0. En ese caso, habría
 * que verificar al inicio y devolver -1 directamente.
 *
 * Complejidad: O(310²) ≈ 1e5 operaciones.
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
    
    int M, Yi, Xi, Ti, answer =-1;

    for (int i = 0; i < MAX_N; i++) {
        for (int j = 0; j < MAX_N; j++) {
            segure[i][j] = true;
            seconds[i][j] = INF;
        }
    }

    cin>>M;

    for(int i=0;i<M;i++){
        cin>>Xi>>Yi>>Ti;
        if (Yi >= 0 && Yi < MAX_N && Xi >= 0 && Xi < MAX_N) {
            segure[Yi][Xi] = false;
            seconds[Yi][Xi] = min(seconds[Yi][Xi], Ti);

            for(int d=0;d<4;d++){
                int ny = Yi + mov_r[d];
                int nx = Xi + mov_c[d];
                if (ny >= 0 && ny < MAX_N && nx >= 0 && nx < MAX_N) {
                    segure[ny][nx] = false;
                    seconds[ny][nx] = min(seconds[ny][nx], Ti);
                }
            }
        }
        
    }

    queue<tiii> visit;
    visit.push({0,0,0});


    while(!visit.empty() && answer ==-1){
        auto curr = visit.front();
        visit.pop();
        
        int r = get<0>(curr);
        int c = get<1>(curr);
        int t = get<2>(curr);
        
        if(segure[r][c]){
            answer = t;
        }
        else{
            for(int i=0;i<4;i++){
                int dr = r + mov_r[i];
                int dc = c + mov_c[i];
                if(0 <= dr && dr <MAX_N && 0 <= dc && dc < MAX_N && t+1 < seconds[dr][dc]){
                    seconds[dr][dc] = t+1;
                    visit.push({dr,dc,t+1});
                }
            }
        }

    }

    cout<<answer<<ENDL;

    return 0; 
}