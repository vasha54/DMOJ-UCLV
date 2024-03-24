/*
* DMOJ - Swapeable.
* Tematica : Aritmetica y Algebra: Sumatoria de Gauss, Estructura de datos:mapas
* Idea: Dado una colección de valores encontrar la cantidad de pares que puedo crear
* tal que los elementos que formen el par sean distintos. Si tenemos N elementos podemos
* formar N(N-1)/2 pares dicho valor digamos que es Z. Pero en el valor estamos contandos
* aquellos pares con dos números quue son iguales. Es por que a Z debemos restarles por
* cada valor numerico b diferente presente en la colección (f(b)(f(b)-1)/2) donde f(x)
* devuelve la cantidad de valores iguales a b presentes en la colección. Para f(x) se puede
* llevar un mapa donde la clave sea el valor mientras el valor asociado sea la cantidad de
* ocurrencia del valor en la colección.
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
using namespace std;

int n,solutions,x;
map<int,int> v;

signed main(){
    OPTIMIZAR_IO
    //PRESICION(0)
    //READ_FILE
    //WRITE_FILE
    cin>>n;
    solutions=(n*(n-1))/2;
    for(int i=0;i<n;i++){
        cin>>x;
        v[x]++;
    }
    for(auto t:v){
        solutions-=(t.second*(t.second-1))/2;
    }
    cout<<solutions<<ENDL;
    return 0;
}
