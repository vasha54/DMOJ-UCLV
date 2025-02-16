/**
 * DMOJ - Tipenado un número
 * 
 * Temática: Add Hoc + Condicionales
 * 
 * Idea: Dado un numero de tres digitos clasificar el  número de acuerdo a la 
 * relacion entre los digitos adyacentes del número.
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



signed main()
{
    OPTIMIZAR_IO
    PRESICION(2)
    //READ_FILE
    //WRITE_FILE
	string N;
	cin>>N;
	if(N[0] < N[1] && N[1] < N[2]) cout<<"Ascendente"<<ENDL;
	else if(N[0] > N[1] && N[1] > N[2]) cout<<"Descendente"<<ENDL;
	else if(N[0] == N[1] && N[1] == N[2]) cout<<"Equilibrado"<<ENDL;
	else cout<<"Alterno"<<ENDL;
	return 0;
}

