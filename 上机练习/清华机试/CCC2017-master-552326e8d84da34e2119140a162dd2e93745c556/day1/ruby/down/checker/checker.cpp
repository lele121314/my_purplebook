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

const int N = 311;
const lld inf = 0x3F3F3F3F3F3F3F3FLL;
FILE *fin, *fout, *fans, *fsco, *frep;
int n, m, dist[N][N], val[N];
double total_score;
lld ans, scoring[13];
char buff[2055];

void error(const char* info){
	if(frep)
		fprintf(frep, "Error: %s\n", info);
	if(fsco)
		fprintf(fsco, "0\n");
	exit(0);
}

void read_in(){
	if(!fin)
		error("Can not open input file.");
	fscanf(fin, "%d%d", &n, &m);
	for(int i = 1; i <= n; i++)
		for(int j = 1; j <= n; j++)
			fscanf(fin, "%d", &dist[i][j]);
	for(int i = 1; i <= m; i++){
		int x, y;
		fscanf(fin, "%d%d", &x, &y);
		val[x] = y;
	}
	scoring[1] = inf;
	for(int i = 2; i <= 9; i++)
		fscanf(fin, LLD, &scoring[i]);
	fclose(fin);
}

const char* suf(int a){
	if(a % 10 == 1 && a % 100 != 11)
		return "st";
	if(a % 10 == 2 && a % 100 != 12)
		return "nd";
	if(a % 10 == 3 && a % 100 != 13)
		return "rd";
	return "th";
}

void read_out(){
	if(!fout)
		error("Can not open output file.");
	int last, cur;
	if(fscanf(fout, "%d", &last) != 1)
		error("Can not read the first integer.");
	if(last != 1){
		sprintf(buff, "The 1-st integer must be 1, but %d get.", last);
		error(buff);
	}
	lld summary = val[1];
	val[1] = 0;
	for(int i = 2; i <= n * n; i++){
		if(fscanf(fout, "%d", &cur) != 1)
			break;
		if(cur < 1 || cur > n){
			sprintf(buff, "The %d-%s integer must between [1, n], but %d get.", i, suf(i), cur);
			error(buff);
		}
		summary += val[cur] - dist[last][cur];
		val[cur] = 0;
		last = cur;
	}
	fclose(fout);
	if(frep)
		fprintf(frep, "The format of your output file is correct. The profit is " LLD ".\n", summary);
	if(fsco){
		int score;
		for(score = 10; score >= 1; score--)
			if(summary >= ans - scoring[score])
				break;
		fprintf(fsco, "%.6f\n", .1 * score * total_score);
	}
}

void read_ans(){
	if(!fans)
		return;
	fscanf(fans, LLD, &ans);
	fclose(fans);
}

int main(int argc, char **argv){
	switch(argc){
		case 2:
			fin = fopen((std::string(argv[1]) + ".in").data(), "r");
			fout = fopen((std::string(argv[1]) + ".out").data(), "r");
			frep = stdout;
			break;
		case 3:
			fin = fopen(argv[1], "r");
			fout = fopen(argv[2], "r");
			frep = stdout;
			break;
		case 4:		//Arbiter
			fin = fopen(argv[1], "r");
			fout = fopen(argv[2], "r");
			fans = fopen(argv[3], "r");
			total_score = 10.;
#ifdef WIN32
			fsco = frep = fopen("tmp/_eval.score", "w");
#else
			fsco = frep = fopen("/tmp/_eval.score", "w");
#endif
			break;
		case 7:		//TUOJ and Lemon
			fin = fopen(argv[1], "r");
			fout = fopen(argv[2], "r");
			fans = fopen(argv[3], "r");
			sscanf(argv[4], "%lf", &total_score);
			fsco = fopen(argv[5], "w");
			frep = fopen(argv[6], "w");
			break;
		default:
			printf("Usage:\n");
			printf("./checker FILE_NAME\t\t//Input file: FILE_NAME.in, output file: FILE_NAME.out\n");
			printf("./checker INPUT_FILE_NAME OUTPUT_FILE_NAME\n");
			return 0;
	}
	read_in();
	read_ans();
	read_out();
	return 0;
}
