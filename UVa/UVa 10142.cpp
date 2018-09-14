#include <iostream>
#include <cstdio>
#include <vector>
#include <queue>
#include <sstream>

using namespace std;

int main()
{
    int T;
    cin >> T;
    while ( T-- ) {
        int n;
        vector<string> v;
        scanf("%d ", &n);

        for (int i=0;i<n;i++) {
            string name;
            getline(cin, name);

            v.push_back(name);
        }

        bool isElimited[1005] = {0};
        int VoteTime[1005] = {0};
        queue<int> vote[1005];

        string input;
        while ( getline(cin, input) && input != "" ) {
            stringstream ss(input);

            for (int i=0;i<n;i++) {
                int num;
                ss >> num;
                vote[ index ].push(num);
            }
        }
    }
    return 0;
}
