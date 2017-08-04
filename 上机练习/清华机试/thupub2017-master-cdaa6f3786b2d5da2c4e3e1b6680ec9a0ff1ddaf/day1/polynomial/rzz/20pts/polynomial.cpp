#include <stdio.h>
#include <stdlib.h>
#define p 1000000007
using namespace std;

int n,m,a,ca,c,i,j,k,ans;
int b[105];

int main()
{
	freopen("polynomial.in","r",stdin);
	freopen("polynomial.out","w",stdout);
	scanf("%d%d%d",&n,&m,&a);
	for(i=0;i<=m;++i)scanf("%d",&b[i]);
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
