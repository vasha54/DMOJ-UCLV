/**
 * DMOJ -Pepe y los palillos
 * Temáticas: Teoria de Numero + BigInteger
 *
 *  Idea: Implementar la suma para números grandes
 */
#include <iostream>
#include <bits/stdc++.h>
#include <algorithm>
#define ENDL '\n'
#define MAX 110
#define MOD 10000
using namespace std;


int main() {

	ios_base::sync_with_stdio(0);
	cin.tie(0);

	cout.setf(ios::fixed, ios::floatfield);
	cout.precision(0);

	string A,B,C="";

	cin>>A>>B;

	reverse(A.begin(),A.end());
	reverse(B.begin(),B.end());

	while(A.size()<B.size())A=A+"0";
	while(B.size()<A.size())B=B+"0";

	int carry=0;
	int n = A.size();

	for(int i=0;i<n;i++){
		int a = A[i]-'0';
		int b = B[i]-'0';
		C.push_back('0'+(a+b+carry)%10);
		carry = (a+b+carry)/10;
	}

	if(carry>0)
		C.push_back('0'+carry);

	reverse(C.begin(),C.end());
	cout<<C<<ENDL;

	return 0;
}
