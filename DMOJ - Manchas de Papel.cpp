/**
* DMOJ - Manchas de Papel
* Temática : Teoría de Grafos FloodFill 
*    
* Idea: Dado una imagen en forma de matriz se quiere determinar la cantidad 
* mancha que existen en la imagen . Una mancha es un grupo de 1 que comparten un
* lado común. El area es la  cantidad de 1 de la mancha. Se debe buscar la 
* cantidad de manchas y el area mayor de todas las manchas. Para resolver el 
* problema vamos aplicar un floodFill que cada vez que euncuentre un uno contamos
* una nueva mancha yy con el floodfill contamos la cantidad de celdas de la mancha
* luego por cada mancha solo debemos quedarnos con la mancha de mayor area. 
*/
#include <bits/stdc++.h>
#include <bitset>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
 
#define ENDL '\n'
#define OPTIMIZAR_IO ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define PRESICION(x) cout.setf(ios::fixed,ios::floatfield); cout.precision(x);
#define READ_FILE freopen("Input.txt","r",stdin);
#define WRITE_FILE freopen("Output.txt","w",stdout);
#define REP_INDEX_1(x) for(int i=1;i<=x;i++)
#define REP_INDEX_0(x) for(int i=0;i<x;i++)
#define int long long
#define uint unsigned long long
#define PRINT_LINE cout<<ENDL;
#define MAX_N 100010
#define MAX_TREE (MAX_N << 2)
#define MOD  1000000007
#define pii pair<int,int>
#define mp(x,y) make_pair(x,y) 
#define mid (l+r)/
#define OO MAX_N*2
 
const int ROW_SPARSE_TABLE = floor(log2(MAX_N) +1 );
 
using namespace std;
using namespace __gnu_pbds;

const vector<pair<int,int>> direcciones = {{1,0},{0,1},{-1,0},{0,-1}};

int floodfill(int filas, int columnas, int sx, int sy, vector<vector<int>> &mapa){
	queue<pair<int,int>> q;
	mapa[sx][sy] = 0;
	q.push({sx,sy});
	int cont=0;
	while(!q.empty()){
		auto[x,y] = q.front();q.pop();
		cont++;
		for(auto c : direcciones){
			int nx = c.first + x;
			int ny = c.second + y;
			
			if(nx<filas && ny<columnas && nx>=0 && ny>=0 && 
				mapa[nx][ny]==1){
				mapa[nx][ny] = 0;
				q.push({nx,ny});
			}		
		}
	}
	return cont;
}

signed main()
{
	
    OPTIMIZAR_IO
    //PRESICION(0)
    //READ_FILE
    //WRITE_FILE
	int mayor_area=0,filas,columnas,manchas=0;
	string line;
	cin>>filas>>columnas;
	
	vector<vector<int>> mapa(filas,vector<int>(columnas));
	
	for(int i=0;i<filas;i++){
		cin>>line;
		for(int j=0;j<columnas;j++){
			mapa[i][j]=line[j]-'0';
		}
	}
	
	
	for(int i=0;i<filas;i++){
		for(int j=0;j<columnas;j++){
			if(mapa[i][j]==1 ){
				manchas++;
				int area = floodfill(filas,columnas,i,j,mapa);
				if(mayor_area<area) mayor_area=area;
			}
		}
	}
	
	cout<<manchas<<" "<<mayor_area<<ENDL;
    return 0;
}