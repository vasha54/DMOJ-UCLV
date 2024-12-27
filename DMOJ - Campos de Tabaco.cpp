//============================================================================
// Name        : COJCPP.cpp
// Author      : Lavalido
// Version     : DMOJ - Campos de Tabaco
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <bits/stdc++.h>
#include <algorithm>
#define MOD 1000000007
#define ENDL '\n'
#define MAX 1010
#define TWO32 4294967296
#define ERROR 1e-15
#define ULL unsigned long long
using namespace std;

int matrix[MAX][MAX], row, column, queries,X1,Y1,X2,Y2;
ULL sumAreaTable[MAX][MAX];

int main() {
	//freopen("Input.txt", "r", stdin);
	ios_base::sync_with_stdio(false);
	cin.tie(0);

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