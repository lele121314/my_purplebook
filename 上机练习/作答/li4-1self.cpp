#include<stdio.h>
#include<string.h>
#include<algorithm>
using namespace std;
char i1[105],i2[105];
int a1[258],a2[258];
int len;
bool cmp(int a,int b){
	return a>b;
}
int main(){
	freopen("ans.txt","r",stdin);
	while(scanf("%s%s",i1,i2)!=EOF){
		len=strlen(i1);
		memset(a1,0,sizeof(a1));
		memset(a2,0,sizeof(a2));
		for(int i=0;i<len;i++){
			a1[i1[i]]++;
			a2[i2[i]]++;
		}
		sort(a1,a1+258,cmp);
		sort(a2,a2+258,cmp);
		bool find=false;
		for(int i=0;i<len;i++){
			if(a1[i]!=a2[i]){
				printf("NO\n");
				find=true;
				break;
			}
		}
		if(!find)
		printf("YES\n");
	}
}
