//2249 - Curious Robin Hood
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
#define MOD 1000003
#define MAX 100010
#define LIMIT 9223372036854775807
#define INF 1000000000010
#define ULL unsigned long long
#define LL long long
#define ENDL '\n'
#define SYMBOL '#'

using namespace std;

struct fenwick_tree 
{
   vector <int> x;
   fenwick_tree (int n): x (n, 0){}
   
   ULL sum (int i, int j) 
   {
     if (i == 0) 
     {
       ULL S = 0;
       for (j; j>=0;j=(j&(j+1))-1) 
        S+=x[j];
       return S;
     } 
     else return sum (0, j) - sum (0, i-1);
   }
   
   void add (int k, int a) 
   {
     for (; k <x.size (); k|=k+1) x[k]+=a;
   }
   
 };
 

int cases,N,queries,values[MAX],type_querie,indexs,value,indexsB;
fenwick_tree * tree;

int main()
{
	//freopen("Input.txt","r",stdin);
	
	cout.setf(ios::fixed,ios::floatfield);
	cout.precision(7);
	ios_base::sync_with_stdio(0);
	std::cin.tie(0);
	while(cin>>cases)
	{
	    for(int i=1;i<=cases;i++)
	    {
	        cin>>N>>queries;
	        tree=new fenwick_tree(N);
	        for(int k=0;k<N;k++)
	        {
	            cin>>values[k];
	            tree->add(k,values[k]);
	        }
	        cout<<"Case "<<i<<":"<<ENDL;
	        while(queries--)
	        {
	            cin>>type_querie;
	            switch(type_querie)
	            {
	                case 1:
	                    cin>>indexs;
	                    tree->add(indexs,-values[indexs]);
	                    cout<<values[indexs]<<ENDL;
	                    values[indexs]=0;
	                break;
	                case 2:
	                    cin>>indexs>>value;
	                    tree->add(indexs,value);
	                    values[indexs]+=value;
	                break;
	                case 3:
	                    cin>>indexs>>indexsB;
	                    cout<<tree->sum(min(indexs,indexsB),max(indexs,indexsB))<<ENDL;
	                break;
	            }
	        }
	    }
	}
	return 0;        
}