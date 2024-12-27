/**
 * DMOJ - La Inmortalidad Eternal
 * Temáticas: Aritmetica y Algebra
 *
 * Idea: Dados dos números a y b se nos pide calcular b!/a! y decir el último dígito
 * del resultado. Sabiendo que b>=a se puede simplificar o expresar b!/a! como la
 * multiplicación de todos los números naturales en el rango de [a+1,b].
 * La multiplicación puede ser costosa porque la diferencia entre a y b puede ser
 * de hasta 10^18 por tanto debemos ver como podemos simplificar dicho calculo.
 * Si entre a+1 y b hay algún multiplo de 10 esto nos garantiza que el último dígito
 * sea 0. En caso de no haber es una buena noticia por significa que la diferencia
 * entre a+1 y b es menor que 10 por tanto podemos iterativamente haciendo la
 * multiplicación y modulando los valores parciales. Para saber si hay un múltiplo
 * entre a+1 y b basta con probar que (a+1)/10 != b/10.
 */
#include <bits/stdc++.h>
#include <math.h>
#define ENDL '\n'
#define OPTIMIZAR_IO ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define PRESICION(x) cout.setf(ios::fixed,ios::floatfield); cout.precision(x);
#define MAX_N 100010
#define MOD 10000
#define EPS 1e-9
#define INF 100000000000010
#define LL long long
#define ULL unsigned long long
using namespace std;


int cases;
ULL a,b,answer;


int main() {

	OPTIMIZAR_IO
	PRESICION(0)

    cin>>cases;
	while(cases--){
		cin>>a>>b;
		a++;
		if(a/10!=b/10){
			cout<<0<<ENDL;
		}else{
			answer=1;
			for(ULL i=a;i<=b;i++){
				answer =(answer*(i%10))%10;
			}
			cout<<answer<<ENDL;
		}
	}

	return 0;
}
