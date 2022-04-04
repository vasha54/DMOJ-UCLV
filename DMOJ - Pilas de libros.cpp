/*
 ============================================================================
 Name        : DMOJ - Pilas de libros
 Author      : Vasha
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>
#define MAX 55
int piles[MAX][MAX],N,nVisible,i,j,maxH;
short visible[MAX][MAX];

void viewHorizontal()
{
	for(i=0;i<N;i++)
	{
		maxH=0;
		for(j=0;j<N;j++)
		{
			if(maxH<piles[i][j])
			{
				maxH=piles[i][j];
				visible[i][j]=1;
			}
		}
	}
	for(i=N-1;i>=0;i--)
	{
		maxH=0;
		for(j=N-1;j>=0;j--)
		{
			if(maxH<piles[i][j])
			{
				maxH=piles[i][j];
				visible[i][j]=1;
			}
		}
	}
}

void viewVertical()
{
	for(i=0;i<N;i++)
	{
		maxH=0;
		for(j=0;j<N;j++)
		{
			if(maxH<piles[j][i])
			{
				maxH=piles[j][i];
				visible[j][i]=1;
			}
		}
	}


	for(i=N-1;i>=0;i--)
	{
		maxH=0;
		for(j=N-1;j>=0;j--)
		{
			if(maxH<piles[j][i])
			{
				maxH=piles[j][i];
				visible[j][i]=1;
			}
		}
	}
}

int main(void)
{
	//freopen("Input.txt","r",stdin);
	while(scanf("%d",&N)!=EOF)
	{
		for( i=0;i<N;i++)
		{
			for(j=0;j<N;j++)
			{
				visible[i][j]=0;
				scanf("%d",&piles[i][j]);
			}
		}

		nVisible=0;
		viewHorizontal();
		viewVertical();
		for(i=0;i<N;i++)
		{
			for(j=0;j<N;j++)
			{
				if(visible[i][j])
				{
					nVisible++;
				}
			}
		}
		printf("%d\n",nVisible);
	}
	return EXIT_SUCCESS;
}