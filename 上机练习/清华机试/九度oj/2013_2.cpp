#include<iostream>
#include<cstdio>
#include<map>
#include<string>
using namespace std;
struct e{
    string a,b,c,d;
    bool operator < (const e& x) const{
        return x.a<a;
    }
};
map<string,e> q;

int main(){
    //freopen("1.txt","r",stdin );
    int n;
    while(cin>>n){
        for(int i=0;i<n;i++){
            e x;
            cin>>x.a>>x.b>>x.c>>x.d;
            q[x.a]=x;
        }
        cin>>n;
        for(int i=0;i<n;i++){
            string aaa;
            cin>>aaa;
            if(!q.count(aaa))cout<<"No Answer!"<<endl;
            else cout<<q[aaa].a<<" "<<q[aaa].b<<" "<<q[aaa].c<<" "<<q[aaa].d<<endl;
        }
    }
}
