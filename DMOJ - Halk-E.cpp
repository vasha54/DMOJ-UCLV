/**
 * DMOJ - Halk-E
 * (https://dmoj.uclv.edu.cu/problem/copa2023p4)
 * Tematica: Recursividad + Memorizacion
 * 
 * Idea: Dado un numero N debemos determinar cuantas operaciones mínimas se deben
 * realizar para de un valor inicial 1 llegar a ese valor N de ser posible. Las 
 * operaciones son:
 *   - Multiplicar el valor actual por 2
 *   - Sumarle al valor actual 3
 * Para hallar la solución vamos a resolver el problema al revés es decir como 
 * de un valor N puede llegar con la mínima operaciones al valor 1 siendo las 
 * operaciones:
 *   - Dividir el valor actual por 2
 *   - Restarle al valor actual 3 
 * Analizando la situación podemos percartarnos que:
 *   - Si N es multiplo de 3 nunca va ser posible llevar el valor hasta 1. Porque
 *   si es par puedo realizar divisiones sucesivas hasta que arroje un impar que
 *   que bien puede ser el tres o un múltiplo de este.
 *   - Si N es pontecia de 2 mayor que dos la cantidad de operaciones será igual
 *   a log2(N)- 1 porque cuando N sea valor 4 será mejor restarle 3 e ir directamente
 *   al 1 que dividir dos veces por 2 para llegar al uno.
 *   - Cualquier otro número X siempre debemos dividir entre 2 de ser par o restarle
 *   tres para que genere un numero par por tanto nos queda la siguiente recurrencia
 *   F(x) = 0           si x mod 3 == 0
 *          log2(x)-1   si a^b = x donde b pertenece a los naturales
 *          1 + F(x/2)  si x mod 2 == 0
 *          1 + F(x -3) si x mod 2 == 1
 *   Podemos implementar una función recursiva que responda a la función reccurente
 *   incluso usar memorization para tener un grupo de valores previemente calculados
 *   y no crear tantos ambientes recursivos.
 */ 
#include <bits/stdc++.h>
#define ENDL '\n'
#define READ_FILE freopen("Input.txt","r",stdin); 
#define OPTIMIZAR_IO ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define PRESICION(x) cout.setf(ios::fixed,ios::floatfield); cout.precision(x);
#define REP_INDEX_0(x) for(int i=0;i<x;i++)
#define REP_INDEX_1(x) for(int i=1;i<=x;i++)	
#define MAX_N 100
#define int long long
using namespace std;

vector<int> dp(MAX_N,0);

void precalculate(){
	dp[1] = 1;
	REP_INDEX_1(MAX_N-1){
		if(dp[i] && i * 2 <MAX_N && !dp[i*2]){
			dp[i*2]= dp[i] + 1;
				}
		if(dp[i] && i * 2 <MAX_N && dp[i*2]){
			dp[i*2]= min(dp[i*2],dp[i] + 1);
				}
		if(dp[i] && i + 3 <MAX_N && !dp[i + 3]){
			dp[i + 3]= dp[i] + 1;
				}
		if(dp[i] && i + 3 <MAX_N && dp[i + 3]){
			dp[i + 3]= min(dp[i + 3],dp[i] + 1);
				}
		}
}

int halkE(int n){
	if(n % 3 == 0) return 0;
	else if(n < MAX_N) return dp[n];
	else if (__builtin_popcount(n)==1) return __builtin_ctz(n)-1;
	else{
		if(n%2== 0) return 1 + halkE(n/2);
		else return 1 + halkE(n - 3);
		}
	}

signed main(){
    OPTIMIZAR_IO
    //PRESICION(2)
	 precalculate(); 
    int N;
	 cin>>N;
	 cout<<halkE(N)<<ENDL;
	 return 0;
}
