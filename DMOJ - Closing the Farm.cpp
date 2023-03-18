/**
 * DMOJ - Closing the Farm
 * Temáticas: Estructura de Datos + Disjoint Set
 *
 *  Idea: Saber en cada momento si el grafo es conexo o no sabiendo que existen
 *  granjas que se va a quitar
 */
#include <iostream>
#include <bits/stdc++.h>
#include <algorithm>
#define ENDL '\n'
#define MAX 110
using namespace std;

struct DisjoinSet{

	vector<int> parent,sizes;
	int ncomponents;
	DisjoinSet(int n) : parent(n),sizes(n){
		for(int i = 0; i < n; i++)
			sizes[parent[i] = i] = 1;
		ncomponents = n;
	}

	int root(int x){
		return x == parent[x] ? x : root(parent[x]);
	}

	void join(int a,int b){
		int x = root(a);
		int y = root(b);
		if(x == y)
			return;
		if(sizes[x] < sizes[y])
			swap(x,y);
		parent[y] = x;
		sizes[x] += sizes[y];
		ncomponents--;
	}

};

int main() {

	ios_base::sync_with_stdio(0);
	cin.tie(0);

	cout.setf(ios::fixed, ios::floatfield);
	cout.precision(0);

	int nnodes,npaths;
	cin >> nnodes >> npaths;

	vector<vector<int> > graph(nnodes+1);

		for(int i = 0 ; i <npaths; i++){
			int a,b;
			cin >> a >> b;
			graph[a].push_back(b);
			graph[b].push_back(a);
		}

		vector<int> remove(nnodes+1);
		for(int i = 1; i <= nnodes; i++){
			cin >> remove[i];
		}

		DisjoinSet dsu(nnodes);
		vector<bool> answer(nnodes+1,false),used(nnodes+1,false);
		answer[nnodes] = true;
		used[remove[nnodes]] = true;
		for(int i = nnodes - 1; i >= 1; i--){
			int node = remove[i];
			for(auto x : graph[node])
				if(used[x])
					dsu.join(node,x);
			used[node] = true;
			answer[i] = (dsu.ncomponents == i);
		}

		for(int i = 1; i <= nnodes; i++)
			cout << (answer[i] ? "YES" : "NO") << ENDL;

	return 0;
}
