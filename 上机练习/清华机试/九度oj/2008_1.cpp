#include<cstdio>
#include<cstring>

char inp[105];
char x[256],p[256];
//     abc def
//ghi  jkl mno
//pqrs tuv wxyz
int is(char a,char b){
    if(p[a]==p[b])return 2;
    return 0;
}
int main(){
    freopen("1.txt","r",stdin);
    for(int i='a';i<='r';i++){
        int n;
        n=(i-'a')%3;
        x[i]=n+1;
        p[i]=(i-'a')/3;
    }
    x['s']=4;
    p['s']=5;
    for(int i='t';i<='y';i++){
        int n;
        n=(i-'t')%3;
        x[i]=n+1;
        p[i]=(i-'t')/3+5+1;
    }
    x['z']=4;
    p['z']=7;
    //for(int i='a';i<='z';i++)printf("%c %d\n",i,p[i]);
    while(scanf("%s",inp)!=EOF){
        int len=strlen(inp);
        int ans=x[inp[0]];
        for(int i=1;i<len;i++){
            ans+=x[inp[i]]+is(inp[i-1],inp[i]);
        }
        printf("%d\n",ans);
    }
}
