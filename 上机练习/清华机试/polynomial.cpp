#include<iostream>
#include<cstdio>
using namespace std;
typedef long long ll;
const int p=1000000000+7;
int n,m,a;
int x[100+5];
int main(){
    freopen("1.txt","r",stdin);
    cin>>n>>m>>a;
    for(int i=0;i<=m;i++){
        cin>>x[i];
    }
    ll ca=1,c,ans;
    for(int i=0;i<=n;i++){
        c=ca;ca=ca*a%p;
        for(int j=0;j<=m;j++){
            ans=(ans+c*x[j])%p;
            c=(ll)c*i%p;
        }

    }
    printf("%d\n",ans);
    return 0;
}
