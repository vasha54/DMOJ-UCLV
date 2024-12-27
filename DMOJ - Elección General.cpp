/**
 * DMOJ - Elección General
 * Temática: Add - Hoc + Busqueda 
 * 
 * Idea: Dado un grupo de candidatos  como fueron votados en un grupo de regiones determinados
 * el candidato ganador.
 */ 
#include <bits/stdc++.h>
#include <bitset>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>

#define ENDL '\n'
#define OPTIMIZAR_IO ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define PRESICION(x) cout.setf(ios::fixed,ios::floatfield); cout.precision(x);
#define READ_FILE freopen("Input.txt","r",stdin);
#define WRITE_FILE freopen("Output.txt","w",stdout);
#define REP(x) for(int i=1;i<=x;i++)
#define int long long
#define uint unsigned long long
#define PRINT_LINE cout<<ENDL;
#define MAX_N 100010
#define MOD 1000000007
 
using namespace std;
using namespace __gnu_pbds;


signed main()
{
    OPTIMIZAR_IO
    PRESICION(2)
    //READ_FILE
    //WRITE_FILE
    int ncandidatos,nregiones,voto,winner,cases;
    cin>>cases;
    while(cases--){
        cin>>ncandidatos>>nregiones;
        vector<int> votos(ncandidatos,0);
        REP(nregiones)
        {
            for(int i=0;i<ncandidatos;i++)
            {
                cin>>voto;
                votos[i]+=voto;
            }
        }
        winner =0;
        voto = votos[0];
        for(int i=1;i<ncandidatos;i++)
        {
            if(votos[i]>voto)
            {
                winner = i;
                voto =votos[i];
            }
        }
        cout<<winner+1<<ENDL;
    }
    return 0;
}
