#include<cstdio>
#include<cstring>
#include<vector>
#include<algorithm>
using namespace std;

const int maxn=10,inf=0x7fffffff;
char letter[maxn], s[100];//��ĸ,��������
int id[256]; //��ĸ�ı��
int p[maxn]; //ȫ���еı������� ,�洢����ÿ����ĸ�ı��
int pos[maxn];//��¼ÿ����ĸ��λ�ã�����Ƶ��ʹ��strchr

int main(){
    while(scanf(" %s",&s),s[0]!='#'){
        int len=strlen(s),n=0;
        for(char ch='A';ch<='Z';ch++)if(strchr(s,ch)!=NULL){
            letter[n]=ch;
            id[ch]=n++;
        }
        vector<int> u,v;
        for(int i=0;i<len;i++){
            int t=i;//��¼��ʼ�ڵ�
            i+=2;
            while(i<len && s[i]!=';'){
                u.push_back(id[s[t]]);//������ʼ�ڵ�
                v.push_back(id[s[i]]);//������ʼ�ڵ�����ڽڵ�
                i++;
            }
        }
        //����+��֦
        int bandwidth=0,res=inf;
        int bestP[maxn];//�洢���ս��
        for(int i=0;i<n;i++)p[i]=i;
        do{
            bandwidth=0;//��ʼ��������
            for(int i=0;i<n;i++)pos[p[i]]=i;//��¼���Ϊpi�Ľڵ��λ��
            for(int i=0;i<u.size();i++){
                bandwidth=max(bandwidth,abs(pos[u[i]]-pos[v[i]]));
                if(bandwidth>=res)break;//��֦
            }
            if(bandwidth<res){
                memcpy(bestP,p,sizeof(p));//memcpy�ȽϿ�
                res=bandwidth;
            }
        }while(next_permutation(p,p+n));
        for(int i=0;i<n;i++)printf("%c ",letter[bestP[i]]);
        printf("-> %d\n",res);
    }
}
