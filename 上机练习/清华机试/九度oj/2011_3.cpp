#include<cstdio>
#include<cstring>
using namespace std;
int l,m;
bool vis[10001];
int main(){
    freopen("1.txt","r",stdin);
    //freopen("12.txt","w",stdout);
    while(scanf("%d%d",&l,&m)!=EOF){
        memset(vis,false,sizeof(bool)*(l+1));
        for(int i=0;i<m;i++){
            int a,b;
            scanf("%d%d",&a,&b);
            memset(vis+a,true,sizeof(bool)*(b-a+1));
        }
        int ans=0;
        for(int i=0;i<=l;i++){
            if(vis[i])ans++;
            //printf("%d %d\n",i,vis[i]);
        }
        printf("%d\n",l-ans+1);
    }

}
