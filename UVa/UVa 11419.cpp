#include <iostream>
#include <cstdio>
#include <vector>
#include <cstring>
#include <map>
#include <cmath>

using namespace std;

struct Student
{
    int Height;
    char Sex;
    string Music,Sport;
};

const int Max_Size = 1005;
vector< int > v[Max_Size];
int MatchX[ Max_Size ],MatchY[ Max_Size ];
int usedX[ Max_Size ], usedY[ Max_Size ];
int X,Y;

bool DFS( int x )
{
    usedX[ x ] = true;
    for (int i=0;i<v[x].size();i++) {
        int y = v[x][i];
        if ( !usedY[ y ] ) {
            usedY[ y ] = true;
            if ( MatchY[ y ] == -1 || DFS( MatchY[ y ] ) ) {
                MatchX[ x ] = y;
                MatchY[ y ] = x;
                return true;
            }
        }
    }
    return false;
}

int bipartite_matching ()
{
    memset(MatchX,-1,sizeof(MatchX));
    memset(MatchY,-1,sizeof(MatchY));
    int ans = 0;

    for (int i=0;i<X;i++) {
        memset(usedY,0,sizeof(usedY));
        if ( DFS(i) ) ans++;
    }

    return ans;
}

int main()
{
    int N;
    while ( cin >> X >> Y >> N && X+Y+N ) {
        for (int i=0;i<X;i++) v[i].clear();

        for (int i=0;i<N;i++) {
            int r,c;
            cin >> r >> c;
            v[ r-1 ].push_back(c-1);
        }

        cout << bipartite_matching();

        memset(usedX,false,sizeof(usedX));
        memset(usedY,false,sizeof(usedY));
        for (int i=0;i<X;i++) {
            if ( MatchX[ i ] == -1 ) // 從未匹配點開始找
                DFS(i);
        }
        for (int i=0;i<X;i++) {
            if ( !usedX[i] ) {
                // X 側的覆蓋點
            }
        }
        for (int i=0;i<Y;i++) {
            if ( usedY[i] ) {
                // Y 側的覆蓋點
            }
        }


        cout << endl;
    }
    return 0;
}
