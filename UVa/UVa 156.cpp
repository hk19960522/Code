#include <iostream>
#include <stdio.h>
#include <algorithm>
#include <ctype.h>
#include <map>
#include <vector>

using namespace std;

int main()
{
    string Input;
    map< string , string > Record;
    while ( cin >> Input && Input != "#" )
    {
        string Temp = Input;
        transform(Input.begin(),Input.end(),Temp.begin(), ::tolower );
        sort( Temp.begin() , Temp.end() );
        if ( Record[Temp] == "" )
            Record[ Temp ] = Input;
        else
            Record[ Temp ] = "#";
    }


    map< string , string >::iterator it1;
    for ( it1 = Record.begin() ; it1 != Record.end() ; it1++ )
    {
        if ( it1->second != "#")
            Ans.push_back(it1->second);
    }
    sort( Ans.begin() , Ans.end() );
    for (int i=0;i<Ans.size();i++)
        cout << Ans[i] << endl;
    return 0;
}
