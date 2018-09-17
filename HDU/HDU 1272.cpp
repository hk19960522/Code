#include <iostream>
#include <cstdio>
#define maxn 100010

using namespace std;

int disjoint[maxn];
bool isVisit[maxn] = {0};

int Find(int x)
{
    return (disjoint[x] == x ? x : disjoint[x] = Find(disjoint[x]));
}

bool Union(int x, int y)
{
    if (Find(x) == Find(y))
        return false;

    disjoint[Find(y)] = Find(x);
    return true;
}

int main()
{
    bool D = true;
    int a, b;

    for (int i=0;i<maxn;i++) {
        disjoint[i] = i;
        isVisit[i] = false;
    }

    while (cin >> a >> b && (a != -1 && b != -1)) {
        if ( !a && !b ) {
            int cnt = 0;
            for (int i=0;i<maxn;i++) {
                // Only have one group
                if (disjoint[i] == i && isVisit[i])
                    cnt++;

                disjoint[i] = i;
                isVisit[i] = false;
            }
            cout << (cnt <= 1 && D ? "Yes" : "No") << endl;

            D = true;
            continue;
        }

        if (!Union(a, b)) D = false;
        isVisit[a] = isVisit[b] = true;
    }
    return 0;
}
