#include <iostream>
#include <cstdio>

using namespace std;


/*
void Build()
{
    for (int i=1;i<=50;i++) {
        for (int j=1;j<=50;j++) {
            for (int k=1;k<=50;k++) {
                if ( j == 1 && k >= i ) DP[i][j][k] = 1;
                else {
                    for (int l=1;l<=k && l<=i;l++) {
                        DP[i][j][k] += DP[i-l][j-1][k];
                    }
                }
            }
        }
    }
}
*/

int main()
{
    //Build();
    int N,K,M;
    while ( cin >> N >> K >> M ) {
        long long DP[51][51] = {0};

        DP[0][0] = 1;
        for (int i=1;i<=N;i++){
            for (int j=1;j<=K;j++) {
                for (int k=1;k<=M && k<=i;k++) {
                    DP[i][j] += DP[i-k][j-1];
                }
            }
        }
        cout << DP[N][K] << endl;
    }
    return 0;
}
