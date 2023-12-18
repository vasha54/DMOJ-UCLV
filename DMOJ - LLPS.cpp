/**
* DMOJ - LLPS
* Temática: Mascara de bits + Ordenamiento + Palindrome
* Idea: Dada una cadena a lo sumo de 10 caracteres generar todas las posibles subsecuencias
* no necesariamente consecutivas   ver de aquellas que son palindromes cual  es mayor lexigraficamente
*/
#include <iostream>
#include <math.h>
#include <bits/stdc++.h>
#define ENDL '\n'
#define OPTIMIZAR_IO ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define PRESICION(x) cout.setf(ios::fixed,ios::floatfield); cout.precision(x);
#define READ_FILE freopen("Input.txt","r",stdin);
#define WRITE_FILE freopen("Output.txt","w",stdout);
#define MAX_N 1005
#define MOD 1000000007
#define EPS 1e-9
#define INF 1000000000
#define int long long
#define uint unsigned long long
#define pii pair<int,int>
#define ALPHABET_SIZE 26 //['a-z']
using namespace std;

string input,subsequence;
vector<string> palindromes;
int ninput;

bool isPalindrome(string t){
    bool is =true;
    int r= t.size()-1;
    int l = 0;

    while(l<=r && is){
        is = ( t[l]!=t[r] ? false:is);
        r--;
        l++;
    }
    return is;
}

signed main(){
    OPTIMIZAR_IO
    PRESICION(0)
    //READ_FILE

    cin>>input;
    ninput = input.size();
    palindromes.clear();

    for(int i=1;i<(1<<ninput);i++){
        subsequence.clear();
        for(int j=0;j<ninput;j++){
            if(i & (1<<j)) subsequence.push_back(input[j]);
        }
        if( isPalindrome(subsequence) && !subsequence.empty())
            palindromes.push_back(subsequence);
    }

    sort(palindromes.begin(),palindromes.end());
    cout<<palindromes.back()<<ENDL;
    return 0;
}
