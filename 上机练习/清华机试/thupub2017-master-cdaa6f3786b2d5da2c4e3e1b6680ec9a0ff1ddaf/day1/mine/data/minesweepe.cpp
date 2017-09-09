#include<cstdio>
#include<algorithm>
#include<vector>
#include<queue>
using namespace std;

struct ans{
    int a,b,r;
};

const int dx[]={-1,0,1,1,1,0,-1,-1};
const int dy[]={-1,-1,-1,0,1,1,1,0};
char adj[1010][1010]={0};
int state[1010][1010]={0};
//    未探明0
//    已探明1
//    有旗帜2
int total_step=0;
int n,m;
int white_blocks=0;
bool is_falure=false;
bool is_succ=false;
vector<ans> anss;

bool cmp(ans x,ans y){
    if(x.a!=y.a)return x.a<y.a;
    else return x.b<y.b;
}
bool is_in(int a,int b){
//    printf("a>=0 %d\n",a>=0);
//    printf("a<n %d\n \n\nn:%d\n\n",a<n,n);
//    printf("b>=0 %d\n",b>=0);
//    printf("b<m %d\n",b<m);
    return a>=0&&a<n&&b>=0&&b<m;
}
void flag(int a,int b){
    total_step++;
    if(state[a][b]==1){
        printf("swept\n");
        return ;
    }
    else if(state[a][b]==0){
        state[a][b]=2;
        printf("success\n");
        return ;
    }
    else {
        state[a][b]=0;
        printf("cancelled\n");
        return ;
    }
}
void quit(){
    if(is_falure){
        printf("game over\n");
    }
    else if(is_succ){
        printf("finish\n");
    }
    else printf("give up\n");
    printf("total step %d\n",total_step);
    exit(0);
}
void mine(int x,int y){
    queue<int> q;
    q.push(x),q.push(y);
    while(!q.empty()){
        int a=q.front();q.pop();
        int b=q.front();q.pop();
        if(state[a][b]>0)continue;
        if(adj[a][b]=='*'){
            is_falure=true;
            printf("boom\n");
            quit();
            return ;
        }
        state[a][b]=1;
        int minenum=0;
        for(int i=0;i<8;i++){
            int aa=a+dx[i],bb=b+dy[i];
            if(is_in(aa,bb)){
                if(adj[aa][bb]=='*')minenum++;
            }
        }
        struct ans tmp;
        tmp.a=a+1;
        tmp.b=b+1;
        tmp.r=minenum;
        anss.push_back(tmp);
        white_blocks--;


        if(minenum!=0)continue;
        for(int i=0;i<8;i++){
            int aa=a+dx[i],bb=b+dy[i];
            //printf("\n\n!!!\n\n%d %d %d\n\n",aa,bb,is_in(aa,bb));
            if(is_in(aa,bb)){
                q.push(aa);
                q.push(bb);
            }
        }

    }

}
void print_ans(){
    printf("%d cell(s) detected\n",anss.size());
    sort(anss.begin(),anss.end(),cmp);
    for(int i=0;i<anss.size();i++){
        printf("%d %d %d\n",anss[i].a,anss[i].b,anss[i].r);
    }
    anss.clear();
    if(white_blocks==0){
        is_succ=true;
        quit();
        return;
    }
}
void sweep(int a,int b){
    total_step++;
    if(state[a][b]==1){
        printf("swept\n");
        return ;
    }
    else if(state[a][b]==2){
        printf("flagged\n");
        return;
    }
    mine(a,b);
    print_ans();

}

void dsweep(int a,int b){
    total_step++;
    if(state[a][b]==0||state[a][b]==2){
        printf("not swept\n");
        return ;
    }
    int flanum=0;
    int minenum=0;

    for(int i=0;i<8;i++){
        int aa=a+dx[i],bb=b+dy[i];
        if(is_in(aa,bb)){
            if(adj[aa][bb]=='*')minenum++;
            if(state[aa][bb]==2)flanum++;
        }
    }
    if(minenum==0||flanum!=minenum){
        printf("failed\n");
        return;
    }
    for(int i=0;i<8;i++){
        int aa=a+dx[i],bb=b+dy[i];
        if(is_in(aa,bb)){
            mine(aa,bb);
        }
    }
    if(anss.size()==0){
        printf("no cell detected\n");
        return;
    }
    print_ans();
}

int main(){
    freopen("1.in","r",stdin);
    freopen("ans.txt","w",stdout);
    scanf("%d%d",&n,&m);
    for(int i=0;i<n;i++){
        scanf("%s",adj[i]);
    }
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            if(adj[i][j]=='.')white_blocks++;
        }
    }
    //printf("%d\n\n\n\n",white_blocks);
    char commend[10];
    while(~scanf("%s",commend)){
        if(commend[0]=='Q'){
            quit();
        }

        int a,b;
        scanf("%d%d",&a,&b);
        a--;b--;
        //printf("%d\n\n\n\n",white_blocks);
        if(commend[0]=='F'){
            flag(a,b);
        }
        else if(commend[0]=='S'){
            sweep(a,b);
        }
        else if(commend[0]=='D'){
            dsweep(a,b);
        }

    }
    return 0;
}
