#include<cstdio>
#include<set>
using namespace std;
set<int> ss;



int main(){
    int n;
    while(~scanf("%d",&n)){
        ss.clear();
        while(n--){
            int x;
            scanf("%d",&x);
            for(int i=1;i*i<=x;i++){
                if(x%i==0){
                    int t=x/i;
                    ss.insert(t);
                    ss.insert(i);
                }
            }
            printf("%d\n",ss.size());
            ss.clear();
        }
    }

}
