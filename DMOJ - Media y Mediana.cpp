// DMOJ - Media y Mediana
// Tematica :Aritemtica y Algebra
//
// Idea Básica: Dado dos numeros A y B nos piden hallar un C tal que sean el mínimo
// y que se cumpla que la media de A,B y C sea igual a la mediana. Se conoce que A
// siempre va ser menor e igual que B. Partiendo de esta idea como el valor de C debe
// ser minimo el mismo debe ser menor que A por lo que A seria la mediana del conjunto
// por lo que pudieras plantear que A = (A+B+C)/3. Haciendo el despeje correcto nos queda
// que 3A-A-B=C simplficando 2A-B seria la ecuación que arroja el valor buscado

#include <iostream>
#include <bits/stdc++.h>
#define ENDL '\n'
#define MAX 1010
#define LL long long
#define ULL unsigned long long

using namespace std;

int main(){
   //freopen("Input.txt","r",stdin);

    ios_base::sync_with_stdio(0);
    cin.tie(0);

    cout.setf(ios::fixed , ios::floatfield);
    cout.precision(0);

    long long A,B;
    while(cin>>A>>B && (A || B)){
        cout<<(A-(B-A))<<ENDL;
    }
}
