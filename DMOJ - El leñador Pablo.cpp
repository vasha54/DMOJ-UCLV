/**
 * DMOJ - El leñador Pablo
 * (https://dmoj.uclv.edu.cu/problem/madera)
 * Tematica: Busqueda Binaria
 * 
 * Idea: Dado un grupo de valores A (altura de árboles) se quiere hallar el máximo
 * valor X tal que la sumatoria de Ai-X con i que pertenece a [1,n] y siempre
 * que Ai >= X sea mayor igual a un valor Z que es la cantidad de madera a recolectar.
 * Para buscar el máximo valor que puede tomar X vamos a realizar una búsqueda binaria
 * en el rango de [0,P] siendo P la máxima valor de todos los valores o mayor altura
 * de todos los árboles.
 * Para determinar si se puede picar a una determinada altura o no creamos una función
 * que compruebe si dado un valor cuanta madera se obtiene de picar los arboles que
 * se puedan (si el valor de la altura a picar es mayor que la del arbol, no se obtiene 
 * madera de ese árbol) a esa altura. Para optimizar esta comprobación podemos tener
 * los valores ordenados de forma decreciente para que el primer árbol cuya altura 
 * no cumpla con altura que se corta no seguir con los demas y comprobar la cantidad 
 * de madera obtenida hasta el momento.
 */ 
#include <bits/stdc++.h>
#define ENDL '\n'
#define READ_FILE freopen("Input.txt","r",stdin); 
#define OPTIMIZAR_IO ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define PRESICION(x) cout.setf(ios::fixed,ios::floatfield); cout.precision(x);
#define REP_INDEX_0(x) for(int i=0;i<x;i++)
#define REP_INDEX_1(x) for(int i=1;i<=x;i++)	
#define MAX_N 1000010
#define int long long
using namespace std;

bool is_cutt(int * A , int B, int C,int n){
	int sum =0 ;
	int it = 0;
	while( it < n && sum < C){
		sum+=(A[it]>= B ? A[it]-B:0);
		it++;
		}
	return sum >= C;
	}

signed main(){
    OPTIMIZAR_IO
    //PRESICION(2)
	 int ntrees, woods, min_heigth, max_heigth, pivot, answer = LONG_MIN;
	 cin>> ntrees >> woods;
    int  trees[ntrees];
    REP_INDEX_0(ntrees){
		cin>>trees[i]; 
		}
    min_heigth = 0;
	 max_heigth = *max_element(trees,trees+ntrees);
	 
	 while(min_heigth <= max_heigth){
		 pivot = (min_heigth + max_heigth) / 2;
		 if(is_cutt(trees,pivot,woods,ntrees)){
			 answer = max(answer,pivot);
			 min_heigth = pivot + 1;
			 }
       else max_heigth = pivot -1;  
		 }
    cout<<answer<<ENDL;   
	 return 0;
}
