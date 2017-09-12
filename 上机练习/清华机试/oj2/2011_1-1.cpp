#include<cstdio>
#include<algorithm>
#include<iostream>
#include<vector>
using namespace std;
#define inf 2211686018427387904
typedef long long ll;
int l1,l2,l3,c1,c2,c3;
int A,B;
vector<int> a;
ll dp[3000000];
ll fee(int x,int y){
    int dis=a[y]-a[x];
    if(dis<=l1)return c1;
    if(dis<=l2)return c2;
    if(dis<=l3)return c3;
    else return -1;
}
int main(){
  //  freopen("1.txt","r",stdin);
    while(cin>>l1>>l2>>l3>>c1>>c2>>c3){
        a.clear();
        cin>>A>>B;
        int n;
        cin>>n;
        a.push_back(0);
        a.push_back(0);
        for(int i=2;i<=n;i++){
            int x;
            cin>>x;
            a.push_back(x);
        }
        for(int i=A+1;i<=B;i++)dp[i]=inf;
        dp[A]=0;
        for(int i=A;i<B;i++){
            for(int j=i+1;j<=B;j++){
                ll dis=fee(i,j);
                if(dis==-1)break;
                dp[j]=min(dp[i]+dis,dp[j]);
            }
        }
        cout<<dp[B]<<endl;
    }
    return 0;
}
