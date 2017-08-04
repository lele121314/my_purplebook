#include<stdio.h>
int n,a,b,c,d,aa,bb,cc,dd,a1,b1,c1,d1,a0,b0,c0,d0;
void ex(){
    a=aa;b=bb;
    c=cc;d=dd;
    a0=a1;b0=b1;c0=c1;d0=d1;
}
bool small(int aa1,int bb1,int cc1,int dd1){
    if(aa1>a1||bb1>b1||cc1>c1||dd1>d1)true;
    else return false;
}
void cmp(){
    a1=0,b1=0,c1=0,d1=0;
    int x=1<<7;
    for(int i=0;i<8;i++){
    //printf("%d %d\n",aa&x,a&x);
    //printf("%d\n",x);
        int t1=aa&x,t2=a&x;
        if(t1==t2)a1++;
        else return;
        x=x>>1;

    }
                x=1<<7;
    for(int i=0;i<8;i++){
            int t1=bb&x,t2=b&x;
        if(t1==t2)b1++;else return;
        x=x>>1;
    }
    x=1<<7;
    for(int i=0;i<8;i++){
        int t1=cc&x,t2=c&x;
        if(t1==t2)c1++;else return;
        x=x>>1;
    }
                x=1<<7;
    for(int i=0;i<8;i++){
        int t1=dd&x,t2=d&x;
        if(t1==t2)d1++;else return;
        x=x>>1;
    }
}
int main(){
    freopen("ans.txt","r",stdin);
    while(scanf("%d",&n)!=EOF){
        scanf("%d.%d.%d.%d",&a,&b,&c,&d);
        scanf("%d.%d.%d.%d",&aa,&bb,&cc,&dd);
        cmp();

        for(int i=2;i<n;i++){

            a0=a1;b0=b1;c0=c1;d0=d1;
            scanf("%d.%d.%d.%d",&aa,&bb,&cc,&dd);
            cmp();

            if(small(a0,b0,c0,d0))ex();

        }
        printf("%d %d %d %d\n",a,b,c,d);

    }
}
