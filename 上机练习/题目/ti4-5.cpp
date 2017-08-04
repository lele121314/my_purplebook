#include<stdio.h>
#include<string.h>
char a[13],b[13];
void change1(){
    strcpy(b,a);
    b[0]=a[2];
    b[2]=a[5];
    b[3]=a[0];
    b[5]=a[3];
    strcpy(a,b);
}
void change2(){
    strcpy(b,a);
    b[1]=a[3];
    b[2]=a[1];
    b[3]=a[4];
    b[4]=a[2];
    strcpy(a,b);
}
void change(int x){
    if(x%5==0)change1();
    change2();
   // printf("%s\n",a);
}
bool cmp(){
    for(int i=0;i<6;i++){
        if(a[i+6]!=a[i])return false;
    }
    return true;
}
bool find1(){
    for(int i=0;i<4;i++){
        for(int j=0;j<4;j++){
            if(cmp())return true;
            change2();
        }
        change1();
    }
    change1();
    change2();
    change1();
    for(int i=0;i<4;i++){
        for(int j=0;j<4;j++){
            if(cmp())return true;
            change2();
        }
        change1();
    }
    return false;
}
int main(){
    freopen("ans.txt","r",stdin);
    freopen("ans1.txt","w",stdout);
    while(scanf("%s",a)!=EOF){


        printf("%s\n",find1()?"TRUE":"FALSE");
    }
    return 0;
}
