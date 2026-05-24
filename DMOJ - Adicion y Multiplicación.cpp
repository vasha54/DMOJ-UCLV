/**
 * DMOJ - Multiplicación y Adicion
 * Temática: BFS por etapas, simulación
 * 
 * Idea: Se parte del número 1 (etapa 0). En cada etapa k (k>=1) se pueden
 * calcular todas las sumas y productos de dos números cualesquiera generados
 * en etapas anteriores. Los números nuevos se agregan al conjunto de disponibles
 * y se repite el proceso hasta alcanzar el número objetivo N.
 *
 * Observación: como los números solo pueden usarse una vez que han aparecido,
 * el proceso equivale a un BFS donde en cada nivel generamos todos los números
 * posibles <= N a partir de los números del nivel anterior.
 *
 * Complejidad: O(E * A^2) donde A es la cantidad de números disponibles, pero
 * N ≤ 10000 garantiza que la simulación corre en tiempo.
 * 
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
#define MAX_N 1000010
#define MOD  1000000007
#define pii pair<int,int>
#define tiib tuple<int,int,bool>
 
using namespace std;
using namespace __gnu_pbds;


signed main()
{
    OPTIMIZAR_IO
    //PRESICION(2)
    READ_FILE
    //WRITE_FILE
    int N;
    cin >> N;
    
    
    if (N == 1) {
        cout << 0 << ENDL;
        return 0;
    }
    
    vector<bool> reached(N + 1, false);
    reached[1] = true;
    vector<int> current = {1};
    int stage = 0;
    
    while (!reached[N]) {
        stage++;
        vector<int> new_numbers;
        int size = current.size();
        
        
        for (int i = 0; i < size; ++i) {
            for (int j = i; j < size; ++j) {
                int a = current[i];
                int b = current[j];
                
                
                int s = a + b;
                if (s <= N && !reached[s]) {
                    reached[s] = true;
                    new_numbers.push_back(s);
                }
                
                
                int p = a * b;
                if (p <= N && !reached[p]) {
                    reached[p] = true;
                    new_numbers.push_back(p);
                }
            }
        }
        
            
        current.insert(current.end(), new_numbers.begin(), new_numbers.end());
    }
    
    cout << stage << ENDL;
    return 0;
}