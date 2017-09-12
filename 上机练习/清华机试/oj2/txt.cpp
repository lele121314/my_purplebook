#include<iostream>
using namespace std;

int main(){
    long long a0,a1,p,q,k;
    ios::sync_with_stdio(false);
    cin.tie(0);
    while(cin>>a0>>a1>>p>>q>>k){
            for(int i=2;i<=k;i++){
            long long a2=(p*a1+q*a0)%10000;
            a0=a1;
            a1=a2;
        }
        cout<<a1<<endl;
    }
    return 0;
}
