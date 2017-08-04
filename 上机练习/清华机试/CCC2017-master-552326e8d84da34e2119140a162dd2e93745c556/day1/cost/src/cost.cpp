#include <cstdio>
#include <cstdlib>
#include <vector>
#include <algorithm>
using namespace std;
#define rep(i,a,n) for (int i=a;i<n;i++)
#define per(i,a,n) for (int i=n-1;i>=a;i--)
#define pb push_back
#define mp make_pair
#define all(x) (x).begin(),(x).end()
#define SZ(x) ((int)(x).size())
#define fi first
#define se second
typedef vector<int> VI;
typedef long long ll;
typedef pair<int, int> PII;
const ll mod = 1000000007;
ll powmod(ll a, ll b) {
	ll res = 1;
	a %= mod;
	for (; b; b >>= 1) {
		if (b & 1)
			res = res * a % mod;
		a = a * a % mod;
	}
	return res;
}

const int N = 501000;
ll r[N], c[N], ans;
int sr[N], sc[N], tr, tc;
int n, m;
bool cmp(ll *r, int a, int b, int c) {
	return (r[c] - r[a]) * (b - a) <= (r[b] - r[a]) * (c - a);
}
void gao(ll *r, int *s, int &top, int n) {
	rep(i,0,n)
	{
		while (top >= 2 && cmp(r, s[top - 2], s[top - 1], i))
			--top;
		s[top++] = i;
	}
}
int main() {
	scanf("%d%d", &n, &m);
	rep(i,0,n+1)
		scanf("%lld", r + i);
	rep(i,0,m+1)
		scanf("%lld", c + i);
	gao(r, sr, tr, n + 1);
	gao(c, sc, tc, m + 1);
	int pr = 0, pc = 0;
	while (pr < tr - 1 && pc < tc - 1) {
		if ((r[sr[pr + 1]] - r[sr[pr]]) * (sc[pc + 1] - sc[pc])
				<= (c[sc[pc + 1]] - c[sc[pc]]) * (sr[pr + 1] - sr[pr])) {
			ans += (sr[pr + 1] - sr[pr]) * c[sc[pc]];
			pr++;
		} else {
			ans += (sc[pc + 1] - sc[pc]) * r[sr[pr]];
			pc++;
		}
	}
	if (pr == tr - 1)
		ans += (m - sc[pc]) * r[n];
	else
		ans += (n - sr[pr]) * c[m];
	printf("%lld\n", ans);
}
