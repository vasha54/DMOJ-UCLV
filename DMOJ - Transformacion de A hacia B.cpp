//DMOJ - Transformación de A hacia B
//Aritmetica-Algebra + Estructura de Datos : Pila
#include <iostream>
#include <vector>
#include <algorithm>
#include <stdio.h>
#include <math.h>
#include <stack>
#include <set>
#include <queue>
#include <string>
#include <string.h>
#include <map>
#include <complex>
#include <cmath>
#define MID (left+right)/2
#define MOD 1000000007
#define MAX 2010
#define MAX_N 1000010
#define MAX_ROW 1010
#define MAX_COLUMN MAX_ROW
#define MAX_NODE 2010
#define MAX_EDGE 55000
#define MAXTREE (MAX << 2)
#define ULL unsigned long long
#define LL long long
#define ENDL '\n'
#define SYMBOL '#'
#define REP(i,n) for(int i=0;i<(int)n;++i)
#define REP1_N(i,n) for(int i=1;i<=(int)n;++i)
#define FOR(i,c) for(__typeof((c).begin())i=(c).begin();i!=(c).end();++i)
#define ALL(c) (c).begin(), (c).end()
#define LINE_BLANK cout<<ENDL;
#define OPERATOR_INC "++"
#define OPERATOR_DEC "--"
#define MAXELEMENT 260
#define MAXCAPACITYKNAPSACK 1010
#define EPS 1e-9
#define OO 1000000
#define RADIUS 1.50000
using namespace std;

LL a,b,c;
bool firstPrint,push;
stack<LL> p;
int cont;

int main(){
	//freopen("Input.txt","r",stdin);
    //freopen("Output.txt","w",stdout);
	cout.setf(ios::fixed,ios::floatfield);
	cout.precision(2);
	ios_base::sync_with_stdio(0);
	std::cin.tie(0);
	while(cin>>a>>b){
		if(a>b || (b%2!=0 && b%10!=1)){
			cout<<"NO"<<ENDL;
		}
		else {
			cont=1;

			p.push(b);
			push=true;
			while(push==true && p.top()>a){

				push=false;
				c=p.top();

				if(c%2==0){
					push=true;
					cont++;
					p.push(c/2);
				}
				else if(c%10==1){
					push=true;
					cont++;
					p.push((c-1)/10);
				}
			}

			if(p.top()==a){
				cout<<"YES"<<ENDL;
				cout<<cont<<ENDL;
				firstPrint=true;
				while(!p.empty()){
					if(firstPrint)
						firstPrint=false;
					else
						cout<<" ";
					cout<<p.top();
					p.pop();
				}
			}
			else{
				cout<<"NO"<<ENDL;
			}
		}
	}

   return 0;
}

