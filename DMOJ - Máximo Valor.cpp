/**
 * DMOJ - Máximo Valor
 * Temática: Greedy
 * 
 * Idea: Recorremos el número de izquierda a
 * derecha. En cada posición i, mientras queden intercambios (k>0),
 * buscamos en la ventana [i+1, i+k] el dígito más grande. Si existe uno
 * mayor que el dígito actual en i, lo "burbujeamos" hasta la posición i
 * mediante intercambios adyacentes, lo que consume exactamente
 * (posición_del_máximo - i) movimientos. Restamos esa cantidad de k y
 * avanzamos a la siguiente posición. La elección es óptima porque en
 * cada paso colocamos el mayor valor posible en el lugar de mayor peso,
 * sin malgastar intercambios.
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

int seach_best(char * number,int _pos, int _n, int _k){
    char reference = number[_pos];
    int index =-1;
    for(int i=_pos+1;i<_n;i++){
        if(reference < number[i] && i-_pos <=_k){
            index = i;
            reference = number[i];
        }
    }
    return index;
}

void change(char * number, int _b, int _e){
    for(int i=_e;i>_b;i--){
        char tmp = number[i-1];
        number[i-1] = number[i];
        number[i] = tmp;
    }
}

signed main()
{
    OPTIMIZAR_IO
    //PRESICION(2)
    READ_FILE
    //WRITE_FILE
    int k,n,idx;
    char number[20];
    cin>>number>>k;
    n = strlen(number);
    idx = 0;

    while(k>0 && idx<n){
        int best = seach_best(number,idx,n,k);
        if(best != -1){
            k-=(best-idx);
            change(number,idx,best);
        }
        idx++;
    }
    cout<<number<<ENDL;
    return 0;
}