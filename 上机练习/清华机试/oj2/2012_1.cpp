#include<cstdio>
int min(int a,int b){
    return a>b?b:a;
}
int max(int a,int b){
    return a<b?b:a;
}
int main(){
    int n;
    while(scanf("%d",&n)!=EOF){
        int maxx,minx;
        if(n==0){
            printf("\n");
            continue;
        }
        scanf("%d",&maxx);
        minx=maxx;
        for(int i=1;i<n;i++){
            int t;
            scanf("%d",&t);
            minx=min(minx,t);
            maxx=max(maxx,t);
        }
        printf("%d %d\n",maxx,minx);
    }
    return 0;
}

