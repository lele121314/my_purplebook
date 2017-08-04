#include<cstdio>
#include<algorithm>
#include<vector>

using namespace std;
vector<int> qq;
int lower(int x){
    for(int i=0;i<qq.size();i++){
        if(qq[i]>=x)return i;
    }
    return qq.size()-1;
}
int main(){
    freopen("ans.txt","r",stdin);
    int n,q;
    int kase=0;

    while(scanf("%d%d",&n,&q)!=EOF){
        if(n==0||q==0)break;
        qq.clear();
        printf("CASE# %d:\n",++kase);
        for(int i=0;i<n;i++){
            int a;
            scanf("%d",&a);
            qq.push_back(a);
        }
        sort(qq.begin(),qq.end());
        while(q--){
            int ans;
            scanf("%d",&ans);
            int p=lower(ans);
            if(qq[p]==ans)printf("%d found at %d\n",ans,p+1);
            else printf("%d not found\n",ans);
        }
    }
    return 0;
}

