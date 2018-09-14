#include <iostream>
#include <stdio.h>
#include <stack>
#include <vector>

using namespace std;

int main()
{
    int N;
    int T = 0;
    while ( cin >> N && N )
    {
        if ( T )
            cout << endl;
        while ( 1 )
        {
            vector< int > train;
            stack< int > s;
            int a;
            cin >> a;
            if ( !a )
                break;
            train.push_back(a);
            for (int i=1;i<N;i++)
            {
                cin >> a;
                train.push_back(a);
            }
            int Start = 0,Index = 1;
            bool D = 1;

            do
            {
                s.push( Index );
                if ( Index == train[Start] )
                {
                    while ( !s.empty() )
                    {
                        if ( s.top() != train[Start] )
                        {
                            D = 0;
                            break;
                        }
                        s.pop();
                        Start++;
                    }
                }
                Index ++;
            }while ( Index <= N && D );

            if ( !s.empty() ) D = 0;
            cout << ( D ? "Yes" : "No" ) << endl;
        }
        T++;
    }
    return 0;
}
