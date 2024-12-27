/**
 * DMOJ - Sasha y la merienda
 * 
 * Tematica: Simulacion + Fuerza bruta + Busqueda Completa
 * 
 * Idea: Dado que la cantidad de frutas son pocas se puede implementar un 
 * algoritmo de busqueda completa o fuerza bruta que simule el proceso de 
 * de comer frutas . Luego queda ejecutar dicho algoritmo comenzando por cada 
 * fruta para saber a partir de cual se puede comer la mayor cantidad de frutas
 * sin superar el valor C.
 */ 
#include <bits/stdc++.h>
#define ENDL '\n'
#define READ_FILE freopen("Input.txt","r",stdin); 
#define OPTIMIZAR_IO ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define PRESICION(x) cout.setf(ios::fixed,ios::floatfield); cout.precision(x);
#define MAX_N 1000010
#define int long long
using namespace std;

int eats_fruits(vector<int> fruits, int index, int C)
{
	int eat = 0;
	int n = fruits.size();
	while(index < n && C){
		if(C >= fruits[index]){
			eat++;
			C-=fruits[index];
		} 
		index++;
	}
	return eat;
}

signed main(){
    OPTIMIZAR_IO
    //PRESICION(2)

    int n,C,max_fruits=0;
	 cin>>n>>C;
	 vector<int> f(n);
	 for(int i=0;i<n;i++) cin>>f[i];
	 
	 for(int i=0;i<n;i++) max_fruits = max(max_fruits,eats_fruits(f,i,C));
	 
	 cout<<max_fruits<<ENDL;
	 return 0;
}
