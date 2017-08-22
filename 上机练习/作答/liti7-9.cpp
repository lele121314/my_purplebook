#include<cstdio>
#include<cstring>
#include<cctype>
#include<list>
#include<algorithm>

using namespace std;

int w,h,n;

char pic[20][20];//输入
int num[20][20];//
int vis[200][200][200];
int connect[200][200];
int all;

int que[10000000][4];
int goal[4];
inline void BFS(){
    memset(vis,0,sizeof(vis));
    int fro=0,rear=1;
    vis[que[0][1]][que[0][2]][que[0][3]]=true;

    while(fro<rear){
        int &step=que[fro][0],&a=que[fro][1],&b=que[fro][2],&c=que[fro][3];
        if(a==goal[1]&&b==goal[2]&&c==goal[3]){goal[0]=step;return ;}
        for(int i=0,t1;i<=connect[a][0];i++){
            t1=(i==0?a:connect[a][i]);
            for(int j=0,t2;j<=connect[b][0];j++){
                t2=(j==0?b:connect[b][j]);
                for(int k=0,t3;k<=connect[c][0];k++){
                    t3 = (k == 0 ? c : connect[c][k]);
                    if((t1 && t2 && t1 == t2) || (t1 && t3 && t1 == t3) || (t2 && t3 && t2 == t3)) continue; // 不能重合
                    if(t1 && t2 && t1 == b && t2 == a) continue; // t1,t2不能对穿
                    if(t1 && t3 && t1 == c && t3 == a) continue; // t1,t3不能对穿
                    if(t2 && t3 && t2 == c && t3 == b) continue; // t2,t3不能对穿
                    if(!vis[t1][t2][t3]) {
                        vis[t1][t2][t3] = 1;
                        que[rear][0] = step + 1, que[rear][1] = t1, que[rear][2] = t2, que[rear][3] = t3;
                        ++rear;
                    }
                }
            }
        }
    }
}
int main(){
    int _t=0;
    while(scanf("%d%d%d",&w,&h,&n)){
        if(w==0&&h==0&&n==0)break;

        gets(pic[0]);
        for(int i=0;i<h;i++)gets(pic[i]);


        memset(connect,0,sizeof(connect));
        all=0;
        for(int i=0;i<h;i++)
        for(int j=0;j<w;j++){
            if(pic[i][j]='#')num[i][j]=all++;
            else num[i][j]=0;
        }
        for(int i=0;i<h;i++)
        for(int j=0;j<w;j++){
            if(num[i][j]){
                int &pos=num[i][j];
                if(num[i+1][j])connect[pos][++connect[pos][0]]=num[i+1][j];
                if(num[i-1][j])connect[pos][++connect[pos][0]]=num[i-1][j];
                if(num[i][j+1])connect[pos][++connect[pos][0]]=num[i][j+1];
                if(num[i][j-1])connect[pos][++connect[pos][0]]=num[i][j-1];
            }
        }
        que[0][0]=que[0][1]=que[0][2]=que[0][3]=0;
        goal[0]=goal[1]=goal[2]=goal[3]=0;

        for(int i=0;i<h;i++)
        for(int j=0;j<w;j++){
            if(pic[i][j] == 'a') que[0][1] = num[i][j];
            if(pic[i][j] == 'b') que[0][2] = num[i][j];
            if(pic[i][j] == 'c') que[0][3] = num[i][j];
            if(pic[i][j] == 'A') goal[1] = num[i][j];
            if(pic[i][j] == 'B') goal[2] = num[i][j];
            if(pic[i][j] == 'C') goal[3] = num[i][j];
        }
        BFS();
        printf("%d\n",goal[0]);
    }
}

