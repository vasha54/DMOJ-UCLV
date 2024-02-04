/*
* DMOJ - Evaluar Expresión
* Tematica : String
* Idea: Dada  una cadena conformada unicamente por instrucciones de decremento(--) e incremento(++) decir
* una variable la cual inicialmente es cero determinar el valor finaal de la variable luego de ejecutar
* todas las instrucciones.
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

signed main(){
    OPTIMIZAR_IO
    PRESICION(0)
    //READ_FILE
    //WRITE_FILE
    string instrutions;
    int signMinus=0,signPlus=0;
    cin>>instrutions;
    for(char x : instrutions){
       if(x == PLUS) signPlus++;
       if(x == MINUS) signMinus++;
    }
    cout<<(signPlus/2-signMinus/2)<<ENDL;
    return 0;
}
