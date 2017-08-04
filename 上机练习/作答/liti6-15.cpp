#include<cstdio>
#include<cstring>
using namespace std;
const int maxn=110;
int G[maxn][maxn];
int c[maxn],n,m;
int topo[maxn],t;
bool dfs(int u){
    c[u]=-1;
    for(int v=n;v>=1;v--){
        if(G[u][v]){
            if(c[v]<0)return false;
            else if(!c[v]&&!dfs(v))return false;
        }
    }
    c[u]=1;topo[--t]=u;
    return true;
}
bool toposort(){
    t=n;
    memset(c,0,sizeof(c));
    for(int u=1;u<=n;u++)if(!c[u])
        if(!dfs(u))return false;
    return true;
}
int main(){
    freopen("ans.txt","r",stdin);
    freopen("ans1.txt","w",stdout);
    while(scanf("%d%d",&n,&m)!=EOF){
        if(m==0&&n==0)break;
        memset(G, 0,sizeof(G) );

        for(int i=0;i<m;i++){
            int x,y;
           // printf("%d\n",123);
            scanf("%d%d",&x,&y);
            G[x][y]=1;
        }
        toposort();
        for(int i=0;i<n-1;i++)printf("%d ",topo[i]);
        printf("%d\n",topo[n-1]);
    }
}
