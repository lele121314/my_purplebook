#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define p 1000000007
using namespace std;

struct Matrix
{
	#define Matrix_Size 105
	#define Matrix_value long long
	#define Matrix_mod 1000000007
	
	int n;
	Matrix_value a[Matrix_Size][Matrix_Size];
	
	void clear(int N){n=N;for(int i=1;i<=n;++i)for(int j=1;j<=n;++j)a[i][j]=0;}
	void unit(int N){clear(N);for(int i=1;i<=N;++i)a[i][i]=1;}
	
	Matrix operator +(const Matrix &b)const
	{
		Matrix tmp;tmp.clear(n);
		for(int i=1;i<=n;++i)
		for(int j=1;j<=n;++j)
		{
			tmp.a[i][j]=a[i][j]+b.a[i][j];
			if(tmp.a[i][j]>=Matrix_mod)tmp.a[i][j]-=Matrix_mod;
		}
		return tmp;
	}
	Matrix operator -(const Matrix &b)const
	{
		Matrix tmp;tmp.clear(n);
		for(int i=1;i<=n;++i)
		for(int j=1;j<=n;++j)
		{
			tmp.a[i][j]=a[i][j]-b.a[i][j];
			if(tmp.a[i][j]<0)tmp.a[i][j]+=Matrix_mod;
		}
		return tmp;
	}
	Matrix operator *(const Matrix &b)const
	{
		Matrix tmp;tmp.clear(n);
		for(int i=1;i<=n;++i)
		for(int j=1;j<=n;++j)if(a[i][j])
		for(int k=1;k<=n;++k)
		tmp.a[i][k]=(tmp.a[i][k]+a[i][j]*b.a[j][k])%Matrix_mod;
		return tmp;
	}
	Matrix operator *(const Matrix_value &b)const
	{
		Matrix tmp;tmp.clear(n);
		Matrix_value c=b%Matrix_mod;
		for(int i=1;i<=n;++i)
		for(int j=1;j<=n;++j)
		tmp.a[i][j]=a[i][j]*c%Matrix_mod;
		return tmp;
	}
	
	Matrix &operator +=(const Matrix &b){*this=*this+b;return *this;}
	Matrix &operator -=(const Matrix &b){*this=*this-b;return *this;}
	Matrix &operator *=(const Matrix &b){*this=*this*b;return *this;}
	Matrix &operator *=(const Matrix_value &b){*this=*this*b;return *this;}
	
	Matrix operator ^(long long n)const
	{
		Matrix power=*this,tmp;tmp.unit(power.n);
		for(;n;n>>=1)
		{
			if(n&1)tmp*=power;
			power*=power;
		}
		return tmp;
	}
	
	#undef Matrix_mod
	#undef Matrix_value
	#undef Matrix_Size
}A,ans;

int n,m,a,i,j,k;
int b[105],C[105][105];

int main()
{
	freopen("polynomial.in","r",stdin);
	freopen("polynomial.out","w",stdout);
	scanf("%d%d%d",&n,&m,&a);
	for(i=0;i<=m;++i)scanf("%d",&b[i]);
	C[0][0]=1;
	for(i=0;i<=m;++i)
	for(j=0;j<=i;++j)
	{
		if(C[i][j]>=p)C[i][j]-=p;
		C[i+1][j]+=C[i][j];
		C[i+1][j+1]+=C[i][j];
	}
	A.clear(m+2);
	for(i=0;i<=m;++i)
	for(j=0;j<=i;++j)
	A.a[i+1][j+1]=(long long)a*C[i][j]%p;
	for(i=0;i<=m;++i)
	A.a[m+2][i+1]=b[i];
	A.a[m+2][m+2]=1;
	ans=A^(n+1);
	printf("%d\n",ans.a[m+2][1]);
	
}
