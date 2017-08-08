#include<cstdio>
#include<vector>
#include<algorithm>
#include<cstring>
using namespace std;

const int maxn=100+5;
char ed[maxn][maxn];
vector<int> node;
int n,black_nodes;
int pows[maxn];
int build_pow(){
    pows[0]=0;
    pows[1]=1;
    for(int i=2;i<=8;i++){
        pows[i]=pows[i-1]*5;
        //printf("%d\n",pows[i]);
    }
}
//1black 0 gery -1white
int is_all_black(int x,int y,int len){
    int white=len*len,black=len*len;
    int bl=0,wh=0;
    for(int i=0;i<len;i++){
        for(int j=0;j<len;j++){
            if(ed[x+i][y+j]=='1')bl++;
            else wh++;
            if(bl>0&&wh>0)return 0;
        }
    }
    if(bl)return 1;
    else return -1;
}
void build(int x,int y,int len,int depth,int ans,int location){
    int choice=is_all_black(x,y,len);
    if(choice==-1)return;
    else if(choice==1){
        int result=ans+location*pows[depth];
        node.push_back(result);
        black_nodes++;
        return;
    }
    else {
        int result=ans+location*pows[depth];
        build(x,y,len/2,depth+1,result,1);
        build(x,y+len/2,len/2,depth+1,result,2);
        build(x+len/2,y,len/2,depth+1,result,3);
        build(x+len/2,y+len/2,len/2,depth+1,result,4);
        return ;
    }
}
void ipt1(){
    memset(ed,0,sizeof(ed));
    node.clear();
    black_nodes=0;
    for(int i=0;i<n;i++){
        scanf("%s",ed[i]);
    }
    build(0,0,n,0,0,1);
    sort(node.begin(),node.end());
    if(black_nodes==0){
        printf("Total number of black nodes = %d\n",black_nodes);
        return ;
    }
    int mod;
    for(int i=0;i<node.size();i++){
        mod=i%12;
        if(mod==0)printf("%d",node[i]);
        else if(mod==11)printf(" %d\n",node[i]);
        else printf(" %d",node[i]);
    }
    if(mod!=11)
    printf("\n");
    printf("Total number of black nodes = %d\n",black_nodes);
}

void blur(int x,int y,int len){
    //printf("555\n");
    for(int i=0;i<len;i++){
        for(int j=0;j<len;j++){
            int da=x+i,db=y+j;
            //printf("%d %d\n",da,db);
            ed[da][db]='*';
        }
    }

}
void print(int num,int x,int y,int len){
    int dx[]={-1,0,0,len/2,len/2};
    int dy[]={-1,0,len/2,0,len/2};
    int chu=num/5,mo=num%5;
    //printf("%d %d\n",chu,mo);
    if(chu==0){
        int da=x+dx[mo],db=y+dy[mo];
        blur(da,db,len/2);
    }
    else{
        int da=x+dx[mo],db=y+dy[mo];
        print(chu,da,db,len/2);
    }
}
void ipt2(){
    int x;
    memset(ed,'.',sizeof(ed));
    node.clear();
    while(scanf("%d",&x)&&x!=-1){
        node.push_back(x);
    }
    for(int i=0;i<node.size();i++){
        if(node[i]==0){
            memset(ed,'*',sizeof(ed));
            for(int i=0;i<-n;i++){
                ed[i][-n]='\0';
                printf("%s\n",ed[i]);
            }
            //printf("\n");
            return;
        }
        print(node[i],0,0,-n);
    }

    for(int i=0;i<-n;i++){
        ed[i][-n]='\0';
        printf("%s\n",ed[i]);
    }
    //printf("\n");
}
int main(){
    freopen("ans.txt","r",stdin);
    freopen("ans1.txt","w",stdout);
    build_pow();
    int kase=0;
    while(scanf("%d",&n)&&n!=0){
        if(kase)printf("\n");
        printf("Image %d\n",++kase);
        if(n>0)ipt1();
        else ipt2();
    }
}
