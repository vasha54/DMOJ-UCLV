/*
* DMOJ - Clones en la cola.
* Tematica : Counnting Sort + Suma de prefijjo
* Idea: Dada  una colección de N numeros se quiere saber para cada número de la colección
* cuantos pares se pueden formar desde el primer elemento hasta ese enesimo elemento tal que los
* números que se tomen para formar los posibles pares sean dos números diferentes, es decir un par
* no se puede formar con dos números iguales. Analizando el problema podemos darnos cuenta que:
* - Para el elemento en la posicion i = 0 aporta 0 pares ( no tiene predecesores en la colección
*   con los cuales pueda formar pares)
* - Para los elementos en las posiciones i >0 aporta i-c([i])+f(i-1) donde:
*   - i-c([i]) la cantidad de pares que se pueden formar donde uno de los dos numeros que se toman para
*     para formar el par es el valor en la posición i. A esa cantidad de pares hhay que quitar la cantidad
*     pares donde el otro número es igual al que se encuentra en la posición i. Por tanto c([x]) me delvovera
*     la cantidad de valores que hay igual a [x] en una posición menor que x. Esto lo puedo computar con un mapa
*     o utilizando la idea de CountingSort.
*   - f(i-1) será la cantidad de pares que se puede formar sin que uno de los números que se tome para construir los
*     los pares sea el que se encuentra en la posición i pero están en posiciones menores que i y son diferentes
*     valores. La idea es ir calulando la respuesta en las posiciones menores a i para cuando llegue a i utilizar dichas
*     soluciones. Realizando una suma de prefijo se resuelve el problema.
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
#define K 25
#define Point pair<int, int>
#define X first
#define Y second
#define PLUS '+'
#define MINUS '-'
#define SPACE cout<<" ";
using namespace std;

int n;
vector<int> counting(MAX_N,0), ps,values;

signed main(){
    OPTIMIZAR_IO
    PRESICION(0)
    //READ_FILE
    //WRITE_FILE
    cin>>n;
    ps.resize(n,0);
    values.resize(n,0);
    for(int i=0;i<n;i++){
        cin>>values[i];
        if(i) ps[i]=ps[i-1]+i-counting[values[i]];
        counting[values[i]]++;
    }
    for(int i=0;i<n;i++){
        if(i) SPACE
        cout<<ps[i];
    }
    cout<<ENDL;
    return 0;
}
