#include<cstdio>
#include<cstring>
#include<queue>
using namespace std;
char in[3],out[3];
int e[256][256];//-1 s 1is 0not  2end
queue<int> q;
const int dx[]={1,2,-1,-2,1,2,-1,-2};
const int dy[]={2,1,2,1,-2,-1,-2,-1};
bool is_in(int x,int y){
    if(x>='a'&&y>='1'&&x<='h'&&y<='8')return true;
    return false;
}
void bfs(int x,int y){
    if(x==out[0]&&y==out[1]){
        printf("To get from %s to %s takes %d knight moves.\n",in,out,0);
        return ;
    }
    while(!q.empty())q.pop();
    e[x][y]=1;
    q.push(x);q.push(y);q.push(0);
    while(!q.empty()){

        int a=q.front();q.pop();
        int b=q.front();q.pop();
        int st=q.front();q.pop();
        printf("%c %c %d\n",a,b,st);
        if(a==out[0]&&b==out[1]){
            printf("To get from %s to %s takes %d knight moves.\n",in,out,st);
            return ;
        }
        for(int i=0;i<8;i++){
            int da=a+dx[i],db=b+dy[i];
            if(is_in(da,db)&&e[da][db]==0){
                q.push(da);q.push(db);q.push(st+1);
                e[da][db]=1;
            }
        }
    }

}
void solve(){
    memset(e, 0, sizeof(e));
    int x=out[0],y=out[1];
    x=in[0];y=in[1];
    bfs(x,y);
}
int main(){
    freopen("ans.txt","r",stdin);
    //freopen("ans1.txt","w",stdout);
    while(scanf("%s%s",in,out)!=EOF){
        solve();
    }
    return 0;
}
