#include <iostream>
#include <cstdio>
#include <cstring>

using namespace std;

int main()
{
    int N, M;
    bool D = 0;
    while( cin >> N >> M && N && M ) {
        if ( D ) cout << endl;
        D = true;
        pair<int, int> DP[105][105];

        for (int i=1;i<=N;i++) {
            for (int j=1;j<=M;j++) {
               bool d;
               cin >> d;
               DP[i][j] = pair<int, int>(!d, !d);
            }
        }

        int ans = 0;
        for (int i=1;i<=N;i++) {
            for (int j=1;j<=M;j++) {
                if ( DP[i][j].first ) {
                    DP[i][j].first = max(DP[i][j].first, DP[i-1][j].first+1);
                    DP[i][j].second = max(DP[i][j].second, DP[i][j-1].second+1);

                    ans = max(ans, DP[i][j].first * DP[i][j].second);
                }
            }
        }

        cout << ans;
    }
    return 0;
}
