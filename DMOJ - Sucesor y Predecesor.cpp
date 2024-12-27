
/**
 * DMOJ - Sucesor y Predecesor
 * Temática: Teoria de números + Sistema de numeración 
 * 
 * Idea: Si desarrollamos la función que dan en el problema nos queda de la siguiente manera
 * 2^(2n) - 1 . Bien si nos centramos veremos que 8 = 2^3 lo que nos hara el proceso de conversión
 * a octal más facil.
 * 
 * Si 2n mod 3 == 0 significa que esa potencia de 2 es potencia de 8 por tanto su representación
 * en octal seria igual 100...00 donde la cantidad de 0 será igual a (2n)/3 ahora si a esa valor 
 * le quitamos el 1 de la función original (el uno es uno en cualquier sistema de numeración) 
 * quedaria un valor en octal solo conformado por el digito 7 con una cantidad de ese digito
 * igual a  (2n)/3.
 * 
 * Si 2n mod 3 == 1 aplicamos el mismo enfoque veremos que se da como resultado siempre un número 
 * que comienza por el digito 1 seguido por una secuencia de digitos 7 igual a  floor((n*2)/3).
 * 
 * Si 2n mod 3 == 2 aplicamos el mismo enfoque veremos que se da como resultado siempre un número 
 * que comienza por el digito 3 seguido por una secuencia de digitos 7 igual a  floor((n*2)/3).
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
#define MOD 1000000007
 
using namespace std;
using namespace __gnu_pbds;

int n;
string digits;

signed main()
{
    OPTIMIZAR_IO
    PRESICION(2)
    //READ_FILE
    //WRITE_FILE
    cin>>n;
    if((2*n) % 3==0)
    {
        digits = string((n*2)/3,'7');
    }
    else if((2*n) % 3==1)
    {
        digits = "1"+string(floor((n*2)/3),'7');
    }
    else
    {
        digits = "3"+string(floor((n*2)/3),'7');
    }
    cout<<digits<<ENDL;
    return 0;
}
