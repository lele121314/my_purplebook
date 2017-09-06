#include<iostream>
#include<algorithm>
#include<cstdio>
using namespace std;
#define MAXN 2211686018427387904
#define l first
#define c second
pair<long long,long long> piao[3];
int A,B;
long long dis[300000];
long long dp[300000];
long long ans,N;
long long ddis(int i,int j){
    long long temp=dis[j]-dis[i];
    for(int i=0;i<3;i++)
    if(temp<=piao[i].l)return piao[i].c;
}
int main(){
    freopen("1.txt","r",stdin);
    while(cin>>piao[0].l>>piao[1].l>>piao[2].l>>piao[0].c>>piao[1].c>>piao[2].c){
        cin>>A>>B;
        cin>>N;
        for(int i=0;i<300000;i++)dis[i]=dp[i]=MAXN;
        ans=0;
        dis[1]=0;
        for(int i=2;i<=N;i++){
            cin>>dis[i];
        }
        dp[A]=0;

        for(int i=A;i<B;i++){
            for(int j=i+1;dis[j]-dis[i]<=piao[2].l&&j<300000;j++){
                long long xx=ddis(i,j);
                dp[j]=min(dp[j],dp[i]+xx);
            }
        }
        cout<<dp[B]<<endl;
    }
    return 0;
}
