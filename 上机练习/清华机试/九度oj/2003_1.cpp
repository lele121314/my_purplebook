#include<cstdio>
#include<cmath>
#include<algorithm>
using namespace std;
//(x-x1)*(x-x1)+(y-y1)*(y-y1)+(z-z1)*(z-z1)

int main(){
    double x,y,z,x1,y1,z1;
    while(scanf("%lf%lf%lf%lf%lf%lf",&x,&y,&z,&x1,&y1,&z1)!=EOF){
        double r=sqrt((x-x1)*(x-x1)+(y-y1)*(y-y1)+(z-z1)*(z-z1));
        printf("%.3f %.3f\n",r,4*acos(-1)*r*r*r/3);
    }
}
