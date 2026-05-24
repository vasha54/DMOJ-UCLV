 /**
 * DMOJ - Números pesados. 
 * Temática: Ordenamiento + operadores personalizados
 * 
 * Idea: Un número se considera más pesado que otro si la suma de sus dígitos
 * es mayor. En caso de empate en la suma, el número más grande (en valor
 * numérico) es considerado más pesado. Se leen los tres enteros, se ordenan en orden 
 * descendente según el criterio de peso definido. Para ello se implementa un comparador 
 * personalizado que primero compara la suma de dígitos: si la suma de 'a' es
 * menor que la de 'b', entonces 'a' es "menor" (debe ir antes en orden 
 * ascendente). Luego, al ordenar con `sort(values.rbegin(), values.rend(), cmp)`
 * se obtiene el orden descendente según ese criterio, por lo que el primer
 * elemento del vector será el más pesado. Finalmente se imprime ese valor.
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

int sumdigits(int n){
    int s = 0;
    while(n){
        s+=(n%10);
        n/=10;
    }
    s+=(n%10);
    return s;
}

bool cmp(int a, int b){
    int sa = sumdigits(a);
    int sb = sumdigits(b);
    if(sa < sb) return true;
    else if( sa > sb ) return false;
    return (a <= b); 
}


signed main()
{
    OPTIMIZAR_IO
    //PRESICION(2)
    READ_FILE
    //WRITE_FILE
    vector<int> values(3);
    cin>>values[0]>>values[1]>>values[2];
    sort(values.rbegin(), values.rend(),cmp);
    cout<<values[0]<<ENDL;
    return 0;
}

