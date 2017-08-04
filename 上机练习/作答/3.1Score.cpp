#include<stdio.h>
#include<string.h>
int T;
char xx[85];
int main(){
	freopen("ans.txt","r",stdin);
	scanf("%d",&T);
	while(T--){
		scanf("%s",xx);
		int len=strlen(xx);
		int O=0;
		int ans=0;
		for(int i=0;i<len;i++){
			if(xx[i]=='O'){
				O++;
				ans+=O;
			}
			else O=0;
		}
		printf("%d\n",ans);
	}
}
