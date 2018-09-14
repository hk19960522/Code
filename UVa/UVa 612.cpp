#include <iostream>
#include <stdio.h>
#include <algorithm>
#include <vector>

using namespace std;

struct T
{
    string DNA;
    int Sort = 0;
    int Order = 0;
    bool operator < ( const T & other ) const
    {
        return Sort < other.Sort;
    }
};

int main()
{
    int t;
    cin >> t;
    while ( t-- )
    {
        vector< T > v;
        int m,n;
        cin >> m >> n;
        for (int i=0;i<n;i++)
        {
            T Temp;
            Temp.Order = i;
            cin >> Temp.DNA;

            for (int j=0;j<m;j++)
                for (int k=j+1;k<m;k++)
                    if( Temp.DNA[j] > Temp.DNA[k] )
                        Temp.Sort ++;
            v.push_back( Temp );
        }

        stable_sort( v.begin() , v.end() );

        for (int i=0;i<v.size();i++)
            cout << v[i].DNA << endl;
        if ( t )
            cout << endl;
    }
    return 0;
}
