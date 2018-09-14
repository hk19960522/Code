#include <iostream>
#include <stdio.h>

using namespace std;

long long int DP[ 30 ][ 30 ][ 30 ] = {0};

void Build()
{
    DP[ 1 ][ 1 ][ 1 ] = 1;
    for (int i=2;i<=20;i++)
        for (int j=1;j<=i;j++)
            for (int k=1;k<=i;k++)
            {
                if ( j+k > i+1 )
                    break;
                DP[i][j][k] = DP[i-1][j-1][k] + DP[i-1][j][k-1] + DP[i-1][j][k] * (i-2);
            }
}

int main()
{
    Build();
    int n,l,r,t;
    cin >> t;
    while (t--)
        cin >> n >> l >> r , cout << DP[n][l][r] << endl;
    return 0;
}
