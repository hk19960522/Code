#include <iostream>
#include <stdio.h>

using namespace std;

int main()
{
    int N;

    while ( cin >> N )
    {
        int DP[ 105 ][ 105 ] = {0};
        for (int i=1;i<=N;i++)
            for (int j=1;j<=N;j++)
                cin >> DP[ i ][ j ] , DP[ i ][ j ] += DP[ i ][ j-1 ];

        int Ans = -2147483646;

        for ( int k = 0 ;k < N; k++)
            for ( int j = k+1;j <= N ; j++)
            {
                int TempSum = DP[1][j] - DP[1][k];
                for (int i = 2;i <= N;i++)
                {
                    int Sum = DP[i][j] - DP[i][k];
                    TempSum = max( Sum , TempSum + Sum );
                    Ans = max( Ans , TempSum );
                }
            }
        cout << Ans << endl;
    }

    return 0;
}
