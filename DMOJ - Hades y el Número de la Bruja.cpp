/**
 * DMOJ - Hades y el Número de la Bruja
 * Temática: Programación Dinámica 
 * 
 * Idea: Dada dos secuencias encontrar la cantiddad de veces que esta una cadena como
 * subsecuencia no consecutiva dentro de la otra.
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
#define REP(x) for(int i=1;i<=x;i++)
#define int long long
#define uint unsigned long long
#define PRINT_LINE cout<<ENDL;
#define MAX_N 5*10000010
#define MOD 1000000007
 
using namespace std;
using namespace __gnu_pbds;

string pattern, text;
int npattern, ntext;

int  count(string a, string b){
    int m= a.size();
    int n= b.size();
    int look[m+1][n+1];
    for(int i=0;i<=n;i++) look[0][i]=0;
    for(int i=0;i<=m;i++) look[i][0]=1;
    for(int i=1;i<=m;i++){
        for(int j=1;j<=n;j++){
            if(a[i-1]==b[j-1]) 
                look[i][j]= (look[i-1][j-1]+ look[i-1][j])%MOD;
            else 
                look[i][j]= (look[i-1][j])%MOD;
        }   
    }   
    return look[m][n];
}

signed main()
{
    OPTIMIZAR_IO
    PRESICION(2)
    //READ_FILE
    //WRITE_FILE
    cin>>npattern>>ntext;
    cin>>pattern>>text;
    cout<<count(text,pattern)<<ENDL;
    return 0;
}
