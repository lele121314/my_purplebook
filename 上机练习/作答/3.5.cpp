#include<stdio.h>
char adj[5][8];
char move;
int x,y;
bool mo(char mmm){
	switch(mmm){
		case 'A':
			if(x-1>=0){
				adj[x][y]=adj[x-1][y];
				adj[x-1][y]=' ';
				x--;
				break;
			}else return true;
		case 'B':
			if(x+1<=4){
				adj[x][y]=adj[x+1][y];
				adj[x+1][y]=' ';
				x++;
				break;
			}else return true;
		case 'L':
			if(y-1>=0){
				adj[x][y]=adj[x][y-1];
				adj[x][y-1]=' ';
				y--;
				break;
			}else return true;
		case 'R':
			if(y+1<=4){
				adj[x][y]=adj[x][y+1];
				adj[x][y+1]=' ';
				y++;
				break;
			}else return true;	
	}
	return false;
	
}
int main(){
	int i=0;
	freopen("ans.txt","r",stdin);
	while(true){
		i++;
		
		gets(&adj[0][0]);
		if(adj[0][0]=='Z')break;
		for(int j=0;j<5;j++){
			if(adj[0][j]==' '){
				x=0;y=j;
			}
		}
		if(i!=1)printf("\n");
		printf("Puzzle #%d:\n",i);
		for(int i=1;i<5;i++){
			gets(&adj[i][0]);
			for(int j=0;j<5;j++){
				if(adj[i][j]==' '){
					x=i;y=j;
				}
			}
		}
/*		for(int i=0;i<5;i++){
			
			for(int j=0;j<5;j++){
				printf("%c",adj[i][j]);
			}
			printf("\n");
		}*/
	//	printf("\n%d %d\n",x,y);
		bool err=false;
		while(true){
			scanf("%c",&move);
	//		printf("%c ",move);
			
			if(move=='0')break;
			if(mo(move)){
				err=true;
			}
		}
		char ssss[111];
		gets(ssss);
	//	printf("\n");
		if(err)printf("This puzzle has no final configuration.\n");
		else{
			for(int j=0;j<5;j++){
				for(int k=0;k<4;k++){
					printf("%c ",adj[j][k]);
				}
				printf("%c\n",adj[j][4]);
			}
		}
		
	}
} 
