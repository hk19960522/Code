#include <iostream>
#include <stdio.h>
#include <vector>
#include <cstring>

using namespace std;

vector<int> v[10005];
int DP[10005][3] = {0};

void DFS( int index , int pre )
{
    DP[index][0] = 1;
    DP[index][1] = 0;
    DP[index][2] = 10005;

    if ( v[index].size() == 1 && pre != 0 ) return;

    for (int i=0;i<v[index].size();i++) {
        int child = v[index][i];
        if ( child != pre ) {
            DFS(child,index);
            DP[index][0] += min( DP[child][0] , DP[child][1] );
            DP[index][1] += DP[child][2];
        }
    }
    for (int i=0;i<v[index].size();i++) {
        int child = v[index][i];
        if ( child != pre ) {
            DP[index][2] = min( DP[index][2] , DP[index][1]-DP[child][2]+DP[child][0]);
        }
    }
}

int main()
{
    int n;
    while ( cin >> n ) {
        memset(DP,0,sizeof(DP));
        for (int i=1;i<=n;i++) {
            v[i].clear();
        }

        for (int i=1;i<n;i++) {
            int a,b;
            cin >> a >> b;
            v[a].push_back(b);
            v[b].push_back(a);
        }

        DFS(1,0);

        cout << min( DP[1][0] , DP[1][2] ) << endl;

        int a;
        cin >> a;
        if ( a == -1 ) break;
    }
    return 0;
}
