/**
 * DMOJ - Huesos Bovinos
 * Temática: Busqueda completa 
 * 
 * Idea:  Dados tres dados con S1, S2 y S3 caras (numeradas de 1 a S_i), 
 * se quiere encontrar la suma que se obtiene con mayor frecuencia al lanzar 
 * los tres dados simultáneamente. Como las restricciones del problema 
 * original son pequeñas (típicamente S1,S2,S3 <= 20), una búsqueda completa 
 * es viable y simple de implementar.
 *
 * Generamos todos los resultados posibles usando tres bucles anidados 
 * (i: 1..dice1, j: 1..dice2, k: 1..dice3). Para cada combinación 
 * calculamos la suma i+j+k y la registramos en un mapa (frecuencia). 
 * Una vez lleno el mapa, recorremos sus entradas (que se iteran en orden 
 * creciente de clave) y nos quedamos con aquella cuya frecuencia sea 
 * estrictamente mayor que el máximo encontrado hasta el momento. 
 * Al usar '>' y recorrer en orden ascendente, automáticamente 
 * preservamos la menor suma en caso de empate.
 *
 * Complejidad: O(N * log N) donde N = S1*S2*S3, suficiente para los límites 
 * del problema. El mapa también puede reemplazarse por un arreglo de 
 * tamaño S1+S2+S3+1 para mejorar la eficiencia, pero esta implementación 
 * es perfectamente aceptable.
 */
#include <bits/stdc++.h>
#include <bitset>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>

#define ENDL '\n'
#define OPTIMIZAR_IO ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define PRESICION(x) cout.setf(ios::fixed,ios::floatfield); cout.precision(x);

#ifdef LOCAL
    #define READ_FILE freopen("Input.txt","r",stdin);
    #define WRITE_FILE freopen("Output.txt","w",stdout);
#else
    #define READ_FILE 
    #define WRITE_FILE 
#endif
#define REP(x) for(int i=1;i<=x;i++)
#define int long long
#define uint unsigned long long
#define PRINT_LINE cout<<ENDL;
#define MAX_N 200010
#define MAXTREE  (MAX_N << 2)
#define MOD  1000000007
#define pii pair<int,int>
#define tiib tuple<int,int,bool>
#define midle (left+right)/2   // OJO: rigth en lugar de right, se mantiene el original

using namespace std;
using namespace __gnu_pbds;



signed main()
{
    OPTIMIZAR_IO
    //PRESICION(2)
    READ_FILE
    //WRITE_FILE

    int dice1, dice2, dice3, max_freq=LONG_MIN, value;

    cin>>dice1>>dice2>>dice3;
    map<int,int>frequency;
    for(int i=1;i<=dice1;i++){
        for(int j=1;j<=dice2;j++){
            for(int k=1;k<=dice3;k++){
                frequency[i+j+k]++;
            }
        }
    }

    for(auto it: frequency){
        if(it.second > max_freq){
            max_freq = it.second;
            value = it.first;
        }
    }

    cout<<value<<ENDL;
    
    return 0;
}