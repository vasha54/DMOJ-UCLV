/*
* DMOJ - El valor más largo.
* Tematica : Add-Hoc + Busqueda
* Idea: Dado un numero de tres digitos generar todos los números que se puede
* sumando o multiplicando los digitos y de todos los numeros determinar el mayor.
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

string input;
int c,d,u;

signed main(){
    OPTIMIZAR_IO
    //PRESICION(0)
    //READ_FILE
    //WRITE_FILE
    cin>>input;
    u=input[2]-'0';
    d=input[1]-'0';
    c=input[0]-'0';
    int values [] ={c+d+u, c+d*u, c*d+u, c*d*u};
    cout<<*max_element(values,values+4)<<ENDL;
    return 0;
}
