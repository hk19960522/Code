#include <iostream>
#include <cstdio>
#include <cstring>

using namespace std;

int G[5][5] = {0}, N;
bool visit[5][5] = {0};
int scoreA = 0, scoreB = 0;
int times[3] = {0};

void dfs(int n, bool D)
{
    bool isEnd = true;
    for (int i=0;i<N;i++) {
        if ( D ) {
            if ( !visit[n][i] ) {
                visit[n][i] = true;
                scoreA += G[n][i];
                dfs(i, !D);
                visit[n][i] = false;
                scoreA -= G[n][i];
                isEnd = false;
            }
        }
        else {
            if ( !visit[i][n] ) {
                visit[i][n] = true;
                scoreB += G[i][n];
                dfs(i, !D);
                visit[i][n] = false;
                scoreB -= G[i][n];
                isEnd = false;
            }
        }
    }

    if ( isEnd ) {
        //cout << scoreA << " " << scoreB << endl;
        times[0] += ( scoreA > scoreB );
        times[1] += ( scoreA < scoreB );
        times[2] += ( scoreA == scoreB );
    }
}



int main()
{
    while ( cin >> N ) {
        scoreA = scoreB = 0;
        memset(times, 0, sizeof(times));
        memset(visit, 0, sizeof(visit));
        for (int i=0;i<N;i++) {
            for (int j=0;j<N;j++) {
                cin >> G[i][j];
            }
        }
        dfs(0, true);
        for (int i=0;i<3;i++) cout << times[i] << " ";
        cout << endl;
    }
    return 0;
}
