#include<cstdio>
#include<algorithm>
#include<iostream>
#include<string>
#include<cstring>
#include<vector>
#include<map>
#include<utility>
#include<assert.h>
using namespace std;

char st[85];
int n,m;

//map<pair<int,int> ,pair<int,int> > match;
map<pair<pair<int,int>,pair<int,int> > ,int > matro;

vector<string> strcache;
map<string,int> IDcache;
int ID(string x){
    if(IDcache.count(x))return IDcache[x];
    strcache.push_back(x);
    return IDcache[x]=strcache.size()-1;
}


void tostring(string&x ,char b[],int i,int j){

    for(int ii=i;ii<=j;ii++)x=x+b[ii];
    if(i>j)x=x+"null";
}

string s[10];
int main(){
    freopen("ans1.txt","r",stdin);
   // freopen("ans1.txt","w",stdout);
    while(scanf("%d%d",&n,&m)!=EOF){
        bool isfind=false;
        strcache.clear();
        IDcache.clear();
        matro.clear();
//        match.clear();
        gets(st);

        for(int i=0;i<n;i++){
            gets(st);
            if(isfind)continue;
            isfind=false;

            int fomer=0;
            int col=0;
            for(int j=0;j<strlen(st)+1;j++){
                if(st[j]==','||st[j]=='\0'){
                    s[col].clear();
                    //cout<<fomer<<endl;
                    //cout<<j-1<<endl;
                    tostring(s[col],st,fomer,j-1);
                    col++;
                    fomer=j+1;
                }

            }
            assert(m==col);
            for(int j=0;j<m;j++){
                for(int k=j+1;k<m;k++){
                    pair<int,int> p1,p2;
                    int a1=ID(s[j]),a2=ID(s[k]);
                   // cout<<i<<" "<<j<<" "<<k<<" "<<a1<<" "<<a2<<" "<<s[j]<<","<<s[k]<<" \n";
                    p1=make_pair(j,k);
                    p2=make_pair(a1,a2);
                    pair<pair<int,int>,pair<int,int> > p666=make_pair(p1,p2);;
                   // int xxxx=p1.first==match[p2].first ?1:0;
                   // cout<<p1.first<<match[p2].first<<p1.second<<match[p2].second <<endl;
                    if(matro.count(p666)&&matro[p666]!=i){
                        isfind=true;
                        cout<<"NO"<<endl;
                        cout<<matro[p666]+1<<' '<<i+1<<endl;
                        cout<<p1.first+1<<' '<<p1.second+1<<endl;
                        break;
                    }
                    //if(isfind)break;
                    matro[p666]=i;
                   // match[p2]=p1;

                }
                if(isfind)break;
            }


//            for(int j=0;j<col;j++){
//                cout<<s[j]<<"//";
//            }
//            cout<<endl;
        }
        if(!isfind) cout<<"YES"<<endl;
    }
}
