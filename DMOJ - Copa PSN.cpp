/*
* DMOJ - Copa PSN
* Tematica : Busqueda
* Idea: Dado un número de tres digitos encontrar el primer valor minimo valor que sea mayor o igual al valor dado  cuyas
* cifras sean iguales. Almacenando de forma ordenanda todos los posibles valores que son pocos y realizando sobre esa coleccion
* la operación lower_bounds con el valor dado es posible solucionar el problema.
*/
#include <iostream>
#include <math.h>
#include <bits/stdc++.h>
#define ENDL '\n'
#define OPTIMIZAR_IO ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define PRESICION(x) cout.setf(ios::fixed,ios::floatfield); cout.precision(x);
#define READ_FILE freopen("Input.txt","r",stdin);
#define WRITE_FILE freopen("Output.txt","w",stdout);
#define MAX_N 10000001
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
using namespace std;

int tickets [] ={111,222,333,444,555,666,777,888,999};
int x;

signed main(){
    OPTIMIZAR_IO
    PRESICION(0)
    //READ_FILE
    //WRITE_FILE
    cin>>x;
    cout<<*lower_bound(tickets,tickets+9,x)<<ENDL;
    return 0;
}
