#include <iostream>
#include <cstdio>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
    int N, M, S = 0;
    cin >> N >> M;

    vector<int> v[25];

    for (int i=0;i<N;i++) {
        v[i].resize(M);
        for (int j=0;j<M;j++) {
            cin >> v[i][j];
        }
        sort(v[i].begin(), v[i].end(), greater<int>() );
        S += v[i][0];
    }

    bool D = false;
    cout << S << endl;
    for (int i=0;i<N;i++) {
        if ( !(S%v[i][0]) ) {
            cout << v[i][0] << " ";
            D = true;
        }
    }
    if ( !D ) cout << -1;
    cout << endl;
    return 0;
}
