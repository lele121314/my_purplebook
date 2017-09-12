#include<iostream>
#define mo 10000
using namespace std;
struct mat{
    long long a[2][2];
    mat operator * (const mat &b)const{
        struct mat tmp;
        tmp.a[0][0]=(a[0][0]*b.a[0][0]+a[0][1]*b.a[1][0])%mo;
        tmp.a[0][1]=(a[0][0]*b.a[0][1]+a[0][1]*b.a[1][1])%mo;
        tmp.a[1][0]=(a[1][0]*b.a[0][0]+a[1][1]*b.a[1][0])%mo;
        tmp.a[1][1]=(a[1][0]*b.a[0][1]+a[1][1]*b.a[1][1])%mo;
        return tmp;
    }
}pq,ans;
int main(){
    long long a0,a1,p,q,k;
    ios::sync_with_stdio(false);
    cin.tie(0);
    while(cin>>a0>>a1>>p>>q>>k){
        pq.a[0][0]=q;
        pq.a[0][1]=p;
        pq.a[1][0]=q*p;
        pq.a[1][1]=p*p+q;
        ans.a[0][0]=1;
        ans.a[0][1]=0;
        ans.a[1][0]=0;
        ans.a[1][1]=1;
        int n=k/2,l=k%2;
        while(n>0){
            if(n&1)ans=pq*ans;
            pq=pq*pq;
            n>>=1;
        }
        cout<<(a0*ans.a[l][0]+a1*ans.a[l][1])%mo<<endl;
    }
    return 0;
}
