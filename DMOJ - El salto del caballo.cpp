//DMOJ - El salto del caballo
//Teoría de grafos : BFS sobre tablero.
#include <iostream>
#include <vector>
#include <algorithm>
#include <stdio.h>
#include <math.h>
#include <stack>
#include <set>
#include <list>
#include <queue>
#include <string>
#include <string.h>
#include <map>
#include <complex>
#include <cmath>
#include <bitset>
#include <cstdlib>
#define MID (left+right)/2
#define MODULO 1000000007
#define MAX 10
#define MIN MAX*(-1)
#define MAXTREE (MAX << 2)
#define LIMIT 2000000010
#define ULL unsigned long long
#define LL long long
#define ENDL '\n'
#define SYMBOL '#'
#define REP(i,n) for(int i=0;i<(int)n;++i)
#define REP1_N(i,n) for(int i=1;i<=(int)n;++i)
#define FOR(i,c) for(__typeof((c).begin())i=(c).begin();i!=(c).end();++i)
#define ALL(c) (c).begin(), (c).end()
#define LINE_BLANK cout<<ENDL;
using namespace std;

struct Cell
{
	int row;
	int column;
	
	Cell(int _r=0,int _c=0)
	{
		row=_r;
		column=_c;
	}
};

istream & operator >> (istream &stream , Cell&_obj)
{
    stream>>_obj.column>>_obj.row;
	return stream ;
}

Cell startCell, endCell;

bool board[MAX][MAX];

int mov_r[]={ 1, 1, 2, 2};
int mov_c[]={-2, 2,-1, 1};

bool isValid(int _row, int _column)
{
	return (1<=_row && _row<=8 && 1<=_column && _column<=8);
}

void resetBoard()
{
	REP(i,MAX)
		REP(j,MAX)
			board[i][j]=false;
}

void bfs()
{
	queue<Cell> visit;
	board[startCell.row][startCell.column]=true;
	visit.push(startCell);
	Cell nextCell, atCell;
	
	while(!visit.empty())
	{
		atCell=visit.front();
		visit.pop();
		
		REP(i,4)
		{
			nextCell=Cell(atCell.row+mov_r[i],atCell.column+mov_c[i]);
			if(isValid(nextCell.row,nextCell.column) && 
			   board[nextCell.row][nextCell.column]==false)
			{
				board[nextCell.row][nextCell.column]=true;
				visit.push(nextCell);
			}
		}
	}
}

int main()
{
	//freopen ("Input.txt","r",stdin );
	//freopen ("Output.txt","w",stdout );
	    
	cout.setf (ios::fixed ,ios::floatfield );
	cout.precision (2) ;
	ios_base::sync_with_stdio(0);
	std::cin.tie(0);
	
	while(cin>>startCell)
	{
		cin>>endCell;
		resetBoard();
		bfs();
		cout<< (board [endCell.row][endCell.column] ?  "yes" : "no" );
		LINE_BLANK;
	}
	
	return 0;
}