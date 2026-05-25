 /**
 * DMOJ - El extraño aparato
 * Temática: Greedy
 * 
 * Idea: Se tiene un aparato con las siguientes teclas:
 *  - Dígitos '1'..'9': cada pulsación escribe el dígito correspondiente.
 *  - Tecla '0': una pulsación escribe un único cero.
 *  - Tecla especial "00": una pulsación escribe dos ceros consecutivos.
 * Dado un número como una cadena de dígitos, se desea escribirlo con la mínima
 * cantidad de pulsaciones posibles.
 *
 * Observación: los dígitos del '1' al '9' siempre requieren una pulsación cada uno.
 * Los ceros pueden escribirse de a pares usando la tecla "00" para ahorrar una pulsación.
 * Así, la estrategia óptima es un barrido greedy de izquierda a derecha:
 *   - Si el carácter actual está entre '1' y '9' -> contar 1 pulsación y avanzar uno.
 *   - Si es '0' y el siguiente también es '0' -> usar la tecla "00": contar 1 pulsación y avanzar dos.
 *   - En otro caso (un '0' solitario o al final) -> usar la tecla '0': contar 1 pulsación y avanzar uno.
 * La suma total es la respuesta.
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
	string line;
	cin>>line;
	int idx=0, minimun_buttons=0, n=line.size();
	while(idx < n){
		if('1'<=line[idx] && line[idx]<='9'){
			minimun_buttons++;
			idx++;
		}else if('0'== line[idx] && idx+1 < n && '0'== line[idx+1]){
			minimun_buttons++;
			idx+=2;
		}else{
			minimun_buttons++;
			idx++;
		}
	}
	cout<<minimun_buttons<<ENDL;
}

