/*
* DMOJ - El festival de MFC.
* Tematica : Add-Hoc + Estructura de datos Mapa
* Idea: Dada una colección de valores que oscilan en el rango de [1,4] y un
* valor K que cuyo valor tambien oscila en ese rango encontrar la ocurrencia
* de dos valores K cuya distancia entre ellos sea la menor en cuanto a sus
* posiciones en la colecciones, en caso de encontrar al menos dos ocurrencias
* imprimir -1.
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

int n,k,best,x;
map<int, vector<int> > pos;

signed main(){
    OPTIMIZAR_IO
    //PRESICION(0)
    //READ_FILE
    //WRITE_FILE
    cin>>n>>k;
    best = LONG_MAX;
    for(int i=0;i<n;i++){
        cin>>x;
        pos[x].push_back(i);
    }
    for(int i=1;i<pos[k].size();i++){
        if(pos[k][i]-(pos[k][i-1]+1) < best) best=pos[k][i]-(pos[k][i-1]+1);
    }
    cout<<(best==LONG_MAX ? -1 : best)<<ENDL;
    return 0;
}
