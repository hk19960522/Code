#include <iostream>
#include <cstdio>
#include <set>

using namespace std;

int main()
{
    int T;
    cin >> T;
    for (int t=1;t<=T;t++) {
        int N;
        cin >> N;

        set<int> s;
        int now = N;

        do {
            s.insert(now);
            int tmp = 0;
            while (now) {
                tmp += ( now % 10 ) * ( now % 10 );
                now /= 10;
            }
            now = tmp;
        }while ( now != 1 && s.count(now) == 0 );

        printf("Case #%d: ", t);
        if ( now != 1 ) {
            printf("%d is an Unhappy number.\n", N);
        }
        else {
            printf("%d is a Happy number.\n", N);
        }
    }
    return 0;
}
