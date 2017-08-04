#include<stdio.h>
#include<string.h>
char s[100002],t[100002];

int main(){
	freopen("ans.txt","r",stdin); 
	while(scanf("%s %s",s,t)!=EOF){
	
		int slen=strlen(s),tlen=strlen(t);
		int sp=0;
		int tp=0;
		for(tp=0;tp<tlen&&sp<slen;tp++){
			if(s[sp]==t[tp])sp++;
		} 
		if(sp==slen)printf("Yes\n");
		else printf("No\n");
	}
	return 0; 
} 
