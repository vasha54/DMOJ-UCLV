 /**
 * DMOJ - Casi todos los divisores
 * Temática: Teoría de Números + Divisores
 * 
 * Idea: Se nos da una lista que contiene casi todos los divisores de un número 
 * entero desconocido N, excepto el 1 y el propio N. El divisor más pequeño 
 * de la lista (mayor que 1) multiplicado por el divisor más grande debe ser 
 * igual a N, pues los divisores vienen en pares (d, N/d). Por tanto, calculamos 
 * el candidato N = min(lista) * max(lista). Luego realizamos dos comprobaciones:
 * 1) Cada número de la lista debe dividir exactamente a N. Si alguno no lo hace, 
 *    la lista es inválida.
 * 2) Para cada divisor i de N con 2 <= i <= sqrt(N), tanto i como N/i deben 
 *    estar presentes en la lista (pues son divisores propios diferentes de 1 y N). 
 *    Si falta algún par, la lista también es inválida.
 * Si ambas comprobaciones son exitosas, se imprime N; en caso contrario, -1.
 */ 
#include <bits/stdc++.h>
#include <bitset>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>

#define ENDL '\n'
#define OPTIMIZAR_IO ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define PRESICION(x) cout.setf(ios::fixed,ios::floatfield); cout.precision(x);
 
#ifdef LOCAL
    #define READ_FILE freopen("Input.txt","r",stdin);
    #define WRITE_FILE freopen("Output.txt","w",stdout);
#else
    #define READ_FILE 
    #define WRITE_FILE 
#endif
#define REP(x) for(int i=1;i<=x;i++)
#define int long long
#define uint unsigned long long
#define PRINT_LINE cout<<ENDL;
#define MAX_N 1000010
#define MOD  1000000007
#define pii pair<int,int>
#define tiib tuple<int,int,bool>
 
using namespace std;
using namespace __gnu_pbds;


signed main()
{
    OPTIMIZAR_IO
    //PRESICION(2)
    READ_FILE
    //WRITE_FILE
	int cases,n;
	cin>>cases;
	while(cases--){
		cin>>n;
		vector<int> divisors(n);
		vector<bool> marks(MAX_N,false);
		for(int i=0;i<n;i++){
			cin>>divisors[i];
			marks[divisors[i]]=true;
		}
		sort(divisors.begin(),divisors.end());
		int answer = divisors.front() * divisors.back();
		for(int i: divisors){
			if(answer%i != 0){
				answer= -1;
				break;
			}
		}
		for(int i=2 ; answer!= -1 && i*i<=answer;i++){
			if(answer%i==0){
				n = answer / i;
				if(!marks[n] || !marks[i]) answer=-1;
			}
		}
		cout<<answer<<ENDL;
	}
}

