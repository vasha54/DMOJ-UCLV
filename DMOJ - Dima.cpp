/**
 * DMOJ - Dima
 * 
 * Tematica: Simulacion + Add - Hoc
 * 
 * Idea: Se tiene una colección A de valores inicialmente todos los valores en 0 y
 * se quiere que en cada posición de la colección exista un determinado valor.
 * Para colocar los valores en la colección existe dos operaciones posibles
 *   1. Seleccionar la posición i e incrementar en uno cada valor que este en 
 * las posiciones del rango [i,n]
 *   1. Seleccionar la posición i e decrementar en uno cada valor que este en 
 * las posiciones del rango [i,n]
 * Se quiere calcular la cantidad minima de operaciones a relealizar para que que 
 * la colección quede con los valores deseados en dichas posiciones.
 * Bien para que en A[1] quede el valor deseado X hay que realizar X operaciones
 * como mínimo. Bien y que para para cualquier A[i] para i que pertenece [1,n].
 *
 * Bueno resulta que para lograr poner el valor deseado en A[i] hay que hacer tantas
 * operaciones como el valor absoluto de la diferencia de los valores deseados
 * en A[i] y A[i-1]. pues resulta que que cuando puse el valor deseado en A[i-1]
 * ese mismo valor quedo en A[i],A[i+1],A[i+2],...,A[n]. Por tanto cuando voy a poner
 * el valor deseado en A[i] ya este tiene un valor igual al que esta en A[i-1], por
 * lo que la cantidad de operaciones será igual a la diferencia dentre el valor 
 * deseado en A[i] y A[i-1]. Estas diferencias por cada posición las voy sumando
 * y sería la respuesta a dar.
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

    int n,operations=0;
	 cin>>n;
	 vector<int> a(n+10,0), b(n+10);
	 for(int i=1;i<=n;i++){
		cin>>b[i];
		operations+=(abs(a[i-1]-b[i]));
		a[i]=b[i];
		}
	 cout<<operations<<ENDL;
	 return 0;
}
