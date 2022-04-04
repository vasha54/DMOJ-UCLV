//3956 - Street Parade
//Estructura de datos: Pila y Cola : Simulacion
#include <iostream>
#include <vector>
#include <algorithm>
#include <stdio.h>
#include <math.h>
#include <stack>
#include <set>
#include <list>
#include <queue>
#include <string>
#include <string.h>
#include <map>
#include <complex>
#include <cmath>
#include <bitset>
#include <cstdlib>
#define MID (left+right)/2
#define MODULO 1000000007
#define MAX 1010
#define MIN MAX*(-1)
#define MAXTREE (MAX << 2)
#define LIMIT 2000000010
#define ULL unsigned long long
#define LL long long
#define ENDL '\n'
#define SYMBOL '#'
#define REP(i,n) for(int i=0;i<(int)n;++i)
#define REP1_N(i,n) for(int i=1;i<=(int)n;++i)
#define FOR(i,c) for(__typeof((c).begin())i=(c).begin();i!=(c).end();++i)
#define ALL(c) (c).begin(), (c).end()
#define LINE_BLANK cout<<ENDL;
using namespace std;

int ncars,car,carExpected;
stack<int> streetParade;
bool re_ordered;

int main()
{
	//freopen ("Input.txt","r",stdin );
	//freopen ("Output.txt","w",stdout );
	    
	cout.setf (ios::fixed ,ios::floatfield );
	cout.precision (2) ;
	ios_base::sync_with_stdio(0);
	std::cin.tie(0);
	
	while(cin>>ncars && ncars!=0)
	{
		re_ordered=true;
		
		carExpected=1;
		
		REP(i,ncars)
		{
			cin>>car;
			if(car==carExpected) 
				carExpected++;
			else 
				streetParade.push(car);
		}
		
		while(!streetParade.empty() && re_ordered)
		{
			car=streetParade.top();
			streetParade.pop();
			if (car==carExpected) 
				carExpected++;
			else
				re_ordered=false;
		}
		
		if(re_ordered==true) 
			cout <<"yes"<<ENDL ;
		else
			cout<<"no"<<ENDL;
		
	}
	
	return 0;
}