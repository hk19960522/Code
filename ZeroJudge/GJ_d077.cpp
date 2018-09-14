#include <iostream>
#include <cstdio>
#include <algorithm>
#include <vector>
#include <queue>

using namespace std;

struct T
{
    int arrive, time;

    bool operator < ( const T & rhs ) const
    {
        return arrive < rhs.arrive;
    }
};

int main()
{
    vector<T> v;
    queue<T> q;

    int n;
    cin >> n;

    for (int i=0;i<n;i++) {
        T tmp;
        cin >> tmp.arrive >> tmp.time;
        v.push_back(tmp);
    }

    sort(v.begin(), v.end());
    int ans = 0, endTime = v[0].arrive + v[0].time;

    for (int i=1;i<v.size();i++) {
        if ( v[i].arrive <= endTime || q.empty() ) {
            q.push(v[i]);
        }
        else {
            if ( !q.empty() ) {
                endTime = max( endTime, q.front().arrive ) + q.front().time;
                q.pop();
            }
            i--;
        }
        ans = max(ans, (int)q.size());
    }

    cout << ans << endl;
    return 0;
}
