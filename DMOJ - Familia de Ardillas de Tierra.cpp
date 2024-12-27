//3022 - Gopher Family
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
#define MOD 1000000007
#define MAX 110
#define MAXTREE (MAX << 2)
#define LIMIT 1000000100
#define INF 1000100
#define ULL unsigned long long
#define LL long long
#define ENDL '\n'
#define SYMBOL '#'
#define REP(i,n) for(int i=0;i<(int)n;++i)
#define REP1_N(i,n) for(int i=1;i<=(int)n;++i)
#define FOR(i,c) for(__typeof((c).begin())i=(c).begin();i!=(c).end();++i)
#define ALL(c) (c).begin(), (c).end()

using namespace std;

typedef int Weight;

struct Edge 
{
    int src, dst;
    Weight weight;
    Edge (int _src=0, int _dst=0, Weight _weight=0):
    src (_src), dst (_dst), weight (_weight) {}
};

struct Point
{
    double X,Y;
    Point(double _X=0,double _Y=0)
    {
        X=_X;
        Y=_Y;
    }
};


typedef vector<Edge> Edges;
typedef vector <Edges> Graph;
typedef vector <Weight> Array;
typedef vector <Array> Matrix;


int nholes,ngophers;
Point holes[MAX],gophres[MAX];
double velocity,secondSafe;

bool augment (const Graph &g, int u, vector <int> & matchTo, 
                vector <bool> & visited) 
{
   if (u <0) 
    return true;
   FOR (e, g[u]) 
    if (! visited[e->dst]) 
    {
     visited [e->dst] = true;
     if (augment (g, matchTo [e->dst], matchTo, visited)) 
     {
       matchTo[e->src] = e->dst;
       matchTo[e->dst] = e->src;
       return true;
     }
    }
   return false;
}


int bipartiteMatching (const Graph &g, int L, Edges & matching) 
{
    int n = g.size();
   vector <int> matchTo (n,-1);
   int match = 0;
   REP (u, L) 
   {
     vector <bool> visited (n);
     if (augment (g, u, matchTo, visited)) 
        ++match;
   }
   REP (u, L) 
    if (matchTo[u]>=0) // make explicit matching
     matching.push_back(Edge (u, matchTo [u]));
   return match;
 }
 
double distanceBetwenPoint(Point _a,Point _b)
{
    return sqrt( (_a.X-_b.X)*(_a.X-_b.X)+(_a.Y-_b.Y)*(_a.Y-_b.Y) );
}
 
int main()
{
	//freopen("Input.txt","r",stdin);
	cout.setf(ios::fixed,ios::floatfield);
	cout.precision(3);
	ios_base::sync_with_stdio(0);
	std::cin.tie(0);
    while(cin>>ngophers>>nholes>>secondSafe>>velocity)
    {
        REP(i,ngophers)
            cin>>gophres[i].X>>gophres[i].Y;
        REP(i,nholes)
            cin>>holes[i].X>>holes[i].Y;
        
        Graph  graphs(nholes+ngophers);
        
        REP(i,ngophers)
        {
            Edges tedges;
            REP(j,nholes)
            {
                double distance=distanceBetwenPoint(gophres[i],holes[j]);
                double timeConsumed=distance/velocity;
                if(timeConsumed<=secondSafe)
                {
                    Edge edge=Edge(i,j+ngophers);
                    graphs[i].push_back(edge);
                    graphs[j+ngophers].push_back(edge); 
                }
            }
            
        }
        Edges eMatch; 
        int nMacth=bipartiteMatching (graphs, ngophers,eMatch); 
        cout<<ngophers-nMacth<<ENDL; 
        
          
    }
	return 0;        
}