//DMOJ - Super Turbo
//Estructura de Datos: Range Tree + Lazy Propagation
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
#define MAX 100010
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

struct Node{
	int swaps;
	bool lazy;
};

Node tree[MAXTREE];

int nelements,value,indexs[MAX],valueUpdate,indexValue,shits,answer;
deque<int> orders;
bool leftPop;

void buildSegTree(int treeIndex, int left, int right){

	tree[treeIndex].lazy=false;
	tree[treeIndex].swaps=0;

	if (left == right) {
		tree[treeIndex].swaps=0;
		return;
	}

	buildSegTree(2*treeIndex,left,MID);
	buildSegTree(2*treeIndex+1,MID+1,right);
}


void updateLazySegTree(int treeIndex, int left, int right, int i, int j, int val){

	if (left > right || left > j || right < i)
		return;

	if (i <= left && right <= j){
		tree[treeIndex].lazy=true;
		tree[treeIndex].swaps+=val;
		return;
	}

	if(tree[treeIndex].lazy==true){
		tree[2*treeIndex].lazy=tree[treeIndex].lazy;
		tree[2*treeIndex+1].lazy=tree[treeIndex].lazy;

		tree[2*treeIndex].swaps+=tree[treeIndex].swaps;
		tree[2*treeIndex+1].swaps+=tree[treeIndex].swaps;
		tree[treeIndex].lazy = false;
		tree[treeIndex].swaps = 0;
	}

	updateLazySegTree(2 * treeIndex , left, MID, i, j, val);
	updateLazySegTree(2 * treeIndex + 1, MID + 1, right, i, j, val);
}

int queryLazySegTree(int treeIndex, int left, int right, int pos){

	if(left==right){
		return tree[treeIndex].swaps;
	}

	if (tree[treeIndex].lazy == true){
		tree[2*treeIndex].lazy=tree[treeIndex].lazy;
		tree[2*treeIndex+1].lazy=tree[treeIndex].lazy;

		tree[2*treeIndex].swaps+=tree[treeIndex].swaps;
		tree[2*treeIndex+1].swaps+=tree[treeIndex].swaps;

		tree[treeIndex].lazy = false;
		tree[treeIndex].swaps = 0;
	}

	if (pos > MID)
		return queryLazySegTree(2*treeIndex+1,MID+1,right,pos);
	else if (pos <= MID)
		return queryLazySegTree(2*treeIndex,left,MID,pos);
}


int main(){
	//freopen("Input.txt","r",stdin);
	//freopen("Output.txt","w",stdout);
	cout.setf(ios::fixed,ios::floatfield);
	cout.precision(2);
	ios_base::sync_with_stdio(0);
	std::cin.tie(0);

	while(cin>>nelements){

		orders.clear();

		REP1_N(i,nelements){
			cin>>value;
			indexs[value]=i;
			orders.push_back(i);
		}

		buildSegTree(1,1,nelements);

		leftPop=true;

		while(!orders.empty()){
			if(leftPop){
				value=orders.front();
				orders.pop_front();
				valueUpdate=1;
			}
			else{
				value=orders.back();
				orders.pop_back();
				valueUpdate=-1;
			}
			indexValue=indexs[value];
			shits=queryLazySegTree(1,1,nelements,indexValue);
			shits+=indexValue;
			answer=abs(value-shits);
			cout<<answer<<ENDL;
			if(answer!=0){
				if(leftPop==true){
					updateLazySegTree(1,1,nelements,1,indexValue-1,valueUpdate);
				}
				else{
					updateLazySegTree(1,1,nelements,indexValue+1,nelements,valueUpdate);
				}
			}

			leftPop=!leftPop;
		}
	}

	return 0;
}

