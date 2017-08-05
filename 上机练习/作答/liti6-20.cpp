#include<cstdio>
#include<queue>
#include<cstring>
#include<vector>
#define inf 0x7fffffff
using namespace std;
const int maxn=100000+2;
const int maxd=1000000000+1;
struct e{
    int next;
    int color;
};
int n,m;
int d[maxn],res[maxn],ds[maxn];
vector<e> edge[maxn];
void solve2(){
    queue<int> q;
    memset(res,0,sizeof(res));
    memset(ds,-1,sizeof(res));
    q.push(1);
    ds[1]=1;
    while(!q.empty()){
        int x=q.front();q.pop();
        if(x==n)return;
        int minc=inf,len=edge[x].size();
        for(int i=0;i<len;i++){
            int y=edge[x][i].next;
            int color=edge[x][i].color;
            if(d[x]-1==d[y])minc=min(minc,color);
        }
        for(int i=0;i<len;i++){
            int y=edge[x][i].next;
            int color=edge[x][i].color;
            if(ds[y]<0&&d[x ]-1==d[y]&&color==minc){
                q.push(y);
                ds[y]=1;
            }
        }
        int idx=d[1]-d[x];
        if(res[idx]==0)res[idx]=minc;
        else res[idx]=min(res[idx],minc);
    }
}
void solve(){
    queue<int> q;
    memset(d,-1,sizeof(d));
    q.push(n);
    d[n]=0;
    while(!q.empty()){
        int x=q.front();q.pop();
        if(x==1){break;}
        for(int i=0;i<edge[x].size();i++){
            if(d[edge[x][i].next]<0){
                q.push(edge[x][i].next);
                d[edge[x][i].next]=d[x]+1;
            }
        }
    }
    printf("%d\n",d[1]);
}
void input(){
    for(int i=1;i<=n;i++)edge[i].clear();
    for(int i=0;i<m;i++){
        int a,b,c;
        scanf("%d%d%d",&a,&b,&c);
        if(a==b)continue;
        e tmp;
        tmp.next=b;tmp.color=c;
        edge[a].push_back(tmp);
        tmp.next=a;
        edge[b].push_back(tmp);
    }
}
int main(){
    freopen("ans.txt","r",stdin);
    while(scanf("%d%d",&n,&m)!=EOF){
        input();
        solve();
        solve2();
        for(int i=0;i<d[1]-1;i++){
            printf("%d ",res[i] );
        }
        printf("%d\n",res[d[1]-1]);
    }
    return 0;
}

