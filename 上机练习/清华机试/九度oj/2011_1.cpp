#include<cstdio>
#include<algorithm>
#include<vector>
#include<cstring>
#define INT_MAX		2147483647
using namespace std;
struct piao{
   int L,C;
}Pi[3];
int L;
int dp[214748364];
bool ipt(){
    if(scanf("%d%d%d%d%d%d",&Pi[0].L,&Pi[1].L,&Pi[2].L,&Pi[0].C,&Pi[1].C,&Pi[0].C)==EOF)return false;
    int A,B;
    scanf("%d%d",&A,&B);
    int n;
    scanf("%d",&n);
    vector<int> a;
    a.push_back(0);
    a.push_back(0);
    for(int i=2;i<=n;i++){
        int x;
        scanf("%d",&x);
        a.push_back(x);
    }
    L=a[B]-a[A];
    return true;

}
void solve(){
    int minc=Pi[0].C,minl=Pi[0].L;
    int maxc=Pi[0].C,maxl=Pi[0].L;
    for(int i=1;i<3;i++){
        minc=min(minc,Pi[i].C);minl=min(minl,Pi[i].L);
        maxc=max(maxc,Pi[i].C);maxl=max(maxl,Pi[i].L);
    }
    for(int i=1;i<=L+maxl;i++)dp[i]=INT_MAX;
    dp[0]=0;
    for(int i=0;i<3;i++){
        for(int j=Pi[i].L;j<=L+maxl;j++){
            if(dp[j-Pi[i].L]!=INT_MAX){
                dp[j]=min(dp[j],dp[j-Pi[i].L]+Pi[i].C);
            }
        }
    }
//    for(int i=0;i<=L;i++){
//            printf("%d\n",dp[i]);
//    }
    int ans=INT_MAX;
    for(int i=L;i<L+maxl;i++){
            //printf("%d\n",dp[i]);
        if(dp[i])ans=min(ans,dp[i]);
    }
    printf("%d\n",ans);
}
int main(){
    freopen("1.txt","r",stdin);
    while(ipt()){
        solve();
    }
}

