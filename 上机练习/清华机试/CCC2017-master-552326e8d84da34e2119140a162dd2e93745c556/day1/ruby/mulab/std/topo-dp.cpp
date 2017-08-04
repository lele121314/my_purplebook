#include <iostream>
#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <algorithm>

#ifdef UNIX
#define LLD "%lld"
#else
#define LLD "%I64d"
#endif

typedef long long lld;
const int N = 311, LOWER = 10000, UPPER = 5e8;
int n, m, pedges, head[N], degree[N], val[N], choice[N];
struct Edge{
	int ver, next, len;
}edges[N * N];
lld rec[N];
bool used[N], instack[N];

void ins(int u, int v, int l){
	edges[++pedges] = (Edge){v, head[u], l};
	head[u] = pedges;
	degree[u]++;
}

void init(){
	scanf("%d%d", &n, &m);
	for(int i = 1; i <= n; i++)
		for(int j = 1; j <= n; j++){
			int x;
			scanf("%d", &x);
			if(i == j){
				if(x != 0)
					fprintf(stderr, "[E]dist[%d][%d] = %d != 0.\n", i, j, x);
				continue;
			}
			if(x <= LOWER)
				ins(i, j, x);
			else if(x < UPPER)
				fprintf(stderr, "[E]dist[%d][%d] = %d, between LOWER and UPPER.\n", i, j, x);
		}
	for(int i = 1; i <= m; i++){
		int x, y;
		scanf("%d%d", &x, &y);
		val[x] = y;
	}
}

lld dp(int a){
	if(instack[a]){
		fprintf(stderr, "[E]Circuit at city %d.\n", a);
		exit(0);
		return 0LL;
	}
	if(used[a])
		return rec[a];
	instack[a] = used[a] = true;
	lld ans = 0;
	int cho = 0;
	for(int i = head[a]; i; i = edges[i].next){
		lld tmp = dp(edges[i].ver) - edges[i].len;
		if(ans < tmp){
			cho = i;
			ans = tmp;
		}
	}
	instack[a] = false;
	choice[a] = cho;
	return rec[a] = ans + val[a];
}

void print(int a){
	if(!a)
		return;
	printf("%d ", a);
	print(edges[choice[a]].ver);
}

int main(){
	init();
	fprintf(stderr, "Best ans = " LLD, dp(1));
	print(1);
	printf("\n");
	
	return 0;
}
