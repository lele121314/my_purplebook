#include<cstdio>
#define mo 1000000000
int f[1000000+5];

int main(){
    f[1]=1;f[2]=2;
    for(int i=3;i<=1000000;i++){
        if(i%2==0){
            f[i]=(f[i/2]+f[i-1])%mo;
        }
        else f[i]=f[i-1];
    }
    int n;
    while(~scanf("%d",&n)){
        printf("%d\n",f[n]);
    }
}
