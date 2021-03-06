#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <algorithm>
#include <iostream>
using namespace std;

long long mult(long long a,long long b,long long p)
{
	a%=p;b%=p;if(a<0)a+=p;if(b<0)b+=p;
	long long ans=(long long)((long double)a*b/p);
	ans=a*b-ans*p;
	if(ans>=p)ans-=p;if(ans<0)ans+=p;
	return ans;
}

long long Power(long long a,long long b,long long p)
{
	long long ans=1;
	for(;b;b>>=1,a=mult(a,a,p))if(b&1)ans=mult(ans,a,p);
	return ans;
}

long long Power10(long long a,long long p)
{
	long long ans,b=mult(a,a,p);
	ans=mult(b,b,p);
	ans=mult(ans,ans,p);
	return mult(ans,b,p);
}

void ex_gcd(long long a,long long b,long long &x,long long &y)
{
    if(!b)x=1,y=0;
    else ex_gcd(b,a%b,y,x),y-=a/b*x;
}
long long Inv(long long a,long long p) 
{
    long long x,y;
    ex_gcd(a%p,p,x,y);
    if(x<0)x+=p;
    return x;
}

int T,d,i,j,k,u,v;
long long M,Q,Qn,Q_inv,a0,b0,N,m1,m2,m3,x,ans,ans1,ans2,ans3;
long long A[30005],B[30005],Qi[15];
long long inv[30005],fac[30005],fac_inv[30005];
long long facl[30005],facr[30005];
char s[100005];

long long Lagrange(long long *f,int d,long long N,long long M)
{
	N%=M;if(N<0)N+=M;
	if(N<=d)return f[N]%M;
	int i;long long ans=0,tmp;
	facl[0]=facr[d]=1;
	for(i=0;i<d;++i)facl[i+1]=mult(facl[i],N-i,M);
	for(i=d;i;--i)facr[i-1]=mult(facr[i],N-i,M);
	for(i=0;i<=d;++i)
	{
		tmp=mult(f[i],mult(mult(facl[i],facr[i],M),mult(fac_inv[i],fac_inv[d-i],M),M),M);
		if((d-i)&1)ans-=tmp;else ans+=tmp;
		if(ans>=M)ans-=M;if(ans<0)ans+=M;
	}
	return ans;
}

long long b[105],c;

int main()
{
	freopen("polynomial.in","r",stdin);
	freopen("polynomial.out","w",stdout);
	
	M=1000000007;
	scanf("%s%d%lld",s+1,&d,&Q);k=strlen(s+1);
	for(i=0;i<=d;++i)scanf("%lld",&b[i]);
	for(i=0;i<=d;++i)
	{
		A[i]=0;c=1;
		for(j=0;j<=d;++j)
		{
			A[i]=(A[i]+b[j]*c)%M;
			c=c*i%M;
		}
	}
	if(Q==0){printf("%lld\n",A[0]);return 0;}
	
	for(i=1,N=0;i<=k;++i)N=N*5%M,N=(N+N+s[i]-'0')%M;
	++N;
	
	inv[0]=inv[1]=fac[0]=fac_inv[0]=1;
	for(i=2;i<=d+14;++i)inv[i]=mult(inv[M%i],M-M/i,M);
	for(i=1;i<=d+14;++i)fac[i]=mult(fac[i-1],i,M);
	for(i=1;i<=d+14;++i)fac_inv[i]=mult(fac_inv[i-1],inv[i],M);
	
	if(Q==1)
	{
		A[d+1]=Lagrange(A,d,d+1,M);
		for(i=1;i<=d+1;++i)
		{
			A[i]+=A[i-1];
			if(A[i]>=M)A[i]-=M;
		}
		printf("%lld\n",Lagrange(A,d+1,N-1,M));
		return 0;
	}
	
	m1=m2=1;m3=M;
	for(u=0;(x=__gcd(Q,m3))!=1;++u)m1*=x,m3/=x;
	for(v=0;(x=__gcd(Q-1,m3))!=1;++v)m2*=x,m3/=x;
	for(i=max(u,d+v);i>d;--i)A[i]=Lagrange(A,d,i,M);
	
	if(m1!=1)
	{
		ans1=0;x=1;
		for(i=0;i<u&&i<N;++i)
		{
			ans1+=mult(A[i],x,m1);
			x=mult(x,Q,m1);
			if(ans1>=m1)ans1-=m1;
		}
	}else ans1=0;
	
	if(m2!=1)
	{
		for(i=0;i<=d+v;++i)
		{
			x=1;B[i]=0;
			for(j=0;j<v&&j<=i;++j)
			{
				B[i]+=x;if(B[i]>=m2)B[i]-=m2;
				x=mult(mult(x,Q-1,m2),mult(i-j,inv[j+1],m2),m2);
			}
			B[i]=mult(B[i],A[i],m2);
		}
		for(i=1;i<=d+v;++i)
		{
			B[i]+=B[i-1];
			if(B[i]>=m2)B[i]-=m2;
		}
		ans2=Lagrange(B,d+v,N-1,m2);
	}else ans2=0;
	
	if(m3!=1)
	{
		Q_inv=Inv(Q,m3);a0=b0=0;x=d+1;
		for(i=1;i<=d+1;++i)
		{
			a0=mult(a0+A[i-1],Q_inv,m3);
			if(i&1)b0-=mult(x,a0,m3);
			else b0+=mult(x,a0,m3);
			if(b0>=m3)b0-=m3;if(b0<0)b0+=m3;
			x=mult(x,mult(d+1-i,inv[i+1],m3),m3);
		}
		B[0]=mult(M-b0,Power(mult(Q,Inv(Q-1,m3),m3),d+1,m3),m3);
		for(i=1;i<=d;++i)B[i]=mult(B[i-1]+A[i-1],Q_inv,m3);
		Qn=Qi[0]=1;
		for(i=1;i<=9;++i)Qi[i]=mult(Qi[i-1],Q,m3);
		for(i=1;i<=k;++i)Qn=mult(Power10(Qn,m3),Qi[s[i]-'0'],m3);
		Qn=mult(Qn,Q,m3);
		ans3=(mult(Qn,Lagrange(B,d,N,m3),m3)+m3-B[0])%m3;
	}else ans3=0;
	
	ans=mult(ans1,mult(m2*m3,Inv(m2*m3,m1),M),M);
	ans+=mult(ans2,mult(m1*m3,Inv(m1*m3,m2),M),M);if(ans>=M)ans-=M;
	ans+=mult(ans3,mult(m1*m2,Inv(m1*m2,m3),M),M);if(ans>=M)ans-=M;
	printf("%lld\n",ans);
}
