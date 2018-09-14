#include <iostream>
#include <stdio.h>

using namespace std;

/*
int main()
{
    int Length;
    while ( cin >> Length && Length )
    {
        long long int DP[ 51 ][ 51 ] = {0};
        int Cut[ 51 ] = {0};
        int CutNum;
        cin >> CutNum;

        Cut[ CutNum+1 ] = Length;

        for (int i=1;i<=CutNum;i++)
            cin >> Cut[i];

        for (int i=2;i<=CutNum+1;i++)
        {
            for (int l=0;l+i<=CutNum+1;l++)
            {
                int r = l+i;
                DP[ l ][ r ] = 1e9;
                for (int k=l+1;k<=r-1;k++)
                    DP[ l ][ r ] = min( DP[ l ][ r ] , DP[ l ][ k ] + DP[ k ][ r ] + Cut[ r ] - Cut[ l ] );
            }
        }

        cout << "The minimum cutting is " << DP[ 0 ][ CutNum+1 ] << ".\n";
    }
    return 0;
}
*/

int main()
{
    int Length,N;
    while ( cin >> Length && Length ) {
        cin >> N;
        int DP[51][51] = {0};
        int Cut[51] = {0};
        for (int i=1;i<=N;i++) {
            cin >> Cut[i];
        }

        Cut[N+1] = Length;

        for (int i=2;i<=N+1;i++) {
            for (int L=0;L+i<=N+1;L++) {
                int R = L+i;
                DP[ L ][ R ] = 1e9;
                for (int K=L+1;K<R;K++) {
                    DP[L][R] = min( DP[L][R] , DP[L][K] + DP[K][R] + Cut[R] - Cut[L] );
                }
            }
        }

        cout << DP[0][N+1] << endl;
    }
    return 0;
}
