#include<cstdio>
#include<vector>
using namespace std;
vector<int> adj[25];
int n=0;
void find_block(int x,int& v,int& h){
    for(v=0;v<n;v++){
        for(h=0;h<adj[v].size();h++){
            if(adj[v][h]==x)return ;
        }
    }
}
void clear_all(int x){
    int v,h;
    find_block(x,v,h);
    for(int i=h+1;i<adj[v].size();i++){
        adj[adj[v][i]].push_back(adj[v][i]);
    }
    adj[v].resize(h+1);
}
void move_to(int p,int h,int p2){
    for(int i=h;i<adj[p].size();i++){
        adj[p2].push_back(adj[p][i]);
    }
    adj[p].resize(h);
}
int main(){
    freopen("ans.txt","r",stdin);
    scanf("%d",&n);
    for(int i=0;i<n;i++)adj[i].push_back(i);
    char s1[6],s2[6];
    int a,b;

    while(scanf("%s %d %s %d",s1,&a,s2,&b)==4){
        //printf("%s %d %s %d\n",s1,a,s2,b);
        int pa,pb,ha,hb;
        find_block(a,pa,ha);
        find_block(b,pb,hb);
        if(pa==pb)continue;
        if(s2[1]=='n')clear_all(b);
        if(s1[0]=='m')clear_all(a);
        move_to(pa,ha,pb);

    }
    for(int i=0;i<n;i++){
        printf("%d:",i);
        for(int j=0;j<adj[i].size();j++){
            printf(" %d",adj[i][j]);
        }
        printf("\n");
    }
    return 0;
}
