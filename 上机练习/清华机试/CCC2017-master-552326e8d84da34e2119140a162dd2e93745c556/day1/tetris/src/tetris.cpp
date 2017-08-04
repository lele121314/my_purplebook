#include <cstdio>
#include <cstdlib>

using namespace std;
const int C = 10;
const int H = 501010;
const int N = 501010;
int op[N][3];

class Tetris {
public:
    int x[4], y[4];
    int mx, my;
    Tetris () {}
    Tetris(int x0, int y0, int x1, int y1, int x2, int y2, int x3, int y3) {
        x[0] = x0; y[0] = y0;
        x[1] = x1; y[1] = y1;
        x[2] = x2; y[2] = y2;
        x[3] = x3; y[3] = y3;
        mx = my = 1;
        for (int i=0; i<4; i++) {
            if (x[i]+1 > mx) mx = x[i]+1;
            if (y[i]+1 > my) my = y[i]+1;
        }
    }
};
Tetris tetris[10][4];

char to_char(int x) {
    if (x == 0) return '.'; else return 'X';
}

class Map {
public:
    int a[C][H];
    int c, h;
    void clear(int c, int h) {
        this->c = c;
        this->h = h;
        for (int i=0; i<c; i++)
            for (int j=0; j<h; j++)
                a[i][j] = 0;
    }
    void print() {
        for (int j=0; j<c; j++)
            printf("%d", j);
        printf("\n");
        for (int i=h-1; i>=0; i--) {
            for (int j=0; j<c; j++)
                printf("%c", to_char(a[j][i]));
            printf("\n");
        }
    }
    int put(Tetris t, int x) {
        int y = 0;
        for (int i=h-1; i>=0; i--) {
            bool flag = true;
            for (int k=0; k<4; k++)
                if (a[x+t.x[k]][i+t.y[k]]) {
                    flag = false;
                    break;
                }
            if (flag) y = i; else break;
        }

        for (int k=0; k<4; k++)
            a[x+t.x[k]][y+t.y[k]] = 1;
        
        int r = 0;
        for (int i=0; i<t.my; i++) {
            int s = 0;
            for (int j=0; j<c; j++)
                s += a[j][i+y];
            if (s == c) {
                r += 1;
            } else {
                if (r > 0) {
                    for (int j=0; j<c; j++)
                        a[j][i+y-r] = a[j][i+y];
                }
            }
        }
        if (r > 0) {
            for (int i=y+t.my; i<h; i++)
                for (int j=0; j<c; j++)
                    a[j][i-r] = a[j][i];
        }
        return r;
    }
} map;

void print(int now) {
    printf("\nstep: %d\n", now);
    map.print();
}

int put(int now) {
    Tetris t = tetris[op[now][0]][op[now][1]];
    int x = op[now][2];
    return map.put(t, x);
}

int create(int n, int c, int h) {
    map.clear(c, h);
    int ans = 0;
    for (int i=0; i<n; i++) {
        ans += put(i);
        //if (i % 1000 == 0) printf("i=%d: ans=%d\n", i, ans);
    }
    return ans;
}

int main() {
    tetris[0][0] = Tetris(0, 0, 1, 0, 0, 1, 1, 1);
    tetris[0][1] = tetris[0][0];
    tetris[0][2] = tetris[0][0];
    tetris[0][3] = tetris[0][0];
    tetris[1][0] = Tetris(0, 0, 0, 1, 0, 2, 0, 3);
    tetris[1][1] = Tetris(0, 0, 1, 0, 2, 0, 3, 0);
    tetris[1][2] = tetris[1][0];
    tetris[1][3] = tetris[1][1];
    
    tetris[2][0] = Tetris(0, 0, 0, 1, 1, 0, 2, 0);
    tetris[2][1] = Tetris(0, 0, 1, 0, 1, 1, 1, 2);
    tetris[2][2] = Tetris(0, 1, 1, 1, 2, 0, 2, 1);
    tetris[2][3] = Tetris(0, 0, 0, 1, 0, 2, 1, 2);
    
    tetris[3][0] = Tetris(0, 0, 1, 0, 2, 0, 2, 1);
    tetris[3][1] = Tetris(0, 2, 1, 0, 1, 1, 1, 2);
    tetris[3][2] = Tetris(0, 0, 0, 1, 1, 1, 2, 1);
    tetris[3][3] = Tetris(0, 0, 0, 1, 0, 2, 1, 0);

    tetris[4][0] = Tetris(0, 1, 1, 0, 1, 1, 2, 0);
    tetris[4][1] = Tetris(0, 0, 0, 1, 1, 1, 1, 2);
    tetris[4][2] = tetris[4][0];
    tetris[4][3] = tetris[4][1];

    tetris[5][0] = Tetris(0, 0, 1, 0, 1, 1, 2, 1);
    tetris[5][1] = Tetris(0, 1, 0, 2, 1, 0, 1, 1);
    tetris[5][2] = tetris[5][0];
    tetris[5][3] = tetris[5][1];

    tetris[6][0] = Tetris(0, 0, 1, 0, 1, 1, 2, 0);
    tetris[6][1] = Tetris(0, 1, 1, 0, 1, 1, 1, 2);
    tetris[6][2] = Tetris(0, 1, 1, 0, 1, 1, 2, 1);
    tetris[6][3] = Tetris(0, 0, 0, 1, 0, 2, 1, 1);

    int n, h, c=C, now;
    //FILE * f = fopen("op.in", "r");
    //fscanf(f, "%d%d", &n, &h);
    scanf("%d%d", &n, &h);
    for (int i=0; i<n; i++) {
        char s[2];
        //fscanf(f, "%s%d%d", s, op[i]+1, op[i]+2);
        scanf("%s%d%d", s, op[i]+1, op[i]+2);
        op[i][0] = s[0] - 'A';
    }
    now = n;
    int ans = create(now, c, h);
    printf("%d\n", ans);
    exit(0);
    print(now);
    
    while (true) {
        FILE * g = fopen("op.out", "w");
        fprintf(g, "%d %d\n", now, h);
        for (int i=0; i<now; i++) {
            fprintf(g, "%c %d %d\n", op[i][0]+'A', op[i][1], op[i][2]);
        }
        fclose(g);
        char s[2];
        scanf("%s", s);
        if (s[0] == '-') {
            break;
        }
        if (s[0] == '0') {
            ans = create(--now, c, h);
            print(now);
        } else {
            op[now][0] = s[0] - 'A';
            scanf("%d%d", op[now]+1, op[now]+2);
            if (op[now][0] >= 0 && op[now][0] < 7) {
                Tetris t = tetris[op[now][0]][op[now][1]];
                printf("mx = %d\n", t.mx);
                if (op[now][2] + t.mx <= c) {
                    ans += put(now++);
                    print(now);
                } else {
                    printf("ERROR: out of range!\n");
                }
            } else {
                printf("ERROR: unknown block!\n");
            }
        }
    }
    printf("%d\n", ans);
}
