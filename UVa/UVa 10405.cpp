#include <iostream>
#include <stdio.h>
#include <string.h>

using namespace std;

int DP[ 1001 ][ 1001 ];

int main()
{
    string str1 , str2;
    while ( getline( cin , str1 ) && getline( cin , str2 ) )
    {
        memset( DP , 0 , sizeof(DP) );
        int Len1 = str1.length() , Len2 = str2.length();

        for (int i=1;i<=Len1;i++)
            for (int j=1;j<=Len2;j++)
                if ( str1[ i-1 ] == str2[ j-1 ] )
                    DP[ i ][ j ] = DP[ i-1 ][ j-1 ] + 1;
                else
                    DP[ i ][ j ] = max( DP[ i-1 ][ j ] , DP[ i ][ j-1 ] );

        cout << DP[ Len1 ][ Len2 ] << endl;
    }
    return 0;
}



