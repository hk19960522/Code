#include <iostream>
#include <stdio.h>
#include <set>
#include <ctype.h>

using namespace std;

int main()
{
    char ch;
    set< string > s;
    string Input;
    bool State = false;
    while ( scanf("%c",&ch) != EOF )
    {
        if ( isalpha(ch) )
            Input += tolower(ch) , State = true;
        else
        {
            State = false;
            if ( Input != "" )
            {
                s.insert( Input );
                Input.clear();
            }
        }
    }

    for( set< string >::iterator it = s.begin() ; it != s.end() ; it++ )
        cout << (*it) << endl;
    return 0;
}
