//DOMJ - Par o impar
#include <iostream>
#include <algorithm>
#include <bits/stdc++.h>

#define ENDL '\n'

using namespace std;

int main(){

    int N;

    while( cin>>N ){
        cout<<( N%2==0 ? "even" : "odd" )<<ENDL;
    }

    return 0;
}
