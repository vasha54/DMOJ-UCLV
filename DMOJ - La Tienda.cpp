/*
* DMOJ - La Tienda
* Tematica : Busqueda + Mapa
* Idea: Dado una colección de valores buscar el que mas se repite con el menor valor posible. Usar un mapa
* donde la clave es el valor  el valor es la cantidad de veces que se repite.
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
#define SPACE ' '
using namespace std;

map<int,int> frecuencys;
int n,x,f,k;


signed main(){
    OPTIMIZAR_IO
    //PRESICION(0)
    //READ_FILE
    //WRITE_FILE
    cin>>n;
    for(int i=0;i<n;i++){
        cin>>x;
        frecuencys[x]++;
    }
    f=LONG_MIN;
    for(auto i=frecuencys.begin();i!=frecuencys.end();i++){
        if(f<i->second){
           f=i->second;
           k=i->first;
        }
    }
    cout<<k<<ENDL;
    return 0;
}
