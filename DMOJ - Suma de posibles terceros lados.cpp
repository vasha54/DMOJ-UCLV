/**
 * DMOJ - Suma de posibles terceros lados
 * Tema: Matemáticas + Geometría
 *
 * Idea: Dados dos enteros positivos A y B, la suma de todos los posibles enteros C
 * tales que A, B y C forman un triángulo no degenerado es (2*min(A,B)-1)*max(A,B).
 * Esto se deduce de la desigualdad triangular |A-B| < C < A+B. Los valores de C
 * forman una progresión aritmética desde |A-B|+1 hasta A+B-1, cuya suma se simplifica
 * a la expresión anterior.
 */
#include <bits/stdc++.h>

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
#define pii pair<int,int>
#define tiii tuple<int,int,int>
#define MAX_N 1010
#define MAX_TREE MAX_N << 2
#define MOD  1000000007
#define MID (right+left)/2

using namespace std;

signed main() {
    OPTIMIZAR_IO
    //PRESICION(2)
    READ_FILE
    //WRITE_FILE
    int A,B;
	cin>>A>>B;
	int m = min(A,B);
	int M = max(A,B);
	int sum = M * (2 * m - 1);
    cout << sum << ENDL;
    return 0;
}