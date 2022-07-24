//DMOJ - Desfile en el campo
// Tematica :Aritmetica - Algebra
// Idea Básica: Para saber quien es la persona al frente cuando termina de pasar
// todas puertas basta con aplicar  la operación de resto de la operación de pu % pe
// siendo pu la cantidad de puertas y pe la cantidad de personas con esta operación
// incrementado en uno sabremos quien esta al frente del desfile.
#include <iostream>
#include <bits/stdc++.h>

#define ENDL '\n'
#define MAX 100010
#define LL long long
#define ULL unsigned long long

using namespace std;

LL pu,pe;
int cases;

int main(){

    //freopen("Input.txt","r",stdin);

    ios_base::sync_with_stdio(0);
    cin.tie(0);

    while(cin>>cases){
        while(cases--){
            cin>>pe>>pu;
            cout<<(pu%pe)+1<<ENDL;
        }
    }
    return 0;
}
