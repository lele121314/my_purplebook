#include <stdio.h>
#include <stdlib.h>
#define p 1000000007
using namespace std;

int n,m,a,ca,c,i,j,k,ans;
int b[105];

long long calc(long long n)
{
	long long n1=n,n2=n+1,n3=2*n+1;
	if(n1%2==0)n1/=2;else n2/=2;
	if(n1%3==0)n1/=3;else if(n2%3==0)n2/=3;else n3/=3;
	return n1*n2%p*n3%p;
}

int main()
{
	freopen("polynomial.in","r",stdin);
	freopen("polynomial.out","w",stdout);
	scanf("%d%d%d",&n,&m,&a);
	for(i=0;i<=m;++i)scanf("%d",&b[i]);
	if(a==1&&m<=2)
	{
		ans=(long long)b[0]*(n+1)%p;
		ans=(ans+(long long)n*(n+1)/2%p*b[1]%p)%p;
		ans=(ans+(long long)b[2]*calc(n))%p;
		printf("%d\n",ans);
		return 0;
	}
	ca=1;
	for(i=0;i<=n;++i)
	{
		c=ca;ca=(long long)ca*a%p;
		for(j=0;j<=m;++j)
		{
			ans=(ans+(long long)c*b[j])%p;
			c=(long long)c*i%p;
		}
	}
	printf("%d\n",ans);
}
