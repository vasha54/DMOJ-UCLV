//============================================================================
// Name        : DMOJ - Profundidad de las Paginas.cpp
// Author      : Vasha
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================
#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <list>
#include <queue>
#include <stack>
#include <deque>
#include <vector>
#include <set>
#include <map>
#include <algorithm>
#include <string>
#include <string.h>
#include <memory.h>
#include <iostream>
// int PP,SIGN,IEOF;
// #define VALID(ch) (ch != ' ' && ch != '\t' && ch != '\r' && ch != '\n' && ch != EOF)
// #define GETCHAR(ch) { ch = getchar_unlocked(); }
// #define PUTCHAR(ch) { putchar_unlocked(ch); }
// #define GETNUMBER(n) { \
//     register char ch = 0; n = 0; SIGN = 1; \
//     while(IEOF != EOF && (ch < 33 || ch == '-')) { if(ch == EOF) IEOF = EOF; if(ch == '-') SIGN = -1; GETCHAR(ch) } \
//     while(IEOF != EOF && ch > 33) { n = ((n << 1) + (n << 3) + (ch - '0')); GETCHAR(ch) } \
//     if(ch == EOF) IEOF = EOF; \
//     n *= SIGN; \
// }
// #define GETWORD(buffer) { \
//     register char ch; \
//     PP = 0; \
//     do { GETCHAR(ch); if(VALID(ch)) buffer[PP++] = ch; else { buffer[PP] = '\0'; if(ch == EOF) IEOF = EOF; } } while(VALID(ch)); \
// }
// #define PUTWORD(buffer, ch) { \
//     PP = 0; \
//     while(buffer[PP]) { PUTCHAR(buffer[PP++]); } \
//     PUTCHAR(ch); \
// }
#define INF 1E10
#define EPS 1E-10
#define ERROR 1e-15
#define max(a,b) (a>b?a:b)
#define min(a,b) (a>b?b:a)
#define REP(i,begin,end) for(int i=begin;i<(int)end;++i)
#define MAXN 10000.000
#define MOD  1000000000
// #define MIN -10000100
#define ELEMENT 75
using namespace std;

struct Pages{
       int level;
       bool visit;
       vector<int> soons;     
};

struct Mark{
      int id,n;
};

Pages pages[ELEMENT];
int cases,npages,nlinks,nqueries,nlevel,a,b;

void reset(){
     REP(i,0,ELEMENT){
         pages[i].visit=false;
         pages[i].soons.clear();
         pages[i].level=-1;
     }
}

void bfs(int a,int b){
     Mark at,next;  
     queue<Mark> see;
 
     pages[a].level=b;
     pages[a].visit=true;

     at.id=a;
     at.n=b;

     see.push(at);

     while(!see.empty()){
          at=see.front();
          see.pop();
          REP(i,0,pages[at.id].soons.size()){
              if(pages[pages[at.id].soons.at(i)].visit==false){
                 pages[pages[at.id].soons.at(i)].level=at.n+1;
                 pages[pages[at.id].soons.at(i)].visit=true;
                 next.id=pages[at.id].soons.at(i);
                 next.n=at.n+1;
                 see.push(next);
              }
          }
     }

}
   
int main() {
    // freopen("Input.txt","r",stdin);
    while(scanf("%d",&cases)!=EOF){
          while(cases--){
                reset();
                scanf("%d%d%d",&npages,&nlinks,&nqueries);
                REP(i,0,nlinks){
                    scanf("%d%d",&a,&b);
                    pages[a].soons.push_back(b);
                }
                nlevel=1;
                bfs(1,nlevel);
                REP(i,0,nqueries){
                  scanf("%d",&a);
                  printf("%d\n",pages[a].level);
                }
          }     
    }
    return 0;
}