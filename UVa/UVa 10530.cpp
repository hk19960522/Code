#include <iostream>
#include <stdio.h>
#include <algorithm>
#include <vector>

using namespace std;

int main()
{
    int n;
    string result;
    int L = -1,R = 111;
    while ( scanf("%d ",&n) == 1 && n )
    {
        getline( cin , result );
        if ( result == "too low" )
            L = max( L , n );
        else if ( result == "too high" )
            R = min( R , n );
        else
        {
            if ( L < n && R > n )
                cout << "Stan may be honest\n";
            else
                cout << "Stan is dishonest\n";
            L = -1,R = 11;
        }
    }
    return 0;
}
