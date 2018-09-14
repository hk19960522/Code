#include <iostream>
#include <stdio.h>

using namespace std;

int main()
{
    int N;
    while ( cin >> N )
    {
        int Ans = 0;
        int Array[10001] = {0};

        for (int i=0;i<N;i++)
            cin >> Array[i];
        for (int i=0;i<N;i++)
            for (int j=N-1;j>i;j--)
                if ( Array[j] < Array[j-1] )
                    swap( Array[j] , Array[j-1] ) , Ans ++;

        printf("Minimum exchange operations : %d\n",Ans);
    }
    return 0;
}
