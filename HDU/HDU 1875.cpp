#include <iostream>
#include <cstdio>
#include <vector>
#include <queue>
#include <cmath>
#include <utility>
#define maxn 105

using namespace std;

int disjoint[maxn] = {0};

struct Edge
{
    int u, v;
    double len;

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
    int T;
    cin >> T;
    while (T--) {
        int n;
        vector< pair<int, int> > v;
        priority_queue<Edge> pq;
        cin >> n;

        for (int i=0;i<n;i++) {
            pair<int, int> p;
            cin >> p.first >> p.second;
            v.push_back(p);
            disjoint[i] = i;
        }

        for (int i=0;i<n;i++) {
            for (int j=i+1;j<n;j++) {
                double dx = v[i].first - v[j].first, dy = v[i].second - v[j].second;
                double len = dx * dx + dy * dy;
                if ( len < 100 || len > 1000000 ) continue;

                Edge e;
                e.u = i;
                e.v = j;
                e.len = sqrt(len) * 100.0;
                pq.push(e);
            }
        }

        if (n == 1) cout << "0.0\n";

        double ans = 0;
        while (!pq.empty() && n > 1) {
            Edge e = pq.top();
            pq.pop();

            if (Union(e.u, e.v)) {
                n--;
                ans += e.len;
            }
        }

        if (n == 1)
            printf("%.1f\n", ans);
        else
            cout << "oh!\n";
    }
    return 0;
}
