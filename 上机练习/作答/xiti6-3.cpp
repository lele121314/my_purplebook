#include<cstdio>
#include<iostream>
#include<cstring>

using namespace std;

const int maxn=26+3;
char xian[maxn],zhong[maxn];
int len;
void dfs(int x,int y,int xx,int yy){
    if(x>y||xx>yy)return ;
    for(int i=xx;i<=yy;i++){
        if(xian[x]==zhong[i]){
            dfs(x+1,x+i-xx,xx,i-1);
            dfs(x+i-xx+1,y,i+1,yy);
            printf("%c",xian[x]);
            return ;
        }
    }
}

void solve(){
    len=strlen(xian);
    dfs(0,len-1,0,len-1);
    printf("\n");

}
int main(){
    freopen("ans.txt","r",stdin);
    freopen("ans1.txt","w",stdout);
    while(scanf("%s%s",xian,zhong)!=EOF){
            //printf("%s\n%s\n",xian,zhong);
        solve();
    }
    return 0;
}
