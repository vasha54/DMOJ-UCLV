//DMOJ - Herederos
//Estructura de Datos + Teoria de grafos.
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
#define MAX 255
#define MAX_N 100001
#define MAX_ROW 1010
#define MAX_COLUMN MAX_ROW
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

struct Node{
      int depth;
      double blood;
      vector<int> indexsParents;
      vector<int> indexsSons;
      string name;
   };
   
Node treeFamily[MAX];   
vector<int> levels[MAX];
int generatorId, nrelations, ncandidates, indexSon, indexFather, indexMother,
maxLevel; 
double bestBlood;  
string king,son,father,mother,nextKing, candidate;
map<string,int> dnis;

void resetTree(){
   REP(i,MAX){
      treeFamily[i].depth=0;
      treeFamily[i].indexsParents.clear();
      treeFamily[i].indexsSons.clear();
      treeFamily[i].blood=0.000000;
      levels[i].clear();
   }
}

void findLevels( int _indexKing ){
   stack<int> visit;
   int parent;
   int son;
   
   maxLevel=0;
   
   visit.push(_indexKing);
   while(!visit.empty()){
      parent=visit.top();
      visit.pop();
      
      int nsons=treeFamily[parent].indexsSons.size();
      REP(i,nsons){
         son=treeFamily[parent].indexsSons[i];
         if(treeFamily[son].depth < treeFamily[parent].depth+1){
            treeFamily[son].depth=treeFamily[parent].depth+1;
            maxLevel=max(maxLevel,treeFamily[son].depth);
            visit.push(son);
         }
      }
   }
   
   REP(i,generatorId)
      levels[treeFamily[i].depth].push_back(i);
}

void flowBlood(){
   
   for(int i=0;i<=maxLevel;i++){
      FOR(k,levels[i]){
         if(i!=0){
            double bF=treeFamily[treeFamily[(*k)].indexsParents[0]].blood/2.0000000;
            double bM=treeFamily[treeFamily[(*k)].indexsParents[1]].blood/2.0000000;
            treeFamily[(*k)].blood=bF+bM;
         }
      }
   }
}

int main()
{
	//freopen("Input.txt","r",stdin);
   //freopen("Output.txt","w",stdout);
	cout.setf(ios::fixed,ios::floatfield);
	cout.precision(10);
	ios_base::sync_with_stdio(0);
	std::cin.tie(0);
	
   while(cin>>nrelations>>ncandidates){
      cin>>king;
      dnis.clear();
      generatorId=0;
      resetTree();
      REP(i,nrelations){
         cin>>son>>father>>mother;
         
         if(dnis.find(son)==dnis.end()){
            dnis.insert(make_pair(son,generatorId));
            treeFamily[generatorId].name=son;
            generatorId++;
         }
         
         if(dnis.find(father)==dnis.end()){
            dnis.insert(make_pair(father,generatorId));
            treeFamily[generatorId].name=father;
            generatorId++;
         }
         
         if(dnis.find(mother)==dnis.end()){
            dnis.insert(make_pair(mother,generatorId));
            treeFamily[generatorId].name=mother;
            generatorId++;
         }
         
         indexSon=dnis[son];
         indexFather=dnis[father];
         indexMother=dnis[mother];
         
         treeFamily[indexSon].indexsParents.push_back(indexFather);
         treeFamily[indexSon].indexsParents.push_back(indexMother);
         
         treeFamily[indexMother].indexsSons.push_back(indexSon);
         treeFamily[indexFather].indexsSons.push_back(indexSon);
      }
      
      treeFamily[dnis[king]].blood=1.000;
      
      findLevels(dnis[king]);
      flowBlood();
      
      cin>>candidate;
      bestBlood=treeFamily[dnis[candidate]].blood;
      nextKing=candidate;
      
      
      REP(i,ncandidates-1){
         cin>>candidate;
         if( bestBlood < treeFamily[dnis[candidate]].blood ){
            bestBlood=treeFamily[dnis[candidate]].blood;
            nextKing=candidate;
         }
      }
      
      cout<<nextKing<<ENDL;
   }
   
   return 0;
}
