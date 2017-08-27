#include<cstdio>
#include<iostream>
#include<vector>
using namespace std;
vector<int> p;
double abs(double x){
    if(x>0)return x;
    return -x;
}
int main(){
    freopen("ans.txt","r",stdin);
    freopen("ans1.txt","w",stdout);
    int n;
    while(scanf("%d",&n)!=EOF){
        int ans=0;
        p.clear();
        for(int i=1;i<=2*n;i++){
            double k=n,y=i;
            double x=k*y/(y-k);
            int kk=x;
            if(abs(kk-x)<0.000001&&kk>0){
                p.push_back(n);p.push_back(kk);p.push_back(i);
                ans++;
            }
        }
        cout<<ans<<endl;
        for(int i=0;i<p.size();i+=3){
            cout<<"1/"<<p[i]<<" = 1/"<<p[i+1]<<" + 1/"<<p[i+2]<<endl;
        }
    }
}
