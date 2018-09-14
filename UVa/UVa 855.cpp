#include <iostream>
#include <stdio.h>
#include <algorithm>

using namespace std;

int main()
{
    int t;
    cin >> t;
    while ( t -- )
    {
        int n,m,p;
        cin >> n >> m >> p;
        int X[50000] = {0},Y[50000] = {0};

        for (int i=0;i<p;i++)
            cin >> X[i] >> Y[i];

        nth_element( X , X+(p-1)/2 , X+p );
        nth_element( Y , Y+(p-1)/2 , Y+p );
        printf("(Street: %d, Avenue: %d)\n",X[ (p-1)/2 ],Y[ (p-1)/2 ]);
    }
    return 0;
}
