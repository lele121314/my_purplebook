#include<cstdio>
#include<iostream>
#include<cstring>
using namespace std;
long long x[19][19],maxn;
int n;
int a[19];
int main(){
    freopen("ans.txt","r",stdin);
    freopen("ans1.txt","w",stdout);
    ios::sync_with_stdio(false);
    int kase=0;
    while(cin>>n){
        maxn=-1000000000000000000;
        for(int i=1;i<=n;i++)cin>>a[i];

        for(int i=0;i<=n;i++){
            x[i][i]=1;
            for(int j=i+1;j<=n;j++){
                x[i][j]=x[i][j-1]*a[j];
                maxn=max(maxn,x[i][j]);
                //printf("%3d ",x[i][j]);
            }
            //printf("\n");
        }
        if(maxn<0)maxn=0;
        cout<<"Case #"<<++kase<<": The maximum product is "<<maxn<<".\n";
        cout<<endl;
    }
}
