#include <iostream>
#include <cstdio>
#include <map>

using namespace std;

map<string, string> m;

string analyis(string str)
{
    if ( m.find(str) != m.end() ) return m[ str ];

    if ( str.length() >= 2 && *(str.rbegin()) == 'y' && ( str[ str.length()-2 ] != 'a' && str[ str.length()-2 ] != 'e' &&
                                                          str[ str.length()-2 ] != 'i' && str[ str.length()-2 ] != 'o' && str[ str.length()-2 ] != 'u' ) ) {
        str[ str.length() - 1 ] = 'i';
        str += "es";
    }
    else if ( str.length() >= 2 && ( str.substr(str.length()-2, 2) == "ch" || str.substr(str.length()-2, 2) == "sh" ) ) {
        str += "es";
    }
    else if ( *(str.rbegin()) == 'o' || *(str.rbegin()) == 's' || *(str.rbegin()) == 'x' ) {
        str += "es";
    }
    else {
        str += "s";
    }
    return str;
}


int main()
{
    int L, N;
    cin >> L >> N;

    for (int i=0;i<L;i++) {
        string str1, str2;
        cin >> str1 >> str2;
        m[ str1 ] = str2;
    }

    for (int i=0;i<N;i++) {
        string str;
        cin >> str;
        cout << analyis(str) << endl;
    }
    return 0;
}
