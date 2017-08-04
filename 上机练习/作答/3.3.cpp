#include<stdio.h>
int a[10001][10]={0};

int main(){
	freopen("ans.txt","r",stdin);
	for(int i=1;i<10001;i++){
		int tmp=i;
		for(int j=0;j<10;j++){
			a[i][j]=a[i-1][j];
		}
		while(tmp!=0){
			int wei=tmp%10;
			tmp/=10;
			
			a[i][wei]=a[i][wei]+1;
			//printf("wei:%d %d\n",wei,a[i][wei]);
		} 
	}
	int t;
	scanf("%d",&t);
	while(t--){
		int n;
		scanf("%d",&n);
		
		for(int i=0;i<9;i++){
			printf("%d ",a[n][i]);
		}
		printf("%d\n",a[n][9]);
	}
}
