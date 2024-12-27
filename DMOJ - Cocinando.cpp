/**
 * DMOJ - Cocinando
 * Temáticas: Programacion Dinámica
 *
 * Idea: Implementar la dinámica que permite calcular como de una colección
 * de valores particionarlo en dos colección tal que la diferencia entre la sumas
 * de los valores de que integran los sub colecciones sea minima.
 * .
 */
#include <iostream>
#include <bits/stdc++.h>
#define ENDL '\n'
#define MAX 110
using namespace std;

int cDishes;
int dishes [MAX];

int minTime(int  _dishes [] ,int nDishes) {
    int diference = 0;
	int sum = 0;
    for(int i=0;i < nDishes;i++)
    	sum+=_dishes[i];
    int y = sum/2 +1;
    bool * dp =new bool [y];
    bool * dd =new bool [y];

    fill(dd,dd+y, false);
    fill(dp,dp+y, false);

    dp[0]=true;

    for(int i=0;i < nDishes;i++) {
    	for(int j=0;j+_dishes[i]<y;j++) {
    		if(dp[j])
    			dd[j+_dishes[i]]=true;
    	}
    	for(int j=0;j<y;j++) {
    		if(dd[j])
    			dp[j] = true;
    		dd[j] = false;
    	}
    }
    int i=y-1;

    for(;i>=0 && !dp[i];i--) {
    	if(dp[i]) {

    	}
    }

    diference =sum -(2*i);

    int a=(sum+diference)/2;
    int b=sum-a;

    return max(a, b);
}

int main() {

	ios_base::sync_with_stdio(0);
	cin.tie(0);

	cout.setf(ios::fixed , ios::floatfield);
	cout.precision(0);
	cin>>cDishes;
	for(int i=0;i<cDishes;i++){
		cin>>dishes[i];
	}
	cout<<minTime(dishes,cDishes)<<ENDL;
	return 0;
}
