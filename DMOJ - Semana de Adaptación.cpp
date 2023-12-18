/**
* DMOJ - Semana de Adaptación
* Temática: Estructura de Datos : Fennick Tree (BIT)
* Idea: La idea es conconer para cada elemento cuantos elementos previos son
* mayores que. La sumatoria de esa informacion para cada elemento es la respuesta
* al ejercicio . Para esto vamos insertar los valores en un arbol binario indexado (BIT)
* de formar que inserte un elemento conozca cuantos valores su valor son mayor
* que el valor insertado. Esto lo hago procesando los números en el orden contrario al que
* me dieron y compriemiendo el rango y comprimiendo los valores al rango de 1 al 10^6
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

int  n, answer, x;
stack<int> inputOrder;
vector<int> values;
vector< pair<int,int> > valuesSort;

class FenwickTree{

    private:
		int * bit;
		int nodes;

    public:
     FenwickTree(int _nnodes) {
        bit = new int [_nnodes];
        fill(bit,bit+_nnodes,0L);
        nodes=_nnodes;
    }

	void add(int idx, int delta) {
        for(;idx<this->nodes;idx+=idx&-idx) bit[idx] += delta;
    }

    int sum(int idx) {
        int ret = 0L;
        for(;idx>0;idx-=idx&-idx) ret += bit[idx];
            return ret;
    }

    int sum(int l, int r) {
       return sum(r)-sum(l-1);
    }

};

signed main(){
    OPTIMIZAR_IO
    PRESICION(0)
    //READ_FILE
    answer = 0;
    cin>>n;

    for(int i=0;i<n;i++){
        cin>>x;
        valuesSort.push_back(make_pair(x,i));
        values.push_back(x);
    }

    sort(valuesSort.begin(),valuesSort.end());

    for(int i=0;i<n;i++){
        values[valuesSort[i].second]=i+1;
    }

    FenwickTree * tree = new FenwickTree(n+10);

    for(int i=n-1;i>=0;i--){
        x = values[i];
        answer+=tree->sum(x);
        tree->add(x,1);
    }

    delete tree;

    cout<<answer<<ENDL;
    return 0;
}
