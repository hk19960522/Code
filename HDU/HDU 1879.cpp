#include <iostream>
#include <cstdio>
#include <queue>

using namespace std;

struct Edge
{
    int u, v;
    int val;

    bool operator < (const Edge & rhs) const
    {
        return val > rhs.val;
    }
};

int disjoint[105] = {0};

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
    int N;
    while (scanf("%d", &N) == 1 && N > 0) {
        priority_queue<Edge> pq;
        int num = N;

        for (int i=0;i<=N;i++) disjoint[i] = i;

        for (int i=1;i<=N;i++) {
            for (int j=i+1;j<=N;j++) {
                int a, b, c, d;
                scanf("%d%d%d%d", &a, &b, &c, &d);

                if (d == 1) {
                    if (Union(a, b)) num--;
                }
                else {
                    Edge e;
                    e.u = a;
                    e.v = b;
                    e.val = c;
                    pq.push(e);
                }
            }
        }

        int ans = 0;
        while (!pq.empty() && num > 1) {
            Edge e = pq.top();
            pq.pop();

            if (Union(e.u, e.v)) {
                num --;
                ans += e.val;
            }
        }

        cout << ans << endl;
    }
    return 0;
}
