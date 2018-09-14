#include <iostream>
#include <stdio.h>
#include <algorithm>
#include <queue>

using namespace std;

struct Pos
{
    int x;
    int y;
};

int Map[1001][1001];
int JackTime[1001][1001];
int N,M;
int Dir[4][2] = { {0,1} , {0,-1} , {1,0} , {-1,0} };

bool Check ( int & x , int & y )
{
    if ( x < 0 || x >= N || y < 0 || y >= M )
        return true;
    else
        return false;
}

int Jack_BFS( queue<Pos> & Jack )
{
    while ( !Jack.empty() )
    {
        Pos Temp = Jack.front();
        Jack.pop();
        for (int i=0;i<4;i++)
        {
            int x = Temp.x + Dir[i][0];
            int y = Temp.y + Dir[i][1];
            if ( Check(x,y) )
                return JackTime[ Temp.x ][ Temp.y ] + 1;

            if ( Map[x][y] != -1 && ( Map[x][y] == 0 || Map[x][y] - 1 > JackTime[ Temp.x ][ Temp.y ] + 1 ) && JackTime[x][y] == -1)
            {
                JackTime[x][y] = JackTime[ Temp.x ][ Temp.y ] + 1;
                Jack.push( { x , y } );
            }
        }
    }
    return 0;
}

void Fire_BFS ( queue<Pos> & Fire )
{
    while ( !Fire.empty() )
    {
        Pos Temp = Fire.front();
        Fire.pop();

        for ( int i=0;i<4;i++ )
        {
            int x = Temp.x + Dir[i][0];
            int y = Temp.y + Dir[i][1];
            if ( !Check( x , y ) && Map[x][y] == 0 )
            {
                Map[x][y] = Map[ Temp.x ][ Temp.y ] + 1;
                Fire.push( { x , y } );
            }
        }
    }
    /*for (int i=0;i<N;i++)
    {
        for (int j=0;j<M;j++)
            cout << Map[i][j] << " ";
        cout << endl;
    }
    cout << "======================\n";*/
}

int main()
{
    int t;
    cin >> t;
    while ( t-- )
    {
        scanf("%d %d",&N,&M);
        queue<Pos> Jack , Fire;
        for (int i=0;i<N;i++)
        {
            char Input[1001];
            scanf("%s",Input);
            for (int j=0;j<M;j++)
            {
                JackTime[i][j] = -1;
                char ch = Input[j];
                Map[i][j] = 0;
                if ( ch == 'J' )
                    Jack.push( {i,j} ) , JackTime[i][j] = 0;
                else if ( ch == 'F' )
                    Fire.push( {i,j} ) , Map[i][j] = 1;
                else if ( ch == '#' )
                    Map[i][j] = -1;
            }
        }

        Fire_BFS( Fire );
        int Ans = Jack_BFS( Jack );

        /*for (int i=0;i<N;i++)
        {
            for (int j=0;j<M;j++)
                cout << JackTime[i][j] << " ";
            cout << endl;
        }*/
        if ( Ans )
            cout << Ans << endl;
        else
            cout << "IMPOSSIBLE\n";
    }
    return 0;
}
