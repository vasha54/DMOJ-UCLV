// DMOJ - Clasificando Palíndromos
// Cadena : KMP(Leer Manual) para una idea bien kamikaze
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
#include <list>
#define MID (left+right)/2
#define MOD 1000000007
#define MAX 1010
#define MAXTREE (MAX << 2)
#define LIMIT 1000010
#define INF 987654321
#define ULL unsigned long long
#define LL long long
#define ENDL '\n'
#define SYMBOL '#'
#define REP(i,n) for(int i=0;i<(int)n;++i)
#define REP1_N(i,n) for(int i=1;i<=(int)n;++i)
#define REPN_1(i,n) for(int i=(int)n;i>=1;--i)
#define FOR(i,c) for(__typeof((c).begin())i=(c).begin();i!=(c).end();++i)
#define ALL(c) (c).begin(), (c).end()
#define LINE_BLANK cout<<ENDL;
#define NEXT( x,n ) ( ( (x) + 1 ) % n )
#define PI 3.1415927

using namespace std;

int cases;
string word;

bool isPalindrome(string _word)
{
    string t=_word;
    reverse(t.begin(),t.end());
    return (t==_word);
}

vector<int> KMP(string _text, string _pattern)
{
    vector<int> matches;

    int * P=new int[MAX];

    int n_pattern=_pattern.size();
    int n_text=_text.size();
    for (int i=0;i<n_pattern;i++)
         P[i] =-1;
    for (int i=0,j=-1;i<n_pattern;)
    {
         while (j>-1 && _pattern[i]!=_pattern[j])
            j=P[j];
         i++;
         j++;

         P[i]=j;
    }

    for (int i=0, j=0;i<n_text;)
    {
         while (j>-1 && _text[i]!=_pattern[j])
            j=P[j];
         i++;
         j++;
         if (j == n_pattern)
         {
             matches.push_back(i - n_pattern);
             j = P[j];
         }
     }
     return matches;
}

bool isBiPalindrome(string _word)
{
   string pattern;
   pattern.push_back(_word[0]);
   pattern.push_back(_word[_word.size()-1]);

   vector<int> kmp=KMP(_word,pattern);

   bool is=kmp.size();

   if(is)
   {
     is=false;
     int length=kmp.size();
     for( int i=0;i<length && !is ;i++)
     {
        int tIndex=kmp[i];
        string a=_word.substr(0,tIndex+1);
        string b=_word.substr(tIndex+1);
        is=( isPalindrome(a) & isPalindrome(b));
     }

   }
   return is;
}

int main()
{
	//freopen ("Input.txt","r",stdin );
	//freopen ("Output.txt","w",stdout);
	cout.setf (ios::fixed ,ios::floatfield );
	cout.precision (4) ;
	ios_base::sync_with_stdio(0);
	std::cin.tie(0);

    while(cin>>cases)
    {
        while(cases--)
        {
            cin>>word;
            if( isPalindrome(word))
                cout<<"palindrome"<<ENDL;
            else if(isBiPalindrome(word))
                cout<<"bi-palindrome"<<ENDL;
            else
                cout<<"non-palindrome"<<ENDL;
        }
    }

	return 0;
}