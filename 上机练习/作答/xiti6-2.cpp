#include<cstdio>
#include<iostream>
#include<string>
using namespace std;
int a[1<<9];
int name[9];
int n,m;
string ss;
void solve(){
    for(int i=0;i<(1<<n);i++){
        a[i]=ss[i]-'0';
    }
}
int main(){
   // freopen("ans.txt","r",stdin);
   // freopen("ans1.txt","w",stdout);
    int kase=1;
    while(cin>>n){

        if(n==0)break;
        cout<<"S-Tree #"<<kase++<<":"<<endl;
        for(int i=0;i<n;i++){
            cin>>ss;
            name[i]=ss[1]-'0';
        }
        cin>>ss;
        solve();
//        for(int i=0;i<(1<<n);i++){
//            cout<<a[i]<<endl;
//        }
        cin>>m;
        for(int i=0;i<m;i++){
            cin>>ss;
            int x=0;
            for(int i=0;i<n;i++){
                //x+= (1<<(n-name[i]))*(ss[name[i]-1]-'0');
                x+= (1<<(n-i-1))*(ss[name[i]-1]-'0');

            }
            //cout<<x<<endl;
            cout<<a[x];
        }
        cout<<endl<<endl;

    }
    return 0;
}
