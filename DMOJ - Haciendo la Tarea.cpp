/**
 * DMOJ - Haciendo la Tarea
 * Temática: Add - Hoc + Simulación + String
 * 
 * Idea: Basta con implementar un algoritmo que describa el procedimiento del problema
 * para resolver el ejercicio.
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
#define REP(x) for(int i=1;i<=x;i++)
#define int long long
#define uint unsigned long long
#define PRINT_LINE cout<<ENDL;
#define MAX_N 100010
#define MOD 1000000007
 
using namespace std;
using namespace __gnu_pbds;

int N,M, candys;
string nStr;

signed main()
{
    OPTIMIZAR_IO
    PRESICION(2)
    //READ_FILE
    //WRITE_FILE
    cin>>N;
    candys =0;
    while(N)
    {
        candys++;
        nStr = to_string(N);
        sort(nStr.begin(),nStr.end());
        M = stoi(nStr);
        N-=M;
    }
    cout<<candys<<ENDL;
    return 0;
}
