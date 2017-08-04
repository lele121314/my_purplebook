#include<stdio.h>
#include<string.h>
int r,c;
char a[10][13];
int aa[10][10];
bool aaa[10][10];
bool isFirst(int x,int y){
	if(a[x][y]=='*')return false;
	if(x-1<0||y-1<0||a[x-1][y]=='*'||a[x][y-1]=='*')return true;
	return false;
}
bool isEnd(int x,int y){
	if(y>=c||x>=r||a[x][y]=='*')return true;
	return false;
}

int main(){
	int T=0;
	freopen("ans.txt","r",stdin);
	freopen("ans1.txt","w",stdout);
	while(scanf("%d",&r)&&r){
		scanf("%d",&c);
		memset(aa,-1,sizeof(aa));
		if(T!=0)printf("\n");
		printf("puzzle #%d:\n",++T);
		int step=1;
		for(int i=0;i<r;i++){
			scanf("%s",a[i]); 
			for(int j=0;j<c;j++){
				if(isFirst(i,j)){
					aa[i][j]=step++;
				}
			}
			//printf("%s\n",a[i]);
		} 
	/*	for(int i=0;i<r;i++){
		
			for(int j=0;j<c;j++){
				
					printf("%2d ",aa[i][j]);
			
				
			}
			printf("\n");
		} */
		printf("Across\n");
		memset(aaa,false,sizeof(aaa));
		for(int i=0;i<r;i++){
			for(int j=0;j<c;j++){
				if(!isEnd(i,j)){
					printf("%3d.",aa[i][j]);
					while(!isEnd(i,j)){
						printf("%c",a[i][j]);
						j++;
					}
					printf("\n");
					j--;
									
				}
			}
		}
		printf("Down\n");
		for(int i=0;i<r;i++){
			for(int j=0;j<c;j++){
				if(aaa[i][j])continue;
				if(!isEnd(i,j)){
					printf("%3d.",aa[i][j]);
					int tx=i;
					while(!isEnd(tx,j)){
						printf("%c",a[tx][j]);
						aaa[tx][j]=true;
						tx++;
					}
					printf("\n");
									
				}
			}
		}
		
		
		
		
	}
}
