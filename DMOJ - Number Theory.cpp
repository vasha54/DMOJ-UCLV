/**
 * DMOJ - Number Theory
 * Tematica: Cuadrados perfectos, Número de divisores, Suma de cuadrados,
 *           Aritmética modular, Algoritmo extendido de Euclides, 
 *           Inverso multiplicativo
 * 
 * Idea: El problema es una variante del "problema de los casilleros".
 * Inicialmente la lista está vacía. En el paso i (1 ≤ i ≤ N) se procesan
 * todos los múltiplos de i. Cada número k cambia de estado tantas veces
 * como divisores tiene. Un número queda en la lista si fue alterado un
 * número impar de veces, lo que ocurre solo si tiene una cantidad impar
 * de divisores. Únicamente los cuadrados perfectos poseen un número impar
 * de divisores, ya que sus divisores se emparejan excepto la raíz cuadrada.
 * Por tanto, tras N pasos la lista contiene los cuadrados perfectos menores
 * o iguales a N: 1^2, 2^2, ..., m^2 con m = ⌊√N⌋.
 * La suma pedida es S = 1^2 + 2^2 + ... + m^2 = m(m+1)(2m+1)/6.
 * Debido a que el módulo 1234567891 es primo y no divide a 6, podemos
 * calcular la división entre 6 mediante el inverso multiplicativo de 6
 * módulo 1234567891. El inverso se obtiene con el algoritmo extendido
 * de Euclides. Luego se aplica la fórmula módulo el número dado.
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
#define MAX_N 1000
#define SHIT 500
#define MAXTREE  (MAX_N << 2)
#define MOD  1234567891LL
#define INF 1e18
#define pii pair<int,int>
#define tiib tuple<int,int,bool>
#define tiii tuple<int,int,int>
#define midle (left+right)/2   

using namespace std;
using namespace __gnu_pbds;

int mov_r[] = { 0, 0, 1,-1};
int mov_c[] = { 1,-1, 0, 0};

int modinv(int a, int m) {
    int m0 = m, y = 0, x = 1;
    if (m == 1) return 0;
    while (a > 1) {
        int q = a / m;
        int t = m;
        m = a % m, a = t;
        t = y;
        y = x - q * y;
        x = t;
    }
    if (x < 0) x += m0;
    return x;
}

signed main()
{
    OPTIMIZAR_IO
    //PRESICION(2)
    READ_FILE
    //WRITE_FILE
    
    int inv6 = modinv(6, MOD);
    int cases, N;
    cin>>cases;
    while(cases --){
        cin>>N;

        int m = (int)sqrt(N);
        while ((m + 1) * (m + 1) <= N) ++m;
        while (m * m > N) --m;

        int ans = (m % MOD) * ((m + 1) % MOD) % MOD;
        ans = ans * ((2 * m + 1) % MOD) % MOD;
        ans = ans * inv6 % MOD;

        cout << ans << ENDL;
    }

    return 0;
}