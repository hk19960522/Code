#include <iostream>
#include <stdio.h>
#include <string.h>

using namespace std;

char G[105][105] = {0};
int side[8][2] = {{-1,-1},{-1,0},{-1,1},{0,-1},{0,1},{1,-1},{1,0},{1,1}};
int N,M;

void DFS( int x , int y )
{
    G[x][y] = '*';
    for (int i=0;i<8;i++)
        if ( G[ x+side[i][0] ][ y+side[i][1] ] == '@' )
            DFS( x+side[i][0] , y+side[i][1] );
}

int main()
{
    while ( cin >> N >> M && N && M )
    {
        memset( G , 0 , sizeof(G) );
        for (int i=1;i<=N;i++)
            for (int j=1;j<=M;j++)
                cin >> G[i][j];
        int Count = 0;
        for (int i=1;i<=N;i++)
            for (int j=1;j<=M;j++)
                if ( G[i][j] == '@' )
                    DFS( i , j ) , Count++;
        cout << Count << endl;
    }
    return 0;
}
