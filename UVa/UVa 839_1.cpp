#include <iostream>
#include <stdio.h>

using namespace std;

bool D = 1;

int DFS( )
{
    int LW,LL,RW,RL;
    cin >> LW >> LL >> RW >> RL;
    if ( !LW )
        LW = DFS();
    if ( !RW )
        RW = DFS();

    if ( LW * LL != RW * RL ) D = 0;

    return LW+RW;
}

int main()
{
    int N;
    cin >> N;
    while ( N-- )
    {
        D = 1;
        DFS();
        cout << ( D ? "YES" : "NO" ) << endl;
        if ( N )
            cout << endl;
    }
    return 0;
}
