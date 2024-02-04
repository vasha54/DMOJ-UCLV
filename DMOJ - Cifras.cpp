/*
* DMOJ - Cifras.
* Tematica : Add-Hoc
* Idea: .
*/
#include <iostream>
#include <math.h>
#include <bits/stdc++.h>
#define ENDL '\n'
#define OPTIMIZAR_IO ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define PRESICION(x) cout.setf(ios::fixed,ios::floatfield); cout.precision(x);
#define READ_FILE freopen("Input.txt","r",stdin);
#define WRITE_FILE freopen("Output.txt","w",stdout);
#define MAX_N 100010
#define MOD 1000000007
#define EPS 1e-4
#define INF 1000000000
#define int long long
#define uint unsigned long long
#define pii pair<int,int>
#define ALPHABET_SIZE 26 //['a-z']
#define K 25
#define Point pair<int, int>
#define X first
#define Y second
#define PLUS '+'
#define MINUS '-'
#define SPACE ' '
using namespace std;

struct Team{
    vector<int> digists1;
    vector<int> digists2;
    vector<int> digistst;
    Team(){
        digists1.resize(10,0);
        digists2.resize(10,0);
        digistst.resize(10,0);
    }
    bool  task1(){
        int c=0;
        for(int i=1;i<10;i++) c+=digistst[i]-max(digists1[i],digists2[i]);
        return (c>0);
    }
    vector<int>  task2(){
        vector<int> d;
        for(int i=1;i<10;i++){
            int c=digistst[i]-max(digists1[i],digists2[i]);
            for(int j=0;j<c;j++) d.push_back(i);
        }
        sort(d.rbegin(),d.rend());
        if(!d.empty()){
            int c=digistst[0]-max(digists1[0],digists2[0]);
            for(int j=0;j<c;j++) d.push_back(0);
        }else{
            d.push_back(0);
        }
        return d;
    }

};

istream & operator>>(istream & in , Team & t) {
   string t1,t2;
   in>>t1>>t2;
   for(char x: t1) t.digistst[x-'0']=(++t.digists1[x-'0']);
   for(char x: t2) t.digistst[x-'0']=t.digists1[x-'0']+(++t.digists2[x-'0']);
   return in;
}

ostream & operator<<(ostream & out, Team t){
   out<<"Digits t"; for(int x:t.digistst) out<<SPACE<<x; out<<ENDL;
   out<<"Digits 1"; for(int x:t.digists1) out<<SPACE<<x; out<<ENDL;
   out<<"Digits 2"; for(int x:t.digists2) out<<SPACE<<x; out<<ENDL;
   out<<"Number x "; for(int x:t.task2()) out<<x; out<<ENDL;
   return out;
}

bool operator<(vector<int> &a, vector<int> &b ){
    if(a.size()<b.size()) return true;
    if(a.size()>b.size()) return false;
    for(int i=0;i<a.size();i++){
        if(a[i]==b[i]) continue;
        if(a[i]>b[i]) return false;
        if(a[i]<b[i]) return true;
    }
    return true;
}


int task,nteams,solution;
vector<Team> teams;

signed main(){
    OPTIMIZAR_IO
    //PRESICION(0)
    //READ_FILE
    //WRITE_FILE
    cin>>task;
    cin>>nteams;
    teams.resize(nteams);
    for(int i=0;i<nteams;i++) {
        cin>>teams[i];
    }
    if(task==1){
        solution=0;
        for(Team t: teams) if(t.task1()) solution++;
        cout<<solution<<ENDL;
    }else if(task==2){
        vector<int> d = teams[0].task2();
        for(int i=1;i<nteams;i++){
            vector<int> b = teams[i].task2();
            if(d<b)d=b;
        }
        for(int s:d)cout<<s;
        cout<<ENDL;
    }
    return 0;
}
