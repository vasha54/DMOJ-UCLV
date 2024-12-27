/**
 * DMOJ - Intercambios en un arreglo
 * 
 * Tematica: Ordenamiento
 * 
 * Idea: Dada una colección de valores determinar si la colección esta ordenada 
 * o con solo intercambiar dos valores bastaría para estar ordenada. Para resover
 * el problema basta con ordenar los valores en una colección identica a la original
 * y despues comprobamos por cada posición de ambas colecciones si los valores
 * son los mismos, sino hubo cambios la colección estaba ordenada inicialmente,
 * si la cantidad de valores que difieren en valor en la misma posición es 1 o 2 
 * con un intercambio se puede ordenar sino no existe forma de ordenarla en un solo
 * intercambio.de dos valores
 */ 
#include <bits/stdc++.h>
#define ENDL '\n'
#define READ_FILE freopen("Input.txt","r",stdin); 
#define OPTIMIZAR_IO ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define PRESICION(x) cout.setf(ios::fixed,ios::floatfield); cout.precision(x);
#define MAX_N 1000010
#define int long long
using namespace std;


signed main(){
    OPTIMIZAR_IO
    //PRESICION(2)

    int n,change=0;
	 cin>>n;
	 vector<int> values(n), values_sort(n);
	 for(int i=0;i<n;i++){
		cin>>values[i];
		values_sort[i] = values[i];
		}
	 sort(values_sort.begin(),values_sort.end());
	 for(int i=0;i<n;i++){
		change+= (values_sort[i] != values[i]);
	 }
	 if(change == 0) cout<<0<<ENDL;
	 else if (change >2 ) cout<<-1<<ENDL;
	 else cout<<1<<ENDL;
    return 0;
}