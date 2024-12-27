/**
* DMOJ - Encontrando al Padre
* Tematica : Teoria de Numero: Sistema de numeración
* Idea: Se tienen un numero N y se quiere hallar el menor valor posible pero que
* sea mayor que N pero que en su representación en binario tenga la misma cantidad
* de uno que la representacion en binario de N. Para solucionarl problema basta
* con hallar el primer uno lo mas a la derecha posible tal que el digito que le
* sigue a la izquierda es cero dichos digitos se intercambian. El otro detalle a
* tener en cuenta es todos los unos que estaban a la derecha del que intercambie
* deben correrse lo mas a la dercha posible de la representación en binario del
* numero. Una vez hecho este procedimiento convertimos el binario resultante a
* decimal y tendremos el resultado
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

int N,posOne,countOne;
vector<int> binary;

signed main(){
    OPTIMIZAR_IO
    PRESICION(0)
    //READ_FILE
    //WRITE_FILE

    while(cin>>N){
        binary.clear();

        while(N/2!=0){
            binary.push_back(N%2);
            N/=2;
        }
        binary.push_back(N%2);
        binary.push_back(0);
        countOne =0;
        posOne =-1;

        //for(int i=binary.size()-1;i>=0;i--)cout<<binary[i];
        //cout<<ENDL;

        for(int i=0;i<binary.size()-1 ;i++){
            if(binary[i]==1 && binary[i+1]==0){
                posOne =i;
                binary[i]=0;
                binary[i+1]=1;
                break;
            }
            if(binary[i]==1) countOne++;
        }

        for(int i=0;i<posOne;i++){
            if(countOne ) {binary[i]=1; countOne--;}
            else binary[i]=0;
        }

        //for(int i=binary.size()-1;i>=0;i--)cout<<binary[i];
        //cout<<ENDL;
        N = 0;
        posOne =1;
        for(int i=0;i<binary.size();i++){
            N+=(binary[i]*posOne);
            posOne*=2;
        }
        cout<<N<<ENDL;
    }

    return 0;
}
