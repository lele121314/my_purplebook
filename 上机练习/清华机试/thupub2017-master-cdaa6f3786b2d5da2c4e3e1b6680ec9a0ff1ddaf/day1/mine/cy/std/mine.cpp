#include <iostream>
#include <cstdlib>
#include <cstring>
#include <cstdio>
#include <algorithm>
#include <vector>
#include <queue>

using namespace std;

namespace Solve
{
    struct Cell
    {
        int x, y;
        Cell(int x, int y): x(x), y(y) {}
    };
    bool operator<(const Cell&A, const Cell&B)
    {
        return A.x < B.x || (A.x == B.x && A.y < B.y);
    }

    const int MAXN = 1000 + 10;
    const int dx[] = {1, -1, 0, 0, 1, 1, -1, -1};
    const int dy[] = {0, 0, 1, -1, 1, -1, 1, -1};

    int n, m;
    char map[MAXN][MAXN];
    int num[MAXN][MAXN];
    bool swept[MAXN][MAXN];
    bool flaged[MAXN][MAXN];
    vector<Cell> cells;
    string status;
    int empty_num;

    bool isok(int x, int y)
    {
        return 1 <= x && x <= n && 1 <= y && y <= m;
    }
    /// return true if boom
    bool process(int x, int y)
    {
        if (map[x][y] == '*')
        {
            puts("boom");
            status = "game over";
            return true;
        }
        queue<int> que;
        que.push(x);que.push(y);
        while(!que.empty())
        {
            int u = que.front(); que.pop();
            int v = que.front(); que.pop();
            if(swept[u][v]) continue;
            cells.push_back(Cell(u, v));
            swept[u][v] = true;
            if (num[u][v] == 0)
            {
                for(int k = 0; k < 8; k ++)
                    if(isok(u+dx[k], v+dy[k]))
                        flaged[u+dx[k]][v+dy[k]] = false;
                for(int k = 0; k < 8; k ++)
                    if(isok(u+dx[k], v+dy[k]) && !swept[u+dx[k]][v+dy[k]])
                    {
                        que.push(u+dx[k]);que.push(v+dy[k]);
                    }
            }
        }

        return false;
    }
    void showCells()
    {
        empty_num -= cells.size();
        if (cells.size() == 0) {
            puts("no cell detected");
            return;
        }
        printf("%d cell(s) detected\n", cells.size()); // FIXME fixed
        sort(cells.begin(), cells.end());
        for(int i = 0; i < (int)cells.size(); i ++)
        {
            printf("%d %d %d\n", cells[i].x, cells[i].y, num[cells[i].x][cells[i].y]);
        }
    }
    void solve()
    {
        scanf("%d%d", &n, &m);
        for(int i=1;i<=n;i++)
        {
            scanf("%s", map[i]+1);
        }
        empty_num = 0;
        for(int x=1;x<=n;x++)
            for(int y=1;y<=m;y++)
            {
                num[x][y]=0;
                for(int k=0;k<8;k++)
                    if(isok(x+dx[k], y+dy[k]) && map[x+dx[k]][y+dy[k]] == '*')
                    {
                        num[x][y]++;
                    }
                if (map[x][y] == '.') empty_num ++;
            }
        memset(swept, 0, sizeof(swept));
        memset(flaged, 0, sizeof(flaged));

        char buf[1024];
        int total_step = 0;
        while(scanf("%s", buf))
        {
            cells.clear();
            int x, y;
            if (buf[0] != 'Q') {
                scanf("%d%d", &x, &y);
                total_step ++;
            }
            if (buf[0] == 'F')
            {
                // FIXME 如果对应方块为空，插上旗帜，输出一行 success fixed
                if (swept[x][y]) {
                    puts("swept");
                } else {
                    if (flaged[x][y]) puts("cancelled");
                    else puts("success");
                    flaged[x][y] = !flaged[x][y];
                }
            } else if (buf[0] == 'S')
            {
                if (swept[x][y]) {
                    puts("swept");
                } else {
                    if (flaged[x][y]) puts("flagged");
                    else {
                        if (process(x, y)) break;
                        showCells();
                    }
                }
            } else if (buf[0] == 'D')
            {
                if (!swept[x][y]) {
                    puts("not swept");
                } else {
                    int flag_num = 0;
                    for(int k = 0; k < 8; k ++)
                        if (isok(x+dx[k], y+dy[k]) && flaged[x+dx[k]][y+dy[k]])
                            flag_num ++;
                    if (num[x][y] == 0 || flag_num != num[x][y]) {
                        puts("failed");
                    } else {
                        bool boom=false;
                        for(int k = 0; k < 8 && !boom; k ++)
                            if (isok(x+dx[k], y+dy[k]) && !flaged[x+dx[k]][y+dy[k]])
                                boom |= process(x+dx[k], y+dy[k]);
                        if (boom) break;
                        showCells();
                    }
                }
            } else {
                status = "give up";
                break;
            }
            if (empty_num == 0) {
                status = "finish";
                break;
            }
        }
        puts(status.c_str());
        printf("total step %d\n", total_step);
    }
}

int main(int argc, char* argv[])
{
    freopen("1.in", "r", stdin);
    freopen("mine.out", "w", stdout);

    Solve::solve();

    return 0;
}
