/**
 * DMOJ - Cuadrantes Iguales
 * Temática: Add-Hoc + Geometria
 *
 * Idea: Dados dos puntos en el eje cartesiano los cuales nunca va estar sobre los
 * ejes determinar si estan en el mismo cuadrante
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

enum Quadrant {Q1,Q2,Q3,Q4,AXIS};

struct Point{
	LL x,y;
};

istream & operator>>(istream & in,Point & p ){
	in>>p.x>>p.y;
	return in;
}

Point p1,p2;

Quadrant search(Point p){

	if(p.x>0 && p.y>0) return Q1;
	if(p.x<0 && p.y>0) return Q2;
	if(p.x<0 && p.y<0) return Q3;
	if(p.x>0 && p.y<0) return Q4;
	return AXIS;
}

int main() {
	OPTIMIZAR_IO
	//PRESICION(20)
	cin>>p1;
	cin>>p2;

	cout<<(search(p1)==search(p2)?"SI":"NO")<<ENDL;
	return 0;
}

