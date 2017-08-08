#include<cstdio>
#include<vector>
#include<cstring>
using namespace std;
const int maxn=100+5;
int P[maxn],np,nt,nf;
bool ok;
struct E{
    vector<int> in,out;
}T[maxn];
bool ipt(){
    scanf("%d",&np);
    if(np==0)return false;
    for(int i=1;i<=np;i++)scanf("%d",&P[i]);
    scanf("%d",&nt);
    for(int i=1;i<=nt;i++){
        T[i].in.clear();
        T[i].out.clear();
        int x;
        while(scanf("%d",&x)&&x!=0){
            if(x>0)T[i].out.push_back(x);
            else T[i].in.push_back(-x);
        }
    }
    scanf("%d",&nf);
    return true;
}
bool move_t(){
    int p[maxn];

    for(int i=1;i<=nt;i++){
        bool can_fire=true;
        memcpy(p,P,sizeof(p));
        for(int j=0;j<T[i].in.size();j++){
            p[T[i].in[j]]--;
            if(p[T[i].in[j]]<0){
                can_fire=false;
                break;
            }
        }
        if(!can_fire)continue;
        for(int j=0;j<T[i].out.size();j++){
            p[T[i].out[j]]++;
        }
        memcpy(P,p,sizeof(p));
        return true;
    }
    return false;

}
void print_ans(int step){
    if(ok)printf("still live after %d transitions",step);
    else printf("dead after %d transitions",step-1);

    printf("\nPlaces with tokens:");
    for(int i=1;i<=np;i++){
        if(P[i]>0)printf(" %d (%d)",i,P[i]);
    }
    printf("\n\n");
}
int solve(){
    ok=true;
    for(int i=1;i<=nf;i++){
        print_ans(i-1);
        if(!move_t()){
            ok=false;
            return i;
        }
    }
    return nf;
}

int main(){
    freopen("ans.txt","r",stdin);
    freopen("ans1.txt","w",stdout);
    int  kase=0;
    while(ipt()){


        int step=solve();
        printf("Case %d: ",++kase);
        print_ans(step);
    }
    return 0;
}
