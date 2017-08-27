#include<cstdio>
#include<cstring>
#include<set>
using namespace std;
const int maxn=1000+10;
int a;
set<int> p;
int main(){
    freopen("1.txt","r",stdin);
    int n;
    while(scanf("%d",&n)!=EOF){
        for(int i=0;i<n;i++){
            scanf("%d",&a);
            int ans=0;
            p.clear();
            for(int j=1;j*j<=a;j++){
                if(a%j==0){
                    int x=a/j;
                    if(!p.count(j)){
                        p.insert(j);
                        ans++;
                    }
                    if(!p.count(x)){
                        p.insert(x);
                        ans++;
                    }
                }
            }
            printf("%d\n",ans);
        }

    }
}
