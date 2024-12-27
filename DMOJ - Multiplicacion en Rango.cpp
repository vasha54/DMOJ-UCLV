//1422 - Range Multiplication
//Estructura de Datos: Range Tree+ Lazy Progation
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
#define MOD 1000000009
#define MAX 1000010
#define MARK 1000
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
using namespace std;

int n,nquery,type,indexA,indexB;
ULL K;
ULL * niz; 
ULL * tree;
ULL * lazy;

void buildSegTree(int treeIndex, int left, int right){
	
	if (left == right) {                 
        tree[treeIndex] = niz[left];
        lazy[treeIndex]=1;
        return;
    }

    buildSegTree( 2 * treeIndex , left, MID);
    buildSegTree( 2 * treeIndex+1, MID + 1, right);

    tree[treeIndex]=(tree[2*treeIndex]+tree[2*treeIndex+1])%MOD;
    lazy[treeIndex]=1;
    
}

void updateLazySegTree(int treeIndex, int left, int right, int i, int j, ULL val){
	
	 if (left > right || left > j || right < i)
        return;  
	
	if (i <= left && right <= j){  
        tree[treeIndex] = (tree[treeIndex] * val)%MOD; 
        lazy[treeIndex] = (lazy[treeIndex] * val)%MOD;
        return;
    }
    
    if(lazy[treeIndex]!=1){
		lazy[2*treeIndex]= (lazy[2*treeIndex] * lazy[treeIndex]) % MOD;
        tree[2*treeIndex]= (tree[2*treeIndex] * lazy[treeIndex]) % MOD;
        lazy[2*treeIndex+1] = (lazy[2*treeIndex+1] * lazy[treeIndex]) % MOD;
        tree[2*treeIndex+1] = (tree[2*treeIndex+1] * lazy[treeIndex]) % MOD;
		lazy[treeIndex] = 1;
	}

    updateLazySegTree(2 * treeIndex , left, MID, i, j, val);
    updateLazySegTree(2 * treeIndex + 1, MID + 1, right, i, j, val);

    tree[treeIndex] = (tree[2*treeIndex]+tree[2*treeIndex+1])%MOD;
}

ULL queryLazySegTree(int treeIndex, int left, int right, int i, int j){
    
    if (left > j || right < i)  
        return 0;  
        
    if (i <= left && j >= right) 
        return tree[treeIndex];    

    if (lazy[treeIndex] != 1){   
		lazy[2*treeIndex]= (lazy[2*treeIndex] * lazy[treeIndex]) % MOD;
        tree[2*treeIndex]= (tree[2*treeIndex] * lazy[treeIndex]) % MOD;
        lazy[2*treeIndex+1] = (lazy[2*treeIndex+1] * lazy[treeIndex]) % MOD;
        tree[2*treeIndex+1] = (tree[2*treeIndex+1] * lazy[treeIndex]) % MOD;
		lazy[treeIndex] = 1; 
    }

    if (i > MID)
        return queryLazySegTree(2*treeIndex+1,MID+1,right,i,j);
    else if (j <= MID)
        return queryLazySegTree(2*treeIndex,left,MID,i,j);

    LL leftQuery =queryLazySegTree(2*treeIndex,left,MID,i,MID);
    LL rightQuery =queryLazySegTree(2*treeIndex+1,MID+1,right,MID+1,j);

    return (leftQuery + rightQuery)%MOD;
}

int main()
{
    //freopen ("Input.txt","r",stdin );
    //freopen ("Output.txt","w",stdout );
    cout.setf (ios::fixed ,ios::floatfield);
    cout.precision (0) ;
    ios_base::sync_with_stdio(0);
    std::cin.tie(0);

	while(cin>>n>>nquery){
		
		niz=new ULL[n+1];
		tree=new ULL [(n+1) <<2];
		lazy=new ULL [(n+1) <<2];
		
		REP1_N(i,n)
			niz[i]=1;
			
		buildSegTree(1,1,n);
		
		REP(i,nquery){
			cin>>type>>indexA>>indexB;
			switch(type){
				case 0:
					cin>>K;
					updateLazySegTree(1,1,n,indexA,indexB,K);
				break;
				case 1:
					cout<<queryLazySegTree(1,1,n,indexA,indexB)<<ENDL;
				break;
			}
		}
		
		delete niz;
		delete tree;
		delete lazy;
	}
	
    return 0;
}

