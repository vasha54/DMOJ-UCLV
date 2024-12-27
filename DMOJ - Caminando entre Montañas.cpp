//============================================================================
// Name        : Jugde.cpp
// Author      : Vasha
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <stdio.h>
//#include <math.h>
//#include <stdlib.h>
//#include <list>
//#include <queue>
//#include <stack>
//#include <deque>
//#include <vector>
//#include <set>
//#include <map>
//#include <algorithm>
//#include <string>
//#include <string.h>
//#include <memory.h>
//#include <iostream>
//#include <utility>

//int PP, SIGN, IEOF;
//#define VALID(ch) (ch != ' ' && ch != '\t' && ch != '\r' && ch != '\n' && ch != EOF)
//#define GETCHAR(ch) { ch = getchar_unlocked(); }
//#define PUTCHAR(ch) { putchar_unlocked(ch); }
//#define GETNUMBER(n) { \
//     register char ch = 0; n = 0; SIGN = 1; \
//     while(IEOF != EOF && (ch < 33 || ch == '-')) { if(ch == EOF) IEOF = EOF; if(ch == '-') SIGN = -1; GETCHAR(ch) } \
//     while(IEOF != EOF && ch > 33) { n = ((n << 1) + (n << 3) + (ch - '0')); GETCHAR(ch) } \
//     if(ch == EOF) IEOF = EOF; \
//     n *= SIGN; \
// }
//#define GETWORD(buffer) { \
//     register char ch; \
//     PP = 0; \
//     do { GETCHAR(ch); if(VALID(ch)) buffer[PP++] = ch; else { buffer[PP] = '\0'; if(ch == EOF) IEOF = EOF; } } while(VALID(ch)); \
// }
//#define PUTWORD(buffer, ch) { \
//     PP = 0; \
//     while(buffer[PP]) { PUTCHAR(buffer[PP++]); } \
//     PUTCHAR(ch); \
// }
//#define INF 1E10
//#define EPS 1E-10
//#define ERROR 1e-15
//#define maxi(a,b) (a>b?a:b)
#define mini(a,b) (a>b?b:a)
#define REP(i,begin,end) for(int i=begin;i<(int)end;++i)
#define MAXN 1000000
//#define MOD  1000000007
//#define MIN -10000100
#define ELEMENT 25
//#define POW32 2147483648
//
int MR[] = { 1, -1, 0, 0, 1, -1, 1, -1, -2, -2, -1, 1, 2, 2, 1, -1, 0, 0, 2, 3,
		0, 0, -2, -3 };
int MC[] = { 0, 0, 1, -1, 1, -1, -1, 1, -1, 1, 2, 2, 1, -1, -2, -2, 2, 3, 0, 0,
		-2, -3, 0, 0 };
using namespace std;

int dimensions, x, y, heights[ELEMENT][ELEMENT], calories[ELEMENT][ELEMENT],
		lentgh, top, left, pivot;
bool visit[ELEMENT][ELEMENT];
char line[ELEMENT];

int main() {

	//freopen("Input.txt", "r", stdin);
	while (scanf("%d\n", &dimensions) != EOF) {
		REP(i,1,dimensions+1)
		{
			scanf("%s",line);
			pivot = 1;
			REP(j,0,dimensions)
			{
				heights[i][pivot] = line[j] - '0';
				calories[i][pivot++] = MAXN;

			}
		}
		scanf("%d%d", &x, &y);


		calories[1][1] = 0;
		REP(i,2,dimensions+1)
			if (heights[1][i - 1] >= heights[1][i])
				calories[1][i] = calories[1][i - 1];
			else
				calories[1][i] = calories[1][i - 1]
						+ (heights[1][i] - heights[1][i - 1]);
		REP(i,2,dimensions+1)
			if (heights[i - 1][1] >= heights[i][1])
				calories[i][1] = calories[i - 1][1];
			else
				calories[i][1] = calories[i - 1][1]
						+ (heights[i][1] - heights[i - 1][1]);
		REP(i,2,dimensions+1)
		{
			REP(j,2,dimensions+1)
			{
				heights[i][j] <= heights[i][j - 1] ?
						left = calories[i][j - 1] :
						left = calories[i][j - 1]
								+ (heights[i][j] - heights[i][j - 1]);
				heights[i][j] <= heights[i - 1][j] ?
						top = calories[i - 1][j] :
						top = calories[i - 1][j]
								+ (heights[i][j] - heights[i - 1][j]);
				calories[i][j] = mini(top,left);
			}
		}
		printf("%d\n", calories[x][y]);
	}
	return 0;
}
