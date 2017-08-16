#include<iostream>
#include<string>
#include<cstdio>
using namespace std;


string a,b;
void build(int ia,int ib,int len){
    if(len==0)return ;
    //if(len==1)cout<<a[ia];

    for(int j=ib;j<ib+len;j++){
        if(a[ia]==b[j]){
            build(ia+1,ib,j-ib);
            build(ia+j-ib+1,j+1,len-j+ib-1);
            cout<<a[ia];
            return;
        }
    }

}
int main(){
    freopen("1.txt","r",stdin);
    while(cin>>a>>b){
        build(0,0,a.length());
        cout<<endl;
    }
}
