#include <iostream>
#include <stdio.h>
#include <algorithm>
#include <ctype.h>

using namespace std;

struct T
{
    char ch = 0;
    int time = 0;
    bool operator < ( const T & other ) const
    {
        return time > other.time;
    }
};

int main()
{
    int n;
    scanf("%d ",&n);

    T Record[26];

    while ( n-- )
    {
        string Input;
        getline( cin , Input );
        for (int i=0;i<Input.length();i++)
            if ( isalpha(Input[i] ) )
            {
                Record[ toupper(Input[i]) - 'A' ].ch = toupper(Input[i]);
                Record[ toupper(Input[i]) - 'A' ].time ++;
            }
    }

    stable_sort( Record , Record+26 );
    for (int i=0;i<26 && Record[i].time ;i++)
        printf("%c %d\n",Record[i].ch,Record[i].time);

    return 0;
}
