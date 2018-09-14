#include <iostream>
#include <stdio.h>
#include <vector>
#include <algorithm>

using namespace std;

struct T
{
    int Time;
    int Fine;
    int Order;
    bool operator < ( const T & other ) const
    {
        return Time * other.Fine < Fine * other.Time;
    }
};

int main()
{
    int t;
    cin >> t;
    while ( t -- )
    {
        vector< T > v;
        int n;
        cin >> n;

        for (int i=0;i<n;i++)
        {
            T Temp;
            cin >> Temp.Time >> Temp.Fine;
            Temp.Order = i+1;
            v.push_back( Temp );
        }

        stable_sort( v.begin() , v.end() );

        for (int i=0;i<n;i++)
        {
            if ( i )
                cout << " ";
            cout << v[i].Order;
        }
        cout << endl;

        if ( t )
            cout << endl;
    }
    return 0;
}
