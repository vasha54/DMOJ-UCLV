/**
 * DMOJ - Finding a Centroid
 * 
 * Temática: Estructura de datos +  Centroide de un árbol
 * 
 * Idea: Dado un árbol encontrar uno de los nodos centroide de este. Con aplicar
 * cualquiera de los algoritmos conocidos es suficiente. Se puede imprimir cualquiera
 * de los centroides en caso de existir varios.
 */ 
#include <bits/stdc++.h>
#include <bitset>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
 
#define ENDL '\n'
#define OPTIMIZAR_IO ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define PRESICION(x) cout.setf(ios::fixed,ios::floatfield); cout.precision(x);
#define READ_FILE freopen("Input.txt","r",stdin);
#define WRITE_FILE freopen("Output.txt","w",stdout);
#define REP_INDEX_1(x) for(int i=1;i<=x;i++)
#define REP_INDEX_0(x) for(int i=0;i<x;i++)
#define int long long
#define uint unsigned long long
#define PRINT_LINE cout<<ENDL;
#define MAX_N 200010
#define MAX_TREE (MAX_N << 2)
#define MOD  1000000007
#define pii pair<int,int>
#define mp(x,y) make_pair(x,y) 
 
const int ROW_SPARSE_TABLE = floor(log2(MAX_N) +1 );
 
using namespace std;
using namespace __gnu_pbds;
 
const int N = 200001;
vector<int> g[N];
int sz[N], max_child[N];
int n;

void dfs(int node, int parent) {
    sz[node] = 1;
    for (int child : g[node]) {
        if (child == parent) continue;
        dfs(child, node);
        sz[node] += sz[child];
        max_child[node] = max(max_child[node], sz[child]);
    }
}

int centroid(int node, int parent, int above) {
    if (max(above, max_child[node]) <= n / 2) {
        return node;
    }
    for (int child : g[node]) {
        if (child == parent) continue;
        int ans = centroid(child, node, above + sz[node] - sz[child]);
        if (ans != -1) return ans;
    }
    return -1;
}

 
signed main()
{
    OPTIMIZAR_IO
    PRESICION(2)
    //READ_FILE
    //WRITE_FILE
	cin >> n;

    for (int i = 1; i <= n - 1; ++i) {
        int a, b;
        cin >> a >> b;
        g[a].push_back(b);
        g[b].push_back(a);
    }

    dfs(1, -1);

    cout << centroid(1, -1, 0) << ENDL;
    return 0;
}