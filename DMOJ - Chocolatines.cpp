/**
 * DMOJ - Chocolatines
 * 
 * Temática: Add Hoc + Fuerza Bruta
 * 
 * Idea: Dado una hora en formato militar se quiera saber cuantos cuatros existen
 * en la representación de la hora militar en ese momento y en lo siguientes dos
 * minutos. Solo se debe considerar los cuatros presentes en las horas analizadas
 * en el rango de 08:00 a 20:00. Basta con simular el tiempo en ese momento y los
 * siguientes dos minutos y por cada minuto generado con su hora conformar un numero
 * con la siguiente expresión h*100+m siendo h las horas y m los minutos. Y con
 * ese número contar la cantidad de cuatro presentes en esos números. Para realizar
 * esto podemos tener un metodo que dado un valor descomponga el valor digito a
 * digito y contar la cantidad de cuatro en ese número.
 * 
 * */
#include <bits/stdc++.h>
#include <bitset>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>

#define ENDL '\n'
#define OPTIMIZAR_IO ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define PRESICION(x) cout.setf(ios::fixed,ios::floatfield); cout.precision(x);
#define READ_FILE freopen("Input.txt","r",stdin);
#define WRITE_FILE freopen("Output.txt","w",stdout);
#define REP_INDEX_1(x) for(int i=1;i<=x;i++)
#define REP_INDEX_0(x) for(int i=0;i<x;i++)
#define int long long
#define uint unsigned long long
#define PRINT_LINE cout<<ENDL;
#define MAX_N 200010
#define MAX_TREE (MAX_N << 2)
#define MOD  1000000007
#define pii pair<int,int>
#define mp(x,y) make_pair(x,y) 

const int ROW_SPARSE_TABLE = floor(log2(MAX_N) +1 );
 
using namespace std;
using namespace __gnu_pbds;

int count_four(int x){
	int c = 0;
	while(x!=0){
		if(x%10==4)c++;
		x/=10;
	}
	return c;
}

signed main()
{
    //OPTIMIZAR_IO
    PRESICION(2)
    //READ_FILE
    //WRITE_FILE
    int hours, minutes, format, answer = 0;
	cin>>hours>>minutes;
	for(int i=0;i<=2;i++){
		format= hours*100+minutes;
		if(800 <= format && format <= 2000){
			answer += count_four(format);
		}
		if(i<2)minutes++;
		if(minutes==60){
			minutes =  0;
			hours++;
		}
		if(hours == 24) hours = 0;
	}
	cout<<hours<<" "<<minutes<<" "<<answer<<ENDL;
	
	return 0;
}

