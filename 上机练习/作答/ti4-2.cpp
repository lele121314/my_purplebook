#include<cstdio>
#include<string.h>
int ad[2][10][10];
int n,m;
int kase=0;
bool judge(int x,int y,int sizew){
    for(int i=0;i<sizew;i++){
        if(!(ad[0][x][y+i]==1&&ad[0][x+sizew][y+i]==1&&
           ad[1][x+i][y]==1&&ad[1][x+i][y+sizew]==1)){
               //printf("%d 3453454353453\n",i);
               return false;
        }
    }
    return true;
}
int main(){
    freopen("ans.txt","r",stdin);
    freopen("ans1.txt","w",stdout);
    while(scanf("%d%d",&n,&m)!=EOF){
        if(kase)printf("\n**********************************\n\n");
        memset(ad,0,sizeof(ad));
        for(int i=0;i<m;i++){
            int x,y;
            char a;
            scanf("%s %d %d",&a,&x,&y);
           // printf("%c %d %d\n",a,x,y);
            if(a=='H')ad[0][x-1][y-1]=1;
            else if(a=='V')ad[1][y-1][x-1]=1;
        }
        printf("Problem #%d\n\n",++kase);
        int knum=0;
//        for(int i=0;i<n;i++){
//            for(int j=0;j<n;j++){
//                printf("%d %d %d %d,",i,j,ad[0][i][j],ad[1][i][j]);
//            }
//            printf ("\n");
//        }

       // printf("555  %d\n",judge(1,1,2));


        for(int sizew=1;sizew<n;sizew++){
            int num=0;
            for(int i=0;i+sizew<n;i++){
                for(int j=0;j<n-sizew;j++){
                    if(judge(i,j,sizew))num++;
                }
            }
            if(num){
                printf("%d square (s) of size %d\n",num,sizew);
                knum++;
            }
        }
        if(!knum)printf("No completed squares can be found.\n");
    }
}
