#include<cstdio>
#include<cstring>
const int maxn=100001;

bool mark[maxn];
int prime[maxn];
int primeSize;
void init()
{
    primeSize=0;
    memset(mark,false,sizeof(mark));
    for(int i=2;i<maxn;i++){
        if(mark[i])continue;
        prime[primeSize++]=i;
        if(i>=1000)continue;
        for(int j=i*i;j<maxn;j+=i){
            mark[j]=true;
        }
    }
}
int main()
{
    init();
    int n;
    while(scanf("%d",&n)!=EOF){

        int ansprime[30];
        int ansSize=0;
        int ansNum[30];

        for(int i=0;i<primeSize;i++){
            if(n%prime[i]==0){
                ansprime[ansSize]=prime[i];
                ansNum[ansSize]=0;

                while(n%prime[i]==0){
                        printf("666\n");
                    ansNum[ansSize]++;
                    n/=prime[i];
                }
                ansSize++;
                if(n==1)break;
            }
        }
        if(n!=1){
            ansprime[ansSize]=n;
            ansNum[ansSize++]=1;
        }

        int ans=0;
        for(int i=0;i<ansSize;i++)ans+=ansNum[i];
        printf("%d\n",ans);
    }
    return 0;
}
