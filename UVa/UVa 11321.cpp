#include <iostream>
#include <stdio.h>
#include <vector>
#include <algorithm>

using namespace std;

struct T
{
    int Number;
    int Mod;
    bool isOdd;
    bool operator < ( const T & other ) const
    {
        if ( Mod == other.Mod )
        {
            if ( isOdd && other.isOdd )
                return Number > other.Number;
            else if ( !isOdd && !other.isOdd )
                return Number < other.Number;
            else
                return isOdd;
        }
        else
            return Mod < other.Mod;
    }
};

int main()
{
    int N,M;
    while ( cin >> N >> M && N && M )
    {
        vector< T > v;
        for (int i=0;i<N;i++)
        {
            T Temp;
            cin >> Temp.Number;
            Temp.Mod = Temp.Number % M;
            Temp.isOdd = Temp.Number % 2;
            v.push_back( Temp );
        }

        sort( v.begin() , v.end() );
        cout << N << " " << M << endl;
        for (int i=0;i<N;i++)
            cout << v[i].Number << endl;
    }
    cout << "0 0\n";
    return 0;
}
