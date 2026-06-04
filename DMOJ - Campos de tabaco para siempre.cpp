/**
 * DMOJ - Campos de tabaco para siempre
 * Tema: Programación Dinámica + Suma de prefijo en 2D 
 *
 * Idea: Suma de prefijo en 2D clasico con la adecuación que los valores negativos 
 * se interpretan como cero.
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

int matrix[MAX_N][MAX_N], row, column, queries,X1,Y1,X2,Y2;
int sumAreaTable[MAX_N][MAX_N];

signed main() {
    OPTIMIZAR_IO
    //PRESICION(2)
    READ_FILE
    //WRITE_FILE
    while (cin >> row >> column >> queries) {
		for (int i = 0; i <= row + 1; i++)
			sumAreaTable[i][0] = 0;
		for (int i = 0; i <= column; i++)
			sumAreaTable[0][i] = 0;

		for (int i = 1; i <= row; i++) {
			for (int j = 1; j <= column; j++) {
				cin >> matrix[i][j];
				if (matrix[i][j] < 0)
					matrix[i][j] = 0;
				sumAreaTable[i][j]=matrix[i][j]+sumAreaTable[i][j-1]+sumAreaTable[i-1][j]-sumAreaTable[i-1][j-1];
			}
		}
		for(int i=0;i<queries;i++)
		{
			cin>>X1>>Y1>>X2>>Y2;
			cout<<sumAreaTable[X1-1][Y1-1]-sumAreaTable[X2][Y1-1]-sumAreaTable[X1-1][Y2]+sumAreaTable[X2][Y2]<<ENDL;
		}
	}
    return 0;
}