#include <iostream>
#include <cstdio>

using namespace std;

int disjoint[1005];

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
    int a, b;
    while (scanf("%d", &n) == 1 && n > 0) {
        scanf("%d", &m);

        for (int i=0;i<=n;i++) {
            disjoint[i] = i;
        }
        for (int i=0;i<m;i++) {
            scanf("%d%d", &a, &b);
            if (Union(a, b))
                n--;
        }

        printf("%d\n", n-1);
    }
    return 0;
}
