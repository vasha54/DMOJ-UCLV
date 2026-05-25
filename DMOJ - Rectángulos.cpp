/**
 * DMOJ - Rectángulos
 * Temática: Teoría de Números + Divisores
 * 
 * Idea: Dado un área S, se desea contar cuántos rectángulos diferentes se 
 * pueden formar con lados enteros (a, b) tales que a * b = S. Como los 
 * rectángulos (a,b) y (b,a) se consideran el mismo, podemos suponer a <= b.
 * Esto equivale a encontrar todos los divisores d de S que sean menores o 
 * iguales que la raíz cuadrada de S, pues por cada tal d, el otro lado será 
 * S/d y se cumple d <= S/d. Por lo tanto, la respuesta es la cantidad de 
 * divisores de S hasta sqrt(S). Se itera i desde 1 hasta i*i <= S: si i 
 * divide a S, se incrementa un contador.
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



signed main()
{
    OPTIMIZAR_IO
    //PRESICION(2)
    READ_FILE
    //WRITE_FILE

    int S, rectangle =0;
    cin>>S;
    for(int i=1;i*i<=S;i++){
        if(S%i==0) rectangle++;
    }
    cout<<rectangle<<ENDL;
    return 0;
}
