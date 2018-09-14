#include <iostream>
#include <stdio.h>
#include <string.h>

using namespace std;

int n,m,s,t,num;
int d[105][105] = {0};

int min(int a ,int b)
{ return a<b?a:b; }
int max(int a, int b)
{ return a>b?a:b; }

void BF ( )
{
    for (int k=1;k<=n;k++)
        for (int i=1;i<=n;i++)
            for (int j=1;j<=n;j++)
                d[i][j] = max( d[i][j] , min( d[i][k], d[k][j] ) );
}

int main()
{
    int T = 0;
    while ( cin >> n >> m && n && m )
    {
        T++;
        memset(d,0,sizeof(d));
        for (int i=0;i<m;i++)
        {
            int u , v , w;
            cin >> u >> v >> w;
            d[u][v] = d[v][u] = w;
        }
        cin >> s >> t >> num;

        BF( );
        //cout << d[s][t];
        d[s][t] --;

        printf("Scenario #%d\n",T);
        if ( num % d[s][t] )
            printf("Minimum Number of Trips = %d\n",( num / d[s][t] ) + 1 );
        else
            printf("Minimum Number of Trips = %d\n", num / d[s][t] );
        printf("\n");
    }

    return 0;
}
