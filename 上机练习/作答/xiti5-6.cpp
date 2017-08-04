#include<cstdio>
#include<algorithm>
#include<vector>
#include<utility>
using namespace std;
vector<pair<int,int> > qq1,qq2;
bool cmp1(pair<int,int> xx,pair<int,int>  yy){
    if(xx.first!=yy.first)return xx.first < yy.first;
    else return xx.second < yy.second;
}
bool cmp2(pair<int,int>  xx,pair<int,int>  yy){
    if(xx.first!=yy.first)return xx.first > yy.first;
    else return xx.second < yy.second;
}

int main(){
    freopen("ans.txt","r",stdin);
    int t;
    scanf("%d",&t);
    while(t--){
        qq1.clear();
        qq2.clear();
        pair<int,int> a;
        a.first=1;
        int n;
        scanf("%d",&n);
        while(n--){
            int x,y;
            scanf("%d%d",&x,&y);
            pair<int,int> xy=make_pair(x,y);
            qq1.push_back(xy);
            qq2.push_back(xy);
        }
        sort(qq1.begin(),qq1.end(),cmp1);
        sort(qq2.begin(),qq2.end(),cmp2);
        bool isf=false;
        int len=qq2[0].first+qq1[0].first;

        //printf("len  %d\n",len);
        for(int i=0;i<qq1.size();i++){
        //printf("%d %d %d %d\n",qq1[i].first,qq1[i].second,qq2[i].first,qq2[i].second );

            if(!(qq1[i].first ==len-qq2[i].first &&
               qq1[i].second ==qq2[i].second)){
                //printf("%d %d %d %d\n",qq1[i].first,qq1[i].second,qq2[i].first,qq2[i].second );
                isf=true;
                break;
            }
        }
        printf("%s\n",isf?"NO":"YES");

    }
}
