#include <iostream>
#include <stdio.h>

using namespace std;

int main()
{
    int T;
    cin >> T;
    while ( T -- )
    {
        int Weight[ 1005 ] = {0} , Price[ 1005 ] = {0} , Backage[ 100 ];
        int N , M;
        int MaxWeight = 0,ans = 0;
        cin >> N ;
        for (int i=1;i<=N;i++)
            cin >> Price[ i ] >> Weight[ i ];
        cin >> M;

        for (int k=0;k<M;k++)
        {
            cin >> MaxWeight;
            int DP[ 100 ] = {0};
            for (int i=1;i<=N;i++)
                for (int j=MaxWeight;j>=Weight[i];j--)
                    DP[ j ] = max( DP[ j ] , DP[ j-Weight[ i ] ] + Price[ i ] ) ;
            ans += DP[ MaxWeight ];
        }

        cout << ans << endl;
    }
    return 0;
}
