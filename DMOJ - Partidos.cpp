/*
* DMOJ - Partidos
* Tematica : Add-Hoc
* Idea: Dado cuatro valores ver sin con ellos se puede formar un rectangulo y si se puede imprimir el area de dicha figura
* sino imprimir el perimetro del cuadrilatero que se forma.
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

int sides [4];

signed main(){
    OPTIMIZAR_IO
    PRESICION(0)
    //READ_FILE
    //WRITE_FILE
    cin>>sides[0]>>sides[1]>>sides[2]>>sides[3];
    sort(sides,sides+4);
    if(sides[0]==sides[1] && sides[2]==sides[3]){
        cout<<"YES"<<ENDL;
        cout<<sides[0]*sides[2]<<ENDL;
    }else{
        cout<<"NO"<<ENDL;
        cout<<sides[0]+sides[1]+sides[2]+sides[3]<<ENDL;
    }
    return 0;
}
