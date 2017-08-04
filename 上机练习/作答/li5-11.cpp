#include<algorithm>
#include<cstdio>
#include<cstring>
#include<cmath>
using namespace std;
const int maxn=145;
int n,pos;
double sum,pri[maxn];
struct player{
    char name[25];
    double prize;
    bool amateur,t;
    int sc[4],prt,tot,dq,rk;
} p[maxn];
void init(){
    memset(p,0,sizeof(p));
    scanf("%lf",)
}
int main(){
    int t;
    scanf("%d",&t);
    while(t--){
        init();
        solve();
        print_ans();
        if(t)printf("\n");
    }
}
