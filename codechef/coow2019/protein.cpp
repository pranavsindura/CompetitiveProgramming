#include <bits/stdc++.h>
using namespace std;
#define ll long long int

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n, q;
        cin>>n>>q;
        vector<pair<ll, int>> arr;
        pair<ll,int> x;
        for (int i = 0; i < n; i++)
        {
            cin >> x.first;
            x.second = 0;
            arr.push_back(x);
        }
        while(q--)
        {
            int l, r;
            cin>>l>>r;
            l--;
            r--;
            for(int i=l;i<=r;i++)
                arr[i].second+=1;
        }
        ll ans=0;
        int mdrink = INT_MIN;
        for(int i=0;i<n;i++)
        {
            if(arr[i].second > mdrink)
            {
                mdrink = arr[i].second;
                ans = arr[i].first;
            }
            // else if(arr[i].second == mdrink)
            // {
            //     if(arr[i].first > ans)
            //     {
            //         ans = arr[i].first;
            //     }
            // }
        }
        cout<<ans<<endl;
    }
}