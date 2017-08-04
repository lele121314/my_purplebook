#include<cstdio>
#include<queue>
using namespace std;
queue<int> p;
int main(){
    freopen("ans.txt","r",stdin);
    freopen("ans1.txt","w",stdout);
    int n;
    while(scanf("%d",&n)==1&&n){
        while(!p.empty())p.pop();
        for(int i=1;i<=n;i++)p.push(i);
        printf("Discarded cards:");
        while(p.size()!=1){
            if(p.size()!=n)printf(",");
            printf(" %d",p.front());
            p.pop();
            int x=p.front();
            p.pop();
            p.push(x);
        }
        printf("\nRemaining card: %d\n",p.front());
        p.pop();

    }
    return 0;
}
