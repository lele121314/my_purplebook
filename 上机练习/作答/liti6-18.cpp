#include<cstdio>
#include<algorithm>
#include<set>
#include<cstring>
using namespace std;
const int maxn=110;
int vis[maxn][maxn][maxn],vv[maxn][maxn][maxn];
int n,xn,yn,zn;
int xb[maxn],yb[maxn],zb[maxn];
struct e{
    int x0,y0,z0,x,y,z;
    bool operator == (const e &b) const{
        return x0==b.x0&&
         y0==b.y0&&
         z0==b.z0&&
         x==b.x&&
         y==b.y&&
         z==b.z;
    }
    bool operator < (const e &b) const{
        if(x0!=b.x0)return x0<b.x0;
        else if(y0!=b.y0)return y0<b.y0;
        else if(z0!=b.z0)return z0<b.z0;
    }
}box[maxn];
bool is_box(int ii,int jj,int kk){

        if(vv[ii][jj][kk]==2)return true;

    return false;
}
int v,s;
bool is_in(int i,int j,int k){
    if(i<0||i>=xn-1||j<0||j>=yn-1||k<0||k>=zn-1)return false;
    return true;
}
const int dx[]={1,-1,0,0,0,0};
const int dy[]={0,0,1,-1,0,0};
const int dz[]={0,0,0,0,1,-1};
void dfs(int i,int j,int k){
    v+=(xb[i+1]-xb[i])*(yb[j+1]-yb[j])*(zb[k+1]-zb[k]);
   // printf("%d %d %d : %d\n",i,j,k,(xb[i+1]-xb[i])*(yb[j+1]-yb[j])*(zb[k+1]-zb[k]));
    vis[i][j][k]=1;
    for(int w=0;w<6;w++){
        int ii=i+dx[w],jj=j+dy[w],kk=k+dz[w];
        if(!is_in(ii,jj,kk))continue;
        if(vis[ii][jj][kk]==1)continue;

        box[0].x0=xb[ii];
        box[0].y0=yb[jj];
        box[0].z0=zb[kk];
        box[0].x=xb[ii+1]-xb[ii];
        box[0].y=yb[jj+1]-yb[jj];
        box[0].z=zb[kk+1]-zb[kk];
       //printf("%d %d %d : %d %d %d\n",box[0].x0,box[0].y0,box[0].z0,box[0].x,box[0].y,box[0].z);

        if(is_box(ii,jj,kk)){
           // printf("888\n");
            if(w<2) s+=box[0].y*box[0].z;
            else if(w<4) s+=box[0].x*box[0].z;
            else s+=box[0].x*box[0].y;
            continue;
        }
        dfs(ii,jj,kk);

    }

}
void solve(){
    v=0;s=0;
    memset(vis,0,sizeof(vis));
    dfs(0,0,0);
    int V=(xb[xn-1]-xb[0])*(yb[yn-1]-yb[0])*(zb[zn-1]-zb[0]);
    printf("%d %d\n",s,V-v);
}
void build(){

}
void input(){
    scanf("%d",&n);
    for(int i=1;i<=n;i++){
        scanf("%d%d%d%d%d%d",&box[i].x0,&box[i].y0,&box[i].z0,&box[i].x,&box[i].y,&box[i].z);
        xb[i*2-1]=box[i].x0;xb[i*2]=box[i].x0+box[i].x;
        yb[i*2-1]=box[i].y0;yb[i*2]=box[i].y0+box[i].y;
        zb[i*2-1]=box[i].z0;zb[i*2]=box[i].z0+box[i].z;
    }
    //sort(box+1,box+n+1);
    sort(xb+1,xb+2*n+1);sort(yb+1,yb+2*n+1);sort(zb+1,zb+2*n+1);
    xn=unique(xb+1,xb+2*n+1)-xb;yn=unique(yb+1,yb+2*n+1)-yb;zn=unique(zb+1,zb+2*n+1)-zb;
    xb[0]=xb[1];xb[xn]=xb[xn-1];xn+=1;
    yb[0]=yb[1];yb[yn]=yb[yn-1];yn+=1;
    zb[0]=zb[1];zb[zn]=zb[zn-1];zn+=1;
    memset(vv,0,sizeof(vv));
    for(int i=1;i<=n;i++){
        int x1,x2,y1,y2,z1,z2;
        x1=lower_bound(xb+1,xb+xn+1,box[i].x0)-xb;
        x2=lower_bound(xb+1,xb+xn+1,box[i].x0+box[i].x)-xb;
        y1=lower_bound(yb+1,yb+yn+1,box[i].y0)-yb;
        y2=lower_bound(yb+1,yb+yn+1,box[i].y0+box[i].y)-yb;
        z1=lower_bound(zb+1,zb+zn+1,box[i].z0)-zb;
        z2=lower_bound(zb+1,zb+zn+1,box[i].z0+box[i].z)-zb;
//        printf("%d %d\n",box[i].x0,xb[x1]);
//        printf("%d %d\n",box[i].x0+box[i].x,xb[x2]);
//        printf("%d %d\n",box[i].y0,yb[y1]);
//        printf("%d %d\n",box[i].y0+box[i].y,yb[y2]);
//        printf("%d %d\n",box[i].z0,zb[z1]);
//        printf("%d %d\n",box[i].z0+box[i].z,zb[z2]);
        for(int w=x1; w<x2; w++)    //左闭右开区间填格子
            for(int j=y1; j<y2; j++)
                for(int k=z1; k<z2; k++)
                    vv[w][j][k] = 2;


    }
}
int main(){
    freopen("ans.txt","r",stdin);
    //freopen("ans1.txt","w",stdout);
    int T;
    scanf("%d",&T);
    while(T--){
       input();
       build();
//        box[0].x0=1;
//        box[0].y0=2;
//        box[0].z0=3;
//        box[0].x=3;
//        box[0].y=4;
//        box[0].z=5;
//       printf("%d\n",is_box());
//       printf("%d %d %d\n%d %d %d\n",xb[0],yb[0],zb[0],xb[xn-1],yb[yn-1],zb[zn-1]);
//       printf("%d %d %d\n",xn,yn,zn);

       solve();
    }
    return 0;
}
