#include<cstdio>
#include<cstring>
//#include
using namespace std;
const int maxn=52;
int G[maxn][maxn];
int vis[maxn];
int n;
char str[9];
int change(int x){
    return x>25?x-26:x+26;
}
int c2i(char x,char y){
    if(x=='0')return -1;
    int a=x-'A';
    if(y=='-')a+=26;
    return a;
}
void build(){
    for(int i=0;i<8;i+=2){
        int a=c2i(str[i],str[i+1]);
        if(a==-1)continue;
        for(int j=i+2;j<8;j+=2){
            int b=c2i(str[j],str[j+1]);
            if(b==-1)continue;
            //if(a==b)continue;
            G[a][change(b)]=1;
            G[b][change(a)]=1;
        }
    }
}
void init(){
    memset(G,0,sizeof(G));
    for(int i=0;i<n;i++){
        scanf("%s",str);
        build();
    }
}
bool dfs(int u){
    //printf("%d\n",ttt);
    vis[u]=-1;
    //printf("%d \n",u);
    for(int v=0;v<maxn;v++){
        if(G[u][v]){
            if(vis[v]<0){
                   // printf("end %d \n",v);
            return true;}
            else if(!vis[v]&&dfs(v)){return true;}
        }
    }
    vis[u]=1;
    return false;
}
void solve(){
    memset(vis,0,sizeof(vis));
    for(int i=0;i<maxn;i++){
        if(!vis[i]){
            if(dfs(i)){
                printf("unbounded\n");
                return;
            }
        }
    }
    printf("bounded\n");
}
void test(){
    for(int i=-1;i<maxn;i++)printf("%3d",i);
    printf("\n");
    for(int i=0;i<maxn;i++){
            printf("%3d",i);
        for(int j=0;j<maxn;j++){
            printf("%3c",G[i][j]?'*':' ');
        }
    printf("\n");
    }
    for(int i=-1;i<maxn;i++)printf("%3d",i);
    printf("\n");
    for(int i=0;i<maxn;i++){
            printf("%3d",i);
        for(int j=0;j<maxn;j++){
            printf("%3c",G[i][j]?'*':' ');
        }
    printf("\n");
    }
}
int main(){
    freopen("ans.txt","r",stdin);
    freopen("ans1.txt","w",stdout);
    while(scanf("%d",&n)!=EOF){
        init();
//        test();
        solve();
    }
//    for(int i=0;i<26;i++){
//        printf("%d:%c%c\n",c2i(('A'+i),'+'),('A'+i),'+');
//        printf("%d:%c%c\n",c2i(('A'+i),'-'),('A'+i),'-');
//    }
    return 0;
}
