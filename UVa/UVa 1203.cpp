#include <iostream>
#include <stdio.h>
#include <queue>

using namespace std;

struct T
{
    int ID;
    int Time;
    int TotalTime;
    bool operator < ( const T & other ) const
    {
        return ( TotalTime == other.TotalTime) ? ID > other.ID : TotalTime > other.TotalTime;
    }
};

int main()
{
    priority_queue< T > pq;
    string Input;
    while ( cin >> Input && Input != "#" )
    {
        T Temp;
        cin >> Temp.ID >> Temp.Time;
        Temp.TotalTime = Temp.Time;
        pq.push(Temp);
    }
    int N;
    cin >> N;
    while ( N-- )
    {
        T Temp = pq.top();
        pq.pop();
        cout << Temp.ID << endl;
        Temp.TotalTime += Temp.Time;
        pq.push(Temp);
    }
    return 0;
}
