/**
 * DMOJ - ¿Otro problema de segment tree?
 * Temáticas: Progrmación Dinamica + Suma de prefijos
 *
 * Idea: Se tiene un grupo de personas (N<=10^6) de las cuales se conoce el tiempo
 * que comienzan y terminan de trabajar dichos tiempos estan en el intervalos
 * de [1, 10^6]. Conocido esto se desea conocer la mayor cantidad de personas que
 * trabajan al mismo tiempo.
 *
 * Para solucionar el problema vamos aplicar el prefijo de suma de la siguiente
 * manera, incialmente todos los valores de PS son ceros. Para tupla de la forma
 * (a;b) siendo a el tiempo de comienzo de trabajo de una persona vamos a PS[a]
 * e incrementamos en uno para indicar que a partir de de ese instante un persona
 * comenzo a trabajar y en PS[b+1] decrementamos en uno para indicar que a partir
 * de ese momento esa persona dejo de trabajar.  Luego aplicamos lo clasico de
 * Suma de prefijo donde para cada i que pertenece [1,N] PS[i]+=PS[i-1] para luego
 * buscar el mayor valor almacenado en PS y dicho valor será la respuesta.
 **/
#include <bits/stdc++.h>
#include <math.h>
#define ENDL '\n'
#define OPTIMIZAR_IO ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define PRESICION(x) cout.setf(ios::fixed,ios::floatfield); cout.precision(x);
#define MAX_N 100010
#define MOD 10000
#define EPS 1e-9
#define INF 3*10000000000*(-1)
#define LL long long
#define ULL unsigned long long
#define ALPHABET_SIZE 26 //['a-z']
using namespace std;



int main() {
	OPTIMIZAR_IO
	int npersons;
	cin>>npersons;
	map<LL,int> ps;
	LL a, b;
	int best=0,t=0;

	for(int i=0;i<npersons;i++){
		cin>>a>>b;
		ps[a]++;
		ps[b+1]--;
	}

	for(map<LL,int>::iterator it=ps.begin();it!=ps.end();it++){
		t+=it->second;
		best=max(best,t);
	}

	cout<<best<<ENDL;

	return 0;
}

