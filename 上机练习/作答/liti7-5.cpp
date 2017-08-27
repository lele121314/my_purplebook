#include<cstdio>

int L,n;
int S[85];
int cnt;
int dfs(int cur){
    if(cnt++==n){
        int i;
        for( i=0;i<cur;i++){
            printf("%c",'A'+S[i]);
            if(i%64==63){
                printf("\n");
            }
            else if(i%4==3&&i!=cur-1){
                printf(" ");
            }

        }
        //printf("%d\n",i%(4*16) );
        if(i%(4*16)!=0)
            printf("\n");
        printf("%d\n",cur);
        return 0;
    }
    for(int i=0;i<L;i++){
        S[cur]=i;
        int ok=1;
        for(int j=1;j*2<=cur+1;j++){
            int equal=1;
            for(int k=0;k<j;k++){
                if(S[cur-k]!=S[cur-k-j]){
                    equal=0;break;
                }
            }
            if(equal){
                ok=0;break;
            }
        }
        if(ok)if(!dfs(cur+1))return 0;
    }
    return 1;
}
int main(){
    freopen("ans.txt", "r", stdin);
    freopen("ans1.txt", "w", stdout);
    while(scanf("%d%d",&n,&L)==2){
        if(n==0&&L==0)break;
        cnt=0;
        dfs(0);
    }
    return 0;
}
