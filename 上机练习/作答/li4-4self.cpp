#include<stdio.h>
#include<string.h>
int code[8][1<<8];

int readchar(){
	int ch;
	do{
		 ch=getchar();
	}while(ch=='\n'||ch=='\r');
	return ch;
} 
int readint(int t){
	int a=0;
	for(int i=0;i<t;i++){
		a=(a<<1)+readchar()-'0';
	}
	return a;
	
}
int readhead(){
	memset(code,0,sizeof(code));
	code[1][0]=readchar();
	for(int len=2;len<=7;len++){
		for(int i=0;i<(1<<len)-1;i++){
			int ch=getchar();
			if(ch==EOF)return 0;
			if(ch=='\n'||ch=='\r')return 1;
			code[len][i]=ch;
		}
	}
	return 1;
}
void printcodes(){
	for(int len=1;len<=7;len++){
		for(int i=0;i<(1<<len)-1;i++){
			if(code[len][i]==0)return ;
			printf("code[%d][%d]=%c\n",len,i,code[len][i]);
		}
	}
}

int main(){
	freopen("ans.txt","r",stdin);
	while(readhead()){
	//	printcodes();
		while(true){
			int len=readint(3);
		//	printf("%d\n",len);
			if(len==0)break;
			while(true){
				int v=readint(len);
				if(v==(1<<len)-1)break;
			//	putchar(code[len][v]);
				printf("%c",code[len][v]); 
			}
		}
		printf("\n");
	}
	return 0;
}
