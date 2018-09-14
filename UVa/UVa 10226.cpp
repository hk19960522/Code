#include <iostream>
#include <stdio.h>
#include <map>

using namespace std;

int main()
{
    int T;
    scanf("%d ",&T);
    while ( T -- )
    {
        map< string , int > m;
        map< string , int >::iterator it;
        string Tree;
        int Total = 0;
        while ( getline(cin,Tree) && Tree != "" )
            m[ Tree ] ++ , Total ++ ;

        for ( it = m.begin() ; it != m.end() ; it++ )
            printf("%s %.4f\n",(it->first).c_str() ,(it->second)*100.0/Total);

        if ( T )
            cout << endl;

    }
    return 0;
}

