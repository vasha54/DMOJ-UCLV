//DMOJ - Contactos
//String: Trie
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
#define MAX 1000000
#define MAX_N 30
#define MAX_ROW 1010
#define MAX_COLUMN MAX_ROW
#define MAX_NODE 2010
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
#define OO 1000000000
#define RADIUS 1.50000
using namespace std;

const int mov_r[]={ 0, 0,-1, 1};
const int mov_c[]={ 1,-1, 0, 0};

struct charCMP {
      bool operator()( const char  s1, const char s2 ) const {
        return (s1< s2);
      }
    };

struct TrieNode{
	bool leaf;
	int frecuency;
	map<char, TrieNode*,charCMP> alphabet;
	TrieNode() : leaf(false),frecuency(0){}
};

TrieNode *root;
int noperations,answer;
string operation,data;

void insert(TrieNode* x, string s, int pos){
	if (pos == s.length())
		x->leaf=true;
	else{
		char cur = s[pos];
		if(x->alphabet[cur]==NULL){
			x -> alphabet[cur] = new TrieNode();
		}
		x->alphabet[cur]->frecuency++;
		insert(x->alphabet[cur],s,pos+1);
	}
}

bool find(TrieNode* x, string s,int pos, int & frecuency){
	if(pos == s.length()) return true;
	if(x->alphabet[s[pos]]==NULL)return false;
	frecuency=min(x->alphabet[s[pos]]->frecuency,frecuency);
	return find(x->alphabet[s[pos]],s,pos+1,frecuency);
}

int main(){


	freopen("Input.txt","r",stdin);
	//freopen("Output.txt","w",stdout);
	cout.setf(ios::fixed,ios::floatfield);
	cout.precision(2);
	ios_base::sync_with_stdio(0);
	std::cin.tie(0);

	while(cin>>noperations){
		root=new TrieNode();

		REP(i,noperations){
			cin>>operation>>data;
			switch (operation[0]) {
				case 'a':
					insert(root,data,0);
					break;
				case 'f':
					answer=MAX;
					if(find(root,data,0,answer)){
						cout<<answer<<ENDL;
					}
					else
						cout<<0<<ENDL;
					break;
				default:
					break;
			}
		}

		delete root;
	}

	return 0;
}

