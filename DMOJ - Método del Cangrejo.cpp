/**
 * DMOJ - Método del Cangrejo
 * (https://dmoj.uclv.edu.cu/problem/mcangrejo2024/submit)
 * Temática: Add -Hoc
 * 
 * Idea: Data la operacion (X*A-B)/C = D y conocido los valores A,B,C y D nos
 * piden hallar el valor de X lo cual facil si la despejamos de la ecuación
 * inicial lo que nos queda que X = ((C*D)+B)/A.
 */ 
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
#define MAX_N 20010
#define MOD  1000000007
#define pii pair<int,int>
#define mp(x,y) make_pair(x,y) 
 
using namespace std;
using namespace __gnu_pbds;



signed main()
{
    OPTIMIZAR_IO
    PRESICION(2)
    //READ_FILE
    //WRITE_FILE
	int A,B,C,D,N;
	cin>>A>>B>>C>>D;
	N=((C*D)+B)/A;
	cout<<N<<ENDL;
    return 0;
}

