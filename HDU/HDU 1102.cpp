#include <iostream>
#include <cstdio>
#include <queue>
#define maxn 1005

using namespace std;

int disjoint[maxn] = {0};
int G[maxn][maxn] = {0};

struct Edge
{
    int u, v;
    int len;

    bool operator < (const Edge & rhs) const
    {
        return len > rhs.len;
    }
};

int Find(int x)
{
    return (disjoint[x] == x ? x : disjoint[x] = Find(disjoint[x]));
}

bool Union(int x, int y)
{
    int fx = Find(x), fy = Find(y);
    if (fx != fy) {
        disjoint[fy] = fx;
        return true;
    }

    return false;
}

int main()
{
    int n, m;
    while (cin >> n) {
        priority_queue<Edge> pq;
        for (int i=1;i<=n;i++) {
            for (int j=1;j<=n;j++) {
                int a;
                scanf("%d", &a);

                if (a > 0) {
                    Edge e;
                    e.u = i;
                    e.v = j;
                    e.len = a;
                    pq.push(e);
                }
            }
            disjoint[i] = i;
        }

        cin >> m;
        for (int i=0;i<m;i++) {
            int a, b;
            scanf("%d%d", &a, &b);

            if (Union(a, b)) n--;
        }

        long long ans = 0;
        while (!pq.empty() && n > 1) {
            Edge e = pq.top();
            pq.pop();

            if (Union(e.u, e.v)) {
                n--;
                ans += e.len;
            }
        }

        cout << ans << endl;
    }

    return 0;
}
