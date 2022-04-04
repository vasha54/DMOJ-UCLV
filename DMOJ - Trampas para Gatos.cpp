//DMOJ - Trampas para Gatos
//Teoría de grafos: BFS+ Components conexa + ciclos dentro de un grafo
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
#define MAX 1000010
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
   bool endPath;
   bool mark;
   int soon;
   vector<int> parents;
};
   
Node graph[MAX]; 

int columns,rows,tramps,indexNode,indexNtNode;  
char board[MAX_ROW][MAX_COLUMN];

void resetGraph(){
   REP(i,rows*columns+5){
      graph[i].soon=-1;
      graph[i].parents.clear();
      graph[i].endPath=true;
      graph[i].mark=false;
   }
   
}

bool insideBoard(int _r,int _c){
   return (0 <= _r && _r < rows && 0 <= _c && _c <columns);
}

void visitParentsAndSoon(int _source, bool _visitSoon=false){
   queue<int> visits;
   graph[_source].mark=true;
   visits.push(_source);
   int current,next;
   
   while(!visits.empty()){
      current=visits.front();
      visits.pop();
      
      int nparents=graph[current].parents.size();
      
      REP(i,nparents){
         next=graph[current].parents[i];
         if(!graph[next].mark){
            graph[next].mark=true;
            visits.push(next);
         }
      }
      
      if(_visitSoon && graph[current].soon!=-1){
         next=graph[current].soon;
         if(!graph[next].mark){
            graph[next].mark=true;
            visits.push(next);
         }
      }
   }
}


int main(){
   //freopen ("Input.txt","r",stdin );
   //freopen ("Output.txt","w",stdout );
   cout.setf (ios::fixed ,ios::floatfield);
   cout.precision (6) ;
   ios_base::sync_with_stdio(0);
   std::cin.tie(0);
   
   while(cin>>rows>>columns){
      REP(i,rows)
         cin>>board[i];
      resetGraph();  
      REP(i,rows){
         REP(j,columns){
            indexNode=i*columns+j;
            
            if(board[i][j]=='N' && insideBoard(i-1,j)){
               indexNtNode=(i-1)*columns+j;  
               graph[indexNode].soon=indexNtNode;
               graph[indexNode].endPath=false;
               graph[indexNtNode].parents.push_back(indexNode); 
            }
            
            if(board[i][j]=='S' && insideBoard(i+1,j)){
               indexNtNode=(i+1)*columns+j;  
               graph[indexNode].soon=indexNtNode;
               graph[indexNode].endPath=false;
               graph[indexNtNode].parents.push_back(indexNode); 
            }
            
            if(board[i][j]=='W' && insideBoard(i,j-1)){
               indexNtNode=i*columns+(j-1);  
               graph[indexNode].soon=indexNtNode;
               graph[indexNode].endPath=false;
               graph[indexNtNode].parents.push_back(indexNode); 
            }
            
            if(board[i][j]=='E' && insideBoard(i,j+1)){
               indexNtNode=i*columns+(j+1);  
               graph[indexNode].soon=indexNtNode;
               graph[indexNode].endPath=false;
               graph[indexNtNode].parents.push_back(indexNode); 
            }
         }
      }
      
      tramps=0;
      
      REP(i,rows*columns)
         if(graph[i].endPath){
            tramps++;
            visitParentsAndSoon(i);
         }
            
      REP(i,rows*columns)
         if(!graph[i].mark){
            tramps++;
            visitParentsAndSoon(i,true);
         }
      cout<<tramps<<ENDL;  
   }
   
   return 0;
}
