#include <iostream>
#include <stdio.h>
#include <vector>
#include <algorithm>

using namespace std;

struct T
{
    int Order;
    vector< int > v;
    bool operator < ( const T & other ) const
    {
        for ( int i=0;i<v.size();i++)
            if ( v[i] > other.v[i] )
                return false;
            else
                return true;
        return true;
    }
};

int Pre[ 100 ] = {0};
vector< T > v;
vector< int > ans;

void Trace( int Index )
{
    ans.push_back( v[ Index ].Order );
    if ( Pre[ Index ] != -1 )
        Index = Pre[ Index ] , Trace( Index );
}

bool isContain ( T & lhs , T & rhs )
{
    for (int i=0;i<lhs.v.size();i++)
        if ( lhs.v[i] >= rhs.v[i] )
            return false;
    return true;
}

int main()
{
    int N , M;
    while ( cin >> N >> M )
    {
        v.clear();
        for (int i=0;i<N;i++)
        {
            T Temp;
            Temp.Order = i+1;
            for (int j=0;j<M;j++)
            {
                int a;
                cin >> a;
                Temp.v.push_back( a );
            }
            sort( Temp.v.begin() , Temp.v.end() );
            v.push_back( Temp );
        }

        sort( v.begin() , v.end() );
        int DP[ 100 ] = {0};
        for (int i=0;i<N;i++)
            DP[ i ] = 1 , Pre[ i ] = -1;

        for (int i=0;i<v.size();i++)
            for (int j=i+1;j<v.size();j++)
                if ( isContain ( v[i] , v[j] ) && DP[ j ] < DP[ i ] + 1 )
                {
                    DP[ j ] = DP[ i ] + 1;
                    Pre[ j ] = i;
                }

        int Index = 0;
        for (int i=0;i<N;i++)
        {
            if ( DP[i] > DP[ Index ] )
                Index = i;
        }

        ans.clear();
        cout << DP[ Index ] << endl;
        Trace( Index );
        for (int i=0;i<ans.size();i++)
        {
            if ( i )
                cout << " ";
            cout << ans[ ans.size() - 1 - i ];
        }
        cout << endl;
    }
    return 0;
}



