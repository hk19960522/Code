#include <iostream>
#include <stdio.h>
#include <algorithm>

using namespace std;

int main()
{
    int n , d , r;
    while ( cin >> n >> d >> r && n && d && r )
    {
        int Morning[ 200 ] , Evening[ 200 ];
        int ans = 0;
        for (int i=0;i<n;i++)
            cin >> Morning[i];
        for (int i=0;i<n;i++)
            cin >> Evening[i];

        sort( Morning , Morning + n );
        sort( Evening , Evening + n , greater< int > () );

        for ( int i=0;i<n;i++)
        {
            int D =  Morning[i] + Evening[i] - d;
            ans += ( D > 0 ) ? D * r : 0 ;
        }
        cout << ans << endl;
    }
    return 0;
}
