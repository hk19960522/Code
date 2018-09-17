#include <iostream>
#include <cstdio>

using namespace std;

int disjoint[1005] = {0};

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
    int T;
    cin >> T;
    while (T--) {
        int n, m;
        cin >> n >> m;
        for (int i=1;i<=n;i++) {
            disjoint[i] = i;
        }
        while (m--) {
            int a, b;
            cin >> a >> b;

            if (Union(a, b)) {
                n--;
            }
        }

        cout << n << endl;
    }
    return 0;
}
