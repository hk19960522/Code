#include <iostream>
#include <stdio.h>
#include <algorithm>

using namespace std;

int main()
{
    string A,B;
    while ( cin >> A >> B )
    {
        char Message[26] = {0};
        char Encrypt[26] = {0};

        for (int i=0;i<A.length();i++)
            Message[ A[i] - 'A' ]++;
        for (int i=0;i<B.length();i++)
            Encrypt[ B[i] - 'A' ]++;

        sort( Message , Message + 26 );
        sort( Encrypt , Encrypt + 26 );

        bool D = 1;
        for (int i=0;i<26 && D;i++)
            if ( Message[i] != Encrypt[i] )
                D = 0;
        if ( D )
            cout << "YES\n";
        else
            cout << "NO\n";
    }
    return 0;
}
