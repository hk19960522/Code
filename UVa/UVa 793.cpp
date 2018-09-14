#include <iostream>
#include <stdio.h>
#include <sstream>

using namespace std;

int Disjoint[ 10000 ];

void init( int n )
{
    for ( int i=1;i<=n;i++)
        Disjoint[ i ] = i;
}

int Find ( int x )
{
    return ( Disjoint[ x ] == x ) ? x : Disjoint[ x ] = Find( Disjoint[ x ] );
}

void Union( int x , int y )
{
    Disjoint[ Find( y ) ] = Find( x );
}

int main()
{
    int t;
    scanf("%d ",&t);
    while ( t -- )
    {
        int n;
        int Good = 0,Bad = 0;
        scanf("%d ",&n);
        init(n);

        string Input;
        while ( getline(cin,Input) && Input != "" )
        {
            stringstream ss;
            ss << Input;
            char Order;
            int a , b;
            ss >> Order >> a >> b;
            if ( Order == 'c' )
                Union( a , b );
            else
            {
                if ( Find( a ) == Find( b ) )
                    Good ++;
                else
                    Bad ++;
            }
        }
        printf("%d,%d\n",Good,Bad);
        if ( t )
            cout << endl;
    }
    return 0;
}
