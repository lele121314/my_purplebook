#include<cstdio>
#include<cstring>
const int maxn=99999+1;
bool is_vis[maxn];
bool is_cnt[10];
int n,ans;
void solve(){
    for(int f=0;f<10;f++){
        is_cnt[f]=true;
       for(int g=0;g<10;g++){
           if(is_cnt[g])continue;
            is_cnt[g]=true;
            for(int h=0;h<10;h++){
                if(is_cnt[h])continue;
                is_cnt[h]=true;
                for(int i=0;i<10;i++){
                    if(is_cnt[i])continue;
                    is_cnt[i]=true;
                    for(int j=0;j<10;j++){
                        if(is_cnt[j])continue;
                        is_cnt[j]=true;
                        bool can_find=true;
                        int num=f*10000+g*1000+h*100+i*10+j;
                        //printf("%d\n",num);
                        int result=num*n;
                        if(result>=maxn){
                            return;
                        }
                        char abcde[6];
                        bool is[10];
                        memcpy(is,is_cnt,sizeof(is));
                        sprintf(abcde,"%d",result);
                        for(int index=0;index<5;index++){
                            if(is[abcde[index]-'0']){
                                can_find=false;
                                break;
                            }
                            is[abcde[index]-'0']=true;
                        }
                        if(can_find){
                                ans++;
                            printf("%s / %d%d%d%d%d = %d\n",abcde,f,g,h,i,j,n);
                        }
                        is_cnt[j]=false;
                    }
                    is_cnt[i]=false;
                }
                is_cnt[h]=false;
            }
            is_cnt[g]=false;
       }
       is_cnt[f]=false;
    }
}
int main(){
    freopen("ans.txt","r",stdin);
    freopen("ans1.txt","w",stdout);
    int kase=0;
    while(scanf("%d",&n)==1&&n!=0){
        if(kase++)printf("\n");
        memset(is_cnt,false,sizeof(is_cnt));
        ans=0;
        solve();
        if(!ans)printf("There are no solutions for %d.\n",n);
    }
}
