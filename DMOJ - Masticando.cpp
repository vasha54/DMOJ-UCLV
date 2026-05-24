/**
 * DMOJ - Masticando
 * Temática: Flood Fill
 * 
 * Idea: Dada una grilla de hasta 100x100 con un inicio 'C', un destino 'B' y obstáculos '*',
 * se pide la mínima cantidad de pasos para ir de 'C' a 'B'. Cada paso permite moverse a una
 * celda adyacente en las 4 direcciones cardinales.
 * 
 * Se modela como un BFS sobre la matriz de costos:
 *   - Inicializar obstáculos con -1 y el resto con un valor muy grande (LONG_MAX).
 *   - Colocar el costo de la celda de inicio en 0.
 *   - Usar una cola de tuplas (fila, columna, costo) y explorar en orden.
 *   - Para cada vecino dentro de los límites, si el costo acumulado + 1 es menor que el costo
 *     registrado, se actualiza y se encola.
 * Finalmente se imprime el costo registrado en la celda de destino 'B'. Si fuera inalcanzable
 * mostraría LONG_MAX, pero el problema garantiza que siempre existe un camino.
 */
#include <bits/stdc++.h>
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
#define pii pair<int,int>
#define tiii tuple<int,int,int>
#define MAX_N 110
#define MAX_TREE MAX_N << 2
#define MOD  1000000007
#define MID (right+left)/2

using namespace std;
using namespace __gnu_pbds;

int mov_r [] ={ 0, 0, 1,-1};
int mov_c [] ={ 1,-1, 0, 0};

int matrix_cost[MAX_N][MAX_N];
int rows,columns;

string line;

signed main()
{
    OPTIMIZAR_IO
    //PRESICION(2)
    READ_FILE
    //WRITE_FILE

    cin>>rows>>columns;

    pii start,end;

    for(int i=1;i<=rows;i++){
        cin>>line;
        for(int j=1;j<=columns;j++){
            if(line[j-1]=='*') matrix_cost[i][j] = -1;
            else matrix_cost[i][j] = LONG_MAX;
            if (line[j-1]=='C') start = {i,j};
            if (line[j-1]=='B') end = {i,j};
        }
    }

    matrix_cost[start.first][start.second] = 0;

    tiii current, next_cell;
    queue<tiii> visit;

    visit.push({start.first,start.second,0});

    while(!visit.empty()){
        current = visit.front();
        visit.pop();

        for(int i=0;i<4;i++){
            int n_r = get<0>(current) + mov_r[i];
            int n_c = get<1>(current) + mov_c[i];
            int n_cost = get<2>(current) + 1;

            if(1<=n_r && n_r<=rows && 1<=n_c && n_c<=columns && n_cost < matrix_cost[n_r][n_c]){
                matrix_cost[n_r][n_c] = n_cost;
                next_cell = {n_r, n_c, n_cost};
                visit.push(next_cell);
            }
        }
    }

    cout<<matrix_cost[end.first][end.second]<<ENDL;

    return 0;
}