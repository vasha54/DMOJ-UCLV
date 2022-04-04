//DMOJ - Múltiplo de 2, 3 y 5
//Greedy 
#include <iostream>
#include <algorithm>
#include <stdio.h>
#include <vector>
#include <math.h>
#include <set>
#include <string>
#include <string.h>
#include <stdio.h>
#include <queue>

#define MID (left+right)/2
#define MOD 1000000007
#define MAX_SQUARE 1000010
#define MAX_CUBIC 10010
#define MARK 2000010
#define MAXTREE (MAX << 2)
#define LIMIT 100000
#define ULL unsigned long long
#define LL long long
#define ENDL '\n'
#define SYMBOL '#'
#define REP(i,n) for(int i=0;i<(int)n;++i)
#define REP1_N(i,n) for(int i=1;i<=(int)n;++i)
#define FOR(i,c) for(__typeof((c).begin())i=(c).begin();i!=(c).end();++i)
#define ALL(c) (c).begin(), (c).end()
#define LINE_BLANK cout<<ENDL;
#define INF 100000000
#define ROW 110
#define COLUMN 110
#define FAC pair<ULL,int> 
using namespace std;

int ndigits,digit,zeros;
vector<int> mod0,mod1,mod2,answer;

int main()
{
    //freopen("Input.txt","r",stdin);
    //freopen("Output.txt","w",stdout);

    cout.setf(ios::fixed,ios::floatfield);
    cout.precision(0);
	 ios_base::sync_with_stdio(0);
    std::cin.tie(0);

	 cin>>ndigits;
			zeros=0; mod0.clear();
			mod1.clear();  mod2.clear(); answer.clear();
			
			REP(i,ndigits){
				cin>>digit;
				if(digit==0) zeros++;
				else if(digit%3==0) answer.push_back(digit);
				else if(digit%3==1) mod1.push_back(digit);
				else if(digit%3==2) mod2.push_back(digit);		
			}
			
			if(zeros==0){
				cout<<-1<<ENDL;	
			}
			else{
				sort(mod1.begin(),mod1.end());
			    sort(mod2.begin(),mod2.end());
			    answer.push_back(0);
				zeros--;
				
				
				while(mod2.size()>3){
					answer.push_back(mod2.back()); mod2.pop_back();
					answer.push_back(mod2.back()); mod2.pop_back();
					answer.push_back(mod2.back()); mod2.pop_back();
				}
				
				while(mod1.size()>3){
					answer.push_back(mod1.back()); mod1.pop_back();
					answer.push_back(mod1.back()); mod1.pop_back();
					answer.push_back(mod1.back()); mod1.pop_back();
				}
				
				
				if(mod1.size()==3 && mod2.size()==3){
					answer.push_back(mod2.back()); mod2.pop_back();
					answer.push_back(mod2.back()); mod2.pop_back();
					answer.push_back(mod2.back()); mod2.pop_back();
					
					answer.push_back(mod1.back()); mod1.pop_back();
					answer.push_back(mod1.back()); mod1.pop_back();
					answer.push_back(mod1.back()); mod1.pop_back();
				}
				else if(mod1.size()<=1 && mod2.size()==3){
					answer.push_back(mod2.back()); mod2.pop_back();
					answer.push_back(mod2.back()); mod2.pop_back();
					answer.push_back(mod2.back()); mod2.pop_back();
				}
				else if(mod1.size()==3 && mod2.size()<=1){
					answer.push_back(mod1.back()); mod1.pop_back();
					answer.push_back(mod1.back()); mod1.pop_back();
					answer.push_back(mod1.back()); mod1.pop_back();
				}
				
				while(!mod1.empty() && !mod2.empty()){
					answer.push_back(mod1.back()); mod1.pop_back();
					answer.push_back(mod2.back()); mod2.pop_back();
				}
				
				
				if(answer.size()>1){
					while(zeros>0){
						answer.push_back(0);
						zeros--;
					}
				}
				
				ndigits=answer.size();
				
				sort(answer.rbegin(),answer.rend());
			
				REP(i,ndigits) cout<<answer[i];
					cout<<ENDL;
			
			}
	
    
    return 0;
}