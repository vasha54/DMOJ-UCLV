/**
 * DMOJ - Números de seis dígitos
 * Temática: Búsqueda Completa
 * 
 * Idea: Dados N y M, formamos el intervalo [min(N,M), max(N,M)] y recorremos todos los números
 * de 6 dígitos dentro de él. Para cada número i, extraemos sus primeros tres dígitos a = i / 1000
 * y sus últimos tres dígitos b = i % 1000. Si a y b son ambos >= 100 (es decir, cada parte tiene
 * exactamente 3 dígitos), calculamos c = a + b. Verificamos si i es divisible por c (i % c == 0).
 * Los números que cumplen se almacenan, y al final se imprime la cantidad de ellos y la suma total.
 * Complejidad: O(rango) ≈ 900 000 operaciones en el peor caso, perfectamente aceptable para una
 * búsqueda completa. 
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

    int N, M, a, b, c;
    vector<int> answers;
    cin>>N>>M;

    for(int i=min(N,M);i<=max(N,M);i++){
        a = i / 1000;
        b = i % 1000;
        c = a + b;
        if(i%c == 0 && a >= 100 && b >= 100){
          // cout<<i<<" f:"<<a<<" s:"<<b<<" d:"<<c<<ENDL;  
          answers.push_back(i);  
        } 
    }

    c = 0;
    for(auto it: answers) c+= it;
    cout<<answers.size()<<" "<<c<<ENDL;
    
    return 0;
}
