#include<cstdio>
#include<iostream>
#include<cstring>
#include<string>
using namespace std;
int n;
int a[100000];
int main(){
    while(cin>>n){
        a[0]=0;a[1]=1;a[2]=1;
        cout<<a[0]<<endl;
        int x=1;
        for(int i=1;i<n;i++){


            a[x+1]=a[x]+a[x-1];
            a[x+2]=a[x]+a[x+1];
            cout<<a[0];
            for(int j=1;j<x+2;j++)cout<<' '<<a[j];
            cout<<endl;
            x+=2;

        }
    }
    return 0;
}
