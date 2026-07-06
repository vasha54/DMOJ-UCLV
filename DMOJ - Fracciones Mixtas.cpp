/**
 * DMOJ - Fracciones Mixtas
 * Temática: Temática: Aritmética / Simulación
 *
 * Idea: Se reciben pares (numerador, denominador) hasta encontrar "0 0".
 * Para cada fracción impropia se debe generar su representación como 
 * fracción mixta sin simplificar. Basta calcular:
 *   entero = a / b  (división entera)
 *   nuevo_numerador = a % b
 *   denominador = b
 * Se imprime "entero  nuevo_numerador / denominador". Notar que aunque
 * el residuo sea 0 se muestra "0 / b", tal como requiere el ejemplo.
 * Complejidad O(1) por caso.
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
#define MAX_N 110
#define MAXTREE  (MAX_N << 2)
#define MOD  1000000007
#define pii pair<int,int>
#define tiib tuple<int,int,bool>
#define midle (left+right)/2   

using namespace std;
using namespace __gnu_pbds;



signed main()
{
    OPTIMIZAR_IO
    //PRESICION(2)
    READ_FILE
    //WRITE_FILE

    int a,b;

    while(cin>>a>>b && a!=0 && b!=0){
        cout<<(a/b)<<" "<<a%b<<" / "<<b<<ENDL;
    } 

    return 0;
}