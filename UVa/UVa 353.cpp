#include <iostream>
#include <stdio.h>
#include <set>
#include <algorithm>

using namespace std;

int main()
{
    string Input;
    while ( cin >> Input )
    {
        set< string > s;
        int Len = Input.length();
        for ( int i=0;i<Len;i++)
        {
            string Temp;
            for (int j=i;j<Len;j++)
            {
                Temp += Input[j];
                string Re = Temp;
                reverse( Re.begin() , Re.end() );
                if ( Re == Temp )
                    s.insert( Temp );
            }
        }
        printf("The string \'%s\' contains %d palindromes.\n",Input.c_str(),s.size());
    }
    return 0;
}
