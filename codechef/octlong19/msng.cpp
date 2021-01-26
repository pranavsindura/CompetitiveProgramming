#include <bits/stdc++.h>
#define ll long long int
using namespace std;
int val(char b)
{
    if (b >= '0' && b <= '9')
        return b - '0';
    else
        return (b - 'A' + 10);
}

ll dec(int b, string s)
{
    ll ans = 0, pow = 1;
    ll base = b;
    for (int i = s.length() - 1; i >= 0; i--)
    {
        if (pow > 1e12)
            return -1;
        if (val(s[i]) >= b)
            return -1;
        ans += val(s[i]) * pow;
        if (ans > 1e12)
            return -1;
        pow = pow * base;
    }
    return ans;
}

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        int b;
        string s;
        vector<pair<int, string>> v(n);
        for (int i = 0; i < n; i++)
        {
            cin >> b >> s;
            v[i].first = b;
            v[i].second = s;
        }
        vector<vector<ll>> ans(n);
        for (int i = 0; i < n; i++)
        {
            if (v[i].first == -1)
            {
                for (int j = 2; j <= 36; j++)
                {
                    ll a = dec(j, v[i].second);
                    ans[i].push_back(a);
                }
                sort(ans[i].begin(), ans[i].end());
            }
            else
            {
                ll a = dec(v[i].first, v[i].second);
                ans[i].push_back(a);
            }
        }
        vector<ll> intersection;
        for (auto ele : ans[0])
        {
            bool found = true;
            for (int i = 0; i < n; i++)
            {
                if (!binary_search(ans[i].begin(), ans[i].end(), ele))
                {
                    found = false;
                    break;
                }
            }
            if (found && ele != -1)
            {
                intersection.push_back(ele);
            }
        }
        if (intersection.size())
        {
            ll min = *min_element(intersection.begin(), intersection.end());
            cout << min << endl;
        }
        else
        {
            cout << -1 << endl;
        }
    }
    return 0;
}