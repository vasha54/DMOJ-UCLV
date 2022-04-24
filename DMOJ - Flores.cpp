//DMOJ - Flores
//Estructuras de Datos: Range Tree + Lazy Progation
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
#define MAX 1000010
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

struct Node{
	int flowers;
	bool lazy;
};

Node tree[MAXTREE];

int ndays,L,R,fL,fR;


void buildRangeTree(int treeIndex, int left, int right){

	tree[treeIndex].lazy=false;
	tree[treeIndex].flowers=0;

	if (left == right) {
		tree[treeIndex].flowers=0;
		return;
	}

	buildRangeTree(2*treeIndex,left,MID);
	buildRangeTree(2*treeIndex+1,MID+1,right);
}

void updateLazyRangeTree(int treeIndex, int left, int right, int i, int j){

	if (left > right || left > j || right < i)
		return;

	if (i <= left && right <= j){
		tree[treeIndex].lazy=true;
		tree[treeIndex].flowers++;
		return;
	}

	if(tree[treeIndex].lazy==true){
		tree[2*treeIndex].lazy=tree[treeIndex].lazy;
		tree[2*treeIndex+1].lazy=tree[treeIndex].lazy;

		tree[2*treeIndex].flowers+=tree[treeIndex].flowers;
		tree[2*treeIndex+1].flowers+=tree[treeIndex].flowers;
		tree[treeIndex].lazy = false;
		tree[treeIndex].flowers = 0;
	}

	updateLazyRangeTree(2 * treeIndex , left, MID, i, j);
	updateLazyRangeTree(2 * treeIndex + 1, MID + 1, right, i, j);
}

int queryLazyRangeTree(int treeIndex, int left, int right, int pos){

	if(left==right){
		int answer = tree[treeIndex].flowers;
		tree[treeIndex].flowers=0;
		return answer;
	}

	if (tree[treeIndex].lazy == true){
		tree[2*treeIndex].lazy=tree[treeIndex].lazy;
		tree[2*treeIndex+1].lazy=tree[treeIndex].lazy;

		tree[2*treeIndex].flowers+=tree[treeIndex].flowers;
		tree[2*treeIndex+1].flowers+=tree[treeIndex].flowers;

		tree[treeIndex].lazy = false;
		tree[treeIndex].flowers = 0;
	}

	if (pos > MID)
		return queryLazyRangeTree(2*treeIndex+1,MID+1,right,pos);
	if (pos <= MID)
		return queryLazyRangeTree(2*treeIndex,left,MID,pos);
}

int main(){
	//freopen ("Input.txt","r",stdin );
	//freopen ("Output.txt","w",stdout );
	cout.setf (ios::fixed ,ios::floatfield);
	cout.precision (6) ;
	ios_base::sync_with_stdio(0);
	std::cin.tie(0);

	while(cin>>ndays){

		buildRangeTree(1,1,MAX);

		REP(i,ndays){
			cin>>L>>R;
			fL=queryLazyRangeTree(1,1,MAX,L);
			fR=queryLazyRangeTree(1,1,MAX,R);
			cout<<fL+fR<<ENDL;
			updateLazyRangeTree(1,1,MAX,L+1,R-1);
		}
	}


	return 0;
}