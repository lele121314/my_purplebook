#include<cstdio>
#include<cstring>
#include<math.h>
#include<algorithm>
using namespace std;


int main(){
	double M[10][31];
	double bm,dm;
	double lonn1;
	long long E[10][31];
	long long be,de;
	int i=0,j=0;
	char s[30];
	double m;
	int e;
	for(i=0;i<10;i++){
		bm=1-pow(2,-i-1);
		for(j=0;j<31;j++){
			be=pow(2,j)-1;
			lonn1=log10(bm)+be*log10(2);
			de=floor(lonn1);
			dm=pow(10,lonn1-de);
			M[i][j]=dm;
			E[i][j]=de;
		}
	}
	freopen("ans.txt","r",stdin);
	while(scanf("%s",s)==1){
		if(s=="0e0")break;
		s[17]=' ';
		sscanf(s,"%lf %d",&m,&e);
		for(i=0;i<10;i++){
			for(j=0;j<31;j++)
			if(fabs(M[i][j]-m)<1e-5 && E[i][j]==e)printf("%d %d\n",i,j);
		}
		
	}
	return 0;
}
