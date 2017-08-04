#include<cstdio>
#include<algorithm>
#include<vector>
using namespace std;
vector<int> v;
vector<int> v2;
int son,mom;
int s,n;
bool check(){
	for(int i=1;i<n-1;i++){
		if(v[n-1]==v[i]){
			if(v2[i]==v2[n-1]){
				s=n-1-i;
				return true;
			}
		}
	}
	return false;
}
int main(){
	while(scanf("%d%d",&son,&mom)!=EOF){
		v.clear();
		v2.clear();
		s=1;
		int i=0;
		printf("%d/%d = ",son,mom);
		while(true){
			v.push_back(0);
			v2.push_back(0);
			n=v.size();
			v[i]=son/mom;
			v2[i]=son%mom;
			son-=mom*v[i];
			if(son==mom)break;
			if(check())break;
			son*=10;
			i++;
		}
		printf("%d.",v[0]);
		for(i=1;i<n-1-s;i++){
			printf("%d",v[i]);
		} 
		printf("(");
		for(i=n-1-s;i<n-1;i++){
			if(i>=50+n-1-s){
				printf("...");
				break;
			}
			printf("%d",v[i]);
		}
		printf(")");
		printf("\n   %d = number of digits in repeating cycle\n\n",s);
	}
	return 0;
}
