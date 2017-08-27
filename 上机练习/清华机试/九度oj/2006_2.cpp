#include<iostream>
#include<cstdio>
#include<algorithm>
#include<climits>
using namespace std;


int n;
long long a[1000000+1];
long long solve(){
    long long maxn=INT_MIN;
    long long now=a[0];
    for(int i=1;i<n;i++){
        if(now>0){
            now+=a[i];
        }else now=a[i];
        maxn=max(now,maxn);
    }
    return maxn;
}
int main(){
    freopen("1.txt","r",stdin);
    while(cin>>n){
        for(int i=0;i<n;i++)cin>>a[i];
        cout<<solve()<<endl;
    }
    return 0;
}

