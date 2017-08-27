#include<cstdio>
#include<cstring>
#include<vector>
//·ÅÆú
using namespace std;
struct tree{
    double L,R;
    tree():L(0),R(0){}
};

const int maxn=6

int n,vis[1<<maxn];
double r,w[maxn],sum[1<<maxn];
vector<tree> Tree[1<<maxn];
void input(){
    scanf("%lf",&r);
    scanf("%d",&n);
    for(int i=0;i<n;i++)scanf("%lf",&w[i]);
    for(int i=0;i<(1<<n);i++){
        sum[i]=0;
        tree[i].clear();
        for(int j=0;j<n;j++)
            if(i&(1<<j))

    }
}

void solve(){

}
int main(){
    freopen("ans.txt","r",stdin);
    int t;
    while(t--){
        input();
        //output();
        solve();
    }
}
