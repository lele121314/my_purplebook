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

FILE *fin, *fsave;

const int N = 311, M = 111;
static char fname[111];
lld best, cur;
int n, m, val[N], dist[N][N], choice[N][N], que[M];
char *case_no;

void print(FILE* f, int a, int b){
	if(!choice[a][b]){
		fprintf(f, "%d ", a);
		return;
	}
	print(f, a, choice[a][b]);
	print(f, choice[a][b], b);
}

void save(){
	fprintf(stderr, "New best = " LLD "\n", best);
	fflush(stderr);
	
	FILE *fsave = NULL;
	if(case_no){
		sprintf(fname, "ruby%s.out", case_no);
		fsave = fopen(fname, "w");
	}else
		fsave = stdout;
	for(int i = 1; i <= m; i++)
		print(fsave, que[i - 1], que[i]);
	fprintf(fsave, "%d\n", que[m]);
	if(case_no)
		fclose(fsave);
	else
		fflush(fsave);
	
	if(case_no){
		sprintf(fname, "ruby%s.save", case_no);
		fsave = fopen(fname, "w");
		for(int i = 1; i <= m; i++)
			fprintf(fsave, "%d ", que[i]);
		fprintf(fsave, "\n");
		fclose(fsave);
	}
}

void init(){
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
	for(int i = 1; i <= m; i++){
		int x, y;
		fscanf(fin, "%d%d", &x, &y);
		que[i] = x;
		val[x] = y;
	}
	fclose(fin);
	if(fsave){
		//printf("%d\n", fsave);fflush(stdout);
		for(int i = 1; i <= m; i++)
			fscanf(fsave, "%d", &que[i]);
		fclose(fsave);
	}
	que[0] = 1;
	for(int i = 1; i <= m; i++)
		cur += val[que[i]] - dist[que[i - 1]][que[i]];
	best = cur;
	save();
}

void anneal(){
	static lld temp = 0;
	static const lld baseline = 1e3;
	int x, y;
	do{
		x = rand() % m + 1;
		y = rand() % m + 1;
	}while(x >= y);
	lld delta = (
		y == x + 1 ?
		dist[que[x - 1]][que[x]] + dist[que[x]][que[y]] + dist[que[y]][que[y + 1]] - 
		dist[que[x - 1]][que[y]] - dist[que[y]][que[x]] - dist[que[x]][que[y + 1]] :
		dist[que[x - 1]][que[x]] + dist[que[x]][que[x + 1]] + dist[que[y - 1]][que[y]] + dist[que[y]][que[y + 1]] - 
		dist[que[x - 1]][que[y]] - dist[que[y]][que[x + 1]] - dist[que[y - 1]][que[x]] - dist[que[x]][que[y + 1]]
	);
	if(delta > 0 || temp * rand() > (baseline - delta) * 100000){
		std::swap(que[x], que[y]);
		cur += delta;
		if(best < cur){
			best = cur;
			save();
		}
		//if(delta <= 0)
		//	fprintf(stderr, "Boom " LLD " " LLD "\n", delta, temp);
		temp = 0;
	}else
		temp++;
}

int main(int argc, char **argv){
	srand(time(0));
	if(argc > 1){
		sprintf(fname, "../../data/ruby%s.in", argv[1]);
		fin = fopen(fname, "r");
		sprintf(fname, "ruby%s.save", argv[1]);
		fsave = fopen(fname, "r");
		case_no = argv[1];
	}else{
		fin = stdin;
		fsave = NULL;
	}
	init();
	while(true){
		for(int i = 1; i <= 1e8; i++)
			anneal();
		//continue;
		fprintf(stderr, "Reshuffle, best = " LLD "\n", best);
		fflush(stderr);
		std::random_shuffle(que + 1, que + m + 1);
		cur = 0;
		for(int i = 1; i <= m; i++)
			cur += val[que[i]] - dist[que[i - 1]][que[i]];
		if(best < cur){
			best = cur;
			save();
		}
	}
	
	return 0;
}
