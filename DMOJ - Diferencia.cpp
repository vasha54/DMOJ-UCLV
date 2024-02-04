/*
* DMOJ - Diferencia.
* Tematica : Teoría de Número + Buscar divisores
* Idea: Dado un numero encontrar dos números que multiplicados den el numero  cuya
* diferencia entre ellos sean mínimos.
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

int n,a,b,difference;

signed main(){
    OPTIMIZAR_IO
    PRESICION(0)
    //READ_FILE
    //WRITE_FILE
    cin>>n;
    difference = LONG_MAX;
    for(int  i=1,j=0;i*i<=n;i++){
        if(n%i==0){
            j=n/i;
            if(abs(i-j)<difference){
                difference = abs(i-j);
                a = min(i,j);
                b = max(i,j);
            }
        }
    }
    cout<<a<<" "<<b<<ENDL;
    return 0;
}
