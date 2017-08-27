#include<iostream>
#include<cstdio>
#include<string>
#include<set>
#include<vector>
#include<map>
using namespace std;
map<string,int> sss;
set<string> ss;
bool ipt(){
    int n;
    sss.clear();
    ss.clear();
    if(cin>>n){
        while(n--){
            string x;
            cin>>x;
            ss.insert(x);
            sss[x]=0;
        }
        cin>>n;
        string q;
        cin>>q;
        if(ss.count(q)){
            sss[q]++;
        }
        n--;
        while(n--){
            string x;
            cin>>x;
            if(ss.count(x)){
                if(q==x)continue;
                sss[x]++;
            }
            q=x;
        }
        return true;
    }
    return false;
}
void solve(){
    int mins=2147483647;
    for(map<string,int>::iterator it=sss.begin();it!=sss.end();it++){
        mins=min(mins,it->second);
    }
    cout<<mins<<endl;
}
int main(){
    //freopen("1.txt","r",stdin);
    while(ipt()){
        solve();
    }
}
