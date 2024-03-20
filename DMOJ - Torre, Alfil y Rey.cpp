/*
* DMOJ - Torre, Alfil y Rey
* Tematica : Add-Hoc
* Idea: Dados dos posiciones en tablero de ajedrez diga la cantidad minima de jugadas
* para que una torre , alfil y rey vayan de una posición otra.
* Torre: 1 movimiento sin estan en la misma fila o columna sino 2 movimientos
* Rey: La cantidad de movimientos es A+B siendo A minima entre la distancia entre las columnas
* y filas mientras B es la diferencia entre las distancia dentre las filas y columnas
* Afil: 0 si las celdas son de colores diferentes , 1 si estan en la misma diagonal sino 2
*/
#include <iostream>
#include <math.h>
#include <bits/stdc++.h>
#define ENDL '\n'
#define OPTIMIZAR_IO ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define PRESICION(x) cout.setf(ios::fixed,ios::floatfield); cout.precision(x);
#define READ_FILE freopen("Input.txt","r",stdin);
#define WRITE_FILE freopen("Output.txt","w",stdout);
#define MAX_N 100010
#define MOD 1000000007
#define EPS 1e-4
#define INF 1000000000
#define int long long
#define uint unsigned long long
#define pii pair<int,int>
#define ALPHABET_SIZE 26 //['a-z']
#define Point pair<int, int>
#define X first
#define Y second
#define PLUS '+'
#define MINUS '-'
#define SPACE ' '
using namespace std;

int r1,c1,r2,c2,king,bishop,tower;

bool color(int r, int c){
	if( (r%2==1 && c%2==1) || (r%2==0 && c%2==0))
        return true;
	else
        return false;
}


signed main(){
    OPTIMIZAR_IO
    //PRESICION(0)
    //READ_FILE
    //WRITE_FILE
    while(cin>>r1>>c1>>r2>>c2){
        tower=(r1==r2 || c1==c2) ? 1 : 2;
        king=min(abs(c1-c2),abs(r1-r2))+abs(abs(c1-c2)-abs(r1-r2));
        if(color(r1,c1)==color(r2,c2)){
            bishop =( (abs(r1-r2)==abs(c1-c2)) ? 1 : 2 );
        }else
            bishop=0;
        cout<<tower<<SPACE<<bishop<<SPACE<<king<<ENDL;
    }
    return 0;
}
