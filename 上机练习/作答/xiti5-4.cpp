#include<cstdio>
#include<map>

using namespace std;
map<pair<int,int>,int > ss;

int main(){
    freopen("ans.txt","r",stdin);
    freopen("ans1.txt","w",stdout);
    int n;
    while(scanf("%d",&n)==1&&n){
            ss.clear();
        while(n--){
            int x,y;
            scanf("%d%d",&x,&y);
            pair<int,int> ne=make_pair(x,y);
            pair<int,int> ne1=make_pair(y,x);

            if(ss[ne1]){
                ss[ne1]--;
            }
            else{
                ss[ne]++;
            }
            if(!ss[ne1])ss.erase(ne1);
        }
        printf("%s\n",ss.size()?"NO":"YES");
    }
}
