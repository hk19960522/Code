#include <iostream>
#include <cstdio>
#include <cstring>

using namespace std;

int G[50005] = {0};
bool visit[50005] = {0};
int ans = 0, N = 0;

void dfs(int index)
{
    if ( !visit[ G[index] ] ) {
        visit[ G[index] ] = true;
        dfs(G[index]);
    }
}

int main()
{
    cin >> N;
    for (int i=0;i<N;i++) cin >> G[i];

    for (int i=0;i<N;i++) {
        if ( !visit[i] ) {
            visit[i] = true;
            dfs( i );
            ans++;
        }
    }

    cout << ans << endl;

    return 0;
}
