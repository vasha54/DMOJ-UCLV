//DMOJ - 2x1
//Programacion dinamica: Tabla de memorization
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
#define MAX 55
#define MAX_N 20010
#define MAX_ROW 1010
#define MAX_COLUMN MAX_ROW
#define MAX_NODE 30010
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
#define OO 987654321
#define RADIUS 1.50000

using namespace std;

const int mov_c[]={0, 0, 1,-1, 1, 1,-1,-1};
const int mov_r[]={1,-1, 0, 0, 1,-1, 1,-1};

struct Range{
  
  int limitLeft;
  int limitRight;
  bool isCreated;
  LL id;
  
  Range(LL _id=0, int _left=0, int _right=0, bool _isCreated=false){
     id=_id;
     limitLeft=_left;
     limitRight=_right;
     isCreated=_isCreated;
   }
};


int nelements, element,answer,columns;
vector<Range> table[MAX];
LL idGenerator;
Range A, B, C;

bool cmp(Range _a, Range _b){
   if(_a.limitLeft<_b.limitLeft)
      return true;
   else if(_a.limitLeft>_b.limitLeft)
      return false;
   else{
      return (_a.id<_b.id);
   }
}

int main(){
	//freopen ("Input.txt","r",stdin );
	//freopen ("Output.txt","w",stdout );
	cout.setf (ios::fixed ,ios::floatfield);
	cout.precision (6) ;
	ios_base::sync_with_stdio(0);
	std::cin.tie(0);

   while(cin>>nelements){
      idGenerator=1;
      answer=0;
      
      REP(i,nelements){
         cin>>element;
         table[element].push_back(Range(idGenerator,i,i));
         idGenerator++;
      }
      
      REP(i,MAX){
         if(table[i].empty())
            continue;
         sort(table[i].begin(),table[i].end(),cmp);
         columns=table[i].size();
         REP(j,columns){
            A=table[i][j];
            for(int k=j+1;k<columns;k++){
               B=table[i][k];
               if(A.limitRight+1==B.limitLeft){
                  C=Range(idGenerator,A.limitLeft,B.limitRight,true);
                  if(i+1<MAX)
                     table[i+1].push_back(C);
               }else if(A.limitRight+1<B.limitLeft)
                  break;
            }
            if(A.isCreated==true)
               answer=max(i,answer);        
         }
         
         table[i].clear();
      }
      
      cout<<answer<<ENDL;
   }

	return 0;
}