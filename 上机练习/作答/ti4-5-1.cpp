#include<stdio.h>
#include<algorithm>
using namespace std;
struct e{
int a,b,c,d;
}edg[1002];
int a1=0,b1=0,c1=0,d1=0;
int a11=0,b11=0,c11=0,d11=0;
bool cmp(e a,e b){
    if(a.a!=b.a)return a.a<b.a;
    else if(a.b!=b.b)return a.b<b.b;
    else if(a.c!=b.c)return a.c<b.c;
    else return a.d<b.d;
}
void comp(int n){
    a11=0,b11=0,c11=0,d11=0;
    a1=0,b1=0,c1=0,d1=0;
    int x=1<<7;
    for(int i=0;i<8;i++){
        int t1=edg[0].a&x,t2=edg[n].a&x;
        if(t1==t2){a1+=t1;a11+=x;}
        else return;
        x=x>>1;
    }
    x=1<<7;
    for(int i=0;i<8;i++){
        int t1=edg[0].b&x,t2=edg[n].b&x;
        if(t1==t2){b1+=t1;b11+=x;}
        else return;
        x=x>>1;
    }
    x=1<<7;
    for(int i=0;i<8;i++){
        int t1=edg[0].c&x,t2=edg[n].c&x;
        if(t1==t2){c1+=t1;c11+=x;}
        else return;
        x=x>>1;
    }

    x=1<<7;
    for(int i=0;i<8;i++){
        int t1=edg[0].d&x,t2=edg[n].d&x;
        if(t1==t2){d1+=t1;d11+=x;}
        else return;
        x=x>>1;
    }

}
int main(){
    freopen("ans.txt","r",stdin);
    int n;
    while(scanf("%d",&n)!=EOF){
        for(int i=0;i<n;i++)scanf("%d.%d.%d.%d",&edg[i].a,&edg[i].b,&edg[i].c,&edg[i].d);
        sort(edg,edg+n,cmp);
        //printf("%d %d %d %d\n",edg[0].a,edg[0].b,edg[0].c,edg[0].d);
        comp(n-1);
        printf("%d.%d.%d.%d\n%d.%d.%d.%d\n",a1,b1,c1,d1,a11,b11,c11,d11);
    }
}
