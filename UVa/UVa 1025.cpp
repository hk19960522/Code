#include <iostream>
#include <cstdio>

using namespace std;

int main()
{
    int n,Case=0;
    while (cin >> n && n ) {
        int DP[255][55] = {0},Time[55] = {0};
        bool has_train[255][55][2] = {0};
        int T;
        cin >> T;



        for (int i=1;i<n;i++) {
            cin >> Time[i];
        }

        int m,time;
        cin >> m;
        while (m--) {
            cin >> time;
            for (int i=1;i<n;i++) {
                if ( time > T ) break;
                has_train[time][i][0] = 1;
                time += Time[i];
            }
        }
        cin >> m;
        while (m--) {
            cin >> time;
            for (int i=n-1;i>=1;i--) {
                if ( time > T ) break;
                has_train[time][i+1][1] = 1;
                time += Time[i];
            }
        }

        for (int i=1;i<n;i++) DP[T][i] = 1e5;
        DP[T][n] = 0;
        for (int i = T-1;i>=0;i--) {
            for (int j=1;j<=n;j++) {
                DP[i][j] = DP[i+1][j] + 1;
                if ( j < n && has_train[i][j][0] && i + Time[j] <= T )
                    DP[i][j] = min( DP[i][j] , DP[i+Time[j]][j+1] );
                if ( j > 1 && has_train[i][j][1] && i + Time[j-1] <= T )
                    DP[i][j] = min( DP[i][j] , DP[i+Time[j-1]][j-1] );
            }
        }

        printf("Case Number %d: ",++Case);
        if ( DP[0][1] >= 1e5 ) cout << "impossible\n";
        else cout << DP[0][1] << endl;
    }
    return 0;
}
