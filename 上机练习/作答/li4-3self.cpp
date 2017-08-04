#include<stdio.h>
int N,k,m;
int n;
int peo[25];
int rem(int step,int l,int begin){
//	while(step--){
//		do{
//			begin=(begin+l+N-1)%N+1;
//		}while(peo[begin]==0);
//	}
//	return begin;
	int i=0;
	for(;;i++){
		if(peo[(i*l+begin-1)%N+1]==0)step++;
		step--;
		if(step==0)break;
	}
	return (i*l+begin-1)%n+1;
}
int main(){
	freopen("ans.txt","r",stdin);
	//freopen("anss.txt","w",stdout);
	while(scanf("%d%d%d",&N,&k,&m)==3&&N){
		for(int i=1;i<=N;i++)peo[i]=i;
		n=N;
		int begin1=1,beginN=N;
		while(n){
			int a=rem(k,1,begin1);
			int b=rem(m,-1,beginN);
			printf("%3d",a);
			peo[a]=0;n--;
			begin1=a;
			
			if(b!=a){
				printf("%3d",b);
				peo[b]=0;
				n--;
			}
			beginN=b;
			if(n==0)break;
			//for(int i=1;i<11;i++)printf("   %d",peo[i]);
			//printf("\n%d %d\n",begin1,beginN);
			printf(",");
			
		}
		printf("\n");
	}
	return 0;
} 
