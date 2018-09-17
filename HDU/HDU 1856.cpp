#include <iostream>
#include <cstdio>
#include <algorithm>
#include <map>

#define maxn 100005

using namespace std;

int disjoint[maxn] = {0};
int group[maxn] = {0};
int ans = 1;

void init(int n)
{
    for (int i=0;i<=n;i++) {
        disjoint[i] = i;
        group[i] = 1;
    }
}

int Find(int x)
{
    return (disjoint[x] == x ? x : disjoint[x] = Find(disjoint[x]));
}

void Union(int x, int y)
{
    int fx = Find(x), fy = Find(y);
    if (fx != fy) {
        disjoint[fy] = fx;
        group[fx] += group[fy];
        group[fy] = 0;
        ans = max(ans, group[fx]);
    }
}

int main()
{
    int n;

    init(maxn-1);
    while (scanf("%d", &n) == 1) {
        int cnt = 1;
        map<int, int> m;

        for (int i=0;i<n;i++) {
            int a, b;
            scanf("%d%d", &a, &b);
            if (m[a])
                a = m[a];
            else
                m[a] = cnt++, a = m[a];

            if (m[b])
                b = m[b];
            else
                m[b] = cnt++, b = m[b];

            Union(a, b);
        }

        sort(group, group+maxn);
        cout << ans << endl;

        init(cnt);
        ans = 1;
    }

    return 0;
}
