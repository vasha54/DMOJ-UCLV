 /**
 * DMOJ - Completa la Cadena  
 * Temática: Pila
 * 
 * Idea: Simular el proceso con una pila donde voy metiendo cuando los simbolos son de 
 * apertura y los voys cando cuando don de cierre el simbolo que quede en el tope de la pila
 * su simbolo opuesto será la respuesta
 */ 
#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>

#define ENDL '\n'
#define OPTIMIZAR_IO ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define PRESICION(x) cout.setf(ios::fixed,ios::floatfield); cout.precision(x);
 
#ifdef LOCAL
    #define READ_FILE freopen("Input.txt","r",stdin);
    #define WRITE_FILE freopen("Output.txt","w",stdout);
#else
    #define READ_FILE 
    #define WRITE_FILE 
#endif
#define REP(x) for(int i=1;i<=x;i++)
#define int long long
#define uint unsigned long long
#define PRINT_LINE cout<<ENDL;
#define MAX_N 200010
#define MAX_TREE MAX_N << 2
#define MOD  1000000007
#define MID (right+left)/2
 
using namespace std;
using namespace __gnu_pbds;

// int values[MAX_N];
// int rt[MAX_TREE];
// int rtP[MAX_TREE];
// int n, nquerys, rooms;

// void build(int indx, int left, int right){
// 	if(left == right){
// 		rt[indx] = values[left];
// 		rtP[indx] = left;
// 	}
// 	build(indx*2, left, MID);
// 	build(indx*2+1, MID+1, right);
// 	rt[indx] = max(rt[indx*2],rt[indx*2+1]);
// 	if(rt[indx] == rt[indx*2]) rtP[indx] = rtP[indx*2];
// 	else rtP[indx] = rtP[indx*2+1];
// }

// void update(int indx, int pos, int _v, int left, int right){
// 	if(left == right){
// 		rt[indx] = _v;
// 		rtP[indx] = pos;
	
// 	}
// 	else{
// 		if(pos<= MID) update(indx*2,pos,_v,left,MID);
// 		else update(indx*2+1, pos, _v, MID+1, right);
// 		rt[indx] = max(rt[indx*2],rt[indx*2+1]);
// 		rtP[indx] = 
// 	}	
// }

// int query(int indx, int _v, int left, int right){

// }

signed main()
{
    OPTIMIZAR_IO
    //PRESICION(2)
    READ_FILE
    //WRITE_FILE
    string line;
	cin>>line;
	stack<char> next;
	for(auto x: line){
		if(x=='(' or x=='{' or x=='[') next.push(x);
		else next.pop();
	}
	char y= next.top();
	if(y=='(') cout<<')'<<ENDL;
	else if(y=='[') cout<<']'<<ENDL;
	else if(y=='{') cout<<'}'<<ENDL;
    return 0;
}

