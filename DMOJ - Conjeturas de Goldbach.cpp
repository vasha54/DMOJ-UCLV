/**
 * DMOJ - Conjeturas de Goldbach
 * 
 * Tematica: Criba de primos + Busqueda binaria
 * 
 * Idea: Dado un valor N debemos comprobar si dicho valor se puede expresar como
 * suma de dos números primos diferentes los cuales llamaremos A y B. En caso de
 * de existir varias parejas de (A,B) que cumpla la condición se debe elegir cuya
 * diferencia de B-A sea mayor.
 * 
 * Bien los primeros es calcular todos los primos menores e iguales al mayor N
 * que puede tener la entrada. Esto lo hacemos en forma de precalculo y utilizando
 * el algoritmo de criba linear y almacenamos los primos en el vector primes.
 * 
 * El detalle de la criba es que genera o guarda los primos en el vector de forma
 * ordenada de menor a mayor y este importante detalle nos va sevir para buscar de
 * manera eficiente el par (A,B) deseado para cumplir que la diferencia entre A y
 * B sea máxima vamos a buscar el valor de A de forma iterativa por los primos del 
 * menor al mayor mientras para buscar el B que sería N - A los haremos usando 
 * busqueda binaria siempre que B!=A. De esta forma no tenemos que probar todos
 * los posibles pares (A,B) basta con encontrar el primer par y ese tendrá el 
 * menor valor de A de todos los posibles pares y por ende su B será el máximo
 * valor de todas las B de los pares y por tanto generaran la maxima diferencia.
 */ 
#include <bits/stdc++.h>
#define ENDL '\n'
#define OPTIMIZAR_IO ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define PRESICION(x) cout.setf(ios::fixed,ios::floatfield); cout.precision(x);
#define MAX_N 1000010
using namespace std;

vector<int> primes;

void cribePrimesLinear(){
	vector<int> lp (MAX_N,0);
   for (int i = 2; i <= MAX_N; ++i) {
		if (lp[i] == 0) {
         lp[i] = i;
         primes.push_back(i);
      }
      for (int j = 0; j < primes.size() && primes[j] <= lp[i] && i * primes[j] <= MAX_N; ++j) 
			  lp[i * primes[j]] = primes[j];
	}	
}

int main(){
    OPTIMIZAR_IO
    PRESICION(2)

    //Precalculo de todos los primos
    cribePrimesLinear();
    int n;
	 cin>>n;
	 while(n!=0){
		int a=-1,b=-1,i,f,pivote;
		bool find_sum=false;
		//Busqueda iterativa de A
		for(int k=0;k<primes.size() && primes[k]< n && find_sum == false;k++){
		   a = primes[k];
			b = n - a;
			if(a!=b){
			   i =0 ;
				f = primes.size()-1;
				//Busqueda binaria de B
				while(i<=f && find_sum ==false){
				    pivote = (i+f)/2;
				    if(primes[pivote]==b)
					    find_sum=true;
					 else if(primes[pivote] > b)
					     f=pivote-1;
					 else
						  i=pivote+1;
				}
			}
		}
		if(a!=-1 && b!=-1 && find_sum) 
         cout<<n<<" = "<<a<<" + "<<b<<ENDL;
		else
			cout<<"Goldbach conjecture is wrong"<<ENDL; 
		cin>>n;
	 }

    return 0;
}
