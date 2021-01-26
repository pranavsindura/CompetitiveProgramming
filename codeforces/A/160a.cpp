#include <bits/stdc++.h>
#define ll long long int
using namespace std;
int main()
{
    int n;
    cin >> n;
    vector<int> arr(n), pre(n);
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }
    sort(arr.rbegin(), arr.rend());
    pre[0] = arr[0];
    for (int i = 1; i < n; i++)
        pre[i] = arr[i] + pre[i - 1];
    ll l, r;
    int ans;
    for (int i = 0; i < n; i++)
    {
        l = pre[i];
        r = pre[n - 1] - pre[i];
        // cout << l << " " << r << endl;
        if (l > r)
        {
            ans = i + 1;
            break;
        }
    }
    sort(arr.begin(), arr.end());
    pre.clear();
    pre[0] = arr[0];
    for (int i = 1; i < n; i++)
        pre[i] = arr[i] + pre[i - 1];
    for (int i = 0; i < n; i++)
    {
        l = pre[i];
        r = pre[n - 1] - pre[i];
        if (l > r)
        {
            ans = min(ans, i + 1);
            break;
        }
    }
    cout << ans;
    return 0;
}