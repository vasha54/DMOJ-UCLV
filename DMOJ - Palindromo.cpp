//DMOJ - Palindromo
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
#define MOD 1000000007
#define MAX 30
#define ULL unsigned long long
#define ENDL '\n'
using namespace std;

int cases,letters[MAX],length;

string input,outputA,outputB,center;

int main()
{
    //freopen("Input.txt","r",stdin);
	//cout.setf(ios::fixed,ios::floatfield);
	//cout.precision(2);
	ios_base::sync_with_stdio(0);
	std::cin.tie(0);
	while(cin>>cases)
	{
	    while(cases--)
	    {
	        cin>>length;
	        cin>>input;
	        fill(letters,letters+MAX,0);
	        for(int i=0;i<length;i++)
	        {
	            letters[input[i]-'A']++;
	        }
	        
	        outputA="";
	        outputB="";
	        center="";
	        for(int i='A'-'A';i<='Z'-'A';i++)
	        {
	            while(letters[i]>=2)
	            {
	                outputA=outputA+char(i+'A');
	                outputB=char(i+'A')+outputB;
	                letters[i]-=2;
	            }
	        }
	        
	        for(int i='A'-'A';i<='Z'-'A' && center=="";i++)
	            if(letters[i])
	                center=char(i+'A');
	        
	        cout<<outputA<<center<<outputB<<ENDL;
	    }
	}
    return 0;
}