#include <cstdio>

using namespace std;

int n, m, a[501010], b[505050];

int main() {
    scanf("%d%d", &n, &m);
    for (int i=0; i<=n; i++) scanf("%d", a+i);
    for (int i=0; i<=m; i++) scanf("%d", b+i);
    long long ans = a[n] * (long long)(m);
    for (int i=0; i<n; i++) {
        long long now = a[i] * (long long)(m) + (m-i) * (long long)(n);
        if (now < ans) {
            ans = now;
        }
    }
    printf("%lld\n", ans);
}
