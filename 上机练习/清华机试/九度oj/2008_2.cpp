#include<cstdio>
#include<cstring>
#include<cmath>

using namespace std;

int m,n;
char in[100000];
char out[100000];
int i2o(char x){
    if(x>='0'&&x<='9')return x-'0';
    else return x-'A'+10;
}
char o2i(long long x){
    if(x>9)return x-10+'a';
    else return x+'0';
}
int main(){
    freopen("1.txt","r",stdin);
    while(scanf("%d%d",&m,&n)!=EOF){
        scanf("%s",in);
        int len=strlen(in);
        int x=0;
        for(int i=0;i<len;i++){
            int num=i2o(in[len-i-1]);
            x+=pow(m,i)*num;
        }
        memset(out,0,sizeof(out));
        int idx=0;
//        for(int i=0;i<36;i++){
//            printf("%c\n",o2i(i));
//        }
        while(x){
            int son=x%n;
            out[idx++]=o2i(son);
            x/=n;
        }
        while(idx>=0)printf("%c",out[--idx]);
        printf("\n");

    }
}
