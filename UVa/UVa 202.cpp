#include <iostream>
#include <stdio.h>
#include <map>

using namespace std;

int main()
{
    int a,b;
    while ( cin >> a >> b )
    {
        map<int,int> m;
        string ans;
        int First = a/b;
        printf("%d/%d = ",a,b);
        a %= b;
        m[ a ] = 1;
        a *= 10;


        int Count = 2,Break = 0;
        while ( 1 )
        {
            ans += ( a/b )+'0';
            if ( m[ a%b ] )
                break;
            m[ a%b ] = Count++;
            a %= b;
            a *= 10;
        }
        cout << First << ".";
        Break = m[ a%b ];
        for (int i=0;i<Count-1 && i < 50;i++)
        {
            if ( i == Break-1 )
                cout << "(";
            cout << ans[i];
        }
        if ( Count > 50 )
            cout << "...";
        cout << ")\n";
        printf("   %d = number of digits in repeating cycle\n\n",Count-Break);
    }
    return 0;
}
