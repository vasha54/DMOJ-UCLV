/**
 * DMOJ - Saldo de la cuenta
 * Tema: Simulación
 * 
 * Idea: Dado un saldo inicial B y T transacciones (cada una es crédito 'C' o 
 * débito 'D' con un monto entero), se debe calcular el saldo final de la cuenta.
 * Basta leer el saldo inicial y luego procesar secuencialmente cada transacción:
 * - Si el tipo es 'C', sumar el monto al saldo.
 * - Si el tipo es 'D', restar el monto al saldo (puede quedar negativo).
 * Finalmente se imprime el saldo resultante. Al ser una simulación directa sin
 * necesidad de estructuras complejas, la complejidad es O(T) por caso de prueba,
 * perfectamente suficiente para las restricciones.
 */
#include <bits/stdc++.h>

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
#define pii pair<int,int>
#define tiii tuple<int,int,int>
#define MAX_N 1010
#define MAX_TREE MAX_N << 2
#define MOD  1000000007
#define MID (right+left)/2

using namespace std;

signed main() {
    OPTIMIZAR_IO
    //PRESICION(2)
    READ_FILE
    //WRITE_FILE
    int cases, account, operation, noperations;
    char type_operation;
    cin>>cases;
    while(cases--){
        cin>>account;
        cin>>noperations;
        for(int i=1;i<=noperations;i++){
            cin>>type_operation>>operation;
            if(type_operation=='C') account+=operation;
            else if(type_operation=='D') account-=operation;
        }
        cout<<account<<ENDL;
    }
    return 0;
}