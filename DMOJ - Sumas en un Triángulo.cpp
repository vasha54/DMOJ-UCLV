//DMOJ - Sumas en un Triángulo
// Tematica :Programación Dinámica
// Idea Básica: Idea clasica de la matriz triangular y buscar
// la secuencia de elementos comenzando en la punta del trinagulo
// ytermina en algún lugar de la base que genere la mayor suma
#include <iostream>
#include <bits/stdc++.h>

#define ENDL '\n'
#define MAX 1010
#define LL long long
#define ULL unsigned long long

using namespace std;

int rows;
long long triangleMaxtrix[MAX][MAX];

int main(){

    //freopen("Input.txt","r",stdin);

    ios_base::sync_with_stdio(0);
    cin.tie(0);

    cout.setf(ios::fixed , ios::floatfield);
    cout.precision(0);

    while(cin>>rows){
        for(int i=1;i<=rows;i++){
            for(int j=1;j<=i;j++){
                cin>>triangleMaxtrix[i][j];
            }
        }

        for(int i=2;i<=rows;i++){
            for(int j=1;j<=i;j++){
                if( j == 1 ) triangleMaxtrix[i][j]+=triangleMaxtrix[i-1][j];
                else if( j == i ) triangleMaxtrix[i][j]+=triangleMaxtrix[i-1][j-1];
                else triangleMaxtrix[i][j]+=max(triangleMaxtrix[i-1][j],triangleMaxtrix[i-1][j-1]);
            }
        }

        cout<<*max_element(triangleMaxtrix[rows]+1,triangleMaxtrix[rows]+rows)<<ENDL;
    }


    return 0;
}
