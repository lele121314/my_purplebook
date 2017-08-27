#include<cstdio>
void print_permutation(int n,int* A,int cur){
    if(cur==n){
        for(int i=0;i<n;i++)printf("%d ",A[i]);
        printf("\n");
    }
    else for(int i=1;i<=n;i++){
        int ok=1;
        for(int j=0;j<cur;j++){
            if(A[j]==i)ok=0;
        }
        if(ok){
            A[cur]=i;
            print_permutation(n,A,cur+1);
        }
    }
}
int a[199999999];
int main(){
    //freopen("ans.txt","r",stdin);
    //freopen("ans1.txt","w",stdout);
    int n;
    while(scanf("%d",&n)!=EOF){
        print_permutation(n,a,0);
    }
}
