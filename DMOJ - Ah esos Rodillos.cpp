/**
 * DMOJ - Ah esos Rodillos
 * Temáticas: Add-Hoc + Busqueda + Geometría
 *
 * Idea: Como la cantidad de rodillos ronda los 1000 se puede hacer una busqueda
 * total y por cada rodillo ver con quien se conecta. Luego buscar que rodillo solo
 * tiene una conexión y no esta en el eje de coordenadas ese será el último rodillo
 * del mecanismo y por tanto el rodillo solicitado.
 */
#include <iostream>
#include <bits/stdc++.h>
#include <algorithm>
#define ENDL '\n'
#define MAX 1100
#define MOD 10000
#define LL long long
using namespace std;

struct Rodillo{
	LL x,y,radius;
	bool begin;
	int conections;

	Rodillo(LL _x=0,LL _y=0, LL _r=0){
		x=_x;
		y=_y;
		radius=_r;
		begin =false;
		conections=0;
	}
};

istream & operator>>(istream & in, Rodillo & rodillo){
	in>>rodillo.x>>rodillo.y>>rodillo.radius;
	rodillo.begin=(rodillo.x==0 && rodillo.y==0);
	rodillo.conections=0;
	return in;
}

ostream & operator<<(ostream & out, Rodillo rodillo){
	out<<rodillo.x<<" "<<rodillo.y;
	return out;
}

int nRodillos;
Rodillo rodillos[MAX];


bool connected(Rodillo a, Rodillo b){
	LL deltaX=a.x-b.x;
	LL deltaY=a.y-b.y;
    LL d = a.radius+b.radius;
    return  (deltaX*deltaX+deltaY*deltaY == d*d );
}

int main() {

	ios_base::sync_with_stdio(0);
	cin.tie(0);

	cout.setf(ios::fixed, ios::floatfield);
	cout.precision(0);

	cin>>nRodillos;
	for(int i=0;i<nRodillos;i++)
		cin>>rodillos[i];

	for(int i=0;i<nRodillos;i++){
		for(int j=i+1;j<nRodillos;j++){
			if(connected(rodillos[i],rodillos[j])){
				rodillos[i].conections++;
				rodillos[j].conections++;
			}
		}
	}

	for(int i=0;i<nRodillos;i++){
		if(rodillos[i].conections==1 && rodillos[i].begin==false)
			cout<<rodillos[i]<<ENDL;
	}

	return 0;
}
