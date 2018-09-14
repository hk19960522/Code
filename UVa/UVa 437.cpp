#include <iostream>
#include <stdio.h>
#include <string.h>

using namespace std;

struct Block
{
    int x;
    int y;
    int z;
    int isPutOn ( Block other )
    {
        if ( other.x < x && other.y < y )
            return z;
        else
            return 0;
    }
};

int DP[ 100 ] = {0};
int N;
Block Record[100];

int DAG( int Index )
{
    if ( DP[ Index ] >= 0 )
        return DP[ Index ];

    DP[ Index ] = Record[ Index ].z;
    for (int i=0;i<N*3;i++)
        if ( Record[ Index ].isPutOn( Record[ i ] ) )
            DP[ Index ] = max( DP[ Index ] , DAG(i) + Record[ Index ].z );

    return DP[ Index ];
}



int main()
{
    int Case = 1;
    while ( cin >> N && N )
    {
        memset( DP , 0 , sizeof( DP ) );
        for (int i=0;i<100;i++)
            DP[i] = -1;
        for (int i=0;i<N;i++)
        {
            int x,y,z;
            cin >> x >> y >> z;
            Block Temp;
            Temp.x = max( x , y );
            Temp.y = min( x , y );
            Temp.z = z;
            Record[ i*3 ] = Temp;
            Temp.x = max( x , z );
            Temp.y = min( x , z );
            Temp.z = y;
            Record[ i*3+1 ] = Temp;
            Temp.x = max( y , z );
            Temp.y = min( y , z );
            Temp.z = x;
            Record[ i*3+2 ] = Temp;
        }
        int ans = 0;
        for (int i=0;i<N*3;i++)
            DAG( i );
        for (int i=0;i<N*3;i++)
            ans = max( ans , DP[i] );

        printf("Case %d: maximum height = %d\n",Case++,ans);

    }
    return 0;
}
