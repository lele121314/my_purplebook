#include<cstdio>
#include<cstdlib>
#include<iostream>
using namespace std;
long long int QuickPow(long long int n,long long int base,long long int k)
{
    long long int ans=1;
    while(n){
        if(n&1)ans=(base*ans)%k;
        base=(base*base)%k;
        n>>=1;
    }
    return ans;
}


int main()
{
    long long int x,y,k,z;
    while(cin>>x>>y>>k){
        z=QuickPow(y,x,k-1);
        if(z==0)z=k-1;
        cout<<z<<endl;
    }
    return 0;
}
