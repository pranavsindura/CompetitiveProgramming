#include <bits/stdc++.h>
using namespace std;
#define ll long long int
bool distinct(ll num)
{
    ll temp = num;
    set<int> s;
    while (temp)
    {
        if (s.count(temp % 10))
            return false;
        else
            s.insert(temp % 10);
        temp /= 10;
    }
    return true;
}
int main()
{
    ll l, r;
    cin >> l >> r;
    vector<ll> ans;
    for (ll i = l; i <= r; i++)
    {
        if (distinct(i))
            ans.push_back(i);
    }
    ll m = INT_MIN;
    ll an = 0;
    if (!ans.size())
    {
        cout << -1;
        return 0;
    }
    for (int i = 0; i < (int)ans.size(); i++)
    {
        ll a = (r - ans[i]) * (ans[i] - l);
        if (a > m)
        {
            an = ans[i];
            m = a;
        }
        else if (a == m)
        {
            if (ans[i] > an)
            {
                an = ans[i];
            }
        }
    }
    cout << an;
    return 0;
}