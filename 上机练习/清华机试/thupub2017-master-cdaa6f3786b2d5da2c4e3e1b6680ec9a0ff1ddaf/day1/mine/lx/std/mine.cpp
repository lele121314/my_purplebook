#include <cstdio>
#include <algorithm>
#include <vector>
#include <queue>
#include <cassert>

#define rep(i, x, y) for (int i = (x), _ = (y); i <= _; ++i)
#define down(i, x, y) for (int i = (x), _ = (y); i >= _; --i)
#define x first
#define y second
#define LX_JUDGE

using namespace std;

const int maxn = 2005;

const int dx[] = {-1, -1, 0, 1, 1, 1, 0, -1};
const int dy[] = {0, 1, 1, 1, 0, -1, -1, -1};

char board[maxn][maxn];
int val[maxn][maxn];
int N, M;

int state[maxn][maxn];
/*
   state = 
    0. not operated
	1. swept
	2. flagged
*/

inline bool inBoard(int x, int y) {
	return x >= 1 && x <= N && y >= 1 && y <= M;
}
inline bool isMine(int x, int y) {
	return inBoard(x, y) && board[x][y] == '*';
}

void place_flag(int x, int y) {
	switch (state[x][y]) {
		case 0 : 
			state[x][y] = 2;
			puts("success");
			break ;
		case 1 : 
			puts("swept");
			break ;
		case 2 : 
			state[x][y] = 0;
			puts("cancelled");
			break ;
		default :
			assert(0);
	}
}

vector<pair<int, int> > buff;

int Search(int x, int y) {
	assert(inBoard(x, y) && state[x][y] == 0);
	if (board[x][y] == '*') {
		puts("boom");
		return 1;
	}
	queue<pair<int, int> > Q;
	Q.push(make_pair(x, y));
	state[x][y] = 1;
	while (!Q.empty()) {
		pair<int, int > now = Q.front();
		Q.pop();
		buff.push_back(now);
		if (val[now.x][now.y]) {
			continue ;
		}
		for (int i = 0; i < 8; ++i) {
			int tx = now.x + dx[i], ty = now.y + dy[i];
			if (inBoard(tx, ty) && state[tx][ty] != 1) {
				state[tx][ty] = 1;
				Q.push(make_pair(tx, ty));
			}
		}
	}
	return 0;
}

int total_cell, de_cnt;

int output_buff() {
	if (buff.size() == 0) {
		puts("no cell detected");
		return 0;
	}
	de_cnt += buff.size();
	sort(buff.begin(), buff.end());
	printf("%d cell(s) detected\n", buff.size());
	for (int i = 0; i < buff.size(); ++i) {
		printf("%d %d %d\n", buff[i].x, buff[i].y, val[buff[i].x][buff[i].y]);
	}
	buff.clear();
	return total_cell == de_cnt;
}

int sweep_mine(int x, int y) {
	switch (state[x][y]) {
		case 0 : 
			if (Search(x, y) == 1) {
				return 2;
			} else {
				return output_buff();
			}
			break ;
		case 1 :
			puts("swept");
			break ;
		case 2 : 
			puts("flagged");
			break ;
		default :
			assert(0);
	}
	return 0;
}

int d_sweep_mine(int x, int y) {
	if (state[x][y] != 1) {
		puts("not swept");
	} else {
		if (val[x][y] == 0) {
			puts("failed");
		} else {
			int cnt = 0;
			for (int i = 0; i < 8; ++i) {
				cnt += (inBoard(x + dx[i], y + dy[i]) && state[x + dx[i]][y + dy[i]] == 2);
			}
			if (cnt != val[x][y]) {
				puts("failed");
			} else {
				for (int i = 0; i < 8; ++i) {
					if (inBoard(x + dx[i], y + dy[i]) && state[x + dx[i]][y + dy[i]] == 0) {
						if (Search(x + dx[i], y + dy[i]) == 1) {
							return 2;
						}
					}
				}
				return output_buff();
			} 
		}
	}
	return 0;
}

/*
   res = 
	1. finished
	2. game over
	3. given up
*/
void game_end(int res, int tot) {
	switch (res) {
		case 1 :
			puts("finish");
			break ;
		case 2 :
			puts("game over");
			break ;
		case 3 : 
			puts("give up");
			break ;
		default :
			assert(0);
	}
	printf("total step %d\n", tot);
}

int main() {
#if not defined(DATA_GEN) && not defined(__OI_TESTER__) && not defined(ONLINE_JUDGE)
	freopen("mine.in", "r", stdin);
	freopen("mine.out", "w", stdout);
#endif

	scanf("%d%d", &N, &M);

	for (int i = 1; i <= N; ++i) {
		scanf("%s", board[i] + 1);
	}

	for (int i = 1; i <= N; ++i) {
		for (int j = 1; j <= M; ++j) {
			if (board[i][j] == '*') {
				val[i][j] = -1;
			} else {
				total_cell++;
				for (int d = 0; d < 8; ++d) {
					val[i][j] += isMine(i + dx[d], j + dy[d]);
				}
			}
		}
	}

	int opt_num = 0;
	int res = 0;
	char opt[10];
	int x, y;

	while (~scanf("%s", opt)) {
		if (opt[0] == 'Q') {
			res = 3;
			break ;
		}

		++opt_num;
		scanf("%d%d", &x, &y);

		switch (opt[0]) {
			case 'F' :
				place_flag(x, y);
				break ;
			case 'S' :
				res = sweep_mine(x, y);
				break ;
			case 'D' :
				res = d_sweep_mine(x, y);
				break ;
			default :
				assert(0);
		}

		if (res) {
			break ;
		}
	}

	game_end(res, opt_num);

	fclose(stdin);
	fclose(stdout);

	return 0;
}
