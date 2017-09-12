#include<cstdio>
#include<cstring>
using namespace std;
bool vis[10001];
int main(){
    int L,M;
    while(~scanf("%d%d",&L,&M)){
        memset(vis,false,sizeof(vis));
        for(int i=0;i<M;i++){
            int x,y;
            scanf("%d %d",&x,&y);
            memset(vis+x,true,sizeof(bool)*(y-x+1));
        }
        int ans=0;
        for(int i=0;i<=L;i++)if(!vis[i])ans++;
        printf("%d\n",ans);
    }
}
