#include <iostream>
#include <cstdio>
#include <cstring>
#include <queue>

using namespace std;

int N = 9, target = 0;
queue<string> q[10];

int solve()
{
    int score = 0, nowPlayer = 0;
    int outCount = 0;
    bool base[3] = {0};

    while ( target ) {
        string action = q[ nowPlayer ].front();
        q[ nowPlayer ].pop();
        nowPlayer = ( nowPlayer + 1 )%N;

        switch ( action[1] ) {
        case 'O' :
            outCount++;
            if ( outCount == 3 ) {
                outCount = 0;
                memset(base, 0, sizeof(base));
            }
            target--;
            break;

        case 'B' :
            for (int i=0;i<(action[0]-'0');i++) {
                if ( base[2] ) score++;
                base[2] = base[1];
                base[1] = base[0];
                base[0] = false;
            }
            base[(action[0]-'0')-1] = true;
            break;

        case 'R' :
            for (int i=0;i<3;i++) {
                if ( base[i] ) score++;
                base[i] = false;
            }
            score++;
            break;
        }
    }

    return score;
}

int main()
{
    for (int i=0;i<N;i++) {
        int num;
        cin >> num;
        for (int j=0;j<num;j++) {
            string str;
            cin >> str;
            q[i].push(str);
        }
    }

    cin >> target;
    cout << solve() << endl;

    return 0;
}
