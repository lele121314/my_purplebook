#include<cstdio>
#include<cstring>
#include<vector>
#include<algorithm>
using namespace std;

const int maxn=10,inf=0x7fffffff;
char letter[maxn], s[100];//字母,输入序列
int id[256]; //字母的编号
int p[maxn]; //全排列的遍历数组 ,存储的是每个字母的编号
int pos[maxn];//记录每个字母的位置，避免频繁使用strchr

int main(){
    while(scanf(" %s",&s),s[0]!='#'){
        int len=strlen(s),n=0;
        for(char ch='A';ch<='Z';ch++)if(strchr(s,ch)!=NULL){
            letter[n]=ch;
            id[ch]=n++;
        }
        vector<int> u,v;
        for(int i=0;i<len;i++){
            int t=i;//记录起始节点
            i+=2;
            while(i<len && s[i]!=';'){
                u.push_back(id[s[t]]);//加入起始节点
                v.push_back(id[s[i]]);//加入起始节点的相邻节点
                i++;
            }
        }
        //遍历+剪枝
        int bandwidth=0,res=inf;
        int bestP[maxn];//存储最终结果
        for(int i=0;i<n;i++)p[i]=i;
        do{
            bandwidth=0;//初始化别忘了
            for(int i=0;i<n;i++)pos[p[i]]=i;//记录编号为pi的节点的位置
            for(int i=0;i<u.size();i++){
                bandwidth=max(bandwidth,abs(pos[u[i]]-pos[v[i]]));
                if(bandwidth>=res)break;//剪枝
            }
            if(bandwidth<res){
                memcpy(bestP,p,sizeof(p));//memcpy比较快
                res=bandwidth;
            }
        }while(next_permutation(p,p+n));
        for(int i=0;i<n;i++)printf("%c ",letter[bestP[i]]);
        printf("-> %d\n",res);
    }
}
