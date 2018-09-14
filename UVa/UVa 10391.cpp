#include <iostream>
#include <stdio.h>
#include <set>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
    string Input;
    vector< string > v;
    set< string > s;
    while ( cin >> Input )
        v.push_back(Input) , s.insert(Input);

    for (int i = 0;i<v.size();i++)
    {
        if ( v[i].length() > 1 )
        {
            string First , Second;
            Second = v[i];
            for (int j=0;j<v[i].length()-1;j++)
            {
                First += Second[0];
                Second.erase( Second.begin() );
                if ( s.count( First ) && s.count( Second ) )
                {
                    cout << v[i] << endl;
                    break;
                }

            }
        }
    }

    return 0;
}
