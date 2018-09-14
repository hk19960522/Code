#include <iostream>
#include <stdio.h>
#include <vector>
#include <algorithm>

using namespace std;

bool cmp ( const string & lhs , const string & rhs )
{
    return ( lhs + rhs ) > ( rhs + lhs );
}

int main()
{
    int N;
    while ( cin >> N && N )
    {
        vector< string > v;
        string Num;
        for (int i=0;i<N;i++)
        {
            cin >> Num;
            v.push_back( Num );
        }

        sort( v.begin() , v.end() , cmp );

        for (int i=0;i<N;i++)
            cout << v[i];
        cout << endl;
    }
    return 0;
}
