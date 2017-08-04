#include<set>
#include<vector>
#include<cstdio>
using namespace std;
void change(vector<int>& s){
    int a=s[0];
    for(int i=0;i<s.size()-1;i++){
        s[i]=s[i]-s[i+1];
    }
    s[s.size()-1]=s[s.size()-1]-a;
}
int main(){
    freopen("ans.txt","r",stdin);
    int t;
    scanf("%d",&t);
    while(t--){
        int n;
        vector<int> a;
        scanf("%d",&n);
        while(n--){
            int x;
            scanf("%d",&x);
            a.push_back(x);
        }
        set<vector<int> > is;
        int num=1001;
        int isfind=false;
        while(num--){
            if(is.count(a)){
                isfind=true;
                break;
            }
            is.insert(a);
            change(a);
        }
        printf("%s\n",!isfind?"LOOP":"ZERO");
    }
}
