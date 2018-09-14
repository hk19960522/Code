#include <iostream>
#include <stdio.h>
#include <vector>
#include <algorithm>

using namespace std;

struct Node
{
    int x;
    int y;
    int height;
    bool operator < ( const Node & other ) const
    {
        return height > other.height;
    }
};

int Direct[ 4 ][ 2 ] = { { 1 , 0 } , { -1 , 0 } , { 0 , 1 } , { 0 , -1 } };

bool Check( int x , int y , int N , int M )
{
    if ( x >= 0 && x < N && y >= 0 && y < M )
        return true;
    else
        return false;
}

int main()
{
    int T;
    cin >> T;
    while ( T-- )
    {
        string Place;
        int N,M,Ans = 0;
        vector< Node > v;
        vector< int > LIS;
        cin >> Place >> N >> M;

        for (int i=0;i<N;i++)
            for (int j=0;j<M;j++)
            {
                int height;
                cin >> height;
                v.push_back( { i , j , height } );
                LIS.push_back( 1 );
            }
        sort( v.begin() , v.end() );

        for (int i=0;i<v.size();i++)
            for (int j=i+1;j<v.size();j++)
            {
                if ( ( abs( v[i].x - v[j].x ) == 1 && abs( v[i].y - v[j].y ) == 0 )||  ( abs( v[i].x - v[j].x ) == 0 && abs( v[i].y - v[j].y ) == 1 ) )
                    if ( v[i].height > v[j].height )
                        LIS[ j ] = max ( LIS[i] + 1 , LIS[j] ) , Ans = max( Ans , LIS[j] );
            }

        printf("%s: %d\n",Place.c_str(),Ans);
    }
    return 0;
}
