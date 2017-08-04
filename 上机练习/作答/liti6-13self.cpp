#include<cstdio>
#include<ctype.h>
#include<cstring>
#include<vector>
#include<algorithm>
using namespace std;

vector<char> ans;

int H,W;
int pic[205][55*4];
int cop[205][55*4];
int idx[205][55*4];
bool is_visited[205][55*4];
const int xx[]={0,1,0,-1};
const int yy[]={1,0,-1,0};
const char as[]={' ','W','A','K','J','S','D'};
//                 0  1   2   3   4  5  6  7

void vis(int x,int y){

    if(x<0||x>H+1||y<0||y>W*4+1)return ;
    if(is_visited[x][y])return ;
    if(pic[x][y]==0)return ;
    is_visited[x][y]=true;
    cop[x][y]=1;
    for(int i=0;i<4;i++){
        vis(x+xx[i],y+yy[i]);
    }


}

bool coppy(int x,int y){
    if(is_visited[x][y])return false;
    if(pic[x][y]==0)return false;
    memset(cop,0,sizeof(cop));
    vis(x,y);
    return true;
}

void dfs(int r,int c,int id){

    if(r<0||r>H+1||c<0||c>W*4+1)return;
    if(idx[r][c]>0||cop[r][c]==1)return;
    idx[r][c]=id;
    for(int i=0;i<4;i++)dfs(r+xx[i],c+yy[i],id);
}

int main(){
    freopen("ans.txt","r",stdin);
    //freopen("ans1.txt","w",stdout);
    int kase=0;
    while(scanf("%d%d",&H,&W)!=EOF&&H&&W){
        //input
        getchar();
        ans.clear();
        memset(is_visited,false,sizeof(is_visited));
        for(int i=1;i<=H;i++){
            for(int j=1;j<=W*4;j+=4){
                char inpu=getchar();
                int num;
                if(isalpha(inpu)){
                    num=inpu-'a'+10;
                }
                else num=inpu-'0';
                for(int wee=0;wee<=3;wee++){
                       // printf("%d\n",(num&(1<<(3-wee)))>0);
                    pic[i][j+wee]=(num&(1<<(3-wee)))>0;
                }
            }
            getchar();
        }
//        for(int i=0;i<H;i++){
//            for(int j=0;j<W*4;j++){
//                printf("%c",pic[i][j]?'#':' ');
//            }
//            printf("\n");
//        }
        for(int i=1;i<=H;i++){
            for(int j=1;j<=W*4;j++){
                if(coppy(i,j)){
//                        for(int ii=0;ii<H;ii++){
//                            for(int ji=0;ji<W*4;ji++){
//                                printf("%c",cop[ii][ji]?'&':' ');
//                            }
//                            printf("\n");
//                        }
                    memset(idx,0,sizeof(idx));
                    int cnt=0;
                    for(int i1=1;i1<=H;i1++)
                        for(int j1=1;j1<=W*4;j1++)
                        if(idx[i1][j1]==0&&cop[i1][j1]==0)dfs(i1,j1,++cnt);
                        //printf("%d %d %d\n",cnt,i,j);
                    ans.push_back(as[cnt]);
                }
            }
        }
        sort(ans.begin(),ans.end());
        printf("Case %d: ",++kase);
        for(int i=0;i<ans.size();i++){
            printf("%c",ans[i]);
        }
        printf("\n");


    }
}
