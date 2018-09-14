#include <iostream>
#include <cstdio>
#include <algorithm>
#include <vector>

using namespace std;

struct T
{
    int cost , time;

    bool operator < ( const T & rhs ) const
    {
        return cost * rhs.time < rhs.cost * time;
    }
};


int main()
{
    int n;
    long long total = 0;
    cin >> n;

    vector<T> v;
    for (int i=0;i<n;i++) {
        T tmp;
        cin >> tmp.cost;
        v.push_back(tmp);
        total += tmp.cost;
    }

    for (int i=0;i<n;i++) {
        cin >> v[i].time;
    }

    sort(v.begin(), v.end());

    long long ans = 0;

    for (int i=v.size()-1;i>=0;i--) {
        total -= v[i].cost;
        ans += total * v[i].time;
    }

    cout << ans << endl;

    return 0;
}
