#include <iostream>
#include <cstdio>
#include <vector>
#include <stack>

using namespace std;

bool solve(vector<int>& v, int N)
{
    int now = 0;
    stack<int> s;

    for (int i=0;i<N;i++) {
        s.push(i+1);

        if ( v[now] == i+1 ) {
            while ( !s.empty() && now < N && v[now] == s.top() ) s.pop(), now++;
        }
    }

    while ( !s.empty() && now < N && v[now] == s.top() ) s.pop(), now++;
    return s.empty();
}

int main()
{
    int N;
    cin >> N;
    while ( N-- ) {
        int n;

        cin >> n;
        vector<int> v;

        for (int i=0;i<n;i++) {
            int m;

            cin >> m;
            v.push_back(m);
        }

        if ( solve(v, n) ) {
            cout << "Yes\n";
        }
        else {
            cout << "No\n";
        }
    }
    return 0;
}
