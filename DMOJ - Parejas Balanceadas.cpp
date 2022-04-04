//DMOJ - Parejas Balanceadas
//String + Estructura de datos
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
#define MOD 10000000
#define MAX 110
#define MAXTREE (MAX << 2)
#define MAX_NODE 66000
#define LIMIT 2500000100
#define ULL unsigned long long
#define LL long long
#define ENDL '\n'
#define SYMBOL '#'
#define REP(i,n) for(int i=0;i<(int)n;++i)
#define REP1_N(i,n) for(int i=1;i<=(int)n;++i)
#define FOR(i,c) for(__typeof((c).begin())i=(c).begin();i!=(c).end();++i)
#define ALL(c) (c).begin(), (c).end()
#define LINE_BLANK cout<<ENDL;
#define OO 1111000
using namespace std;

int cases,N;
stack<char> womens;
bool is;
string input;

int main(){
    //freopen ("Input.txt","r",stdin );
    //freopen ("Output.txt","w",stdout );
    cout.setf (ios::fixed ,ios::floatfield );
    cout.precision (2) ;
    ios_base::sync_with_stdio(0);
    std::cin.tie(0);

    cin>>cases;
    while(cases--){
    	cin>>N;
    	cin>>input;

    	is=true;

    	for(int i=0;i<N && is==true ;i++){
    		if(input[i]=='>')
    			womens.push(input[i]);
    		else if(input[i]=='<'){
    			if(womens.empty()==false)
    				womens.pop();
    			else
    				is=false;
    		}
    	}

    	while(womens.empty()==false){
    		is=false;
    		womens.pop();
    	}

    	if(is==true){
    		cout<<"Balanceada"<<ENDL;
    	}
    	else{
    		cout<<"No Balanceada"<<ENDL;
    	}

    }


    return 0;
}
