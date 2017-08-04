#include <iostream>
#include <cstring>
#include <cstdlib>
#include <cstdio>

using namespace std;

namespace Solve
{
    const int maxn = 100000 + 10, maxh = 100000 + 10;
    int n, m, k;
    int h[maxn];
    int sum[maxn];

    void solve()
    {
        scanf("%d%d%d", &n, &m, &k);
        int max_h=0;
        for(int i=1;i<=n;i++)
        {
            scanf("%d", &h[i]);
            max_h=max(max_h, h[i]);
        }

        int l = 1, r = n + 1, mid;
        while(l < r)
        {
            mid = (l+r)/2;
            for(int i=0;i<=max_h;i++)sum[i]=0;
            for(int i=1;i<=mid;i++)sum[h[i]]++;
            for(int i=1;i<=max_h;i++)sum[i]+=sum[i-1];

            int flag=0;
            for(int i=0;i<=max_h&&flag==0;i++)
            {
                int x=sum[i];
                if(i-k-1>=0)x-=sum[i-k-1];
                if(x>=m)flag=1;
            }
            
            if(flag) r=mid;
            else l=mid+1;
        }
        if (l == n + 1) puts("impossible");
        else printf("%d\n", l);
    }
}

int main()
{
#if not defined(DATA_GEN) && not defined(__OI_TESTER__) && not defined(ONLINE_JUDGE)
    freopen("interview.in", "r", stdin);
    freopen("interview.out", "w", stdout);
#endif

    Solve::solve();

    return 0;
}