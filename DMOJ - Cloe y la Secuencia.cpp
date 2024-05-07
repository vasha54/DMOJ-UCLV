/*
* DMOJ - Cloe y la Secuencia
* Tematica : Exponencion Binaria + Busqueda Binaria
* Idea: Una vez que se lee el problema y se realiza el procedimiento a mano nos podemos percatar
* de ciertas cosas:
*  1. La cantidad de valores es igual a 2^n -1.
*  2. La secuencia generada se puede ver como el recorrido entre orden
*  de un arbol binario completo donde cada padre su valor  es una unidad
*  mayor que sus dos hijos.
*  3. El valor que esta en cada posición x se corresponde con la f(x) donde
*  f(x) = n - cantidad  de iteraciones de la busqueda binaria si se buscara
*  un valor que estuviese en la posicion x.
*
* Visto lo anterior podemos implementar un algoritmo que solucione el problema.
*/
#include <iostream>
#include <math.h>
#include <bits/stdc++.h>
#define ENDL '\n'
#define OPTIMIZAR_IO ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define PRESICION(x) cout.setf(ios::fixed,ios::floatfield); cout.precision(x);
#define READ_FILE freopen("Input.txt","r",stdin);
#define WRITE_FILE freopen("Output.txt","w",stdout);
#define MAX_N 100010
#define MOD 1000000007
#define EPS 1e-4
#define INF 1000000000
#define int long long
#define uint unsigned long long
#define pii pair<int,int>
#define ALPHABET_SIZE 26 //['a-z']
#define Point pair<int, int>
#define X first
#define Y second
#define PLUS '+'
#define MINUS '-'
#define SPACE ' '
#define PRINT_LINE cout<<ENDL;
using namespace std;

int pow_binary(int base, int expo){
   int res = 1;
   while(expo){
      if(expo&1) res*=base ;
      base*=base ;
      expo>>=1;
   }
   return res ;
}



signed main(){
    OPTIMIZAR_IO
    //PRESICION(0)
    //READ_FILE
    //WRITE_FILE
    int n,k,ll,lr,pivot;
    bool find_th = false;
    cin>>n>>k;
    lr = pow_binary(2,n) - 1;
    ll = 1;

    while(!find_th){
        pivot = (ll+lr)/2;
        if( pivot == k ){
            find_th=true;
        }else if (pivot < k){
            n--;
            ll=pivot+1;
        }else{
            n--;
            lr=pivot-1;
        }
    }

    cout<<n<<ENDL;

    return 0;
}
