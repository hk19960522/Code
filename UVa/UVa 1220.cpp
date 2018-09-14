#include <iostream>
#include <stdio.h>
#include <map>
#include <vector>
#include <cstring>

using namespace std;

int DP[205][2] = {0};
bool f[205][2] = {0};
vector<int> v[205];

void DFS( int index )
{
    DP[index][1] = 1;
    DP[index][0] = 0;

    for (int i=0;i<v[index].size();i++) {
        int child = v[index][i];
        DFS( child );

        if ( DP[child][0] > DP[child][1] ) {
            DP[index][0] += DP[child][0];
            if ( f[child][0] ) f[index][0] = 1;
        }
        else if ( DP[child][0] < DP[child][1] ) {
            DP[index][0] += DP[child][1];
            if ( f[child][1] ) f[index][0] = 1;
        }
        else {
            DP[index][0] += DP[child][0];
            f[index][0] = 1;
        }

        DP[index][1] += DP[child][0];
        if ( f[child][0] ) f[index][1] = 1;
    }
}

int main()
{
    int n;
    while ( cin >> n && n ) {
        memset(DP,0,sizeof(DP));
        memset(f,0,sizeof(f));

        string boss[205],name[205];

        string str1,str2;
        cin >> name[0];

        for (int i=1;i<n;i++) {
            cin >> name[i] >> boss[i];
        }
        for (int i=0;i<n;i++) v[i].clear();

        for (int i=1;i<n;i++) {
            int j;
            for (j=0;j<n;j++) {
                if ( boss[i] == name[j] ) break;
            }
            v[j].push_back(i);
        }

        DFS(0);

        if ( DP[0][0] > DP[0][1] ) {
            printf("%d %s\n",DP[0][0],(f[0][0] ? "No" : "Yes") );
        }
        else if ( DP[0][0] < DP[0][1] ) {
            printf("%d %s\n",DP[0][1],(f[0][1] ? "No" : "Yes") );
        }
        else {
            printf("%d No\n",DP[0][0]);
        }
    }
    return 0;
}
