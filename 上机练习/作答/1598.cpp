#include<stdio.h>
#include<string.h>
#include<vector>
using namespace std;
char ad[11][10],add[11][10];

int n,xx,yy;
vector<int> p;
int hx[]={2,2,1,-1,-2,-2,-1,1};
int hy[]={1,-1,-2,-2,-1,1,2,2};
int biex[]={1,1,1,-1,-1,-1,-1,1};
int biey[]={1,-1,-1,-1,-1,1,1,1};
int yix[]={-1,0,1,0};
int yiy[]={0,1,0,-1};
int overc(int x,int y){
	if(x<1||y<1||x>10||y>9)return false;
	return true;
}
bool jud(int x,int y){
	//house
	for(int i=0;i<8;i++){
		int tx=x+hx[i],ty=y+hy[i];
		int tjx=x+biex[i],tjy=y+biey[i];
		if(overc(tx,ty)){
			if(ad[tx][ty]=='H'&&ad[tjx][tjy]==0){
				return false;
			}
		}
	}
	//GC
	for(int i=x+1;i<=10;i++){
		if(ad[i][y]=='G'||ad[i][y]=='R')return false;
		else if(ad[i][y]!=0)break; 
		
	}
	for(int i=x-1;i>=1;i--){
		if(ad[i][y]=='G'||ad[i][y]=='R')return false;
		else if(ad[i][y]!=0)break; 
	}
	for(int i=y+1;i<=9;i++){
		if(ad[x][i]=='G'||ad[x][i]=='R')return false;
		else if(ad[x][i]!=0)break; 
	}
	for(int i=y-1;i>=1;i--){
		if(ad[x][i]=='G'||ad[x][i]=='R')return false;
		else if(ad[x][i]!=0)break; 
	}
	//C
	int nnn=0;
	for(int i=x+1;i<=10;i++){
		//printf("%d .  %d %c\n",i,nnn,ad[i][y]);
		if(ad[i][y]!=0)nnn++;
		if(ad[i][y]=='C'&&nnn==2)return false;
	}
	nnn=0;
	for(int i=x-1;i>=1;i--){
		if(ad[i][y]!=0)nnn++;
		if(ad[i][y]=='C'&&nnn==2)return false;
	}
	nnn=0;
	for(int i=y+1;i<=9;i++){
		if(ad[x][i]!=0)nnn++;
		if(ad[x][i]=='C'&&nnn==2)return false;
	}
	nnn=0;
	for(int i=y-1;i>=1;i--){
		if(ad[x][i]!=0)nnn++;
		if(ad[x][i]=='C'&&nnn==2)return false;
	}
	//if(x==2&&y==5)printf("1\n");
	return true;
}


bool iiscross(int x,int y){
	if(y<4||y>6||x<1||x>3)return false;
	return true;
}
bool check(){//£¿ 
	for(int i=xx+1;i<=10;i++){
		if(ad[i][yy]=='G')return false;
		else if(ad[i][yy]!=0)break;
	}
	for(int i=0;i<4;i++){
		int tx=xx+yix[i],ty=yy+yiy[i];
		if(iiscross(tx,ty)&&jud(tx,ty)){
			return false;
		}
	}
	return true;
}
int main() {
	freopen("ans.txt","r",stdin);
//	freopen("ans1.txt","w",stdout);
    while(scanf("%d%d%d",&n,&xx,&yy)!=EOF){
    	if(n==0)break;
    	memset(ad,0,sizeof(ad));
	    memset(add,0,sizeof(ad));
	    //left=0;
        p.clear();
        for(int i=0;i<n;i++){
        	int x,y;
        	char ppp;
        	scanf("%s",&ppp);
            scanf("%d %d",&x,&y);
            ad[x][y]=ppp;
            p.push_back(x),p.push_back(y);
        }
        //check();
        printf("%s\n",check()?"YES":"NO");
    }
    return 0;
}
