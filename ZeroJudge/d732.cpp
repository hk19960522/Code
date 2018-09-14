#include <iostream>
#include <cstdio>

using namespace std;

int main()
{
    int arr[100005] = {0};
    int N, M;
    cin >> N >> M;

    for (int i=1;i<=N;i++) cin >> arr[i];
    for (int i=1;i<=M;i++) {
        int tar, ans = 0;
        int l = 1, r = N;
        cin >> tar;

        while ( l <= r ) {
            int mid = ( l + r ) / 2;
            if ( arr[mid] == tar ) {
                ans = mid;
                break;
            }

            if ( arr[mid] > tar ) r = mid-1;
            else l = mid+1;
        }

        cout << ans << endl;
    }
    return 0;
}
