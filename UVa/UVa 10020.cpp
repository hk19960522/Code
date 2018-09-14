#include <iostream>
#include <stdio.h>
#include <algorithm>
#include <vector>

using namespace std;

struct T
{
    int L;
    int R;
    bool operator < ( const T & other ) const
    {
        return ( L == other.L ) ? R < other.R : L < other.L;
    }
};

int main()
{
    int t;
    cin >> t;
    while ( t -- )
    {
        int M;
        int L,R;
        vector< T > v;
        vector< int > ans;
        cin >> M;
        while ( cin >> L >> R && ( L || R ) ) v.push_back( {L,R} );

        sort(v.begin() , v.end());

        int Left = 0 , Right = 0 , Max = 0 , Index;
        while ( Max < M )
        {
            int i;
            Right = Max;
            for ( i = Left; v[i].L <= Right && i < v.size() ;i++)
            {
                if ( v[i].R > Max )
                {
                    Index = i;
                    Max = v[i].R;
                }
            }
            if ( Max == Right )
            {
                ans.clear() ;
                break;
            }
            ans.push_back( Index );
            Left = i;
        }

        cout << ans.size() << endl;
        for (int i=0;i<ans.size();i++)
            cout << v[ ans[i] ].L << " " << v[ ans[i] ].R << endl;

        if ( t )
            cout << endl;
    }
    return 0;
}
