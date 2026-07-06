/**
 * DMOJ - Subsequences Summing to Sevens
 * Temática: Programación Dinámica + Suma de prefijos
 *
 * Idea: Dado un arreglo de N identificadores de vacas, encontrar la longitud máxima
 * de un subarreglo contiguo cuya suma sea múltiplo de 7.
 *
 * Se utiliza un enfoque con sumas prefijo módulo 7. Sea pref[i] = (pref[i-1] + a[i]) % 7.
 * Un subarreglo desde l+1 hasta r tiene suma múltiplo de 7 si y solo si pref[r] == pref[l].
 * Para maximizar la longitud, almacenamos la primera posición (índice) donde aparece cada
 * residuo (0 a 6). Al encontrar un residuo ya visto, la longitud del subarreglo es
 * (posición actual - primera posición). Se actualiza un máximo.
 *
 * Caso especial: pref[0] = 0 en la posición 0 (antes de cualquier vaca), lo que permite
 * subarreglos que comienzan desde el inicio.
 *
 * Complejidad: O(N) en tiempo, O(N) o O(7) en espacio.
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

    int ncows, subsequences=-1;
    cin>>ncows;

    vector<int> cows(ncows+1), dp(ncows+1,0);
    map<int,int> first_pos;

    first_pos[0]=0;

    for(int i=1;i<=ncows;i++){
        cin>>cows[i];
        dp[i]= (dp[i-1] + cows[i])%7;
        if(first_pos.find(dp[i])==first_pos.end())
            first_pos[dp[i]] = i;
        else
            subsequences = max(subsequences,i-first_pos[dp[i]]);
    }

    cout<<subsequences<<ENDL;
    return 0;
}