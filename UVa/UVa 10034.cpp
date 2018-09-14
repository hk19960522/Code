#include <iostream>
#include <stdio.h>
#include <string.h>
#include <queue>
#include <math.h>

using namespace std;

struct Edge
{
    int a;
    int b;
    double Distance;
    bool operator < ( const Edge & other ) const
    {
        return Distance > other.Distance;
    }
};

int Disjoint[105] = {0};
double x[105] = {0},y[105] = {0};

int Find ( int x )
{
    return ( Disjoint[ x ] == x ) ? x : Disjoint[ x ] = Find( Disjoint[ x ] );
}

void Union ( int x , int y )
{
    Disjoint[ Find( y ) ] = Find( x );
}

double MST( int N )
{
    priority_queue< Edge > pq;
    for (int i=0;i<N;i++)
    {
        Disjoint[ i ] = i;
        for (int j=i+1;j<N;j++)
            pq.push( {i , j , ( x[i] - x[j] ) * ( x[i] - x[j] ) + ( y[i] - y[j] ) * ( y[i] - y[j] ) } );
    }


    double Ans = 0;
    while ( !pq.empty() )
    {
        Edge Temp = pq.top();
        pq.pop();
        if ( Find( Temp.a ) != Find( Temp.b ) )
        {
            Union( Temp.a , Temp.b );
            Ans += sqrt( Temp.Distance );
        }
    }
    return Ans;
}

int main()
{
    int T;
    cin >> T;
    while ( T-- )
    {
        int N;
        cin >> N;
        for (int i=0;i<N;i++)
            cin >> x[i] >> y[i];
        printf("%.2f\n",MST(N));
        if ( T )
            cout << endl;

    }
    return 0;
}
