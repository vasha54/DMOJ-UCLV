/**
* DMOJ - Fedor y el Nuevo Juego
* Tematica : Operadores a nivel de bit
* Idea: Se tiene una lista de N numeros (1 <= N <= 10^3) cuyos valores oscilan
* en el rango de [0,2^20-1] de los cuales se desea conocer la cantidad de valores
* que su representacion en binario no difiere en no mas de K bits de un valor X
* La idea trivial sería convertir cada valor a binario y analizar bit a bit con
* los bits de la repreentación en binario del valor X pero como solo tenemos que
* buscar los bits donde difieran podemos hacer un xor entre valor i y el valor x
* y al nuevo valor calcular la cantida de bit activos que nos indicaria la cantidad
* de bit que existian diferencia entre el valor inesimo y X esto gracias a la propiedad
* del xor que solo da uno si los valores difieren.
*/

#include <iostream>
#include <bits/stdc++.h>
#define ENDL '\n'
#define OPTIMIZAR_IO ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define PRESICION(x) cout.setf(ios::fixed,ios::floatfield); cout.precision(x);
#define REP(i,a,b) for (int i=a; i<b; ++i)
#define MAX_N 25
#define EPS 1e-9
#define INF 1000000000
#define MOD 1000000007
#define READ_FILE freopen("Input.txt","r",stdin);
#define WRITE_FILE freopen("Output.txt","w",stdout);
#define int long long
#define uint unsigned int

using namespace std ;

int N,K,X,bits;
vector<int> numbers;

signed main(){
    OPTIMIZAR_IO
    PRESICION(0)
    //READ_FILE
    //WRITE_FILE

    cin>>bits>>N>>K;

    for(int i=0;i<N;i++){
        cin>>bits;
        numbers.push_back(bits);
    }
    cin>>X;
    N=0;
    for(auto x : numbers){
        bits = x ^ X;
        if( __builtin_popcount(bits) <=K) N++;
    }
    cout<<N<<ENDL;

    return 0;
}
