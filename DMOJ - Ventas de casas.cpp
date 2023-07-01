/**
 * DMOJ - Ventas de casas
 * Tematica : Estructuras de Datos : Arbol de Fenwick (ABI, BIT)
 *
 * Idea: La descripción es la clasica utilización de esta idea
 **/
#include <bits/stdc++.h>
#include <math.h>
#define ENDL '\n'
#define OPTIMIZAR_IO ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define PRESICION(x) cout.setf(ios::fixed,ios::floatfield); cout.precision(x);
#define MAX_N 1010
#define MOD 10000
#define EPS 1e-9
#define INF 3*10000000000*(-1)
#define LL long long
#define ULL unsigned long long
#define pii pair<int,int>
#define ALPHABET_SIZE 26 //['a-z']
using namespace std;

struct FenwickTreeOneBasedIndexing {
	vector<ULL> bit;
	int n;

	FenwickTreeOneBasedIndexing(int n) {
		this->n = n + 1;
		bit.assign(n + 1, 0L);
	}

	ULL sum(int idx) {
		ULL ret = 0L;
		for (; idx > 0; idx -= idx & -idx)
			ret += bit[idx];
		return ret;
	}

	ULL sum(int l, int r) {
		return sum(r) - sum(l - 1);
	}

	void add(int idx, ULL delta) {
		for (; idx < n; idx += idx & -idx)
			bit[idx] += delta;
	}

};

int main() {
	OPTIMIZAR_IO
	int N,l,r,nquerys;
	char operation;
	ULL v;
	cin>>N;
	FenwickTreeOneBasedIndexing * tree = new FenwickTreeOneBasedIndexing(N);
	for(int i=1;i<=N;i++){
		cin>>v;
		tree->add(i,v);
	}
	cin>> nquerys;
	for(int i=0;i<nquerys;i++){
		cin>>operation;
		if( operation == 'U'){
			cin>>l>>v;
			tree->add(l,v);
		}else if(operation=='R'){
			cin>>l>>r;
			cout<<tree->sum(l,r)<<ENDL;
		}
	}
	return 0;
}

