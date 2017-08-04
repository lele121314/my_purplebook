#include <cstdio>
#include <cstdlib>

using namespace std;

int n;
int flag[1010101];

int main() {
    scanf("%d", &n);
    for (int i=1; i<=n; i++) flag[i] = 1;
    for (int i=2; i<=n; i++) {
        if ((long long)(i) * i <= n && flag[i*i]) {
            for (int j=1; j*i*i<=n; j++) {
                flag[j*i*i] = 0;
            }
        }
    }
    int ans = 0;
    for (int i=1; i<=n; i++)
        ans += flag[i];
    printf("%d\n", ans);
}
