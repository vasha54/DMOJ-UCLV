/*
* DMOJ - Monstruos.
* Tematica : Greedy + Progrmación dinámica : Prefijo de Suma
* Idea: Dado un grupo de monstruos de los cuales se conoce su fuerza se quiere
* hallar la cantidad de ellos que se pueden comer a todos los demas monstruos.
* Se conoce que un monstruo se come a otro siempre y cuando el doble de su fuerza
* es mayor o igual que la fuerza del otro monstruos. De igual manera se conoce que
* cuando un monstruo se come otro su fuerza se incrementa con el valor de la fuerza
* del monstruo comido. Para resolver el proeblema vamos a ordenar los monstruos por
* su fuerza de forma decreciente de esta forma un monstruo en la posicion i va poder
* comer a todos los mounstruos hacia su derecha. Ahora para ver si puede comer a todos
* los monstruos a la izquierda solo debemos busca el último mounstruo que se comio a
* todos si el monstruo i con el doble toda la fuerza que le aportará comerse a todos
* los monstruo a la derecha mas la suya es mayor que ese último monstruo que se comio
* a todos j con j<i entonces el monstruo en i podra comerse a todos los mounstruos.
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

vector<int> monsters,ps;
int nmonsters,killed,lastKilled;

signed main(){
    OPTIMIZAR_IO
    PRESICION(0)
    //READ_FILE
    //WRITE_FILE
    cin>>nmonsters;
    monsters.resize(nmonsters);
    ps.resize(nmonsters,0);

    for(int i=0;i<nmonsters;i++) cin>>monsters[i];
    sort(monsters.rbegin(),monsters.rend());
    for(int i=0;i<nmonsters;i++) ps[i]=(i ? ps[i-1]+monsters[i]:monsters[i]);
    killed = 1;
    lastKilled = 0;
    for(int i=1;i<nmonsters;i++){
        if(monsters[lastKilled] <= 2*( ps[nmonsters-1]-ps[i-1] )){
            killed++;
            lastKilled = i;
        }
    }
    cout<<killed<<ENDL;
    return 0;
}
