/*
* DMOJ - Números distintos
* Tematica: Ordenamiento
* Idea: Dada un coleccion de números determinara la cantidad de numeros diferentes
* en la colección
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


signed main(){
    OPTIMIZAR_IO
    //PRESICION(0)
    //READ_FILE
    //WRITE_FILE
    int n,diferents =1;
    cin>>n;
    vector<int> values(n);
    for(int i=0;i<n;i++)cin>>values[i];
    sort(values.begin(),values.end());
    for(int i=0;i<n-1;i++) if(values[i]!=values[i+1]) diferents++;
    cout<<diferents<<ENDL;
    return 0;
}
