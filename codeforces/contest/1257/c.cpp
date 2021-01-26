#include <bits/stdc++.h>
#define ll long long int
#define mod 1000000007
#define all(x) x.begin(), x.end()
#define FASTIO                            \
    {                                     \
        ios_base::sync_with_stdio(false); \
        cin.tie(NULL);                    \
        cout.tie(NULL);                   \
    }
using namespace std;

int main()
{
    FASTIO;
    int t;
    cin >> t;
    while (t--)
    {
        int n, x;
        cin >> n;
        vector<vector<int>> v(n + 1);
        for (int i = 0; i < n; i++)
        {
            cin >> x;
            v[x].push_back(i + 1);
        }
        int ans = INT_MAX;
        for (int i = 1; i <= n; i++)
        {
            if (v[i].size() > 1)
            {
                for (int j = 0; j < v[i].size() - 1; j++)
                {
                    ans = min(ans, abs(v[i][j] - v[i][j + 1]) + 1);
                }
            }
        }
        if (ans == INT_MAX)
            cout << -1 << endl;
        else
            cout << ans << endl;
    }
    return 0;
}