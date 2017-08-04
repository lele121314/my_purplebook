#include<stdio.h>
#include<string.h>
char a[85];
int main(){
	int m;
	freopen("ans.txt","r",stdin);
	freopen("ans1.txt","w",stdout);
	scanf("%d",&m);
	while(m--){
		scanf("%s",a);
		int len=strlen(a);
		bool isfind=false;
		bool notfind=false;
		int ans=0;
		int j=0,i=0;
		for(i=1;i<len;i++){
			notfind=false;
			for(j=0;i+j<len;j++){
				if(a[j]==a[j+i]);
				else {
					notfind=true;
					break;
				}
			}
			if(!notfind)break;
		}
		if(len%i==0)ans=i;
			else ans=len;
		if(m>0)printf("%d\n\n",ans);
		else printf("%d\n",ans);
	
	
	}
}
