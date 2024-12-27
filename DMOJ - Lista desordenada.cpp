/**
 * DMOJ - Lista desordenada
 * Temática: Estructura de Datos + ABI o Range Tree 
 * 
 * Idea: Dada una coleccción de valores se quiere saber para cada valor de la 
 * coleccion hacia la derecha de el son mayores que el. Dada las restricciones 
 * del problema aplicar una solución trivial no entraría en tiempo aunque pudiera 
 * raspar par de puntos. Bien la solución esta en utilizar una estructura de datos
 * eficiente que dado un valor x saber cuantos números hay en el rango de [x+1, 10^5]
 * Esto lo puedo sacar con un ABI o Range Tree. La cuestión es procesar los valores 
 * de derecha a izquierda es decir desde el final al principio de esta forma cuando
 * llegue a la posición i todos los valores de la posición i+1 a n habrán sido procesado
 * y almacenados en la estructura de datos  podré saber cuantos números son mayores
 * al que esta en la posición i . Luego de saber esto inserto el valor en el árbol
 * para que sea utilizado en las proximas posiciones.
 */ 
#include <bits/stdc++.h>
#include <bitset>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>

#define ENDL '\n'
#define OPTIMIZAR_IO ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define PRESICION(x) cout.setf(ios::fixed,ios::floatfield); cout.precision(x);
#define READ_FILE freopen("Input.txt","r",stdin);
#define WRITE_FILE freopen("Output.txt","w",stdout);
#define REP(x) for(int i=1;i<=x;i++)
#define int long long
#define uint unsigned long long
#define PRINT_LINE cout<<ENDL;
#define MAX_N 100010
#define MOD 1000000007
 
using namespace std;
using namespace __gnu_pbds;

struct FenwickTreeOneBasedIndexing {
    vector<int> bit; int n;

    FenwickTreeOneBasedIndexing(int n) {
        this->n = n + 1; bit.assign(n + 1, 0);
    }
    
    int sum(int idx) {  
        int ret = 0;
        for(;idx>0;idx-=idx&-idx) ret += bit[idx];
        return ret;
    }

    int sum(int l, int r) {
        return sum(r)-sum(l-1);
    }

    void add(int idx, int delta) {
        for(;idx<n;idx+=idx&-idx) bit[idx] += delta;
    }
    
    
    int point_query(int idx) {
        int ret = 0;
        for (; idx > 0; idx -= idx & -idx)
        ret += bit[idx];
        return ret;
    }
};

vector <int> values, answers;
int nvalues,x;

signed main()
{
    OPTIMIZAR_IO
    PRESICION(2)
    //READ_FILE
    //WRITE_FILE
    cin>>nvalues;
    REP(nvalues)
    {
        cin>>x;
        values.push_back(x);
        answers.push_back(0);
    }

    FenwickTreeOneBasedIndexing abi = FenwickTreeOneBasedIndexing(MAX_N);

    for(int i=nvalues-1;i>=0;i--)
    {
        answers[i] = abi.sum(values[i]+1,MAX_N);
        abi.add(values[i],1);
    }

    for(int i=0;i<nvalues;i++)
    {
        if(i)cout<<" ";
        cout<<answers[i];
    }
    cout<<ENDL;
    return 0;
}
