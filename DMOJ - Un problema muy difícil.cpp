/**
 * DMOJ - Un problema muy difícil
 * Temática: Add-Hoc
 *
 * Idea: Dados cuatro valores (a,b,c,d) determinar que multiplicación entre (a*b)
 * y (c*d) es mayor;
 */
#include <bits/stdc++.h>
#include <math.h>
#define ENDL '\n'
#define OPTIMIZAR_IO ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define PRESICION(x) cout.setf(ios::fixed,ios::floatfield); cout.precision(x);
#define MAX_N 85
#define MOD 1000000007
#define EPS 1e-9
#define INF 1000000000
#define LL long long
#define ULL unsigned long long
#define pii pair<int,int>
#define ALPHABET_SIZE 26 //['a-z']
using namespace std;



int main() {
	OPTIMIZAR_IO
	//PRESICION(20)
	int cases,a,b,c,d;
	cin>>cases;
	while(cases--){
		cin>>a>>b>>c>>d;
		cout<<max(a*b,c*d)<<ENDL;
	}
	return 0;
}

