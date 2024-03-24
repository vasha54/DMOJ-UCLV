/*
* DMOJ - Ficha perdida.
* Tematica : Aritmetica  Algebra
* Idea: Vamos a calcular la suma de todos los valores menores de las fichas (A) y la
* suma de todos los valores mayores de todos las fichas (B) luego a medida que vamos
* leyendo las fichas el menor valor se lo resto a A y el mayor se los resto a B y los
* valores que queden en A y B serán los valores de la ficha de domino que falta.
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

int npieces,A,B,a,b;

signed main(){
    OPTIMIZAR_IO
    //PRESICION(0)
    //READ_FILE
    //WRITE_FILE
    cin>>npieces;
    A=B=0;
    for(int i=0;i<=npieces;i++){
        A+=(i*(i+1)/2);
        B+=(i*(i+1));
    }
    npieces=((npieces+2)*(npieces+1))/2;
    for(int i=1;i<npieces;i++){
        cin>>a>>b;
        if(a>b)swap(a,b);
        A-=a;
        B-=b;
    }
    cout<<A<<" "<<B<<ENDL;
    return 0;
}
