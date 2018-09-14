#include <iostream>
#include <stdio.h>
#include <string.h>

using namespace std;

bool G[ 30 ][ 30 ] = {0};
int InDegree[ 26 ] = {0};
int OutDegree[ 26 ] = {0};
bool isVisited[ 26 ] = {0};

bool isEuler()
{
    int Start = 0 , End = 0;
    for (int i=0;i<26;i++)
    {
        if ( InDegree[ i ] + 1 == OutDegree[ i ] )
            Start ++ ;
        else if ( OutDegree[ i ] + 1 == InDegree[ i ] )
            End ++ ;
        else if ( OutDegree[ i ] != InDegree[ i ] )
            return false;
    }
    if ( Start == 1 && End == 1 ) return true;
    if ( !Start && !End ) return true;
    return false;
}

void DFS ( int Index )
{
    for (int i=0;i<26;i++)
        if ( G[ Index ][ i ] && !isVisited[i] )
            isVisited[ i ] = 1 , DFS( i ) ;
}

bool isConnect()
{
    memset( isVisited , 0 , sizeof( isVisited ) );
    int Count = 0;
    for (int i=0;i<26;i++)
        if ( ( InDegree[ i ] || OutDegree[ i ] ) && !isVisited[ i ])
        {
            isVisited[ i ] = 1;
            Count++;
            DFS( i );
        }
    if ( Count == 1 )
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
        memset( G , 0 , sizeof( G ) );
        memset( InDegree , 0 , sizeof( InDegree ) );
        memset( OutDegree , 0 , sizeof( OutDegree ) );
        int N;
        cin >> N;
        for (int i=0;i<N;i++)
        {
            string str;
            cin >> str;
            G[ str[0] - 'a' ][ str[ str.length()-1 ] - 'a' ] = 1;
            OutDegree[ str[0] - 'a' ] ++;
            InDegree[ str[ str.length()-1 ] - 'a' ] ++;
        }
        if ( isEuler() && isConnect() )
            cout << "Ordering is possible.\n";
        else
            cout << "The door cannot be opened.\n";
    }
    return 0;
}
