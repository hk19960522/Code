#include <iostream>
#include <cstdio>
#include <stack>

using namespace std;

bool solve(string str)
{
    if ( str.length() % 2 ) return false;

    stack<char> s;
    for (int i=0;i<str.length();i++) {
        if ( str[i] == ']' ) {
            if ( s.empty() || s.top() != '[' ) {
                return false;
            }
            s.pop();
        }
        else if ( str[i] == ')' ) {
            if ( s.empty() || s.top() != '(' ) {
                return false;
            }
            s.pop();
        }
        else {
            s.push(str[i]);
        }
    }

    return s.empty();
}

int main()
{
    int N;
    scanf("%d", &N);
    scanf("%*c");
    while ( N-- ) {
        string input;
        getline(cin, input);

        if ( solve(input) ) {
            cout << "Yes\n";
        }
        else {
            cout << "No\n";
        }
    }
    return 0;
}
