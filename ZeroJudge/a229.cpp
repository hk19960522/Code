#include <iostream>
#include <cstdio>
#include <stack>

using namespace std;

void Print(char s[], int N)
{
    for (int i=0;i<N;i++) printf("%c", s[i]);
    printf("\n");
}

void Find(int L, int R, char s[], int& N)
{
    if ( L + R == N ) {
        if ( L == R )
            Print(s, N);
        return;
    }

    if ( L == R ) {
        s[ L+R ] = '(';
        L++;
        Find(L, R, s, N);
        L--;
    }
    else {
        s[ L+R ] = '(';
        L++;
        Find(L, R, s, N);
        L--;

        s[ L+R ] = ')';
        R++;
        Find(L, R, s, N);
        R--;
    }
}

int main()
{
    int N;
    bool D = true;
    while ( cin >> N ) {
        if ( !D ) cout << endl;

        char s[100];
        N = 2*N;
        Find(0, 0, s, N);

        D = false;
    }
    return 0;
}
