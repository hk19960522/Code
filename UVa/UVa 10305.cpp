#include <iostream>
#include <stdio.h>
#include <vector>
#include <string.h>

using namespace std;

vector< int > G[105];
vector< int > Ans;
bool isVisit[105] = {0};
int N,M;

void DFS ( int Index )
{
    isVisit[ Index ] = 1;
    for ( int i=0;i<G[Index].size();i++ )
    {
        if ( !isVisit[ G[Index][i] ] )
            DFS( G[ Index ][ i ] );
    }
    Ans.push_back( Index );
}

void Topological_Sort ( )
{
    Ans.clear();
    memset( isVisit , 0 , sizeof( isVisit ) );
    for (int i=1;i<=N;i++)
        if ( !isVisit[ i ] )
            DFS( i );
    for (int i=Ans.size()-1;i>=0;i--)
    {
        cout << Ans[i];
        if ( i )
            cout << " ";
    }
    cout << endl;
}

int main()
{
    while ( cin >> N >> M && ( N || M ) )
    {
        for (int i=1;i<=N;i++)
            G[i].clear();
        for (int i=0;i<M;i++)
        {
            int a,b;
            cin >> a >> b;
            G[a].push_back( b );
        }
        Topological_Sort( );
    }
    return 0;
}
