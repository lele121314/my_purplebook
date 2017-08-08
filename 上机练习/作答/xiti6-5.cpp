#include<cstdio>
#include<cstring>
#include<queue>
using namespace std;
const int maxn=20+1;
int m,n,k;
int ed[maxn][maxn],qiang[maxn][maxn],step[maxn][maxn],vis[maxn][maxn];
const int dy[]={0,1,0,-1};
const int dx[]={1,0,-1,0};
queue<int> q;
bool is_in(int x,int y){
    return x>=0&&y>=0&&x<m&&y<n;
}
void solve(){
    while(!q.empty())q.pop();
    q.push(0);q.push(0);
    vis[0][0]=1;
    while(!q.empty()){
        int a=q.front();q.pop();
        int b=q.front();q.pop();
        if(a==m-1&&b==n-1){
            return ;
        }
        for(int i=0;i<4;i++){
            int da=a+dx[i],db=b+dy[i];
            if(is_in(da,db)){
                if(!vis[da][db]){
                    if(qiang[a][b]+ed[da][db]<=k){
                        qiang[da][db]=ed[da][db]==0?0:qiang[a][b]+ed[da][db];
                        step[da][db]=step[a][b]+1;
                        vis[da][db]=1;
                        q.push(da);q.push(db);
                    }
                }
                else if(vis[da][db]){
                    if(qiang[da][db]>qiang[a][b]){
                            //printf("666\n");
                        if(qiang[a][b]+ed[da][db]<=k){
                            qiang[da][db]=ed[da][db]==0?0:qiang[a][b]+ed[da][db];
                            step[da][db]=step[a][b]+1;
                            vis[da][db]=1;
                            q.push(da);q.push(db);
                        }
                    }
                }
            }
        }
    }

}
void ipt(){
    memset(qiang,0,sizeof(qiang));
    memset(vis,0,sizeof(qiang));
    memset(step,0,sizeof(qiang));
    scanf("%d%d%d",&m,&n,&k);
    for(int i=0;i<m;i++)
        for(int j=0;j<n;j++)
        scanf("%d",&ed[i][j]);
}
int main(){
    freopen("ans.txt","r",stdin);
    freopen("ans1.txt","w",stdout);
    int t;
    scanf("%d",&t);
    while(t--){
        ipt();
        if(m==1&&n==1){
            if(ed[m-1][n-1]==1)printf("-1\n");
            else printf("0\n");
            continue;
        }
        solve();

//        for(int i=0;i<m;i++){
//            for(int j=0;j<n;j++){
//                printf("%2d ",step[i][j]);
//            }
//            printf("\n");
//        }
//        printf("\n");
//        printf("\n");
//        for(int i=0;i<m;i++){
//            for(int j=0;j<n;j++){
//                printf("%2d ",qiang[i][j]);
//            }
//            printf("\n");
//        }
        printf("%d\n",step[m-1][n-1]==0?-1:step[m-1][n-1]);
    }
    return 0;
}
