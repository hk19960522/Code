#include <iostream>
#include <stdio.h>

using namespace std;

int main()
{
    long long int C[ 105 ][ 105 ] = {0};
    for (int i=1;i<=100;i++)
        for (int j=0;j<=i;j++)
            if ( j == 0 || i == j ) C[i][j] = 1;
            else C[i][j] = C[i-1][j] + C[i-1][j-1];

    int m,n;
    while ( cin >> n >> m && ( m || n ) )
        printf("%d things taken %d at a time is %lld exactly.\n",n,m,C[n][m]);
    return 0;
}
