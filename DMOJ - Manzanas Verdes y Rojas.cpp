/**
 * DMOJ - Manzanas Verdes y Rojas
 * Temática: Greedy
 * 
 * Idea: Se tiene un grupo de elementos con donde cada uno tiene un valor
 * y color (existen a lo sumo tres colores [rojo,verde,blanco]). Se quiere
 * seleccionar a lo sumo X elementos verdes y Y elmentos rojos. En el caso
 * de los elementos blancos se pueden convertir en verdes y rojos. Se quiere
 * maximar la suma de los valores de los elementos seleccionados.
 * 
 * La solución es ordenar los elementos de acuerdo a sus valores de manera 
 * descendemente. Luego recorremos los elementos llevando la cuenta de verdes
 * y rojas hasta cumplir con la condición requerida. En el caso de las blancas
 * se van contando y cuando su cantidad sea igual a la cantidad de verdes y rojos
 * requeridos que faltan por cubrir listo porque con esas blancas cubrimos los 
 * verdes y rojos y los elementos están ordenados los elementos tomados maximan
 * la suma.
 */ 
#include <bits/stdc++.h>
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
#define COLOR char
#define APPLES vector<pair<int,char>>
 
using namespace std;
using namespace __gnu_pbds;

APPLES apples;
int X, Y, A, B, C, value, sumMax, takeWhite; 

signed main()
{
    OPTIMIZAR_IO
    PRESICION(2)
    //READ_FILE
    //WRITE_FILE
    cin>>X>>Y>>A>>B>>C;
    REP(A)
    {
        cin>>value;
        apples.push_back(make_pair(value,'R'));
    }

    REP(B)
    {
        cin>>value;
        apples.push_back(make_pair(value,'G'));
    }

    REP(C)
    {
        cin>>value;
        apples.push_back(make_pair(value,'W'));
    }

    sort(apples.rbegin(),apples.rend());
    
    sumMax = 0;
    takeWhite = 0;
    int index = 0;
    while(index < (A+B+C) && X+Y > takeWhite )
    {  
        if(apples[index].second == 'R' && X)
        {
           sumMax += apples[index].first; 
           X--;
        }
        else if(apples[index].second == 'G' && Y)
        {
           sumMax += apples[index].first; 
           Y--;
        }
        else if(apples[index].second == 'W')
        {
           sumMax += apples[index].first; 
           takeWhite++;
        }
        index++;
    } 
    cout<<sumMax<<ENDL;
    
    return 0;
}
