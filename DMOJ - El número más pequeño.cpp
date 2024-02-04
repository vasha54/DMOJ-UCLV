/*
* DMOJ - El número más pequeño
* Tematica : Busqueda + Fuerza Bruta
* Idea: Dado tres valores buscar el primer valor positivo que se puede obtener que no se puede representar como suma de alguna
* combinación de los tres valores dados.
*/
#include <iostream>
#include <math.h>
#include <bits/stdc++.h>
#define ENDL '\n'
#define OPTIMIZAR_IO ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define PRESICION(x) cout.setf(ios::fixed,ios::floatfield); cout.precision(x);
#define READ_FILE freopen("Input.txt","r",stdin);
#define WRITE_FILE freopen("Output.txt","w",stdout);
#define MAX_N 1010
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
using namespace std;

int a,b,c;
set<int> sums;

signed main(){
    OPTIMIZAR_IO
    PRESICION(0)
    //READ_FILE
    //WRITE_FILE
    while(cin>>a>>b>>c){
        sums.insert(a);
        sums.insert(b);
        sums.insert(c);
        sums.insert(a+b);
        sums.insert(a+c);
        sums.insert(b+c);
        sums.insert(a+b+c);

        for(int  i=1;;i++){
            if(sums.find(i)==sums.end()){
                cout<<i<<ENDL;break;
            }
        }
        sums.clear();
    }
    return 0;
}
