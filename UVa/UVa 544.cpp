#include <iostream>
#include <stdio.h>
#include <map>
#include <string.h>

using namespace std;

int G[205][205] = {0};

int main()
{
    int N,M;
    int T = 0;
    while ( cin >> N >> M && ( N || M ) )
    {
        string a , b;
        int Dis = 0;
        int Count = 1;
        map< string , int > m;
        for (int i=0;i<M;i++)
        {
            int IndexA , IndexB;
            cin >> a >> b >> Dis;
            if ( !m[a] )
                m[ a ] = Count++;
            if ( !m[b] )
                m[ b ] = Count++;

            G[ m[a] ][ m[b] ] = Dis;
            G[ m[b] ][ m[a] ] = Dis;
        }

        for (int k=1;k<=N;k++)
            for (int i=1;i<=N;i++)
                for (int j=1;j<=N;j++)
                    G[i][j] = max( G[i][j] , min( G[i][k] , G[k][j] ) );

        cin >> a >> b;
        printf("Scenario #%d\n%d tons\n\n",++T,G[ m[a] ][ m[b] ]);
    }
    return 0;
}
