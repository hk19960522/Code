#include <iostream>
#include <stdio.h>
#include <string.h>

using namespace std;

bool Check ( int X , int Y )
{
    if ( X <= 0 || X > 5 || Y <= 0 || Y > 5 )
        return false;
    return true;
}

int main()
{
    int Case = 1;
    int Count = 0;
    char Record[7][7] = {0};
    char ch;
    while ( scanf("%c",&Record[1][1]) == 1 && Record[1][1] != 'Z' )
    {
        if ( Case != 1 ) cout << endl;
        int CurX,CurY;
        bool isLegal = 1;

        for (int i=1;i<6;i++) {
            for (int j=1;j<6;j++) {
                if ( i == 1 && j == 1 ) continue;
                scanf("%c",&Record[i][j]);
                if ( Record[i][j] == ' ' ) {
                    CurX = i , CurY = j;
                }
                if ( Record[i][j] == '\n' ){
                    if ( j == 5 ) {
                        CurX = i , CurY = j;
                        Record[i][j] = ' ';
                    }
                    else
                        j--;
                }
            }
        }
        /*cout << CurX << " " << CurY << endl;
        for (int i=1;i<6;i++) {
                for (int j=1;j<6;j++) {
                    if ( j != 1 ) cout << " ";
                    cout << Record[i][j];
                }
                cout << endl;
            }*/
        while ( scanf("%c",&ch) == 1 && ch != '0' ) {
            if ( isLegal ) {
                if ( ch != '\n' ) {
                    int NextX = CurX , NextY = CurY;
                    if ( ch == 'A' ) NextX --;
                    else if ( ch == 'B' ) NextX ++;
                    else if ( ch == 'R' ) NextY ++;
                    else if ( ch == 'L' ) NextY --;
                    else {
                        isLegal = false;
                        continue;
                    }

                    isLegal = Check( NextX , NextY );
                    if ( !isLegal ) continue;

                    swap( Record[ CurX ][ CurY ] , Record[ NextX ][ NextY ] );
                    CurX = NextX , CurY = NextY;
                }
            }
        }

        printf("Puzzle #%d:\n",Case++);
        if ( isLegal ) {
            for (int i=1;i<6;i++) {
                for (int j=1;j<6;j++) {
                    if ( j != 1 ) cout << " ";
                    cout << Record[i][j];
                }
                cout << endl;
            }
        }
        else
            printf("This puzzle has no final configuration.\n");
        getchar();
    }
    return 0;
}
