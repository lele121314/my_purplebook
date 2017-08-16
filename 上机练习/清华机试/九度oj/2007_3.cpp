#include<cstdio>
#include<cstring>
#include<algorithm>
#define inf 0x7ffffff
using namespace std;
int n,m;
int a[25];
int dp[105];
bool inpt(){
    if(scanf("%d%d",&m,&n)==EOF)return false;
    for(int i=n-1;i>=0;i--)scanf("%d",&a[i]);
    return true;
}
void solve(){
    memset(dp,-1,sizeof(dp));
    for(int i=1;i<=m;i++)dp[i]=inf;
    dp[0]=0;
    int ans=0;
    for(int i=0;i<n;i++){
        for(int j=m;j>=a[i];j--){
            if(dp[j-a[i]]!=-1){
                dp[j]=min(dp[j],dp[j-a[i]]+1);
            }

        }
    }
    printf("%d\n",dp[m]==inf?0:dp[m]);
}
int main(){
    freopen("1.txt","r",stdin);
    while(inpt()){
        solve();
    }
    return 0;
}
