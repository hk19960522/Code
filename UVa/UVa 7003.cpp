#include <iostream>
#include <cstdio>
#include <vector>
#include <sstream>
#include <cstring>
#include <algorithm>

using namespace std;

vector< int > v[105];
int DP[105][2][2] = {0};
int n,k;

int stoii ( string str )
{
    int ans = 0;
    for (int i=0;i<str.length();i++) {
        ans *= 10;
        ans += ( str[i]-'0' );
    }
    return ans;
}

void DFS ( int index )
{
    if ( v[index].empty() ) {
        DP[index][0][0] = DP[index][0][1] = -1;
        DP[index][1][0] = 0;
        if ( k == 1 )
            DP[index][0][0] = 1;
        return;
    }

    vector< int > state[3];
    for (int i=0;i<v[index].size();i++) {
        int child = v[index][i] ;
        DFS( child );
        state[0].push_back( DP[child][0][0] );
        state[1].push_back( DP[child][0][1] );
        state[2].push_back( DP[child][1][0] );
    }

    int DP2[105][105];
    memset(DP2,-1,sizeof(DP2));
    DP2[0][0] = 0;
    for (int i=0;i<v[index].size();i++) {
        for (int j=0;j<=k;j++) {
            if ( DP2[i][j] == -1 ) continue;
            if ( state[1][i] != -1 ) {
                DP2[i+1][j] = max( DP2[i+1][j] , DP2[i][j] + state[1][i] );
            }
            if ( state[2][i] != -1 ) {
                DP2[i+1][j+1] = max( DP2[i+1][j+1] , DP2[i][j] + state[2][i] );
            }
        }
    }

    if ( DP2[v[index].size()][k-1] != -1 ) DP[index][0][0] = DP2[v[index].size()][k-1] + 1;
    if ( DP2[v[index].size()][k] != -1 )   DP[index][0][1] = DP2[v[index].size()][k] + 1;

    DP[index][1][0] = 0;
    for (int i=0;i<v[index].size();i++) {
        DP[index][1][0] += max( state[0][i] , state[2][i] );
    }
}

int main()
{
    int t;
    cin >> t;
    while ( t-- ) {
        memset(DP,-1,sizeof(DP));

        scanf("%d%d ",&n,&k);

        for (int i=1;i<=n;i++) {
            v[i].clear();

            string str;
            stringstream ss;
            getline(cin,str);
            ss << str;
            while ( ss >> str ) {
               int tmp = stoii(str);
               if ( tmp ) v[i].push_back(tmp);
            }

        }

        /*for (int i=1;i<=n;i++) {
            for (int j=0;j<v[i].size();j++) {
                cout << v[i][j] << " ";
            }
            cout << endl;
        }*/

        DFS(1);
        cout << max( DP[1][0][1] , DP[1][1][0] ) << endl;

    }
    return 0;
}
