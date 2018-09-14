#include <iostream>
#include <cstdio>
#include <algorithm>
#include <vector>

using namespace std;

struct Edge
{
    int u, v;
    int c;

    bool operator < (const Edge& rhs) const
    {
        return c < rhs.c;
    }
};

int N, M;
int disjoint[10005] = {0};

int Find(int x)
{
    return ( x == disjoint[x] ? x : disjoint[x] = Find( disjoint[x] ) );
}

bool Union(int x, int y)
{
    if ( Find(x) != Find(y) ) {
        N--;
        disjoint[ Find(x) ] = Find(y);
        return true;
    }
    return false;
}

int main()
{
    int ans = 0;
    cin >> N >> M;

    vector<Edge> v;
    for (int i=0;i<M;i++) {
        Edge tmp;
        scanf("%d%d%d", &tmp.u, &tmp.v, &tmp.c);
        v.push_back(tmp);
    }
    for (int i=0;i<N;i++) disjoint[i] = i;

    sort(v.begin(), v.end());
    for (int i=0;i<v.size() && N > 1;i++) {
        if ( Union(v[i].u, v[i].v) ) ans += v[i].c;
    }

    cout << ans << endl;

    return 0;
}
