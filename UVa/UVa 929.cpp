#include <iostream>
#include <stdio.h>
#include <queue>
#include <string.h>

using namespace std;

struct State
{
    int x;
    int y;
    int Dis;
    bool operator < ( const State & other ) const
    {
        return Dis > other.Dis;
    }
};

int G[1001][1001] = {0};
int Dis[1001][1001] = {0};
bool Visited[1001][1001] = {0};
int Dir[4][2] = { {1,0} , {-1,0} , {0,1} , {0,-1} };

bool Check ( int x , int y , int N , int M )
{
    if ( x >= 0 && x < N  && y >= 0 && y < M && ( x || y ) && !Visited[ x ][ y ] )
        return true;
    else
        return false;
}

int DIJK ( int N ,int M )
{
    priority_queue< State > pq;
    pq.push( { 0 , 0 , G[0][0] } );
    Visited[0][0] = 1;
    while ( !pq.empty() )
    {
        State Temp = pq.top();
        pq.pop();
        Visited[ Temp.x ][ Temp.y ] = true;
        if ( Temp.x == N-1 && Temp.y == M-1 )
            return Temp.Dis;
        if ( !Dis[ Temp.x ][ Temp.y ] || Dis[ Temp.x ][ Temp.y ] > Temp.Dis )
        {
            Dis[ Temp.x ][ Temp.y ] = Temp.Dis;
            for (int i=0;i<4;i++)
                if ( Check( Temp.x + Dir[i][0] , Temp.y + Dir[i][1] , N , M ) )
                    pq.push( {Temp.x + Dir[i][0] , Temp.y + Dir[i][1] , G[ Temp.x + Dir[i][0] ][ Temp.y + Dir[i][1] ] + Temp.Dis } );
        }
    }
}

int main()
{
    int T;
    cin >> T;
    while ( T-- )
    {
        int N,M;
        memset( G , 0 , sizeof( G ) );
        memset( Dis , 0 , sizeof( Dis ) );
        memset( Visited , 0 , sizeof( Visited ) );
        cin >> N >> M;
        for (int i=0;i<N;i++)
            for (int j=0;j<M;j++)
                cin >> G[i][j];
        cout << DIJK( N , M ) << endl;
    }
    return 0;
}
