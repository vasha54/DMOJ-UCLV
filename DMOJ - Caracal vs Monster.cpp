 /**
 * DMOJ - Caracal vs Monster
 * Temática:  Recursión / Relaciones de recurrencia:
 * 
 * Idea: El problema describe un combate contra un monstruo con salud 
 * inicial H. Caracal puede atacar a un monstruo cualquiera y, 
 * dependiendo de su salud, ocurre lo siguiente:
 * - Si la salud es 1, con un ataque se reduce a 0 (el monstruo muere).
 * - Si la salud es mayor que 1 (H > 1), ese monstruo desaparece y en 
 * su lugar aparecen dos nuevos monstruos, cada uno con salud ⌊H/2⌋ 
 * (parte entera de H/2). Este ataque cuenta por 1.
 * 
 * Caracal gana cuando todos los monstruos existentes tienen salud ≤ 0. 
 * Se pide el número mínimo de ataques necesarios.
 * 
 * Independientemente del orden de ataque, atacar a un monstruo de salud 
 * H > 1 genera dos monstruos idénticos de salud ⌊H/2⌋. Para eliminarlos, 
 * necesitamos eliminar cada uno de ellos por separado. Por tanto, 
 * el número total de ataques necesarios para eliminar un monstruo de salud H, 
 * denotado como A(H), cumple:
 * - A(1) = 1
 * - A(H) = 1 + 2 * A(⌊H/2⌋)   para H > 1
 * Si expandimos la recurrencia, partiendo de H y dividiendo entre 2 
 * hasta llegar a 1, obtenemos que si H necesita k divisiones para llegar 
 * a 1 (es decir, k = ⌊log₂ H⌋), entonces:
 * - A(H) = 2^{k+1} - 1
 * 
 * Como H puede ser grande basta un bucle que vaya dividiendo H entre 2 
 * y acumulando la respuesta. La complejidad es O(log H). También se 
 * puede calcular directamente con operaciones bit a bit:
 * 
 * ans = (1LL << (1 + (int)log2(H))) - 1;
 * 
 * pero un bucle explícito evita errores de precisión.
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
    int H, attacks;
    cin >> H;

    attacks = 1; // A(1) = 1
    while (H > 1) {
        attacks = attacks * 2 + 1;
        H /= 2;
    }
    cout << attacks << ENDL;
	return 0;
}

