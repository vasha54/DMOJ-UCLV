/**
 * DMOJ - Morteza, Joseph y las monedas. 
 * Temática: Sumatoria de Gauss
 * 
 * Idea: 
 * El problema presenta n cajas, donde la caja i tiene exactamente i monedas.
 * Joseph apila las cajas en el orden que desee. Morteza realiza n/10 pasos.
 * En cada paso, toma las 10 cajas superiores, las abre, y elige una de todas
 * las cajas abiertas hasta el momento para tomar todas sus monedas (dejándola vacía).
 * Se busca la máxima cantidad de monedas que Morteza puede asegurar sin importar
 * el orden que elija Joseph.
 *
 * Estrategia óptima de Joseph (adversario): ordenar las cajas de menor a mayor
 * en cada grupo de 10. Es decir, coloca las cajas con 1 a 10 monedas en el primer
 * grupo (las 10 superiores), las de 11 a 20 en el segundo, etc. Así, en el paso i,
 * las mejores monedas disponibles para Morteza serán exactamente 10*i.
 *
 * Estrategia óptima de Morteza: en cada paso, tomar la caja con más monedas entre
 * las disponibles. En el peor caso (el orden de Joseph anterior), obtendrá
 * 10 + 20 + 30 + ... + n monedas.
 *
 * Como cualquier otro orden solo puede aumentar las monedas máximas disponibles
 * en pasos tempranos, Morteza siempre puede garantizar al menos esa suma.
 * Por lo tanto, la respuesta es la suma de la progresión aritmética
 * 10, 20, 30, ..., n, donde k = n / 10:
 *   respuesta = 10 * k * (k + 1) / 2
 */
#include <bits/stdc++.h>
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
#define MAX_N 200010
#define MAX_TREE MAX_N << 2
#define MOD  1000000007
#define MID (right+left)/2
 
using namespace std;
using namespace __gnu_pbds;

signed main()
{
    OPTIMIZAR_IO
    //PRESICION(2)
    READ_FILE
    //WRITE_FILE
    int n;
    cin>>n;
    n/=10;
    int answer = (n*(n+1)/2) * 10;
    cout<<answer<<ENDL;
    return 0;
}