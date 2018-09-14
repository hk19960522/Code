#include <iostream>
#include <stdio.h>
#include <queue>
#include <vector>
#include <string.h>

using namespace std;

int main()
{
    int T;
    cin >> T;
    while ( T-- )
    {
        int N,M;
        cin >> N >> M;
        vector<int> v[1005];
        bool visited[1005] = {0};
        int Ans[1005] = {0};

        for (int i=0;i<M;i++)
        {
            int a,b;
            cin >> a >> b;
            v[a].push_back(b);
            v[b].push_back(a);
        }

        queue< pair<int,int> > q;
        q.push({0,0});
        visited[ 0 ] = 1;
        while ( !q.empty() )
        {
            pair<int,int> pa = q.front();
            q.pop();
            Ans[ pa.first ] = pa.second;
            for (int i=0;i<v[pa.first].size();i++)
            {
                if ( !visited[ v[pa.first][i] ] )
                {
                    visited[ v[pa.first][i] ] = 1;
                    q.push( { v[ pa.first ][i],pa.second + 1 });
                }

            }
        }
        for (int i=1;i<N;i++)
            cout << Ans[i] << endl;
        if ( T )
            cout << endl;
    }
    return 0;
}
