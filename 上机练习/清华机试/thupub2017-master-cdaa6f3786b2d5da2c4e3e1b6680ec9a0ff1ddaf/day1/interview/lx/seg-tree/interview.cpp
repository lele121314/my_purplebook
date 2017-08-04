#include <cstdio>
#include <algorithm>

#define rep(i, x, y) for (int i = (x), _ = (y); i <= _; ++i)
#define down(i, x, y) for (int i = (x), _ = (y); i >= _; --i)
#define LX_JUDGE

using namespace std;

template<typename T> inline void upmax(T &x, T y) { x < y ? x = y : 0; }
template<typename T> inline void upmin(T &x, T y) { x > y ? x = y : 0; }

const int inf = 0x3f3f3f3f;
const int maxn = 1e5 + 10;

int N, M, K;
int h[maxn], poi[maxn];

inline int cmp(int x, int y) {
	return h[x] < h[y];
}

#define ls (o << 1)
#define rs (o << 1 | 1)
int seg[maxn * 4];

void ins(int o, int l, int r, int p) {
	seg[o]++;
	if (l == r)  return ;
	int mid = (l + r) / 2;
	mid >= p ? ins(ls, l, mid, p) : ins(rs, mid + 1, r, p);
}
void del(int o, int l, int r, int p) {
	seg[o]--;
	if (l == r)  return ;
	int mid = (l + r) / 2;
	mid >= p ? del(ls, l, mid, p) : del(rs, mid + 1, r, p);
}
int getK(int o, int l, int r, int k) {
	if (l == r)  return l;
	int mid = (l + r) / 2, sz = seg[ls];
	return sz >= k ? getK(ls, l, mid, k) : getK(rs, mid + 1, r, k - sz);
}
#undef ls
#undef rs

int main() {
#if not defined(DATA_GEN) && not defined(__OI_TESTER__) && not defined(ONLINE_JUDGE)
	freopen("interview.in", "r", stdin);
	freopen("interview.out", "w", stdout);
#endif
	scanf("%d%d%d", &N, &M, &K);
	rep (i, 1, N) {
		scanf("%d", &h[i]);
		poi[i] = i;
	}
	sort(poi + 1, poi + N + 1, cmp);
	int ans = inf, last = 1;
	rep (i, 1, N) {
		int v = h[poi[i]];
		while (v - h[poi[last]] > K) {
			del(1, 1, N, poi[last]);
			last++;
		}
		ins(1, 1, N, poi[i]);
		if (seg[1] >= M) {
			upmin(ans, getK(1, 1, N, M));
		}
	}
	if (ans == inf) {
		puts("impossible");
	} else {
		printf("%d\n", ans);
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
