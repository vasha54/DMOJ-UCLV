/**
* DMOJ - Número Oculto
* Tematica : Add -Hoc + Aritmetica
* Idea: Dado un numero X el mismo se multiplica por diez el cual se suma al valor
* original de X y se obtiene un nuevo valor Y. Dado el valor de Y se desea conocer
* el valor orginal de X de ser posible además se concoce que Y esta modulado a
* 10^n donde n es la cantidad de digitos del valor X original.
*
* Basicamente en el problema lo que se hace una suma de segundo grado de la forma:
*     C5   C4   C3   C2  C1  C0
*     X5   X4   X3   X2  X1  X0  (X)
* +   X4   X3   X2   X1  Xo   0  (X*10)
* ------------------------------
*     Y5   Y4   Y3   Y2  Y1  Y0  (Y)
*
* Donde Ci representa el acarreo acumulado para el inesimo digito del número cuando
* representamos el problema de esta forma podemos ver que inicialmente será
* cero para todas las posiciones:
*
* Y0 = X0 porque C0 es 0 ya que no hay acarreo inicial
* Yi = Xi-1 + Xi + Ci  donde el valor desconocido es Xi el cual se puede determinar
*     de la siguiente manera:
* Xi =  Yi -  (Xi-1 + Ci)  si Yi ≥  (Xi-1 + Ci)
*    =  Yi+10 -  (Xi-1 + Ci)  si Yi < (Xi-1 + Ci) y esto provoca que Ci+1 = 1
*
* Para un mejor trabajo invertir el numero inicial y despues volver invertir el
* numero hallado. El problema no tiene solución cuando X0 luego de invertir los digitos
* el valor que queda es cero
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

int n;
string input;
vector<int> c,x,y,z;

signed main(){
    OPTIMIZAR_IO
    PRESICION(0)
    //READ_FILE
    //WRITE_FILE

    cin>>input;

    n = input.size();

    for(int i=n-1;i>=0;i--){
        y.push_back(input[i]-'0');
        c.push_back(0);
        x.push_back(0);
    }

    for(int i=0;i<n;i++){
        if( i ==0) x[i]=y[i];
        else{
            if(y[i]>= x[i-1]+c[i]) x[i]= y[i] - (x[i-1]+c[i]);
            else{
                x[i]= y[i]+10 - (x[i-1]+c[i]);
                if(i+1<n) c[i+1]=1;
            }
        }
    }

    reverse(x.begin(),x.end());

    if(x[0]==0) puts("IMPOSSIBLE");
    else{
        for(auto d : x) cout<<d;
        cout<<ENDL;
    }


    return 0;
}
