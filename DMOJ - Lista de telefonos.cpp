// DMOJ - Lista de telefonos

#include <stdio.h>
#include <vector>
#include <string>
#include <string.h>
#include <algorithm>

using namespace std;

int cases,numbers_phones,size;
char phone[20];
vector<string> phones;
string tmp;
bool consistent;


int main()
{
    //freopen("Input.txt","r",stdin);
    while(scanf("%d",&cases)!=EOF){
            while(cases--){
                 scanf("%d",&numbers_phones);
                 for(int i=1;i<=numbers_phones;i++){
                        scanf("%s",phone);
                        tmp=phone;
                        phones.push_back(tmp);
                     }
                 sort(phones.begin(),phones.end());
                 consistent=false;
                 for(int i=0;i<numbers_phones-1 && !consistent;i++){
                         size=phones[i].size();
                         tmp=phones[i+1].substr(0,size);
                         if(strcmp(tmp.c_str(),phones[i].c_str())==0)
                           consistent=true;
                     }
                 phones.clear();
                 consistent ? puts("NO") : puts("YES");
                }
        }
    return 0;
}