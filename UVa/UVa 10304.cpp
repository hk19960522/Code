#include <iostream>
#include <stdio.h>

using namespace std;

int main()
{
    int n;
    while ( cin >> n ) {
        int DP[255][255];
        int F[255];
        int Sum[255] = {0};

        for (int i=1;i<=n;i++) {
            cin >> F[i];
            Sum[i] = Sum[i-1] + F[i];
        }

        for (int i=0;i<n;i++) {
            for (int j=1;j+i<=n;j++) {
                DP[j][j+i] = 1e9;
                for (int k=j;k<=j+i;k++) {
                    DP[j][j+i] = min( DP[j][j+i] ,
                                      DP[j][k-1] + DP[k+1][j+i] + Sum[j+i] - Sum[j-1] - F[k] );
                }
            }
        }

        cout << DP[1][n] << endl;
    }
    return 0;
}
