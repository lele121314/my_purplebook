#include<cstdio>
#include<queue>
using namespace std;
int a[10];
int main(){
    freopen("ans.txt","r",stdin);
    freopen("ans1.txt","w",stdout);
    int t;
    scanf("%d",&t);
    while(t--){
        int n,m;

        scanf("%d%d",&n,&m);
        for(int i=0;i<n;i++){
            scanf("%d",&a[i]);

        }
        int ans=0;
        bool is_find=false;
        int j=0;
        int po=0;
        for(int i=9;i>=a[m];i--){
            int count1=0;
            j=po;
            while(true){
                   // printf("%d %d %d\n",j,count1,i);
                if(a[j]==i){
                       // printf("%d %d %d\n",j,count1,i);
                    ans++;
                    po=j;
                    if(m==j){

                        is_find=true;

                        break;
                    }
                }

                j++;
                j=j%n;
                count1++;
                if(count1==n)break;

            }
            if(is_find)break;
        }
        printf("%d\n",ans);
    }
    return 0;
}
