#include<stdio.h>
#include<string.h>
const double a[]={12.01,1.008,16,14.01,0};
int T;
char mm[85];
int main(){
	freopen("ans.txt","r",stdin);
	scanf("%d",&T);
	while(T--){
		scanf("%s",mm);
		int len=strlen(mm);
		double ans=0;
		for(int i=0;i<len;i++){
			int nn=0;
			int chose=4;
			switch(mm[i]){
				case 'C':chose=0;break;
				case 'H':chose=1;break;
				case 'O':chose=2;break;
				case 'N':chose=3;break;
			}
			for(int j=1;i+j<len;j++){
				if(mm[i+j]>='0'&&mm[i+j]<='9'){
					nn=nn*10+(mm[i+j]-'0');
					
				}
				else {
					i+=j-1;
					break;
				}
			}
		//	printf("%d ssss\n",nn);
			if(!nn){
				ans+=a[chose];
			//	printf("666 %d %d\n",chose,a[chose]);
			} 
			else {
				ans+=a[chose]*nn;
			//printf("666 %f %d\n",a[chose],nn);
			}
			
		}
		printf("%.3f\n",ans);
	}
}
