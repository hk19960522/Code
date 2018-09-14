#include <iostream>
#include <stdio.h>
#include <cstring>

using namespace std;

long long DP[1025][105][10] = {0};

int main()
{
    int Base[10] = {0};
    for (int i=0,base = 1;i<10;i++) {
        Base[i] = base;
        base *= 2;
    }
    int T;
    cin >> T;
    while ( T-- ) {
        memset(DP,0,sizeof(DP));
        int N,M;
        cin >> N >> M;

        DP[1][1][0] = 0;
        for (int i=1;i<N;i++) {
            DP[Base[i]][1][i] = 1;
        }
        // 1 2 3 4 5 6 7 8 9

        for (int i=0;i<Base[N-1]*2;i++) {
            for (int j=1;j<M;j++) {
                for (int k=0;k<N;k++) {
                    if ( k != 0 ) {
                        DP[ i | Base[k-1] ][ j+1 ][ k-1 ] += DP[ i ][ j ][ k ];
                        DP[ i | Base[k-1] ][ j+1 ][ k-1 ] %= 1000000007;
                    }
                    if ( k != N-1 ) {
                        DP[ i | Base[k+1] ][ j+1 ][ k+1 ] += DP[ i ][ j ][ k ];
                        DP[ i | Base[k+1] ][ j+1 ][ k+1 ] %= 1000000007;
                    }
                }
            }
        }

        long long ans = 0;
        for (int i=0;i<N;i++) {
            for (int j=1;j<=M;j++) {
                ans += DP[ Base[N-1]*2-1 ][ j ][ i ]; // 11111111111...
                ans %= 1000000007;
            }
        }
        cout << ans%1000000007 << endl;
    }
    return 0;
}
