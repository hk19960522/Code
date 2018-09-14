#include <iostream>
#include <cstdio>
#include <vector>

using namespace std;

int main()
{
    int n, m;
    while ( cin >> n >> m && ( n || m ) ) {
        vector<int> ans;
        bool G[105][105] = {0};
        int degree[105] = {0};

        for (int i=0;i<m;i++) {
            int a, b;
            cin >> a >> b;
            G[a][b] = true;
            degree[b] ++;
        }

        while ( true ) {
            vector<int> v;
            for(int i=1;i<=n;i++) {
                if ( !degree[i] ) v.push_back(i);
            }

            if ( v.empty() ) break;
            for (int i=0;i<v.size();i++) {
                ans.push_back(v[i]);

                for (int j=1;j<=n;j++) {
                    if ( G[v[i]][ j ] ) degree[j]--;
                }

                degree[ v[i] ] = -1;
            }
        }

        for (int i=0;i<ans.size();i++) {
            if ( i ) cout << " ";
            cout << ans[i];
        }
        cout << endl;
    }
    return 0;
}
