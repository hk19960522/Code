#include <iostream>
#include <cstdio>
#include <algorithm>
#include <vector>
#include <cstring>
#include <cmath>

using namespace std;

vector<int> v[100005];
int DP[100005];
int N,T;

void DFS ( int index )
{
    if ( v[index].empty() ){
        DP[ index ] = 1;
        return ;
    }

    vector< int > tempv;
    for (int i=0;i<v[index].size();i++) {
        int child = v[index][i];
        DFS( child );
        tempv.push_back( DP[child] );
    }

    sort(tempv.begin(),tempv.end());
    int c = ceil( tempv.size()*T / 100.0 );

    for (int i=0;i<c;i++) {
        DP[index] += tempv[i];
    }
}

int main()
{
    /*
    while ( cin >> N >> T && ( N || T ) ) {
        memset(DP,0,sizeof(DP));
        v[0].clear();
        for (int i=1;i<=N;i++) {
            v[i].clear();

            int a;
            cin >> a;
            v[a].push_back(i);
        }
        DFS(0);

        cout << DP[0] << endl;
    }
    */
    cout << 0 / 5 << endl;
    return 0;
}
