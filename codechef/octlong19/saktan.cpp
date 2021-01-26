#include <bits/stdc++.h>
#define ll long long int
using namespace std;

int main()
{
    ll t;
    cin >> t;
    while (t--)
    {
        ll n, m, q, r = 0, c = 0;
        cin >> n >> m >> q;
        // map<int, int> row, col;
        set<ll> row, col;
        while (q--)
        {
            ll x, y;
            cin >> x >> y;
            if (row.count(x))
                row.erase(x);
            else
                row.insert(x);
            if (col.count(y))
                col.erase(y);
            else
                col.insert(y);
            // row[x]++;
            // col[y]++;
        }
        r = row.size();
        c = col.size();
        // for (auto it = row.begin(); it != row.end(); it++)
        // {
        //     if (it->second & 1)
        //     {
        //         r++;
        //     }
        // }
        // for (auto it = col.begin(); it != col.end(); it++)
        // {
        //     if (it->second & 1)
        //     {
        //         c++;
        //     }
        // }
        ll ans = (r * m + c * n - 2 * (r * c));
        cout << ans << endl;
    }
    return 0;
}