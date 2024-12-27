// DMOJ Numeros de Humble
#include <stdio.h>
#include <vector>
using namespace std;

int K,N,pset_number_prime[110],pos;
double set_number_prime[110],minimo_humble;

vector<double> humble_Numbers;
vector<int> indexs;
int main()
{
    //freopen("Input.txt","r",stdin);
    while(scanf("%d%d",&K,&N)!=EOF){
          for(int i=0;i<K;i++){
             scanf("%lf",&set_number_prime[i]);
             pset_number_prime[i]=0;
            }
          humble_Numbers.push_back(1);
          while(humble_Numbers.size()<=N+2){
                minimo_humble=set_number_prime[0]*humble_Numbers[pset_number_prime[0]];
                pos=0;
                for(int i=1;i<K;i++){
                    if(minimo_humble>set_number_prime[i]*humble_Numbers[pset_number_prime[i]]){
                        minimo_humble=set_number_prime[i]*humble_Numbers[pset_number_prime[i]];
                        pos=i;
                        indexs.clear();
                      }
                     else if(minimo_humble==set_number_prime[i]*humble_Numbers[pset_number_prime[i]])
                        indexs.push_back(i);
                    }
                humble_Numbers.push_back(minimo_humble);
                pset_number_prime[pos]++;
                while(!indexs.empty()){
                      pset_number_prime[indexs.back()]++;
                      indexs.pop_back();
                    }
              }
            printf("%.0lf\n",humble_Numbers[N]);
            humble_Numbers.clear();
        }
    return 0;
}