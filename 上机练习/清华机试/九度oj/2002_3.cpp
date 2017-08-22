#include<iostream>
#include<cstdio>
#include<cstring>
using namespace std;
char x[100000];
void judge(long xxx){
    long xx=xxx*xxx;
    sprintf(x,"%ld",xx);
    int len=strlen(x);
    for(int i=0;i<len;i++){
        if(x[i]!=x[len-i-1])return ;

    }
    cout<<xxx<<endl;
}
int main(){
    for(long i=0;i<=256;i++){
        judge(i);
    }
}
