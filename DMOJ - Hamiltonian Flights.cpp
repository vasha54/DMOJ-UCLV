/**
* DMOJ - Hamiltonian Flights
* Tematica : Teoria de grafos: Camino Hamilton
*
* Idea: Resolvemos el problema en tiempo O(2^n n^2) usando programación dinámica.
* Calculamos, para cada ciudad c y subconjunto de ciudades S,
* el número de maneras en que podemos llegar a la ciudad c desde la ciudad 1
* de modo que visitemos cada ciudad de S exactamente una vez.
* Representamos cada subconjunto de ciudades como una máscara de bits de n bits.
* Para cada una de estas máscaras, recorremos todas las formas posibles de elegir
* la última ciudad y la anterior en el recorrido.
* Hay O(2^n) subconjuntos de ciudades posibles y
* O(n^2) maneras posibles de elegir la última ciudad y la anterior.
*/
 
#include <iostream>
#include <vector>
using namespace std;
using ll = long long;

const int M = 1000000007;

int main() {
    int n, m;
    cin >> n >> m;

    vector<vector<int>> count(n, vector<int>(n));

    for (int i = 0; i < m; i++) {
        int a, b;
        cin >> a >> b;
        a--;
        b--;
        count[a][b]++;
    }

    vector<vector<ll>> ways(1 << n, vector<ll>(n));
    ways[1][0] = 1;

    for (int mask = 2; mask < (1 << n); mask++) {
        vector<int> nodes;
        for (int node = 0; node < n; node++) {
            if (mask & (1 << node)) {
                nodes.push_back(node);
            }
        }

        for (auto last : nodes) {
            for (auto prev : nodes) {
                ways[mask][last] +=
                    count[prev][last] * ways[mask ^ (1 << last)][prev];
            }
            ways[mask][last] %= M;
        }
    }

    cout << ways[(1 << n) - 1][n - 1] << "\n";
}