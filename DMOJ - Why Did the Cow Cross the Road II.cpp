/**
 * DMOJ - Why Did the Cow Cross the Road II.
 * Temática: Progrmación Dinamica . Suma de prefijo
 *
 * Idea: Se tiene N señales de cruce, K señales que deben formar un bloque
 * contiguo funcionando, y B señales dañadas (dadas por sus índices).
 * Se necesita reparar la mínima cantidad de señales dañadas para que exista
 * al menos un bloque continuo de K señales funcionando.
 *
 * Se construye un arreglo binario donde 1 indica señal dañada y 0 señal
 * buena. Luego se calcula la suma de prefijos: dp[i] = cantidad de dañadas
 * entre 1 e i. Para cualquier intervalo de longitud K que termine en i,
 * la cantidad de señales dañadas en él es dp[i] - dp[i-K].
 * Esa cantidad es precisamente el número de reparaciones necesarias si
 * se elige ese intervalo como el bloque de K señales. Se toma el mínimo
 * sobre todos los intervalos posibles (i = K .. N).
 *
 * Complejidad: O(N) después de leer los datos.
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
    
    int N, K, B, idx, answer;
    cin>>N>>K>>B;
    vector<int> dp(N+1,0);
    for(int i=0;i<B;i++){
        cin>>idx;
        dp[idx]=1;
    }

    for(int i=1;i<=N;i++) dp[i]= dp[i] + dp[i-1];   

    answer= K+1;

    for(int i=K;i<=N;i++){
        answer = min(answer, dp[i]-dp[i-K]);
    }

    cout<<answer<<ENDL;

    return 0; 
}