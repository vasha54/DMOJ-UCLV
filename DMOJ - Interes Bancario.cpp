//DMOJ - Interés Bancario
// Tematica :Add -Hoc
// Idea Básica: Simular el proceso descrito en el problema.
// Tener en cuenta que se debe truncar la salida
#include <iostream>
#include <bits/stdc++.h>

#define ENDL '\n'
#define MAX 100010
#define LL long long
#define ULL unsigned long long

using namespace std;



int main(){

    freopen("Input.txt","r",stdin);

    ios_base::sync_with_stdio(0);
    cin.tie(0);

    cout.setf(ios::fixed , ios::floatfield);
    cout.precision(0);

    double rateInterest, money;
    int years;

    while(cin>>rateInterest>>money>>years){
        for(int i=0;i<years;i++){
            money = money + ((rateInterest*money)/100.00);
        }
        cout<<floor(money)<<ENDL;
    }

    return 0;
}
