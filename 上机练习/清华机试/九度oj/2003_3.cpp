#include<cstdio>
#include<set>
#include<iostream>
using namespace std;
set<int> p;
int a[15];
int total=0;
void solve(int x){
    p.insert(total);
    if(x>=15) return ;
    total+=a[x];
    solve(x+1);
    total-=a[x];
    solve(x+1);
}
int main(){
    a[0]=8;
    a[1]=8;
    a[2]=8;
    a[3]=8;
    a[4]=8;
    a[5]=10;
    a[6]=10;
    a[7]=10;
    a[8]=10;
    a[9]=18;
    a[10]=18;
    a[11]=18;
    a[12]=18;
    a[13]=18;
    a[14]=18;
    solve(0);
//    for(set<int>::iterator it=p.begin();it!=p.end();it++){
//        cout<<*it<<endl;
//    }
    cout<<p.size()<<endl;
    return 0;
}
