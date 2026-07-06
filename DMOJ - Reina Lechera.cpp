/**
 * DMOJ - Reina Lechera
 * Temática: Programación Dinámica + Coin Change
 *
 * Idea: Dado un monto N y C monedas con valores dados, calcular el número
 * de maneras de hacer el cambio usando combinaciones (no permutaciones).
 * Se utiliza DP: ways[i] = número de combinaciones para suma i.
 * Inicial: ways[0] = 1.
 * Para cada moneda, para i desde coin hasta N: ways[i] += ways[i-coin].
 * El orden de los bucles (monedas afuera, cantidad adentro) garantiza que
 * cada combinación se cuente exactamente una vez.
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
#define MOD  1000000007
#define pii pair<int,int>
#define tiib tuple<int,int,bool>
#define tiii tuple<int,int,int>
#define midle (left+right)/2   

using namespace std;
using namespace __gnu_pbds;

char maps[MAX_N][MAX_N];
int rows=MAX_N, columns=MAX_N, r, c, dc, dr, nlodo;

int mov_r[] = { 0, 0, 1,-1};
int mov_c[] = { 1,-1, 0, 0};

signed main()
{
    OPTIMIZAR_IO
    //PRESICION(2)
    READ_FILE
    //WRITE_FILE
    int n, ncoins;
    cin >> n >> ncoins;
    vector<int> ways(n+1, 0);
    vector<int> coins(ncoins);
    for(int i = 0; i < ncoins; i++) cin >> coins[i];

    ways[0] = 1;

    for(int coin : coins) {
        for(int i = coin; i <= n; i++) {
            ways[i] += ways[i - coin];
        }
    }

    cout << ways[n] << ENDL;

    return 0;
}