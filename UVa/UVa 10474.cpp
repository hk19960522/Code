#include <iostream>
#include <stdio.h>
#include <algorithm>
#include <vector>

using namespace std;

int main()
{
    int N,M;
    int C = 0;
    while ( cin >> N >> M && N && M )
    {
        vector< int > v;
        vector< int >::iterator it;
        for (int i=0;i<N;i++)
        {
            int temp;
            cin >> temp;
            v.push_back( temp );
        }

        sort( v.begin() , v.end() );

        printf("CASE# %d:\n",++C );
        for (int i=0;i<M;i++)
        {
            int target;
            cin >> target;
            it = lower_bound( v.begin() , v.end() , target );
            if ( it == v.end() || *it != target )
                printf("%d not found\n", target );
            else
                printf("%d found at %d\n", target , it - v.begin() + 1 );
        }
    }
    return 0;
}
