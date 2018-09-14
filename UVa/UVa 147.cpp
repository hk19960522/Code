#include <iostream>
#include <stdio.h>

using namespace std;

int main()
{
    int Cost[ 11 ] = { 5 , 10 , 20 , 50 , 100 , 200 , 500 , 1000 , 2000 , 5000 , 10000 };
    long long int DP[ 30001 ] = {1};
    for (int i=0;i<11;i++)
        for (int j=Cost[i];j<=30000;j++)
            DP[ j ] += DP[ j - Cost[i] ];
    int Money1 , Money2;
    while ( scanf("%d.%d",&Money1,&Money2) == 2 && ( Money1 || Money2 ) )
        printf("%3d.%02d%17lld\n",Money1,Money2,DP[ Money1*100+Money2 ] );
    return 0;
}
