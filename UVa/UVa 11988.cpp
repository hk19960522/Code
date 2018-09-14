#include <iostream>
#include <stdio.h>
#include <list>

using namespace std;

int main()
{
    char ch;
    list< char > li;
    list< char >::iterator it;
    it = li.begin();
    while ( scanf("%c",&ch) == 1 )
    {
        if ( ch == '\n' )
        {
            it = li.begin();
            for ( ; it != li.end() ; it++ )
                cout << *it;
            cout << endl;
            li.clear();
            it = li.begin();
            continue;
        }

        if ( ch == '[' )
            it = li.begin();
        else if ( ch == ']' )
            it = li.end();
        else
            li.insert( it , ch );
    }
    return 0;
}
