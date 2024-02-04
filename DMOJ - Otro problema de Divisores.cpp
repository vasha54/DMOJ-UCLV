/*
* DMOJ - Otro problema de Divisores
* Tematica : Teoria de Números + Cantidad de divisores
* Idea: Dada una colección de valores buscar ell menor valor con la mayor cantidad de divisores.
* Hacer un precalculo que permita calcular todos los divisores para todos los posibles numeros
* usuando la idea de la cibra.
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
using namespace std;

vector<short> divisors (MAX_N,1);
int n,x,maxDivisor,answer;

void cribe(){
   for(int i=2; i<MAX_N; i++){
      for(int j=i; j<MAX_N; j+=i){
         divisors[j]++;
      }
   }
}

signed main(){
    OPTIMIZAR_IO
    PRESICION(0)
    //READ_FILE
    //WRITE_FILE
    cribe();
    cin>>n;
    answer = LONG_MAX;
    maxDivisor = LONG_MIN;
    for(int i=0;i<n;i++){
        cin>>x;
        if(divisors[x]>maxDivisor){
           maxDivisor=divisors[x];
           answer = x;
        }else if(divisors[x]==maxDivisor)
          answer = min(answer,x);
    }
    cout<<answer<<ENDL;
    return 0;
}
