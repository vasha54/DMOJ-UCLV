//============================================================================
// Name        : COJCPP.cpp
// Author      : Lavalido
// Version     : 2002 - Cows in a Row
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
#define MAX_ELEMENT 1010
#define ULL unsigned long long

int N,last,max_continous,tContinous,key,cow,cows[MAX_ELEMENT];
set<int> keys;

int main() {

  //freopen("Input.txt","r",stdin);
  ios_base::sync_with_stdio(false);
  cin.tie(0);

  while(cin>>N)
    {
      for(int i=0;i<N;i++)
        {
          cin>>cow;
          cows[i]=cow;
          keys.insert(cow);
        }
      max_continous=0;
      set<int>::iterator it=keys.begin();

      while(it!=keys.end())
        {
          key=(*it);
          tContinous=0;
          last=-1;
          for(int i=0;i<N;i++)
            {
              if(cows[i]!=key)
                {
                  if(cows[i]==last )
                    tContinous++;
                  else if(cows[i]!=last)
                    {
                      max_continous=max(max_continous,tContinous);
                      tContinous=1;
                      last=cows[i];
                    }
                }
            }
          max_continous=max(max_continous,tContinous);
          it++;
        }

      cout<<max_continous<<ENDL;
      keys.clear();
    }

  return 0;
}
