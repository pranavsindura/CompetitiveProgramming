#include <bits/stdc++.h>
#define ll long long int
using namespace std;
int main()
{
    int n;
    cin >> n;
    ll arr[n + 2];
    for (int i = 1; i <= n; ++i)
        cin >> arr[i];
    arr[0] = INT_MAX;
    arr[n+1] = INT_MIN;
    for (int i = 1; i <= n; ++i)
    {
        ll mind = min(abs(arr[i] - arr[i - 1]), abs(arr[i] - arr[i + 1]));
        ll maxd = max(abs(arr[i] - arr[1]), abs(arr[i] - arr[n]));
        cout<<mind<<" "<<maxd<<endl;
    }
    return 0;
}