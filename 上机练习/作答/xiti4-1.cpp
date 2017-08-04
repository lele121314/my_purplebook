#include<stdio.h>
#include<string.h>
#include<vector>
using namespace std;
char ad[11][10],add[11][10],ppp;
int left;
int n,xx,yy;
vector<int> p;
int hx[]={2,2,1,-1,-2,-2,-1,1};
int hy[]={1,-1,-2,-2,-1,1,2,2};
int biex[]={1,1,0,0,-1,-1,0,0};
int biey[]={0,0,-1,-1,0,0,1,1};
void house(int x,int y){
	for(int i=0;i<8;i++){
		if(x+hx[i]>1&&x+hx[i]<=10&&y+hy[i]>1&&y+hy[i]<10){
			if(ad[x+biex[i]][y+biey[i]]==0){
				if(add[x+hx[i]][y+hy[i]]=='N'){
					left--;add[x+hx[i]][y+hy[i]]==0;
				}
			}
		}
	}
}
void txit(int x,int y){
	for(int i=x-1;i>0;i--){
		if(add[i][y]=='N'){
			add[i][y]=0;
			left--;
			
		}
		else if(ad[i][y]=='G'||ad[i][y]=='R'||ad[i][y]=='H'||ad[i][y]=='C'){
			break;
		}
	}
	for(int i=y-1;i>0;i--){
		if(add[x][i]=='N'){
			add[x][i]=0;
			left--;
			
		}
		else if(ad[x][i]=='G'||ad[x][i]=='R'||ad[x][i]=='H'||ad[x][i]=='C'){
			break;
		}
	}
	for(int i=y+1;i<10;i++){
		if(add[x][i]=='N'){
			add[x][i]=0;
			left--;
			
		}
		else if(ad[x][i]=='G'||ad[x][i]=='R'||ad[x][i]=='H'||ad[x][i]=='C'){
			break;
		}
	}
	for(int i=x+1;i<=10;i++){
		if(add[i][y]=='N'){
			add[i][y]=0;
			left--;
			
		}
		else if(ad[i][y]=='G'||ad[i][y]=='R'||ad[i][y]=='H'||ad[i][y]=='C'){
			break;
		}
	}
}
void pao(int x,int y){
	int k=0;
	for(int i=x-1;i>0;i--){
		if(add[i][y]=='N'&&k==1){
			add[i][y]=0;
			left--;
			
		}
		else if(ad[i][y]=='G'||ad[i][y]=='R'||ad[i][y]=='H'||ad[i][y]=='C'){
			k++;
		}
		if(k>2)break;
	}
	k=0;
	for(int i=y-1;i>0;i--){
		if(add[x][i]=='N'&&k==1){
			add[x][i]=0;
			left--;
			
		}
		else if(ad[x][i]=='G'||ad[x][i]=='R'||ad[x][i]=='H'||ad[x][i]=='C'){
			k++;
		}
		if(k>2)break;
	}
	k=0;
	for(int i=y+1;i<10;i++){
		if(add[x][i]=='N'&&k==1){
			add[x][i]=0;
			left--;
			
		}
		else if(ad[x][i]=='G'||ad[x][i]=='R'||ad[x][i]=='H'||ad[x][i]=='C'){
			k++;
		}
		if(k>2)break;
	}
	k=0;
	for(int i=x+1;i<=10;i++){
		if(add[i][y]=='N'&&k==1){
			add[i][y]=0;
			left--;
			
		}
		else if(ad[i][y]=='G'||ad[i][y]=='R'||ad[i][y]=='H'||ad[i][y]=='C'){
		k++;
		}
		if(k>2)break;
	}
}

void ju(int x,int y){
	for(int i=x-1;i>0;i--){
		
		if(i==xx&&y==yy){
			left=1000;
			return;
		}
		if(add[i][y]=='N'){
			add[i][y]=0;
			left--;
			return;
		}
		else if(ad[i][y]=='G'||ad[i][y]=='R'||ad[i][y]=='H'||ad[i][y]=='C'){
			break;
		}
	}
}
bool check(){
	
	memset(add,0,sizeof(ad));
	if(xx-1>=1){
		add[xx-1][yy]='N';left++;
		for(int i=0;i<2*n;i+=2){
        	int x=p[i],y=p[i+1];
        	if(xx-1==x&&yy==y)continue;
        
			if(ad[x][y]=='H')house(x,y);
			else if(ad[x][y]=='C')pao(x,y);
			else if(ad[x][y]=='R')txit(x,y);
			else txit(x,y);
		}
		if(left)return false;
		
	}
	left=0;
	memset(add,0,sizeof(ad));
    if(xx+1<=3){
		add[xx+1][yy]='N';left++;
		for(int i=0;i<2*n;i+=2){
        	int x=p[i],y=p[i+1];
        	if(xx+1==x&&yy==y)continue;
        
			if(ad[x][y]=='H')house(x,y);
			else if(ad[x][y]=='C')pao(x,y);
			else if(ad[x][y]=='R')txit(x,y);
			else txit(x,y);
		}
		if(left)return false;
	}
	left=0;
	memset(add,0,sizeof(ad));
    if(yy+1<=6){
		add[xx][yy+1]='N';left++;
		for(int i=0;i<2*n;i+=2){
        	int x=p[i],y=p[i+1];
        	if(xx==x&&yy+1==y)continue;
        
			if(ad[x][y]=='H')house(x,y);
			else if(ad[x][y]=='C')pao(x,y);
			else if(ad[x][y]=='R')txit(x,y);
			else txit(x,y);
		}
		if(left)return false;
	}
	left=0;
	memset(add,0,sizeof(ad));
    if(yy-1>=4){
		add[xx][yy-1]='N';left++;
		for(int i=0;i<2*n;i+=2){
        	int x=p[i],y=p[i+1];
        	if(xx==x&&yy-1==y)continue;
        
			if(ad[x][y]=='H')house(x,y);
			else if(ad[x][y]=='C')pao(x,y);
			else if(ad[x][y]=='R')txit(x,y);
			else txit(x,y);
		}
		if(left)return false;
	}
	
	return true;
	
}

void nextb(int x,int y){
    memset(ad,0,sizeof(ad));
    memset(add,0,sizeof(ad));
    left=0;
    //ad[x][y]='B';
}
int main() {
	freopen("ans.txt","r",stdin);
	//freopen("ans1.txt","w",stdout);
    while(scanf("%d%d%d",&n,&xx,&yy)!=EOF){
    	if(n==0)break;
    	
        p.clear();
        //printf("1.  %d %d %d\n",n,xx,yy);
        nextb(xx,yy);
        //printf("1. %d\n",left);
        for(int i=0;i<n;i++){
        	//getchar();
        	int x,y;
        	scanf("%s",&ppp);
            scanf("%d %d",&x,&y);
           // printf("2.  %d %d %c\n",x,y,ppp);
            ad[x][y]=ppp;
            p.push_back(x),p.push_back(y);
        }
        //n=p.size()/2;
        check();
        printf("%s\n",left<=0?"YES":"NO");
        //printf("2. %d\n",left);

    }
    return 0;
}
