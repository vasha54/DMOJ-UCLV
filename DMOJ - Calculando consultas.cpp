/**
 *  DMOJ - Calculando consultas
 *  Temática: Estructura de Datos + Range Tree .
 *  
 *  Idea: Dada una colección de valores V  un grupo de pregunta Q donde para una
 *  posición p se quiere saber el valor dado un índice p, él desea saber el 
 *  primer número menor que precede al elemento en el índice dado. Si no existe 
 *  este número, imprima -1.
 *
 *  Para resolver el problema vamos a construir un Range Tree que calcule el menor
 *  valor para cualquier rango con la modificación en la operación de consulta donde
 *  una vez que estemos en el rango de busqueda nos vamos a mover al rango derecho
 *  del rango siempre que el valor mínimo de ese rango sea menor que el valor V[p]
 *  en caso contrario nos moveremos en el rango izquierdo. En caso que el menor valor
 *  delrango no sea menor que V[p] podemos parar la búsqueda. 
 * 
 **/
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
#define MAX_N 500010
#define MAX_TREE (MAX_N << 2)
#define MOD  10000
#define pii pair<int,int>
#define mp(x,y) make_pair(x,y) 
#define mid (left+rigth)/2

const int ROW_SPARSE_TABLE = floor(log2(MAX_N) +1 );
 
using namespace std;
using namespace __gnu_pbds;

int values[MAX_N],rt[MAX_TREE], n, querys, pos, value, answer;

void build_tree(int idx, int left, int rigth)
{
	if(left==rigth){
		rt[idx] = values[left];
	}
	else{
		build_tree(2*idx,left,mid);
		build_tree(2*idx+1,mid+1,rigth);
		rt[idx] = min(rt[2*idx],rt[2*idx+1]);
	}
}

int query(int idx, int l,int r, int left, int rigth, int x)
{
	if(rigth < l || r< left) return LONG_MAX;
	
	if (l <= left && rigth <= r) 
	{
		if (rt[idx] >= x) return LONG_MAX;
		
		while (left != rigth) 
		{
			int MID = (left + rigth) / 2;
			if (rt[2 * idx +1 ] < x) {
				idx = 2 * idx + 1;
				left = MID + 1;	
			} else {
				idx = 2 * idx;
				rigth = MID;
			}
		}
		return rt[idx];
	}
	
	int rs = query(2 * idx + 1, l, r, mid + 1, rigth, x);
	if( rs != LONG_MAX) return rs;
	return query(2* idx,l,r,left,mid,x);
}
	


signed main()
{
    OPTIMIZAR_IO
	cin>>n>>querys;
	for(int i=1;i<=n;i++)cin>>values[i];
	
	build_tree(1,1,n);
	
	for(int i=0;i<querys;i++)
	{
		cin>>pos;
		value = values[pos];
		answer = query(1,1,pos-1,1,n,value);
		cout<<( answer == LONG_MAX ? -1: answer )<<ENDL;
	}
    return 0;
}