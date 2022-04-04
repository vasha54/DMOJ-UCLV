//============================================================================
// Name        : 3317.cpp
// Author      : Vasha
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <stdio.h>
#include <memory.h>
#define MOD 1000000007
#define MAX 1000040
using namespace std;

unsigned long long ways[MAX];
int cases,feet;


void preCalculate()
{
	memset(ways,0,sizeof(ways));
	ways[1]=1;
	ways[2]=1;
	for(int i=1;i<MAX-2;i++)
	{
		ways[i+1]+=ways[i];
		ways[i+2]+=ways[i];
		ways[i+1]=ways[i+1]%MOD;
		ways[i+2]=ways[i+2]%MOD;
	}
}

int main()
{
	//freopen("Input.txt","r",stdin);
	preCalculate();
	while(scanf("%d",&cases)!=EOF)
	{
		while(cases--)
		{
			scanf("%d",&feet);
			printf("%lld\n",ways[feet]);
		}
	}
	return 0;
}