#include<cstdio>
#include<algorithm>
#include<cstring>
using namespace std;
int isp[33];
int n;
int A[33];
int vis[33];
void dfs(int cur){
    //printf("%d\n",cur);
    if(cur==n&&isp[A[0]+A[n-1]]){
        for(int i=0;i<n-1;i++)printf("%d ",A[i]);
        printf("%d\n",A[n-1]);
    }
    else for(int i=2;i<=n;i++)
    if(!vis[i]&&isp[i+A[cur-1]]){
        A[cur]=i;
        vis[i]=1;
        //printf("666\n");
        dfs(cur+1);
        vis[i]=0;
    }
}
int is_prime(int n){
    for(int i=2;i*i<=n;i++){
        if(n%i==0)return 0;
    }
    return 1;
}
int main(){
    for(int i=2;i<=16*2;i++)isp[i]=is_prime(i);
    //for(int i=2;i<=16*2;i++)printf("%d:%d\n",i,isp[i]);
    int kase=0;
    while(scanf("%d",&n)!=EOF){
        if(kase)printf("\n");
        memset(vis,0,sizeof(A));
        memset(A,0,sizeof(A));
        printf("Case %d:\n",++kase);
        A[0]=1;
        vis[1]=1;
        dfs(1);
    }
}
