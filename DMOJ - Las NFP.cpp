/**
 * DMOJ - Las NFP
 * 
 * Tematica: Busqueda Completa + String
 * 
 * Idea: Una vez leido el ejercicio el problema se reduce a dado una matriz es 
 * buscar la menor y mayor fila donde se encuentra un simbolo '#' e imprimir la 
 * diferencia entre dichos valores. Cada fila la podemos leer como una cadena de 
 * caracteres y ver si dentro de este está el carácter # y de estar forma el 
 * ejercicio se reduce a leer un grupo de cadenas y almacenar las posiciones de 
 * la primera y ultima cadena donde aparece un símbolo #.
 */ 
#include <bits/stdc++.h>
#define ENDL '\n'
#define READ_FILE freopen("Input.txt","r",stdin); 
#define OPTIMIZAR_IO ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define PRESICION(x) cout.setf(ios::fixed,ios::floatfield); cout.precision(x);
#define MAX_N 1000010
#define int long long
using namespace std;

int cases, rows, columns,min_rows,max_rows;
string line;

signed main(){
    OPTIMIZAR_IO
    //PRESICION(2)
	cin>>cases>>rows>>columns;
	while(cases--){
		min_rows = LONG_MAX;
		max_rows = LONG_MIN;
		for(int i=1;i<=rows;i++){
			cin>>line;
			if(line.find("#")!=string::npos){
				min_rows=min(i,min_rows);
				max_rows=max(i,max_rows);
			}
		}
		cout<<max_rows-min_rows<<ENDL;
	}
    
	 return 0;
}
