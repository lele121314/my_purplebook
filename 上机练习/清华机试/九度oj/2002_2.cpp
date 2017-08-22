#include<cstdio>
#include<set>
#include<iostream>
#include<cstring>
using namespace std;
int n;
long a[10000],b[10000];
void solve(int x){
    if(x>=n)return;

}
int main(){
    while(cin>>n){
        a[0]=1;a[1]=1;a[2]=-1;
        cout<<"1 1\n";
        for(int i=1;i<n-1;i++){
            memcpy(b,a,sizeof(a));
            cout<<1<<" ";
            int x=1;
            while(a[x]!=-1){
                cout<<b[x-1]+b[x]<<" ";
                a[x]=b[x]+b[x-1];
                x++;
            }
            a[x]=1;
            a[x+1]=-1;
            cout<<1<<endl;
        }
    }
    return 0;
}
