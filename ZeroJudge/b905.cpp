#include <iostream>
#include <cstdio>
#include <vector>

using namespace std;

bool solve(string a, string b)
{
    int Max = max(a.length(), b.length());
    vector< pair<int, int> > v;

    for (int i=0, j=0;i<a.length() && j<b.length();i++) {
        if ( a[i] == '*' ) v.push_back( pair<int, int>(-1, -1) );
        else {
            int tmp = i;
            bool D = false;
            while ( i < a.length() && j < b.length() ) {
                if ( a[i] != b[j] ) j++;
                else {

                }
            }
        }
    }

    for (int i=0;i<v.size();i++) {
        cout << v[i].first << " " << v[i].second << endl;
    }

    return true;
}

int main()
{
    int N;
    cin >> N;

    while (N--) {
        string str1, str2;
        cin >> str1 >> str2;

        solve(str1, str2);
    }
    return 0;
}
