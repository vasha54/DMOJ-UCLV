/*
* DMOJ - Ifri y la ecuación
* Tematica : Fuerza bruta + Add Hoc
* Idea: Es suficiente con comprobar cada posible variante y, en caso de haber varias, obedecer el orden de
* prioridad establecido. Un detalle importante es a la hora de comprobar la división es mejor comprobar de la
* forma b*c==a cundo se desea comprobar a/b=c porque recuerde que la división puede dar con parte decimal que
* se puede truncar y provocar una respuesta no correcta.
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

int a,b,c;

signed main(){
    OPTIMIZAR_IO
    //PRESICION(0)
    //READ_FILE
    //WRITE_FILE
    cin>>a>>b>>c;
    if(a+b==c) // a+b=c
        cout<<a<<"+"<<b<<"="<<c<<ENDL;
    else if(a-b==c) // a-b=c
        cout<<a<<"-"<<b<<"="<<c<<ENDL;
    else if(a*b==c) // a*b=c
        cout<<a<<"*"<<b<<"="<<c<<ENDL;
    else if(a==b*c) // a/b=c
        cout<<a<<"/"<<b<<"="<<c<<ENDL;
    else if(a==b+c) // a=b+c
        cout<<a<<"="<<b<<"+"<<c<<ENDL;
    else if(a==b-c) // a=b-c
        cout<<a<<"="<<b<<"-"<<c<<ENDL;
    else if(a==b*c) // a=b*c
        cout<<a<<"="<<b<<"*"<<c<<ENDL;
    else if(a*c==b) // a=b/c
        cout<<a<<"="<<b<<"/"<<c<<ENDL;
    return 0;
}
