#include<cstdio>
#include<cstring>

using namespace std;
const int mo=10000;
int pq[2][2];
void MetrixMul(int p1[2][2],int p2[2][2])
{
	int t[2][2];
	t[0][0]=(p1[0][0]*p2[0][0]%10000+p1[0][1]*p2[1][0]%10000)%10000;
	t[0][1]=(p1[0][0]*p2[0][1]%10000+p1[0][1]*p2[1][1]%10000)%10000;
	t[1][0]=(p1[1][0]*p2[0][0]%10000+p1[1][1]*p2[1][0]%10000)%10000;
	t[1][1]=(p1[1][0]*p2[0][1]%10000+p1[1][1]*p2[1][1]%10000)%10000;
	p1[0][0]=t[0][0];
	p1[0][1]=t[0][1];
	p1[1][0]=t[1][0];
	p1[1][1]=t[1][1];

}
int main(){
    int a0,a1,p,q,k;
    while(scanf("%d%d%d%d%d",&a0,&a1,&p,&q,&k)!=EOF){
if(k==0)
        {
            printf("%d\n",a0%10000);
            continue;
        }
        if(k==1)
        {
            printf("%d\n",a1%10000);
            continue;
        }

        pq[0][0]=p;
        pq[0][1]=q;
        pq[1][0]=1;
        pq[1][1]=0;
        int ans[2][2];
        ans[0][0]=1;
        ans[0][1]=0;
        ans[1][0]=1;
        ans[1][1]=0;
        k--;
        while(k){
            if(k%2==1){
                MetrixMul(ans,pq);
            }
            MetrixMul(pq,pq);
            k/=2;

        }
        int ans1;
        ans1=ans[0][0]*a1+ans[0][1]*a0;
        printf("%d\n",ans1%mo);
    }
}
