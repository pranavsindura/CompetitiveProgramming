#include <bits/stdc++.h>
#define ll long long int
using namespace std;

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        ll n, p, x;
        cin >> n >> p;
        vector<ll> arr;
        for (int i = 0; i < n; i++)
        {
            cin >> x;
            arr.push_back(x);
        }
        sort(arr.begin(), arr.end());
        for (int i = 1; i < n; i++)
            arr[i] += arr[i - 1];
        // for(int i=0;i<n;i++)
            // cout<<arr[i]<<" ";
        auto it = upper_bound(arr.begin(), arr.end(), p);
        if (it != arr.end())
        {
            // it--;
            cout << it - arr.begin()<< endl;
        }
        else
            cout << "0\n";
    }
    return 0;
}