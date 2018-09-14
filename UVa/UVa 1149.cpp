#include <iostream>
#include <stdio.h>
#include <algorithm>
#include <vector>

using namespace std;

int main()
{
    int t;
    cin >> t;
    while ( t-- )
    {
        int L , N;
        vector < int > v;
        cin >> N >> L;
        for (int i=0;i<N;i++)
        {
            int temp;
            cin >> temp;
            v.push_back( temp );
        }

        sort( v.begin() , v.end() );
        int Left = 0 , Right = N-1;
        int Ans = 0;

        while ( Left <= Right )
        {
            if ( v[ Left ] + v[ Right ] <= L )
                Left ++ , Right -- ;
            else
                Right -- ;
            Ans++;
        }
        cout << Ans << endl;
        if ( t )
            cout << endl;
    }
    return 0;
}
