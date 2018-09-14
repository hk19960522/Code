#include <iostream>
#include <stdio.h>
#include <queue>

using namespace std;

int main()
{
    int N;
    while ( cin >> N && N )
    {
        priority_queue< int > pq;
        int Total = 0;
        for (int i=0;i<N;i++)
        {
            int a;
            cin >> a;
            pq.push(-a);
        }

        while ( pq.size() != 1 )
        {
            int a , b;
            a = pq.top();
            pq.pop();
            b = pq.top();
            pq.pop();
            Total += ( a+b );
            pq.push(a+b);
        }
        cout << -Total << endl;
    }
    return 0;
}
