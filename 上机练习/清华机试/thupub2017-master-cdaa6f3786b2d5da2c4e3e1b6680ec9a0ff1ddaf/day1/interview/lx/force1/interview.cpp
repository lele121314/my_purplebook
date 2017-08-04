#include <cstdio>
#include <cassert>
#include <algorithm>

#define rep(i, x, y) for (int i = (x), _ = (y); i <= _; ++i)
#define down(i, x, y) for (int i = (x), _ = (y); i >= _; --i)
#define x first
#define y second
#define mp make_pair
#define pb push_back
#define bin(x) (1<<(x))
#define LX_JUDGE

using namespace std;
typedef long long LL;
typedef pair<int, int> pii;

template<typename T> inline void upmax(T &x, T y) { x < y ? x = y : 0; }
template<typename T> inline void upmin(T &x, T y) { x > y ? x = y : 0; }

template<typename T>
inline void read(T &x) {
	char c;
	while ((c = getchar()) < '0' || c > '9');
	for (x = c - '0'; (c = getchar()) >= '0' && c <= '9'; x = x * 10 + c - '0');
}

const int inf = 0x3f3f3f3f;
const int maxn = 1e5 + 10;

int N, M, K;
int cnt[105];

int main() {
//	freopen("interview1.in", "r", stdin);
	scanf("%d%d%d", &N, &M, &K);
	assert(K == 0);
	assert(M <= 100);
	int ans = -1, val;
	rep (i, 1, N) {
		scanf("%d", &val);
		assert(val <= 100);
		cnt[val]++;
		if (cnt[val] >= M) {
			ans = i;
			break ;
		}
	}
	if (ans < 0) {
		puts("impossible");
	} else {
		printf("%d\n", ans);
	}
	return 0;
}
