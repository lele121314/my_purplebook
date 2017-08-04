#include<iostream>
using namespace std;
void swap2(int& a,int& b){
    int r=a;
    a=b;
    b=r;
}
int main(){
    int a=3,b=4;
    swap2(a,b);
    cout<<a<<" "<<b<<endl;
    return 0;
}
