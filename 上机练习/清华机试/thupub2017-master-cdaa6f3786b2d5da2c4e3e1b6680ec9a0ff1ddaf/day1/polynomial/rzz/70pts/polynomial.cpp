#include <stdio.h>
#include <stdlib.h>
#define p 1000000007
using namespace std;

struct Lagrange_polynomial_interpolation
{
	#define pol_m 200005
	
	int m,fac[pol_m],fac_inv[pol_m],fac_l[pol_m],fac_r[pol_m],f[pol_m];
	
	int Power(int a,int b)
	{
		int ans=1;
		for(;b;b>>=1,a=(long long)a*a%p)if(b&1)ans=(long long)ans*a%p;
		return ans;
	}
	void prepare()
	{
		int i;
		for(fac[0]=i=1;i<=m;++i)fac[i]=(long long)fac[i-1]*i%p;
		for(fac_inv[m]=Power(fac[m],p-2),i=m;i>=1;--i)fac_inv[i-1]=(long long)fac_inv[i]*i%p;
	}
	int calc(int n)
	{
		n%=p;
		if(n<=m)return f[n];
		int i,ans=0,tmp;
		for(fac_l[0]=i=1;i<=m;++i)fac_l[i]=(long long)fac_l[i-1]*(n-i)%p;
		for(fac_r[m+1]=1,i=m;i>=1;--i)fac_r[i]=(long long)fac_r[i+1]*(n-i)%p;
		for(i=1;i<=m;++i)
		{
			tmp=(long long)f[i]*fac_l[i-1]%p*fac_r[i+1]%p*fac_inv[i-1]%p;
			if((m-i)&1)tmp=(long long)tmp*(p-fac_inv[m-i])%p;
			else tmp=(long long)tmp*fac_inv[m-i]%p;
			ans+=tmp;if(ans>=p)ans-=p;
		}
		return ans;
	}
	
	#undef pol_m
}A;

int n,m,a,ca,c,i,j,k,ans;
int b[105];

int main()
{
	freopen("polynomial.in","r",stdin);
	freopen("polynomial.out","w",stdout);
	scanf("%d%d%d",&n,&m,&a);
	for(i=0;i<=m;++i)scanf("%d",&b[i]);
	if(a==1)
	{
		A.m=105;ca=1;
		for(i=0;i<=A.m;++i)
		{
			c=ca;ca=(long long)ca*a%p;
			for(j=0;j<=m;++j)
			{
				A.f[i]=(A.f[i]+(long long)c*b[j])%p;
				c=(long long)c*i%p;
			}
			A.f[i+1]=A.f[i];
		}
		A.prepare();
		printf("%d\n",A.calc(n));
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
