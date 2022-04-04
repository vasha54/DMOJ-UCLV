//============================================================================
// Name        : DMOJ Conociendo a Miguel
// Author      : Vasha
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <stdio.h>
#include <math.h>
//#include <stdlib.h>
//#include <list>
//#include <queue>
//#include <stack>
//#include <deque>
#include <vector>
//#include <set>
//#include <map>
#include <algorithm>
#include <string>
#include <string.h>
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
#define MAXN 27000
//#define MAX 1000000000001
#define MOD  1000000007
//#define MIN -10000100
//#define POW32 2147483648
using namespace std;

//int MR[] = { 1, -1, 0, 0, 1, -1, 1, -1, -2, -2, -1, 1, 2, 2, 1, -1, 0, 0, 2, 3,
//		0, 0, -2, -3 };
//int MC[] = { 0, 0, 1, -1, 1, -1, -1, 1, -1, 1, 2, 2, 1, -1, -2, -2, 2, 3, 0, 0,
//		-2, -3, 0, 0 };

int matriz_old[30][30], matriz_young[30][30], n_street, energy, min_energy,size;
char type_street[2], direction[2], city1[2], city2[2], begin[2], end[2];
vector<char> places;
int main() {

//	freopen("Input.txt", "r", stdin);
	while (1) {
		scanf("%d", &n_street);
		if (n_street == 0)
			break;
		for (int i = 0; i < 30; i++) {
			for (int j = 0; j < 30; j++) {
				matriz_old[i][j] = matriz_young[i][j] = MAXN;
				if (i == j)
					matriz_old[i][j] = matriz_young[i][j] = 0;
			}
		}
		for (int k = 0; k < n_street; k++) {
			scanf("%s%s%s%s%d\n", type_street, direction, city1, city2,
					&energy);
			if (type_street[0] == 'Y') {
				if (matriz_young[city1[0] - 'A'][city2[0] - 'A'] > energy)
					matriz_young[city1[0] - 'A'][city2[0] - 'A'] = energy;
				if (direction[0] == 'B'
						&& matriz_young[city2[0] - 'A'][city1[0] - 'A']
								> energy)
					matriz_young[city2[0] - 'A'][city1[0] - 'A'] = energy;
			} else if (type_street[0] == 'M') {
				if (matriz_old[city1[0] - 'A'][city2[0] - 'A'] > energy)
					matriz_old[city1[0] - 'A'][city2[0] - 'A'] = energy;
				if (direction[0] == 'B'
						&& matriz_old[city2[0] - 'A'][city1[0] - 'A'] > energy)
					matriz_old[city2[0] - 'A'][city1[0] - 'A'] = energy;
			}
		}
		scanf("%s%s\n", begin, end);
		for (int i = 'A' - 'A'; i <= 'Z' - 'A'; i++)
			for (int j = 'A' - 'A'; j <= 'Z' - 'A'; j++)
				for (int k = 'A' - 'A'; k <= 'Z' - 'A'; k++) {
					if (i != j && j != k && i != k) {
						matriz_old[i][j] = min(matriz_old[i][j],
								matriz_old[i][k] + matriz_old[k][j]);
						matriz_young[i][j] = min(matriz_young[i][j],
								matriz_young[i][k] + matriz_young[k][j]);
					}
				}

		min_energy = MAXN;

		for (int k = 'A' - 'A'; k <= 'Z' - 'A'; k++) {
			if (min_energy
					> matriz_young[begin[0] - 'A'][k]
							+ matriz_old[end[0] - 'A'][k]) {
				min_energy = matriz_young[begin[0] - 'A'][k]
						+ matriz_old[end[0] - 'A'][k];
				places.clear();
				places.push_back(k + 'A');
			} else if (min_energy
					== matriz_young[begin[0] - 'A'][k]
							+ matriz_old[end[0] - 'A'][k]) {
				places.push_back(k + 'A');
			}
		}
		sort(places.begin(),places.end());
		if (min_energy != MAXN) {
			printf("%d ", min_energy);
			size=places.size();
            for(int i=0;i<size-1;i++)
            	printf("%c ",places.at(i));
            printf("%c\n",places.back());
		} else
			puts("You will never meet.");
		places.clear();
	}

	return 0;
}