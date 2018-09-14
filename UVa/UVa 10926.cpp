#include <iostream>
#include <stdio.h>
#include <vector>
#include <string.h>

using namespace std;

int N,Deep,Ans;
vector< int > v[105];
int Distance[105] = {0};

int DFS( int Index )
{
    if ( Distance[ Index ] ) return Distance[ Index ];
    int Max = 0;
    for (int i=0;i<v[Index].size();i++)
        Max = max( DFS( v[Index][i] ) , Max );
    return Distance[ Index ] = Max+1;
}

int main()
{
    while ( cin >> N && N )
    {
        Deep = 0;
        Ans = 0;
        memset( Distance , 0 , sizeof(Distance) );
        for (int i=0;i<N;i++)
        {
            int Num;
            cin >> Num;
            v[i].clear();
            for (int j=0;j<Num;j++)
            {
                int a;
                cin >> a;
                v[i].push_back( a-1 );
            }
        }
        for (int i=0;i<N;i++)
            DFS( i );
        for (int i=1;i<N;i++)
            if ( Distance[ Ans ] < Distance[i] )
                Ans = i;
        cout << Ans+1 << endl;
    }
    return 0;
}
