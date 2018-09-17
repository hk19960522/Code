#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#define maxn 100005

using namespace std;

int disjoint[maxn] = {0};
int isVisit[maxn] = {0};
int times[maxn] = {0};

void init(int n)
{
    for (int i=0;i<n;i++) {
        disjoint[i] = i;
        isVisit[i] = false;
        times[i] = 0;
    }
}

int Find(int x)
{
    return (disjoint[x] == x ? x : disjoint[x] = Find(disjoint[x]));
}

bool Union(int x, int y)
{
    int fx = Find(x), fy = Find(y);
    if ( fx != fy ) {
        disjoint[fy] = fx;

        return true;
    }

    return false;
}

int main()
{
    int a, b, mn = 0, cnt = 0, Case = 0;
    bool D = true;
    init(maxn);
    while (cin >> a >> b && a != -1 && b != -1) {
        if ( a || b ) {
            isVisit[a] = isVisit[b] = true;
            times[b]++;

            if (times[b] > 1 || !Union(a, b)) {
                D = false;
            }
            mn = max(mn, max(a, b));
        }
        else {
            int root = 0;
            for (int i=0;i<=mn;i++) {
                if (isVisit[i] && Find(i) == i) {
                    cnt++;
                }
            }

            cout << "Case " << (++Case);
            if (cnt == 1 && D)
                cout << " is a tree.\n";
            else
                cout << " is not a tree.\n";

            init(mn+1);
            mn = cnt = 0;
            D = true;
        }
    }
    return 0;
}
