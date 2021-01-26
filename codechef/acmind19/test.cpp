#include <bits/stdc++.h>
#define ll long long int
#define mod 1000000007
#define M 35
using namespace std;
pair<int, string> f(ll arr[], set<pair<int, string>> s, int pos)
{
    if (pos > 34 && s.size())
    {
        return *s.begin();
    }

    set<pair<int, string>> s2;
    for (auto it = s.begin(); it != s.end(); ++it)
    {
        if (it->second[pos] == '0')
        {
            s2.insert(*it);
            // cout<<arr[it->first]<<" ";
        }
    }
    if (s2.size())
    {
        return f(arr, s2, pos + 1);
    }
    else
    {
        return f(arr, s, pos + 1);
    }
}
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n, x;
        cin >> n;
        ll arr[n];
        // vector<pair<ll, pair<pair<int,int>,int>>> bit;
        string v[n];
        set<pair<int, string>> s;
        for (int i = 0; i < n; i++)
        {
            cin >> arr[i];
            bitset<M> y = bitset<M>(arr[i]);
            // v.push_back(y);
            v[i] = y.to_string();
            s.insert({i, v[i]});
        }
        vector<int> ind;
        while (s.size())
        {
            pair<int, string> x = f(arr, s, 0);
            // cout << endl;
            ind.push_back(x.first);
            s.erase(x);
        }
        // reverse(ind.begin(), ind.end());
        ll happy[n + 1];
        happy[0] = arr[ind[0]];
        for (int i = 1; i < n; i++)
        {
            happy[i] = happy[i - 1] | arr[ind[i]];
        }
        ll ans = 0;
        for (int i = 0; i < n; i++)
        {
            ans += happy[i];
        }
        cout<<ans<<endl;
        for (int i = 0; i < n; i++)
        {
            cout<<ind[i]+1<<" ";
        }
        cout<<endl;
        // sort(bit.begin(), bit.end(), [](pair<ll, pair<pair<int,int>,int>> a, pair<ll, pair<pair<int,int>,int>> b) { return (a.second.first.first >= b.second.first.first && a.first > b.first); });
        // ll happy[n + 1];
        // for (int i = 0; i < n; i++)
        //     cout<<bit[i].first<<" "<<bit[i].second.first<<endl;
        // happy[0] = bit[0].first;
        // for (int i = 1; i < n; i++)
        // {
        //     happy[i] = happy[i - 1] | bit[i].first;
        // }
        // for (int i = 0; i < n; i++)
        //     cout<<happy[i]<<" ";
        // cout<<endl;
        // ll ans = 0;
        // for (int i = 0; i < n; i++)
        // {
        //     ans += happy[i];
        // }
        // cout << ans << endl;
        // for (int i = n-1; i >=0; i--)
        // {
        //     cout<<bit[i].second.second<<" ";
        // }
        // cout<<endl;
    }
    return 0;
}