#include<stdio.h>
#include<string.h>
char mom[208],son[208];
int dad[104];
int l1,l2;
bool input(){
	memset(mom,'0',sizeof(mom));
	memset(son,'0',sizeof(son));
	if(scanf("%s",mom)==EOF)return false;
	else scanf("%s",son);
	l1=strlen(mom);l2=strlen(son);
	if(l1<l2){
		char temp[208];
		int t=l2;l2=l1;l1=t;
		strcpy(temp,mom);
		strcpy(mom,son);
		strcpy(son,temp);
	}
	return true;
}
int main(){
	freopen("ans.txt","r",stdin); 
	freopen("anss.txt","w",stdout); 
	while(input()){
		
		mom[l1]='0';son[l2]='0';
		int ans=0;
		int i=0,j=0;
		while(i<l2){
			if(mom[i+j]+son[i]-'0'-'0'<=3)i++;
			else {
				i=0;j++;
			}
		}
		
		ans=l1>i+j?l1:i+j;
		i=0;j=0;
		while(i<l1){
			if(son[i+j]=='0')break;
			if(son[i+j]+mom[i]-'0'-'0'<=3)i++;
			else {
				i=0;j++;
			}
		}
		int ans1=j+l1;
		
	//	printf("%d %d\n",l1,l2);
		
	//	printf("%d %d\n",i,j);
		printf("%d\n",ans<ans1?ans:ans1);
	}
	return 0;	
}
