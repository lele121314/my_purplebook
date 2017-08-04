#include <iostream>
#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <ctime>
#include <algorithm>
#include <map>

#ifndef WIN32
#define LLD "%lld"
#else
#define LLD "%I64d"
#endif

typedef long long lld;
const int N = 311, M = 33, S = (1 << 20) + 11;
const lld inf = 0x3F3F3F3F3F3F3F3FLL;
int n, m, dist[N][N], choice[N][N], rubies[M], val[M], sets[M][M], set_bit[M];
std::map<int, int>mig[M][M];
std::map<int, lld>rec[M][M];
lld best, cur;

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
	rubies[0] = 1;
	for(int i = 1; i <= m; i++){
		int x, y;
		fscanf(fin, "%d%d", &x, &y);
		rubies[i] = x;
		val[i] = y;
	}
	fclose(fin);
	for(int i = 1; i <= 5; i++)
		for(int j = 1; j <= 6; j++)
			sets[i][j] = (i - 1) * 6 + j;
	FILE *fsave = fopen("save", "r");
	if(!fsave)
		return;
	fscanf(fsave, LLD, &best);
}

lld dp(int st, int ed, int s){
	if(!s)
		return -inf;
	if(rec[st][ed].count(s))
		return rec[st][ed][s];
	lld ans = 0;
	int cho = 0;
	for(int i = 1; i <= m; i++)
		if(i != ed && (s >> (i - 1)) & 1){
			lld tmp = dp(st, i, s & ~(1 << (ed - 1))) + dist[rubies[i]][rubies[ed]];
			if(ans < tmp){
				ans = tmp;
				cho = i;
			}
		}
	mig[st][ed][s] = cho;
	return rec[st][ed][s] = ans + val[ed];
}

void dfs(int st, int ed, int s, int de){
	if(!de){
		dp(st, ed, s);
		return;
	}
	for(int i = 1; i <= m; i++)
		if(~(s >> (i - 1)) & 1)
			dfs(st, i, s | (1 << (i - 1)), de - 1);
}

void shuffle(){
	for(int i = 1; i <= 10000; i++){
		int x, y;
		do{
			x = rand() % 5 + 1;
			y = rand() % 5 + 1;
		}while(x == y);
		std::swap(sets[x][rand() % 6 + 1], sets[y][rand() % 6 + 1]);
	}
	cur = 0;
	for(int i = 1; i <= 5; i++){
		set_bit[i] = 0;
		for(int j = 1; j <= 6; j++)
			set_bit[i] |= 1 << (sets[i][j] - 1);
		cur += rec[sets[i][1]][sets[i][6]][set_bit[i]] - dist[rubies[sets[i - 1][6]]][rubies[sets[i][1]]];
	}
	if(best < cur){
		printf(LLD "\n", best = cur);
		FILE *fsave = fopen("save", "w");
		fprintf(fsave, LLD "\n", best);
		fclose(fsave);
		fflush(stdout);
	}
	printf("Shuffle best = " LLD "\n", best);
}

void tweak(){
	switch(rand() % 3){
		case 0:{
			int x = rand() % 5 + 1;
			int y = rand() % 4 + 2;
			lld delta =
				(rec[sets[x][y]][sets[x][6]][set_bit[x]] - dist[rubies[sets[x - 1][6]]][rubies[sets[x][y]]]) -
				(rec[sets[x][1]][sets[x][6]][set_bit[x]] - dist[rubies[sets[x - 1][6]]][rubies[sets[x][1]]]);
			if(delta > 0){
				std::swap(sets[x][1], sets[x][y]);
				cur += delta;
			}
			break;
		}
		case 1:{
			int x = rand() % 5 + 1;
			int y = rand() % 4 + 2;
			lld delta =
				rec[sets[x][1]][sets[x][y]][set_bit[x]] - rec[sets[x][1]][sets[x][6]][set_bit[x]];
			if(x != 5)
				delta -= 
					dist[rubies[sets[x][y]]][rubies[sets[x + 1][1]]] - dist[rubies[sets[x][6]]][rubies[sets[x + 1][1]]];
			if(delta > 0){
				std::swap(sets[x][6], sets[x][y]);
				cur += delta;
			}
			break;
		}
		case 2:{
			int x1, x2;
			do{
				x1 = rand() % 5 + 1;
				x2 = rand() % 5 + 1;
			}while(x1 == x2);
			int y1 = rand() % 4 + 2;
			int y2 = rand() % 4 + 2;
			lld delta =
				rec[sets[x1][1]][sets[x1][6]][(set_bit[x1] & ~(1 << (sets[x1][y1] - 1))) | (1 << (sets[x2][y2] - 1))] +
				rec[sets[x2][1]][sets[x2][6]][(set_bit[x2] & ~(1 << (sets[x2][y2] - 1))) | (1 << (sets[x1][y1] - 1))] -
				rec[sets[x1][1]][sets[x1][6]][set_bit[x1]] - rec[sets[x2][1]][sets[x2][6]][set_bit[x2]];
			if(delta > 0){
				std::swap(sets[x1][y1], sets[x2][y2]);
				set_bit[x1] = (set_bit[x1] & ~(1 << (sets[x1][y1] - 1))) | (1 << (sets[x2][y2] - 1));
				set_bit[x2] = (set_bit[x2] & ~(1 << (sets[x2][y2] - 1))) | (1 << (sets[x1][y1] - 1));
				cur += delta;
			}
			break;
		}
	}
	if(best < cur){
		printf(LLD "\n", best = cur);
		FILE *fsave = fopen("save", "w");
		fprintf(fsave, LLD "\n", best);
		fclose(fsave);
		fflush(stdout);
	}
}

int main(){
	srand(time(0));
	init();
	for(int i = 1; i <= m; i++){
		printf("i = %d\n", i);fflush(stdout);
		rec[i][i][1 << (i - 1)] = val[i];
		mig[i][i][1 << (i - 1)] = 0;
		dfs(i, i, 1 << (i - 1), 6 - 1);
	}
	while(true){
		shuffle();
		for(int i = 1; i <= 1e8; i++)
			tweak();
	}
	
	return 0;
}
