#include<cstdio>
#include<iostream>
#include<string>
#include<set>
#include<vector>
using namespace std;
set<string> a[1000];
vector<string> b;

int main(){
    freopen("ans.txt","r",stdin);
    char ss[10000];
    int max1=0;
    set<string> ans;
    while(scanf("%s",ss)!=EOF){
        string s(ss);
        b.push_back(s);
        a[s[0]].insert(s);
    }
    for(int i=0;i<b.size();i++){
        for(int j=0;j<b[i].length();j++){
            string x=b[i].substr(0,j+1);
            if(!a[x[0]].count(x)) continue;
            string y=b[i].substr(j+1);
            if(!a[y[0]].count(y)) continue;
            if(!ans.count(x+y)){
                ans.insert(x+y);
                cout<<x+y<<endl;
            }
        }

    }
    return 0;
}
