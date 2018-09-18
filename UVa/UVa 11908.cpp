#include <iostream>
#include <cstdio>
#include <algorithm>

using namespace std;

struct ad
{
    int pos, hei, val;

    bool operator < (const ad & rhs) const
    {
        return hei < rhs.hei;
    }
};

int main()
{
    int T;
    cin >> T;
    for (int t = 0; t < T; t++) {
        int n;
        cin >> n;

        ad order[30005];
        int dp[30005] = {0};

        for (int i=1;i<=n;i++) {
            cin >> order[i].pos >> order[i].hei >> order[i].val;
            order[i].hei += order[i].pos-1;
        }

        sort(order+1, order+1+n);
        int ans = 0;
        dp[0] = 0;

        for (int i=1;i<=n;i++) {
            int l = 0, r = i-1, best = 0;

            while (l <= r) {
                int mid = (l+r)>>1;
                if (order[mid].hei < order[i].pos)
                    l = mid+1, best = mid;
                else
                    r = mid-1;
            }
            dp[i] = max(dp[i-1], dp[best] + order[i].val);
        }

        printf("Case %d: %d\n", t+1, dp[n]);
    }
    return 0;
}
