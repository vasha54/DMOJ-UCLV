/**
 * DMOJ - ¿Cuántos primos?
 * Temática: Números primos + busqueda binaria + BitSet
 * 
 * Idea: Dado un grupo de consulta del rango de [A,B] determinar cuantos numeros primos 
 * en ese rango. El problema es que A y B están en un rango de de 1 a 5*10^7 por tanto
 * a la hora de generar todos los numeros primos usando la criba linear pero usando un 
 * bitset para marcar los que son números primos para el ahorrar memoria. Una vez calculado
 * y almacenados todos los primos solo debemos buscar el menor primo mayor e igual A y el mayor
 * primo menor igual a B estos primos lo podemos buscar usando una busqueda binaria buscando las
 * posiciones de estos dentro del vector de primos y luego restamos las posiciones y sumamos uno 
 * y tenemos la solución al problema. 
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
#define MAX_N 5*10000010
 
using namespace std;
using namespace __gnu_pbds;

vector<int> pr;

void cribePrime()
{
    std::bitset<MAX_N> lp;
    for (int i=2; i <= MAX_N; ++i) {
        if (lp[i] == 0) {
            lp[i] = 1;  
            pr.push_back(i);
        }
        for (int j=0; j < (int)pr.size() && i*pr[j] <= MAX_N; ++j) {
            lp[i * pr[j]] = 1;
        }
    }
}

int lower_bounds(int begins, int ends, int x)
{
    int p =-1, pivot;
    while(begins <= ends)
    {
        pivot = (begins + ends)/2;
        if(pr[pivot]<= x)
        {
            p = max(p,pivot);
            begins = pivot + 1;
        }
        else
        {
            ends = pivot - 1;
        }
    }
    return p;
}

int upper_bounds(int begins, int ends, int x)
{
    int p = LONG_MAX, pivot;
    while(begins <= ends)
    {
        pivot = (begins + ends)/2;
        if(pr[pivot] >= x)
        {
            p = min(p,pivot);
            ends = pivot - 1;
        }
        else
        {
            begins = pivot + 1;
        }
    }
    return p;
}

signed main()
{
    OPTIMIZAR_IO
    PRESICION(2)
    //READ_FILE
    //WRITE_FILE
    cribePrime();
    
    int cases,a,b,solution;
    cin>>cases;
    REP(cases)
    {
        cin>>a>>b;
        int x = upper_bounds(0,pr.size()-1,a);
        int y = lower_bounds(0,pr.size()-1,b);
        solution = y - x + 1;
        cout<<"Test Case #"<<i<<": "<<solution<<ENDL;
    }    
    return 0;
}
