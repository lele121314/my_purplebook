#include<stdio.h>
#include<string.h>
int t;
int m,n;
char a[50][1003];
char ans[1003];
int ans1;
char jian[]={'A','C','G','T'};
int x[4];
int main(){
	//printf("%d",'G'<'T');
//	freopen("ans.txt","r",stdin);
//	freopen("ans1.txt","w",stdout);
	scanf("%d",&t);
	while(t--){
		ans1=0;
		scanf("%d%d",&m,&n);
		memset(ans,'\0',sizeof(ans));
		memset(a,0,sizeof(a));
		for(int i=0;i<m;i++){
			scanf("%s",a[i]);
		}
		for(int i=0;i<n;i++){
			memset(x,0,sizeof(x));
			for(int j=0;j<m;j++){
				switch(a[j][i]){
					case 'A':x[0]++;break;
					case 'C':x[1]++;break;
					case 'G':x[2]++;break;
					case 'T':x[3]++;break;
				}
			}
			int max=x[0];
			int index=0;
			for(int j=1;j<4;j++){
				if(max<x[j]||max==x[j]&&jian[j]<jian[index]){
					max=x[j];
					index=j;
				}
			}
			for(int j=0;j<4;j++){
				if(j!=index){
					ans1+=x[j];
				}
			}
			ans[i]=jian[index];			
		}
		printf("%s\n%d\n",ans,ans1);
		
	}
}
