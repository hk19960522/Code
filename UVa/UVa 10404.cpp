#include <iostream>
#include <stdio.h>
#include <cstring>

using namespace std;

int DP[1000005] = {0};

int main()
{
    int N,M;
    while ( cin >> N ) {
        int Num[15] = {0};
        memset(DP,0,sizeof(DP));
        cin >> M;
        for (int i=0;i<M;i++) {
            cin >> Num[i];
        }

        DP[0] = -1;
        for (int i=1;i<=N;i++) {
            DP[i] = 1e9;
            for (int j=0;j<M;j++) {
                if ( Num[j] <= i ) {
                    DP[i] = min( DP[i] , DP[i-Num[j]]);
                }
            }
            DP[i] = -DP[i];
        }

        if ( DP[N] == 1 )
            cout << "Stan wins\n";
        else
            cout << "Ollie wins\n";
    }

    return 0;
}
