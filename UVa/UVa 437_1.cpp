#include <iostream>
#include <stdio.h>
#include <algorithm>
#include <vector>

using namespace std;

struct Box
{
    int Length,Width;
    int Height;
};

vector<Box> v;
int DP[100] = {0};

int DAG ( int index )
{
    if ( DP[index] >= 0 ) return DP[index];

    DP[ index ] = v[index].Height;
    for (int i=0;i<v.size();i++) {
        if ( v[i].Length < v[index].Length && v[i].Width < v[index].Width ) {
            DP[ index ] = max( DP[ index ] , DAG(i) + v[ index ].Height );
        }
    }
    return DP[ index ];
}

int main()
{
    int n;
    int Case = 0;
    while ( cin >> n && n ) {
        for (int i=0;i<n;i++) {
            int a , b , c;
            cin >> a >> b >> c;
            v.push_back({min(a,b),max(a,b),c});
            v.push_back({min(a,c),max(a,c),b});
            v.push_back({min(c,b),max(c,b),a});
            DP[i*3] = DP[i*3+1] = DP[i*3+2] = -1;
        }

        int ans = 0;
        for (int i=0;i<v.size();i++){
            //cout << v[i].Length << " " << v[i].Width << " " << v[i].Height << endl;
            ans = max(ans,DAG(i));
        }

        printf("Case %d: maximum height = %d\n",++Case,ans);
        v.clear();
    }
    return 0;
}
