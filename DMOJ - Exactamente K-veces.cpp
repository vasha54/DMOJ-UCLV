//DMOJ - Exactamente K-veces
//String : Suffix Array
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
/*
struct strCmp {
	bool operator()( const string & _a, const string & _b){
		if(_a.length() > _b.length())
			return true;
		else if(_a.length() < _b.length())
			return false;
		else{
			return (strcmp(_a.c_str(),_b.c_str())!=0);
		}
	}
};*/

bool cmp( const string & _a, const string & _b){
	if(_a.length() > _b.length())
		return true;
	else if(_a.length() < _b.length())
		return false;
	else{
		return (strcmp(_a.c_str(),_b.c_str())!=0);
	}
}


string input, lcpTmp, lcpTmp2;
int K,N,repeated;
vector<string> suffixArray;
vector<string> candidates;
map<string,set<int> > ocurrences;

string lcp(string _a , string _b){
	int k=0;
	int n=min(_a.length(),_b.length());
	for(;k<n;k++){
		if(_a[k]!=_b[k])
			break;
	}

	return _a.substr(0,k);
}

bool onlyLetter(string _string){
    int n=_string.length();
    for(int e=1;e<n;e++){
        if(_string[e-1]!=_string[e])
            return false;
    }
    return true;
}

int main(){
	//freopen("Input.txt","r",stdin);
	//freopen("Output.txt","w",stdout);
	cout.setf(ios::fixed,ios::floatfield);
	cout.precision(2);
	ios_base::sync_with_stdio(0);
	std::cin.tie(0);

	while(cin>>K){
		cin>>input;
		N=input.size();
		if(K==1){
            cout<<input.length()<<ENDL;
		}else if( onlyLetter(input)){
            if(N>=K){
                cout<<N-K+1<<ENDL;
            }
            else
                cout<<-1<<ENDL;

		}else{

			suffixArray.clear();
			ocurrences.clear();
			REP(i,N){
				suffixArray.push_back(input.substr(i));
			}

			sort(suffixArray.begin(),suffixArray.end());

			for(int i=0;i<N;i++){
				ocurrences[suffixArray[i]].insert(i);
				for(int j=i+1;j<N;j++){
					string lcpTmp=lcp(suffixArray[i],suffixArray[j]);
					if(lcpTmp.length()!=0){
						ocurrences[lcpTmp].insert(i);
						ocurrences[lcpTmp].insert(j);
					}
					else
						break;
				}
			}


			map<string,set<int> >::iterator it=ocurrences.begin();
			while(it!=ocurrences.end()){
				if(K==(*it).second.size())
					candidates.push_back((*it).first);
				it++;
			}
			sort(candidates.begin(),candidates.end(),cmp);

			if(candidates.empty())
				cout<<-1<<ENDL;
			else
				cout<<candidates[0].length()<<ENDL;
		}


	}

	return 0;
}

