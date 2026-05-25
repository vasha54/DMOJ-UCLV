/**
 * DMOJ - Más cercano a 100
 * Temática: Búsqueda + Ordenacion con comparador
 * 
 * Idea: Se leen 10 enteros y se construye el arreglo de sumas acumuladas
 * (prefijos). Luego se ordena dicho arreglo con un comparador que da
 * prioridad al valor más cercano a 100 (menor diferencia absoluta) y, en
 * caso de empate, al valor numérico mayor. El primer elemento tras la
 * ordenación es la respuesta. Como el tamaño es fijo (10), la complejidad
 * es constante O(1).
 */
#include <bits/stdc++.h>
#include <bitset>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>

#define ENDL '\n'
#define OPTIMIZAR_IO ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define PRESICION(x) cout.setf(ios::fixed,ios::floatfield); cout.precision(x);

#ifdef LOCAL
    #define READ_FILE freopen("Input.txt","r",stdin);
    #define WRITE_FILE freopen("Output.txt","w",stdout);
#else
    #define READ_FILE 
    #define WRITE_FILE 
#endif
#define REP(x) for(int i=1;i<=x;i++)
#define int long long
#define uint unsigned long long
#define PRINT_LINE cout<<ENDL;
#define MAX_N 1000010
#define MOD  1000000007
#define pii pair<int,int>
#define tiib tuple<int,int,bool>

using namespace std;
using namespace __gnu_pbds;

bool cmp(int a,int b){
    int dA = abs(100-a);
    int dB = abs(100-b);
    if(dA < dB) return true;
    else if(dA > dB) return false;
    else return (a >= b);
}

signed main()
{
    OPTIMIZAR_IO
    //PRESICION(2)
    READ_FILE
    //WRITE_FILE

    vector<int> values(10);
    cin>>values[0];
    for (int i = 1; i < 10; ++i)
    {
        cin>>values[i];
        values[i]+=values[i-1];
    }
    sort(values.begin(),values.end(),cmp);
    cout<<values.front()<<ENDL;
    return 0;
}
