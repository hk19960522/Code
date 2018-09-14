#include <iostream>
#include <stdio.h>
#include <algorithm>
#include <vector>

using namespace std;

vector< int > ans;

int LCS( vector<int> & v , int N )
{
    int DP[ 100 ][ 100 ] ={0};

    for (int i=1;i<=N;i++)
        for (int j=1;j<=N;j++)
        {
            if ( v[ i-1 ] == ans[ j-1 ] )
                DP[ i ][ j ] = DP[ i-1 ][ j-1 ] + 1;
            else
                DP[ i ][ j ] = max( DP[ i-1 ][ j ] , DP[ i ][ j-1 ] );
        }

    return max( DP[ N ][ N ] , Ans );
}

int main()
{
    int N , Score;
    int Count = 0;
    vector< int > v;
    cin >> N;
    for (int i=0;i<N;i++)
    {
        int a;
        cin >> a;
        ans.push_back(a);
    }
    while ( cin >> Score )
    {
        Count++;
        v.push_back( Score );
        if ( Count >= N )
        {
            Count = 0;
            cout << LCS( v , N ) << endl;
            v.clear();
        }
    }

    return 0;
}
