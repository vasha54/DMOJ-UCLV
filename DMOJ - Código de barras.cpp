/**
* DMOJ - Código de barras
* Temática: Algebra y Aritmetica
* Idea: Se tiene una barra codigo con m columnas donde las barras son blancas
* o negras con un ancho de 1 o dos unidades. Se quiere dado la cantidad de columnas
* determinar la cantidad de codigos de barras que se pueden formar tal que se cumpla
* lo siguiente:
* - El codigo de barra de comenzar  terminar con una barra negra
* - No puede existir dos barras consecutivas del mismo color
*
* Si analizamos la situación veremos que la cantidad de codigo de barras de m columnas que terminan
* en una barra negra va depender de la cantidad de la suma de la cantidad de codigo de barras de m-1 y
* m-2 columnas que terminan en barra blanca. Dicha situación es similar para el codigo de barra de m
* columnas que termina en barra blanca va depender de la suma de la cantidad de codigos que se forman
* con m-1 y m-2 columnas que terminen en negras de esta forma se forma las siguientes recurrencia:
*
* b(m) = n(m-1) + n(m-2)
* n(m) = b(m-1) + b(m-2)
* Siendo los casos bases
* b0 = 0, b1 = 0, b2 = 1
* n0 = 0, n1 = 1, n2 = 1
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
#define EPS 1e-9
#define INF 1000000000
#define int long long
#define uint unsigned long long
#define pii pair<int,int>
#define ALPHABET_SIZE 26 //['a-z']
#define K 25
using namespace std;

int white[MAX_N],black[MAX_N],m;

signed main(){
    OPTIMIZAR_IO
    PRESICION(0)
    //READ_FILE

    fill(black,black+MAX_N,0);
    fill(white,white+MAX_N,0);

    black[1]=black[2]=1;

    for(int i=1;i<MAX_N-2;i++){
        white[i+1]+=black[i];
        white[i+2]+=black[i];
        black[i+1]+=white[i];
        black[i+2]+=white[i];
        black[i+1]%=MOD;
        black[i+2]%=MOD;
        white[i+1]%=MOD;
        white[i+2]%=MOD;
    }

    cin>>m;
    cout<<black[m]<<ENDL;

    return 0;
}
