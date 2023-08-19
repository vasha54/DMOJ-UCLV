/**
 * DMOJ - Mejor Fila Vacuna
 *
 *
 * Idea:
 */
#include <bits/stdc++.h>
#include <math.h>
#define ENDL '\n'
#define OPTIMIZAR_IO ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define PRESICION(x) cout.setf(ios::fixed,ios::floatfield); cout.precision(x);
#define MAX_N 85
#define MOD 1000000007
#define EPS 1e-9
#define INF 1000000000
#define LL long long
#define ULL unsigned long long
#define pii pair<int,int>
#define ALPHABET_SIZE 26 //['a-z']
using namespace std;

int N, ln;

char S[2 * MAX_N];
int o[2][2 * MAX_N], t[2 * MAX_N][2], A[2 * MAX_N], B[2 * MAX_N], C[2 * MAX_N],
		D[2 * MAX_N];

void prnt(char a) {
	if (ln == 80) {
		cout << ENDL;
		ln = 0;
	}
	cout << a;
	ln++;
}

int main() {
	OPTIMIZAR_IO
	//PRESICION(20)
	while (cin >> N) {
		ln = 0;
		for (int i = 0; i < N; i++) {
			cin >> S[i];
			S[N + i] = S[i];
		}
		memset(A, 0, sizeof(A));
		for (int i = 0; i < 2 * N; ++i)
			A[(int) (S[i] - 'A')] = 1;
		for (int i = 1; i < 26; ++i)
			A[i] += A[i - 1];
		for (int i = 0; i < 2 * N; ++i)
			o[0][i] = A[(int) (S[i] - 'A')];
		int x = 0;
		for (int j = 0, jj = 1, k = 0; jj < N && k < 2 * N; ++j, jj <<= 1) {

			memset(A, 0, sizeof(A));
			memset(B, 0, sizeof(B));

			for (int i = 0; i < N; ++i) {
				++A[t[i][0] = o[x][i]];
				++B[t[i][1] = (i + jj < N) ? o[x][i + jj] : 0];
			}

			for (int i = N; i < 2 * N; ++i) {
				++A[t[i][0] = o[x][i]];
				++B[t[i][1] = (i - jj >= N) ? o[x][i - jj] : 0];
			}

			for (int i = 1; i <= 2 * N; ++i) {
				A[i] += A[i - 1];
				B[i] += B[i - 1];
			}

			for (int i = 2 * N - 1; i >= 0; --i)
				C[--B[t[i][1]]] = i;

			for (int i = 2 * N - 1; i >= 0; --i)
				D[--A[t[C[i]][0]]] = C[i];

			x ^= 1;
			o[x][D[0]] = k = 1;
			for (int i = 1; i < 2 * N; ++i)
				o[x][D[i]] = (k += (t[D[i]][0] != t[D[i - 1]][0]
						|| t[D[i]][1] != t[D[i - 1]][1]));

		}
		int i = 0, j = N - 1;
		while (i <= j) {
			if (S[i] < S[j]) {
				prnt(S[i]);
				i++;
			} else if (S[i] > S[j]) {
				prnt(S[j]);
				j--;
			} else if (o[x][i] < o[x][N + j]) {
				prnt(S[i]);
				i++;
			} else {
				prnt(S[j]);
				j--;
			}
		}
		cout << ENDL;
	}
	return 0;
}

