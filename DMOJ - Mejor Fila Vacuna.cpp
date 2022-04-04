//============================================================================
// Name        : COJCPP.cpp
// Author      : Lavalido
// Version     : DMOJ - Mejor Fila Vacuna
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
#include <stdio.h>
#include <memory.h>
#include <math.h>
#include <algorithm>
#include <list>
#include <queue>
#include <map>
#include <string>
#include <vector>
#include <strings.h>
#include <set>
using namespace std;
#define ENDL '\n'
#define MAXN 500050
#define ULL unsigned long long

int N,ln;

char S[2*MAXN];
int o[2][2*MAXN], t[2*MAXN][2], A[2*MAXN], B[2*MAXN], C[2*MAXN], D[2*MAXN];

void prnt(char a) {
  if(ln==80)
    {
      cout<<ENDL;
      ln=0;
    }
  cout<<a;
  ln++;
}

int main() {

  //freopen("Input.txt","r",stdin);
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  while(cin>>N)
    {
      ln=0;
      for(int i=0;i<N;i++)
        {
          cin>>S[i];
          S[N+i] = S[i];
        }
      memset(A, 0, sizeof(A));
      for (int i = 0; i < 2*N; ++i) A[(int)(S[i]-'A')] = 1;
      for (int i = 1; i < 26; ++i) A[i] += A[i-1];
      for (int i = 0; i < 2*N; ++i) o[0][i] = A[(int)(S[i]-'A')];
      int x=0;
      for (int j = 0,  jj = 1,k = 0; jj < N && k < 2*N; ++j, jj <<= 1) {

          memset(A, 0, sizeof(A));
          memset(B, 0, sizeof(B));

          for (int i = 0; i < N; ++i) {
              ++A[ t[i][0] = o[x][i] ];
              ++B[ t[i][1] = (i+jj<N) ? o[x][i+jj] : 0 ];
          }

          for (int i = N; i < 2*N; ++i) {
              ++A[ t[i][0] = o[x][i] ];
              ++B[ t[i][1] = (i-jj>=N) ? o[x][i-jj] : 0 ];
          }

          for (int i = 1; i <= 2*N; ++i) {
              A[i] += A[i-1];
              B[i] += B[i-1];
          }

          for (int i = 2*N-1; i >= 0; --i)
            C[--B[t[i][1]]] = i;

          for (int i = 2*N-1; i >= 0; --i)
            D[--A[t[C[i]][0]]] = C[i];

          x ^= 1;
          o[x][D[0]] = k = 1;
          for (int i = 1; i < 2*N; ++i)
            o[x][D[i]] = (k += (t[D[i]][0] != t[D[i-1]][0] || t[D[i]][1] != t[D[i-1]][1]));

      }
      int i=0,j=N-1;
      while(i<=j) {
          if(S[i]<S[j])           {prnt(S[i]);i++;}
          else if(S[i]>S[j])      {prnt(S[j]);j--;}
          else if(o[x][i]<o[x][N+j]) {prnt(S[i]);i++;}
          else {prnt(S[j]);j--;}
      }
      cout<<ENDL;
    }


  return 0;
}