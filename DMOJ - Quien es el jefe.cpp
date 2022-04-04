//DMOJ - ¿Quién es el jefe?
//Ordenamiento + Fuerza Bruta
#include <iostream>
#include <vector>
#include <algorithm>
#include <stdio.h>
#include <math.h>
#include <stack>
#include <set>
#include <queue>
#include <string>
#include <string.h>
#include <map>
#include <complex>
#include <cmath>
#define MID (left+right)/2
#define MOD  1000000007
#define MAX 2010
#define MAX_N 30010
#define MAX_ROW 1010
#define MAX_COLUMN MAX_ROW
#define MAX_NODE 2020
#define MAX_EDGE 55000
#define MAXTREE (MAX << 2)
#define ULL unsigned long long
#define LL long long
#define NUMBER LL
#define ENDL '\n'
#define SYMBOL '#'
#define REP(i,n) for(int i=0;i<(int)n;++i)
#define REP1_N(i,n) for(int i=1;i<=(int)n;++i)
#define FOR(i,c) for(__typeof((c).begin())i=(c).begin();i!=(c).end();++i)
#define ALL(c) (c).begin(), (c).end()
#define LINE_BLANK cout<<ENDL;
#define OPERATOR_INC "++"
#define OPERATOR_DEC "--"
#define MAXELEMENT 260
#define MAXCAPACITYKNAPSACK 1010
#define EPS 1e-9
#define OO 1000010
#define RADIUS 1.50000
using namespace std;

const int mov_c[]={0, 0, 1,-1, 1, 1,-1,-1};
const int mov_r[]={1,-1, 0, 0, 1,-1, 1,-1};

struct Employe{
	ULL id;
	ULL height;
	ULL salary;
	ULL idBoss;
	ULL cEmployes;

	Employe(ULL _id=0,ULL _height=0, ULL _salary=0){
		id=_id;
		height=_height;
		salary=_salary;
		idBoss=0;
		cEmployes=0;
	}
};

istream & operator>>(istream & _in, Employe & _e){
	_in>>_e.id>>_e.salary>>_e.height;
	return _in;
}

ostream & operator<<(ostream & _out, Employe & _e){
	_out<<_e.idBoss<<" "<<_e.cEmployes;
	return _out;
}

bool operator<( const Employe & _a , const Employe & _b ){
	if(_a.salary < _b.salary )
		return true;
	else
		return false;
}

int cases,nemployes,nquery;
Employe tmp;
vector<Employe> employes;
map<ULL,Employe> report;
ULL ID;

int main(){
	//freopen("Input.txt","r",stdin);
	//freopen("Output.txt","w",stdout);
	cout.setf(ios::fixed,ios::floatfield);
	cout.precision(2);
	ios_base::sync_with_stdio(0);
	std::cin.tie(0);

	while(cin>>cases){
		while(cases--){
			cin>>nemployes>>nquery;
			employes.clear();
			report.clear();

			REP(i,nemployes){
				cin>>tmp;
				employes.push_back(tmp);
			}
			sort(employes.begin(),employes.end());

			REP(i,nemployes){
				for(int j=i+1;j<nemployes;j++){
					if(employes[i].height <= employes[j].height){
						employes[i].idBoss=employes[j].id;
						employes[j].cEmployes+=(1+employes[i].cEmployes);
						break;
					}
				}
				report.insert(make_pair(employes[i].id,employes[i]));
			}

			REP(i,nquery){
				cin>>ID;
				cout<<report[ID]<<ENDL;
			}
		}
	}

	return 0;
}

