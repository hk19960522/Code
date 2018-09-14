#include <iostream>
#include <stdio.h>
#include <algorithm>
#include <math.h>

using namespace std;

int main()
{
    int t;
    cin >> t;
    while ( t -- )
    {
        int n;
        int House[1000] = {0};
        cin >> n;

        for (int i=0;i<n;i++)
            cin >> House[i];

        nth_element( House , House+n/2 , House+n );

        int ans = 0;
        for (int i=0;i<n;i++)
            ans += abs( House[i] - House[ n/2 ] );
        cout << ans << endl;
    }
    return 0;
}
