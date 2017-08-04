#include <iostream>
#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <ctime>
#include <algorithm>

#ifndef WIN32
#define LLD "%lld"
#else
#define LLD "%I64d"
#endif

typedef long long lld;
const int N = 311, M = 23, S = (1 << 20) + 11;
int n, m, dist[N][N], choice[N][N], que[M], val[M], dp_choice[M][S];
lld rec[M][S];
bool used[M][S];

void init(){
	FILE *fin = stdin;
	fscanf(fin, "%d%d", &n, &m);
	for(int i = 1; i <= n; i++)
		for(int j = 1; j <= n; j++)
			fscanf(fin, "%d", &dist[i][j]);
	for(int k = 1; k <= n; k++)
		for(int i = 1; i <= n; i++)
			for(int j = 1; j <= n; j++)
				if(dist[i][j] > dist[i][k] + dist[k][j]){
					dist[i][j] = dist[i][k] + dist[k][j];
					choice[i][j] = k;
				}
	que[0] = 1;
	for(int i = 1; i <= m; i++){
		int x, y;
		fscanf(fin, "%d%d", &x, &y);
		que[i] = x;
		val[i] = y;
	}
	fclose(fin);
}

lld dp(int a, int s){
	if(used[a][s])
		return rec[a][s];
	used[a][s] = true;
	lld ans = 0;
	int cho = 0;
	for(int i = 1; i <= m; i++){
		lld tmp = dp(i, s | (1 << (i - 1))) - dist[que[a]][que[i]] + val[i];
		if(~(s >> (i - 1)) & 1 && ans < tmp){
			ans = tmp;
			cho = i;
		}
	}
	dp_choice[a][s] = cho;
	return rec[a][s] = ans;
}

void print_sp(int a, int b){
	if(!choice[a][b]){
		printf(" %d", b);
		return;
	}
	print_sp(a, choice[a][b]);
	print_sp(choice[a][b], b);
}

void print_dp(int a, int s){
	if(!dp_choice[a][s])
		return;
	print_sp(que[a], que[dp_choice[a][s]]);
	print_dp(dp_choice[a][s], s | (1 << (dp_choice[a][s] - 1)));
}

int main(){
	init();
	fprintf(stderr, LLD "\n", dp(0, 0));
	printf("1");
	print_dp(0, 0);
	printf("\n");
	return 0;
}
