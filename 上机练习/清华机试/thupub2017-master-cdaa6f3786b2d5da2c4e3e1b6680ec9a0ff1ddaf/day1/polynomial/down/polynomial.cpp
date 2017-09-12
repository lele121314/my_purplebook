#include<iostream>
#include<cstdio>
using namespace std;
typedef long long ll;
const int p=1000000007;
int n,m,a;
int b[100+5];
ll calc(ll n){
    ll n1=1,n2=n+1,n3=2*n+1;
    if(n1%2==0)n1/=2;else n2/=2;
    if(n1%3==0)n1/=3;else if(n2%3==0)n2/=3;else n3/=3;
    return n1*n2%p*n3%p;
}
int main(){
    freopen("3.in","r",stdin);
    cin>>n>>m>>a;
    for(int i=0;i<=m;i++){
        cin>>b[i];
    }
    int ca=1,c,ans=0;
    if(a==1&&m<=2){
        ans=(ll)b[0]*(n+1)%p;
        ans=(ans+(ll)n*(n+1)/2%p*b[1]%p)%p;
        ans=(ans+(ll)b[2]*calc(n))%p;
        printf("%d\n",ans);
        return 0;
    }
    for(int i=0;i<=n;i++){
        c=ca;ca=(ll)ca*a%p;
        for(int j=0;j<=m;j++){
            ans=(ans+(ll)c*b[j])%p;
            c=(ll)c*i%p;
            //cout<<ans<<endl;
        }

    }
    cout<<ans;
    return 0;
}
