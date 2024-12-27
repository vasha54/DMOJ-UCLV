// DMOJ - Cambiando Luces
#include <bits/stdc++.h>
using namespace std;

int main(){
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  int n, q;
  cin >> n >> q;
  short lights[n];
  memset(lights, -1, sizeof(lights));
  while(q--){
    int a, b, c;
    cin >> a >> b >> c;
    if(a){
      int count = 0;
      for (int i = b-1; i < c; ++i) if (lights[i] > 0) ++count;
      cout << count << "\n";
    }
    else{
      for (int i = b-1; i < c; ++i) lights[i] *=-1;
    }
  }
  return 0;
}