/**
 * DMOJ - Mejor Pasto
 * Temática: Flood Fill 
 * 
 * Idea:  Dada una cuadrícula de R filas y C columnas con '#' (pasto) y '.' (suelo),
 * se deben contar los grupos de pasto conexos. Dos '#' pertenecen al mismo grupo 
 * si son adyacentes horizontal o verticalmente (no en diagonal). Como las 
 * dimensiones son pequeñas (R,C ≤ 100), recorremos la matriz: al encontrar 
 * un '#', incrementamos el contador de grupos y realizamos un BFS (flood fill) 
 * para marcar todas las celdas '#' conectadas como '.', evitando contarlas 
 * nuevamente. Al final, el contador tiene el total de grupos. La función 
 * floodfill inunda la componente y podría retornar el tamaño, aunque aquí 
 * solo se usa para eliminar el grupo.
 *
 * Complejidad: O(R*C) porque cada celda se visita una sola vez.  
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
#define MAX_N 200010
#define MAXTREE  (MAX_N << 2)
#define MOD  1000000007
#define pii pair<int,int>
#define tiib tuple<int,int,bool>
#define midle (left+right)/2   // OJO: rigth en lugar de right, se mantiene el original

using namespace std;
using namespace __gnu_pbds;

const vector<pair<int,int>> direcciones = {{1,0},{0,1},{-1,0},{0,-1}};

int floodfill(int filas, int columnas, int sx, int sy, vector<vector<char>> &mapa){
    queue<pair<int,int>> q;
    mapa[sx][sy] = '.';
    q.push({sx,sy});
    int cont=0;
    while(!q.empty()){
        auto[x,y] = q.front();q.pop();
        cont++;
        for(auto c : direcciones){
            int nx = c.first + x;
            int ny = c.second + y;
            
            if(nx<filas && ny<columnas && nx>=0 && ny>=0 && 
                mapa[nx][ny]=='#'){
                mapa[nx][ny]= '.';
                q.push({nx,ny});
            }       
        }
    }
    return cont;
}

signed main()
{
    OPTIMIZAR_IO
    //PRESICION(2)
    READ_FILE
    //WRITE_FILE

    int c_area=0,filas,columnas;
    string line;
    cin>>filas>>columnas;
    
    vector<vector<char>> mapa(filas,vector<char>(columnas));
    
    for(int i=0;i<filas;i++){
        cin>>line;
        for(int j=0;j<columnas;j++){
            mapa[i][j]=line[j];
        }
    }
    
    for(int i=0;i<filas;i++){
        for(int j=0;j<columnas;j++){
            if(mapa[i][j]=='#' ){
                c_area++;
                floodfill(filas,columnas,i,j,mapa);
            }
        }
    }
    
    cout<<c_area<<ENDL;
    
    return 0;
}