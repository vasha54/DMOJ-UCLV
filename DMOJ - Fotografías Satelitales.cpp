/**
 * DMOJ - Fotografías Satelitales
 * Temática: Flood Fill
 * 
 * Idea: Dado un mapa de H filas y W columnas con caracteres '*' (pastizal) y '.' (no pastizal),
 * se desea encontrar el tamaño del pastizal conexo más grande, donde la conexidad es en 4 direcciones
 * (arriba, abajo, izquierda, derecha). Como las dimensiones son moderadas (típicamente W, H <= 1000),
 * podemos recorrer toda la cuadrícula; cada vez que encontremos un '*', iniciamos una búsqueda en
 * anchura (BFS) para inundar el pastizal: marcamos las celdas visitadas cambiándolas a '.' para no
 * procesarlas nuevamente, y contamos el número de celdas de la componente. Actualizamos el máximo
 * encontrado. Al final, la variable mayor_area contiene la respuesta.
 *
 * Complejidad: O(W*H), ya que cada celda se visita una única vez. La cola de BFS puede contener a
 * lo sumo O(W*H) elementos. Este enfoque es suficiente para los límites del problema.  
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
                mapa[nx][ny]=='*'){
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

    int mayor_area=0,filas,columnas,manchas=0;
    string line;
    cin>>columnas>>filas;
    
    vector<vector<char>> mapa(filas,vector<char>(columnas));
    
    for(int i=0;i<filas;i++){
        cin>>line;
        for(int j=0;j<columnas;j++){
            mapa[i][j]=line[j];
        }
    }
    
    for(int i=0;i<filas;i++){
        for(int j=0;j<columnas;j++){
            if(mapa[i][j]=='*' ){
                manchas++;
                int area = floodfill(filas,columnas,i,j,mapa);
                if(mayor_area < area) mayor_area=area;
            }
        }
    }
    
    cout<<mayor_area<<ENDL;
    
    return 0;
}