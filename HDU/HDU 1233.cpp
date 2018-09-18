#include <iostream>
#include <cstdio>
#include <queue>

using namespace std;

int disjoint[105] = {0};

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
    int n;
    while (scanf("%d", &n) == 1 && n > 0) {
        int m = n * (n - 1) / 2;
        priority_queue<Edge> pq;

        for (int i=0;i<=n;i++) disjoint[i] = i;

        for (int i=0;i<m;i++) {
            Edge e;
            scanf("%d%d%d", &(e.u), &(e.v), &(e.len));

            pq.push(e);
        }

        long long ans = 0;
        while (!pq.empty() && n > 1) {
            Edge e = pq.top();
            pq.pop();

            if (Union(e.u, e.v)) ans += e.len;
        }

        printf("%d\n", ans);
    }
    return 0;
}
