#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
int n,m,k;
int x[100000+5]={0};
bool C(int d){
    if(d<m)return false;
    int xx[100000+5]={0};
    int mx=x[1],mi=x[1];
    for(int i=1;i<=d;i++){
        xx[x[i]]++;
        mx=max(mx,x[i]);
        mi=min(mi,x[i]);
    }
    for(int i=mi;i<=mx;i++){
        xx[i]+=xx[i-1];
        //printf("%d %d\n",i,xx[i]);
    }

    for(int i=mi;i+k+1<=mx;i++){
        if(xx[i+k+1]-xx[i]>=m)return true;
    }
    return false;

}
int main(){
    freopen("20.in","r",stdin);
    scanf("%d%d%d",&n,&m,&k);
    for(int i=1;i<=n;i++){
        scanf("%d",&x[i]);
    }
    //printf("%d %d\n",5,C(5));
//    for(int i=70000;i<=n;i++){
//
//        printf("%d %d\n",i,C(i));
//    }
    int lb=1,ub=n+1;
    while(ub-lb>1){

        int mid=(lb+ub)/2;
        if(!C(mid))lb=mid;
        else ub=mid;
        //printf("%d %d\n",lb,ub);
    }
    if(ub==n+1)printf("impossible");
    else printf("%d",ub);
    return 0;

}
