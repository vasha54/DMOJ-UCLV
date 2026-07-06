/**
 * DMOJ - Heno para la Venta (Mochila 0-1)
 * Temática: Programación Dinámica + Mochila booleana
 *
 * Idea: Dado un camión con capacidad C y H fardos de volúmenes V_i (cada uno
 * disponible una sola vez), determinar el máximo volumen total que se puede
 * cargar sin exceder C.
 *
 * Se resuelve con DP de mochila 0-1 usando un arreglo booleano dp[0..C]:
 *   dp[0] = true
 *   Para cada fardo de volumen v:
 *        Recorrer i desde C hasta v:
 *            si dp[i - v] es true, entonces dp[i] = true
 * El orden descendente garantiza que cada fardo se utilice a lo sumo una vez.
 *
 * Finalmente, se busca el mayor índice i ≤ C tal que dp[i] == true.
 * Ese valor es la respuesta.
 *
 * Complejidad: O(H * C) en tiempo, O(C) en espacio.
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



signed main()
{
    OPTIMIZAR_IO
    //PRESICION(2)
    READ_FILE
    //WRITE_FILE
    
    int capacity, nitems;
    cin>>capacity>>nitems;
    vector<int> volumes(nitems);
    vector<bool> dp(capacity+1,false);
    for(int i=0;i<nitems;i++) cin>>volumes[i];

    dp[0] = true;

    for(auto item : volumes){
        for(int i=capacity;i>=item;i--){
            if(dp[i-item]) dp[i] = true;
        }
    }

    int best = -1;
    for(int i=capacity;i>=0 && best < 0;i--){
        if(dp[i]) best=i;
    }

    cout<<best<<ENDL;    

    return 0;
}