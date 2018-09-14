#include <iostream>
#include <stdio.h>
#include <cstring>

using namespace std;

int DP[5005][5005],Car[5005][5005];

int main()
{
    int N;
    cin >> N;
    while (N--) {
        int spos1[26],spos2[26],epos1[26],epos2[26];

        for (int i=0;i<26;i++) {
            spos1[i] = spos2[i] = 1e9;
            epos1[i] = epos2[i] = -1;
        }

        string str1,str2;
        //cout << spos1[3];
        for (int i=0;i<=str1.length();i++) {
            for (int j=0;j<=str2.length();j++) {
                DP[i][j] = Car[i][j] = 0;
            }
        }
        cin >> str1 >> str2;
        for (int i=0;i<str1.length();i++) {
            spos1[ str1[i]-'A' ] = min( spos1[ str1[i]-'A' ] , i+1 );
            epos1[ str1[i]-'A' ] = max( epos1[ str1[i]-'A' ] , i+1 );
        }
        for (int i=0;i<str2.length();i++) {

            spos2[ str2[i]-'A' ] = min( spos2[ str2[i]-'A' ] , i+1 );
            epos2[ str2[i]-'A' ] = max( epos2[ str2[i]-'A' ] , i+1 );
        }
        for (int i=0;i<=str1.length();i++) {
            for (int j=0;j<=str2.length();j++) {
                if ( !i && !j ) continue;

                int val1 = 1e9,val2 = 1e9;
                if ( i ) val1 = DP[i-1][j] + Car[i-1][j];
                if ( j ) val2 = DP[i][j-1] + Car[i][j-1];

                int index;
                if ( val1 < val2 ) {
                    index = str1[i-1] - 'A';
                    Car[i][j] = Car[i-1][j];
                    DP[i][j] = val1;
                    if ( spos1[ index ] == i && spos2[ index ] > j ) Car[i][j] ++;
                    if ( epos1[ index ] == i && epos2[ index ] <= j ) Car[i][j] --;
                }
                else {
                    index = str2[j-1] - 'A';
                    Car[i][j] = Car[i][j-1];
                    DP[i][j] = val2;
                    if ( spos2[ index ] == j && spos1[ index ] > i ) Car[i][j] ++;
                    if ( epos2[ index ] == j && epos1[ index ] <= i ) Car[i][j]--;
                }
            }
        }

        cout << DP[str1.length()][str2.length()] << endl;
    }
    return 0;
}
