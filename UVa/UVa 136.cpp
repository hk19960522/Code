#include <iostream>
#include <stdio.h>
#include <queue>
#include <set>

using namespace std;

int main()
{
    priority_queue<long long int> pq;
    set<long long int> s;
    pq.push(-1);
    int Count = 1;
    s.insert(-1);
    while ( Count < 1500 )
    {
        long long int a = pq.top();
        pq.pop();
        if ( ! s.count(a*2) )
            pq.push(a*2) , s.insert( a*2 );
        if ( ! s.count(a*3) )
            pq.push(a*3) , s.insert( a*3 );
        if ( ! s.count(a*5) )
            pq.push(a*5) , s.insert( a*5 );
        Count++;
    }
    printf("The 1500'th ugly number is %d.\n",- pq.top());
    return 0;
}
