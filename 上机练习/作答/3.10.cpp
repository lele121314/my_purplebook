#include<stdio.h>
#include<algorithm>
using namespace std;
struct E{
	int a,b;
}face[6];
bool cmp(E x,E y){
	if(x.a!=y.a)return x.a<y.a;
	else return x.b<y.b;
}
bool input(){
	for(int i=0;i<6;i++){
		if(scanf("%d%d",&face[i].a,&face[i].b)==EOF)return false;
		else if(face[i].a>face[i].b) {
			int tmp=face[i].a;
			face[i].a=face[i].b;
			face[i].b=tmp;
		}
	}
	return true;
}
int main(){
	freopen("ans.txt","r",stdin); 
	while(input()){
		sort(face,face+6,cmp);
		/*for(int i=0;i<6;i++){
			printf("%d %d\n",face[i].a,face[i].b);
		}*/
		puts(face[0].a==face[2].a&&face[0].b==face[4].a&&face[2].b==face[4].b
		&&face[0].a==face[1].a&&face[0].b==face[1].b
		&&face[3].a==face[2].a&&face[3].b==face[2].b
		&&face[5].a==face[4].a&&face[5].b==face[4].b?"POSSIBLE":"IMPOSSIBLE");
		
	}
	return 0;
} 
