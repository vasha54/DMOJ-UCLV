//DMOJ - Repartiendo caramelos
//Greedy - Busquenada binaria
#include <iostream>
#include <algorithm>
#include <stdio.h>
#include <vector>
#include <math.h>
#include <memory.h>
#include <deque>
#include <stack>
#include <queue>
#include <set>
#define MID (left+right)/2
#define MOD 1000000007
#define MAX 100010
#define MARK 1000010
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
#define IS_BRIDGE(a,b) cout<<"{"<<a<<","<<b<<"}"<<ENDL
#define INF 100000000
#define ROW 110
#define COLUMN 110
#define OPERATOR_INC "++"
#define OPERATOR_DEC "--"
using namespace std;

int nboys;
LL request[MAX],sweets,limitSweets,lLeft,lRigth,pivot, answer;


/*Esta funcion me comprueba para un valor dado x buscar aquellos niños 
 * que quieren una cantidad de caramelos mayor que x por cada uno ellos
 * voy sumando con cuanto caramelos se quedarían los niños si doy ese valor
 * x. Si dicha suma es menor  o igual que la cantidad  de caramelos retorno
 * verdadero sino retorno falso 
 * */
bool check(LL _x){
    LL sum =0;
    for(int i=nboys-1;i>=0 ;--i){
        if(request[i]>_x)
           sum+=(request[i]-_x);
    }
    return (sum<=sweets);
}

int main(){
	#ifndef ONLINE_JUDGE
	    // freopen("Input.txt","r",stdin);
	     //freopen("Output.txt","w",stdout);
	#endif
	cout.setf(ios::fixed,ios::floatfield);
	cout.precision(1);
	ios_base::sync_with_stdio(0);
	std::cin.tie(0);

    while( cin>>sweets>>nboys ){
        REP(i,nboys)
          cin>>request[i];

        /*ordeno las peticiones de caramelos de forma ascedentemente*/ 
        sort(request,request+nboys);

        /*establezco el limite de dulce a quitar*/ 
        limitSweets = request[nboys-1];

        lLeft=0;
        lRigth=limitSweets;

        /*busqueda binaria modificada buscando el menor posible*/
        while(lLeft<=lRigth){
            pivot = (lLeft+lRigth)/2;
            if(check(pivot)){
                limitSweets = min(pivot,limitSweets);
                lRigth=pivot-1;
            }else{
                lLeft=pivot+1;
            }

        }

        /*Una vez que encontre dicho valor comienzo a dar esa cantidad 
         * a cada muchacho siempre que pida una cantidad mayor y tenga
         * dulces disponibles*/ 
        for(int i=nboys-1;i>=0 && sweets>=0;--i){
            if( request[i]>limitSweets && request[i]-limitSweets<=sweets){
               sweets-=(request[i]-limitSweets);
               request[i]=limitSweets;
            }
        }

        /*mientras tenga dulces los voy repartiendo de forma equilibrada
         * empienzo por el fondo como el arreglo esta ordenado lo que mas
         * piden estan en el fondo. La repartición se forma que el arreglo
         * de peticiones siempre este ordenado. */
        while( sweets ){
          if( request[nboys-1] > 0){
            request[nboys-1]--;
            sweets--;
            }
          for(int i =nboys-2;i>=0 && sweets;--i){
              if( request[i] <= request[i+1])
                 continue;
              sweets--;
              request[i]--;
              ++i;
          }
        }
        
        /*Ya aqui veo la cantidad de caramelos que me quedaron por 
         * repatir por cada niño para determinar la solución*/
        answer= 0;
        REP(i,nboys)
          answer+=(request[i]*request[i]);

        cout<<answer<<ENDL;
    }

  return 0;
}
