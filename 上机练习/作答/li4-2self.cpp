#include<stdio.h>
#include<string.h>
int rnd;
int ans[26];
char i1[200],i2[200];
int len1,len2;
int right,wrong;



int main(){
	freopen("ans.txt","r",stdin);
	while(scanf("%d",&rnd)==1&&rnd!=-1){
		memset(ans,0,sizeof(ans));
		printf("Round %d\n",rnd);
		scanf("%s%s",i1,i2);
		wrong=7;
		len1=strlen(i1);
		len2=strlen(i2);
	//	printf("%d %d\n",len1,len2);
		right=len1;
		for(int i=0;i<len1;i++){
			ans[i1[i]-'a']++;
		}
		for(int i=0;i<len2;i++){
			if(ans[i2[i]-'a']==0){
				wrong--;
			}
			else{
				right-=ans[i2[i]-'a'];
				ans[i2[i]-'a']=0;
			}
			if(!wrong||!right)break;
			
		}
		if(!wrong)printf("You lose.\n");
		else if(right==0)printf("You win.\n");
		else printf("You chickened out.\n");
		
		
	}
	return 0;
}
