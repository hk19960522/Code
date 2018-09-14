#include <iostream>
#include <stdio.h>

using namespace std;

int main()
{
    int t;
    cin >> t;
    while ( t -- )
    {
        long long int n , m;
        cin >> n >> m;
        if ( n > m )
            cout << m << endl;
        else
        {
            for (long long int i = 3;i <= n ;i++)
            {
                long long int a = i * ( i - 1 ) / 2;
                if ( a + ( n - i ) >= m )
                {
                    cout << n-i << endl;
                    break;
                }
            }
        }
    }
    return 0;
}
