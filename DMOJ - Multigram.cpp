//DMOJ - Multigram
//Add-Hoc + String
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
#define MOD  1000000007
#define MAX 2010
#define MAX_N 30010
#define MAX_ROW 1010
#define MAX_COLUMN MAX_ROW
#define MAX_NODE 2020
#define MAX_EDGE 55000
#define MAXTREE (MAX << 2)
#define ULL unsigned long long
#define LL long long
#define NUMBER LL
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
#define OO 1000010
#define RADIUS 1.50000
using namespace std;

const int mov_c[]={0, 0, 1,-1, 1, 1,-1,-1};
const int mov_r[]={1,-1, 0, 0, 1,-1, 1,-1};

string input;
int N,root,a,b;
vector<int> divisors;

bool onlyLetter(string _text){
	int length=_text.length();
	for(int i=1;i<length;i++){
		if(_text[i]!=_text[i-1])
			return false;
	}
	return true;
}

bool isAnagram(string _a, string _b){
	sort(_a.begin(),_a.end());
	sort(_b.begin(),_b.end());

	int n=_a.length();
	for(int i=0;i<n;i++){
		if(_a[i]!=_b[i])
			return false;
	}

	return true;
}

void searchMultigram(){

	bool findMultigram=false;

	FOR(it,divisors){
		int K=N/(*it);
		findMultigram=false;
		int nAnagrams=0;
		for(int i=0;i<K;i++){
			if(isAnagram(input.substr(0,(*it)),
					     input.substr((i)*(*it),(*it)))){
				nAnagrams++;
			}
		}

		if(nAnagrams==K){
			findMultigram=true;
			cout<<input.substr(0,(*it))<<ENDL;
			break;
		}

	}
	if(findMultigram==false)
		cout<<-1<<ENDL;

}

int main(){
	//freopen("Input.txt","r",stdin);
	//freopen("Output.txt","w",stdout);
	cout.setf(ios::fixed,ios::floatfield);
	cout.precision(2);
	ios_base::sync_with_stdio(0);
	std::cin.tie(0);
	while(cin>>input){
		N=input.size();

		if(N==1){
			cout<<-1<<ENDL;
		}
		else if(onlyLetter(input)){
			cout<<input[0]<<ENDL;
		}else{
			divisors.clear();
			root=sqrt(N);
			for(int i=2;i<=root;i++){
				if(N%i==0){
					a=i;
					b=N/i;
					divisors.push_back(a);
					if(a!=b)
						divisors.push_back(b);
				}
			}

			sort(divisors.begin(),divisors.end());
			searchMultigram();
		}
	}
	return 0;
}

